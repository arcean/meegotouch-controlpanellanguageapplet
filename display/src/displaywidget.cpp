/***************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Karoliina T. Salminen <karoliina.t.salminen@nokia.com>
**
** This file is part of duicontrolpanel-languageapplet.
**
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/
/* -*- Mode: C; indent-tabs-mode: s; c-basic-offset: 4; tab-width: 4 -*- */
/* vim:set et ai sw=4 ts=4 sts=4: tw=80 cino="(0,W2s,i2s,t0,l1,:0" */

#include "displaywidget.h"

#include "dcpdisplaylangconf.h"
#include "systemcontrol.h"

#include <QtDebug>
#include <QTimer>
#include <QAction>
#include <MList>
#include <MPannableViewport>
#include <mwidgetcreator.h>
#include <MAbstractItemModel>
#include <QSortFilterProxyModel>
#include <MListFilter>
#include <MSortFilterProxyModel>
#include <QGraphicsGridLayout>
#include <QGraphicsLinearLayout>
#include <QModelIndex>
#include <MOrientationChangeEvent>
#include <MSceneManager>
#include <MApplication>
#include <MMessageBox>
#include <MLabel>
#include <MTextEdit>
#include <MStylableWidget>
#include <MModalSceneWindow>
#include <MProgressIndicator>
#include <MWidgetView>
#include <MBanner>
#include <MBasicSheetHeader>
#include <MTheme>
#include <mlabelstyle.h>
#include <MInputMethodState>

#include <dcpperflogger.h>

#include "languagemodel.h"
#include "debug.h"
#include "displaylangcellcreator.h"

#define LANG_CHANGE_DELAY 1000 
#define REBOOT_DELAY 1000

DisplayLangCellCreator::DisplayLangCellCreator() : 
    MAbstractCellCreator<DisplayLangItem>() {
        const MLabelStyle *style =
            qobject_cast<const MLabelStyle *>(MTheme::style("MLabelStyle",
                                                            "CommonSingleTitleAccented"));

        if (style) {
            preamble = "<style> hi { color: " + 
                style->color().name() + 
                "; font-weight: bold; text-decoration: underline; } </style>";
        }
}

void DisplayLangCellCreator::updateCell(
        const QModelIndex& index, MWidget * cell) const
{
    if (!cell){ /* happens to be null when shortening filter string */
        return;
    }
    if(!index.isValid()){ /* happens to be invalid when filtered to be empty */
        return;
    }

    DisplayLangItem * contentItem = qobject_cast<DisplayLangItem *>(cell);
    if (!contentItem)
       return;
    QStringList data = index.data(LanguageModel::DisplayRole).toStringList();
    contentItem->setTitle(formatText(data[LanguageModel::Name]));
}

QString DisplayLangCellCreator::formatText(QString text) const
{
    if (highlightText.isEmpty())
        return text;

    QString result = text;
    int matchingIndex = result.indexOf(highlightText, 0, Qt::CaseInsensitive);
    if(matchingIndex != -1) {
        result.insert(matchingIndex+highlightText.length(), "</hi>");
        result.insert(matchingIndex, "<hi>");
    }
    return preamble + result;
}

M_REGISTER_WIDGET_NO_CREATE (DisplayWidget)

DisplayWidget::DisplayWidget()
              :MSheet(),
               m_ChangeLanguageDialog (0),
               m_SpinnerWindow(0),
               m_ListEnabled(true),
               m_titleLabel(0)
{
    ENTER_FUNCTION();
    DCP_PERF_RECORD_EVENT("DisplayWidget_constructor_start");
    initWidget();
    DCP_PERF_RECORD_EVENT("DisplayWidget_constructor_stop");
    LEAVE_FUNCTION();
}

DisplayWidget::~DisplayWidget()
{
    ENTER_FUNCTION();
    delete m_ChangeLanguageDialog;
    LEAVE_FUNCTION();
}

void DisplayWidget::initWidget()
{
    QGraphicsLinearLayout * layout = new QGraphicsLinearLayout(Qt::Vertical);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QGraphicsWidget *mainWidget = new QGraphicsWidget;

    MPannableViewport *pannableViewport = new MPannableViewport;
    pannableViewport->setObjectName("pannableViewport");

    setStyleName("Inverted");

    m_titleLabel = new MLabel(qtTrId("qtn_comm_settings_language"));
    m_titleLabel->setStyleName("CommonHeaderInverted");
    layout->addItem(m_titleLabel);

    m_List = new MList();
    m_List->setObjectName("DisplayWidgetMList");
    m_List->setStyleName("CommonListInverted");
    m_CellCreator = new DisplayLangCellCreator();
    m_List->setCellCreator(m_CellCreator);
    m_List->setSelectionMode(MList::SingleSelection);

    MAbstractItemModel *model = &(LanguageModel::instance());
    model->setGrouped(true);
    m_List->setItemModel(model);
    m_List->setShowGroups (true);
    m_List->setIndexVisible(true);
    MListFilter *filter = m_List->filtering();

    filter->setEnabled(true);
    filter->setFilterMode(MListFilter::FilterAsSubstring);
    filter->setFilterRole(LanguageModel::FilterRole);
    filter->editor()->setVisible(false);

    connect(filter, SIGNAL(listPannedUpFromTop()),
            this, SLOT(filteringVKBSlot())); 
    connect(filter->editor(), SIGNAL(textChanged()),
            this, SLOT(liveFilteringTextChangedSlot())); 

    retranslateUiWidgets();
    connect(this, SIGNAL(displayEntered()),
            this, SLOT(displayEnteredSlot()));

#ifdef TWOCOLUMNMODE
    connect(MApplication::activeWindow(),
            SIGNAL(orientationChanged(M::Orientation)),
            this, SLOT(changeOrientation(M::Orientation)));
#endif

    if (model->groupCount() == 0) {
        MLabel *label = new MLabel("No language installed", this);
        label->setStyleName("CommonSingleTitleInverted");
        layout->addItem(label);
    } else {
       layout->addItem(m_List);
    }

    pannableViewport->setWidget(mainWidget);
    setCentralWidget(pannableViewport);

    addHeader();
    mainWidget->setLayout(layout);

    selectCurrentLanguage();

    connect (m_List, SIGNAL(itemClicked (QModelIndex)),
             this, SLOT (onItemClicked (QModelIndex)));
    connect(m_List->filtering()->editor(), SIGNAL(returnPressed()), this, SLOT(hideVKB()));
    connect(m_List, SIGNAL(panningStarted()), this, SLOT(hideVKB()));
}

void DisplayWidget::hideVKB()
{
    MInputMethodState::closeSoftwareInputPanel();
    m_List->setFocus();
}


void DisplayWidget::addHeader()
{
    MBasicSheetHeader *basicHeader = new MBasicSheetHeader;
    basicHeader->setStyleName("Inverted");

    basicHeader->setNegativeAction(new QAction(qtTrId("qtn_comm_cancel"), basicHeader));
    QAction* positive = new QAction(qtTrId("qtn_comm_command_done"), basicHeader);
    positive->setEnabled (false);
    basicHeader->setPositiveAction(positive);

    connect(basicHeader->negativeAction(), SIGNAL(triggered()), SLOT(cancelSheet()));
    connect(basicHeader->positiveAction(), SIGNAL(triggered()), SLOT(acceptLanguage()));

    setHeaderWidget(basicHeader);
}

// returns the language id of an index from the proxy model
QString langId (const QModelIndex& proxyIndex)
{
    QStringList currentList =
        proxyIndex.data(LanguageModel::DisplayRole).toStringList();
    if (currentList.count() > LanguageModel::Code) {
        return currentList.at(LanguageModel::Code);
    }
    return QString();
}

void DisplayWidget::onItemClicked (const QModelIndex& index)
{
    QString langId = ::langId(index);
    if (m_SelectedLangId == langId) return;
    m_SelectedLangId = langId;

    // enable accept button:
    setDoneButtonEnabled ();
}

void DisplayWidget::setDoneButtonEnabled (bool enabled)
{
    MBasicSheetHeader *basicHeader =
        qobject_cast<MBasicSheetHeader*>(headerWidget());

    if (basicHeader) {
        QAction* action = basicHeader->positiveAction();
        if (action) {
            action->setEnabled (enabled);
        }
    }
}

void DisplayWidget::acceptLanguage()
{
    if (!m_SelectedLangId.isEmpty())
    {
        onLanguageSelected();
    } else {
        dismiss();
    }
}

void DisplayWidget::cancelSheet()
{
    dismiss();
    selectCurrentLanguage();
}

void DisplayWidget::displayEnteredSlot()
{
    m_List->setFocus();
}



void DisplayWidget::showFullScreenMessage(const QString &str1, 
                                          const QString &str2)
{
    MLabel *label1 = new MLabel(str1);
    label1->setAlignment(Qt::AlignCenter);
    label1->setStyleName("CommonTitleInverted");
    MLabel *label2 = new MLabel(str2);
    label2->setAlignment(Qt::AlignCenter);
    label2->setStyleName("CommonTitleInverted");
    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical);
    layout->addStretch();
    layout->addItem(label1);
    layout->addItem(label2);    
    layout->addStretch();
    MModalSceneWindow *win = new MModalSceneWindow();
    win->setStyleName("LanguageFullScreenMessage");
    win->setLayout(layout);
    win->appear(MApplication::activeWindow(), MSceneWindow::DestroyWhenDone);
}

QString DisplayWidget::title() const
{
    //% "Language"
    const char *widgetTitle = QT_TRID_NOOP("qtn_comm_settings_language");
    return QString(qtTrId(widgetTitle));
}

void DisplayWidget::onLanguageSelected()
{
    if (!m_ListEnabled) {
        qDebug() << "selected during transition";
        return;
    }

    if (m_SelectedLangId.isEmpty()) {
        qWarning("Selected index is invalid"); 
        return;
    }

    // we get the currently set language this stupid, because we would like
    // to know how it is identified in the list, eg. value can be "en", but
    // in the list it is "en_GB"
    QString currentLangCode = langId (currentLanguageProxyIndex());

    if (m_SelectedLangId == currentLangCode) {
        dismiss();
        return;
    }
    m_ListEnabled = false;
    if (SystemControl::needToRebootAfterLanguageChange()) {
        changeLanguageDialog()->appear();
    } else {
        onChangeLanguageDialogAccepted();
    }
}

void DisplayWidget::onChangeLanguageDialogAccepted()
{
    if (SystemControl::needToRebootAfterLanguageChange()) {

        if (m_SystemControl.isUsbConnected()) {
            MBanner *banner = new MBanner;
            banner->setStyleName("InformationBanner");
            //% "Language cannot be changed while USB mass storage is in use."
            banner->setTitle(qtTrId("qtn_lang_usb_reboot_fail"));
            banner->appear(MApplication::activeWindow(),
                           MSceneWindow::DestroyWhenDone);
            m_ListEnabled = true;
            return;
        }

        showFullScreenMessage(
                              //% "Changing language"
                              qtTrId("qtn_lang_change_down"),
                              //% "Please wait!"
                              qtTrId("qtn_lang_wait"));
        // do a delayed language change, let enough time
        // to the shutdown message to appear
        QTimer::singleShot(LANG_CHANGE_DELAY, this, 
                           SLOT(changeLanguageAndClose()));

    } else {
        startSpinner();

        // do a delayed language change, let enough time
        // to the spinner to appear
        QTimer::singleShot(LANG_CHANGE_DELAY, this, 
                           SLOT(changeLanguageAndClose()));
    }
}

void DisplayWidget::onChangeLanguageDialogRejected()
{
    m_ListEnabled = true;
    dismiss();
}

void DisplayWidget::startSpinner()
{
    if (m_SpinnerWindow) {
        qCritical() << "spinner is already shown";
        return;
    }

    m_SpinnerWindow = new MModalSceneWindow();
    m_SpinnerWindow->setStyleName("SpinnerWindow");
    MProgressIndicator *spinner = new MProgressIndicator(m_SpinnerWindow, 
                                             MProgressIndicator::spinnerType);
    spinner->setUnknownDuration(true);
    spinner->setStyleName("CommonLargeSpinnerInverted");
    QGraphicsGridLayout *layout = new QGraphicsGridLayout();
    m_SpinnerWindow->setLayout(layout);
    layout->addItem(spinner, 1, 1);
    // didnt find any other way to center the spinner to the screen than
    // inserting it into a stretching grid
    layout->setRowStretchFactor(0, 1);
    layout->setRowStretchFactor(2, 1);
    layout->setColumnStretchFactor(0, 1);
    layout->setColumnStretchFactor(2, 1);
    m_SpinnerWindow->appear(MApplication::activeWindow(), 
                            MSceneWindow::DestroyWhenDone);
}

void DisplayWidget::changeLanguageAndClose() 
{
    DcpDisplayLangConf* conf = DcpDisplayLangConf::instance();
    conf->setDisplayLanguage(m_SelectedLangId);

    if (SystemControl::needToRebootAfterLanguageChange()) {
        // reboot with a delay
        QTimer::singleShot(REBOOT_DELAY, &m_SystemControl, SLOT(reboot()));
    } else {
        if (m_SpinnerWindow) {
            m_SpinnerWindow->disappear();
            m_SpinnerWindow = 0;
        } else {
            qCritical() << "spinner is already destroyed";
        }
        dismiss();
        m_ListEnabled = true;
    }
}

void DisplayWidget::dismissEvent (MDismissEvent *)
{
    // in startup wizart our sheet is reused, so it does not get deleted
    // when dismissed
    showTextEdit(false);
    setDoneButtonEnabled (false);
}

void DisplayWidget::selectCurrentLanguage()
{
    m_List->filtering()->editor()->clear();
    selectItem (currentLanguageProxyIndex());
    scrollToSelected();
    m_List->setFocus();
}

void DisplayWidget::polishEvent()
{
#ifdef TWOCOLUMNMODE
    if (sceneManager()) {
        changeOrientation(sceneManager()->orientation());
    }
#endif
}

void DisplayWidget::scrollToSelected()
{
    QItemSelectionModel *selectionModel = m_List->selectionModel();

    if (!selectionModel) {
        return;
    }

    QModelIndexList selectIdxList = selectionModel->selection().indexes();
    QModelIndex proxyIdx = translateModelIndex(selectIdxList[0]);
    if (proxyIdx.isValid()) {
        m_List->scrollTo(proxyIdx, MList::PositionAtTopHint);

        m_List->setFocus();

    } else {
        qWarning("selected index is not valid!");
    }

    m_List->setIndexDisplayMode(MList::Floating);
}

void DisplayWidget::changeOrientation(M::Orientation orientation)
{
#ifdef TWOCOLUMNMODE
    int columns = 2;
    if (orientation == M::Portrait) {
        columns = 1;
    }
    m_List->setColumns(columns);
#else
     Q_UNUSED(orientation);
#endif
}

QModelIndex DisplayWidget::langIdProxyIdx (const QString& id)
{
    QString fullName = DcpDisplayLangConf::fullName(id);
    QModelIndex sourceIdx = LanguageModel::instance().getIndex(fullName);    
    QModelIndex proxyIdx = translateModelIndex(sourceIdx);
    return proxyIdx;
}

QModelIndex DisplayWidget::currentLanguageProxyIndex()
{
    DcpDisplayLangConf *conf = DcpDisplayLangConf::instance();
    QString lang = conf->displayLanguage();
    return langIdProxyIdx (lang);
}

void DisplayWidget::liveFilteringTextChangedSlot()
{
    QString filter = m_List->filtering()->editor()->text();

    m_CellCreator->highlightByText(filter);
    MSortFilterProxyModel *proxy = m_List->filtering()->proxy();
    proxy->invalidate();

    // select the current item again if any (it might have been deselected
    // because it was not visible)
    if (!m_SelectedLangId.isEmpty()) {
        QModelIndex index = langIdProxyIdx (m_SelectedLangId);
        if (index.isValid()) {
            m_List->selectItem (index);
        }
    }
}

void DisplayWidget::selectItem (const QModelIndex& index)
{
    m_SelectedLangId = langId (index);
    m_List->selectItem(index);
}

void DisplayWidget::filteringVKBSlot()
{
    if(!m_List->filtering()->editor()->isOnDisplay()) {
        showTextEdit(true);
        m_List->filtering()->editor()->setFocus();
    }
}

QGraphicsLinearLayout *DisplayWidget::getLayout()
{
    MPannableViewport *vport = dynamic_cast<MPannableViewport*>(centralWidget());
    if (!vport) {
        return 0;
    }

    return dynamic_cast<QGraphicsLinearLayout*>(vport->widget()->layout());
}

void DisplayWidget::showTextEdit(bool show) {
    MTextEdit* textEdit = m_List->filtering()->editor();
    QGraphicsLinearLayout *mainLayout = getLayout();

    if (mainLayout) {
        if (show && !textEdit->isOnDisplay()) {
            qDebug() << "Textedit is visible";
            textEdit->setVisible(true);
            mainLayout->insertItem(1, textEdit);
            m_List->setLayoutPosition(M::TopCenterPosition);
        } else if(textEdit->isOnDisplay()) {
            m_List->setFocus();
            qDebug() << "Textedit is NOT visible";
            textEdit->setVisible(false);
            mainLayout->removeAt(1);
            textEdit->clear();
        }
    }
}

void DisplayWidget::retranslateUiWidgets()
{
    if (m_titleLabel) {
        m_titleLabel->setText(qtTrId("qtn_comm_settings_language"));
    }
    MBasicSheetHeader *basicHeader = qobject_cast<MBasicSheetHeader*>(headerWidget());

    if (basicHeader) {
        basicHeader->positiveAction()->setText(qtTrId("qtn_comm_command_done"));
        basicHeader->negativeAction()->setText(qtTrId("qtn_comm_cancel"));
    }
}

void DisplayWidget::retranslateUi() {
    retranslateUiWidgets();
    LanguageModel::instance().retranslateModel();
    selectCurrentLanguage();
}

QModelIndex
DisplayWidget::translateModelIndex(const QModelIndex &languageModelIndex)
{
    const QAbstractItemModel *sourceModel = languageModelIndex.model();
    QList<const MSortFilterProxyModel *> modelChain;
    const int maxDepth = 3;
    const QAbstractItemModel *m = m_List->itemModel();
    for (int depth = 0; depth < maxDepth; ++depth) {
        if (m == sourceModel) {
            break;
        }
        const MSortFilterProxyModel *proxyModel = 
            qobject_cast<const MSortFilterProxyModel *>(m);
        if (!proxyModel) {
            break;
        }
        modelChain.append(proxyModel);
        m = proxyModel->sourceModel();
    }
    if (m != sourceModel) {
        qWarning() << "original language model not found in proxy chain";
        return QModelIndex();
    }

    if (modelChain.isEmpty()) {
        // no proxy models in the way
        return languageModelIndex;
    }

    QModelIndex translatedIndex = languageModelIndex;
    for (int i = modelChain.count() - 1; i >= 0; --i) {
         const MSortFilterProxyModel *m = modelChain[i];
         translatedIndex = m->mapFromSource(translatedIndex);
    }

    return translatedIndex;
}

MMessageBox* DisplayWidget::changeLanguageDialog()
{
    if (!m_ChangeLanguageDialog) {
        //% "Change device language?" 
        m_ChangeLanguageDialog = new MMessageBox(qtTrId("qtn_lang_change_title"),
                             //% "The device will reboot, temporarily disabling all functions, including emergency calls."
                             qtTrId("qtn_lang_change_query"),
                             M::YesButton | M::NoButton);
        connect(m_ChangeLanguageDialog, SIGNAL(accepted()),
                this, SLOT(onChangeLanguageDialogAccepted()));
        connect(m_ChangeLanguageDialog, SIGNAL(rejected()),
                this, SLOT(onChangeLanguageDialogRejected()));
    }
    return m_ChangeLanguageDialog;
}


