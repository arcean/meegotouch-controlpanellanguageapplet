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
#include "ut_displaywidget.h"
#include "stub_dcpdisplaylangconf.h"

#include "dcpdisplaylangconf.h"
#include "displaywidget.h"
#include "languagemodel.h"
#include "displaylangcellcreator.h"

#include <MApplication>
#include <MContainer>
#include <QStringListModel>
#include <QSortFilterProxyModel>
#include <MList>
#include <MSceneWindow>

void MSceneWindow::appear(MWindow*,MSceneWindow::DeletionPolicy)
{

}

void QSortFilterProxyModel::setFilterRegExp (const QRegExp &)
{

}

void Ut_DisplayWidget::initTestCase()
{
}

void Ut_DisplayWidget::cleanupTestCase()
{
}

void Ut_DisplayWidget::init ()
{
    m_Widget = new DisplayWidget();
}

void Ut_DisplayWidget::cleanup ()
{
    delete m_Widget;
}

void Ut_DisplayWidget::testConstructDestruct()
{
    // tests only that it did not segfault on construction
    QVERIFY(m_Widget->m_List != 0);
}

void Ut_DisplayWidget::testDisplayEnteredSlot()
{
    m_Widget->displayEnteredSlot();
}

void Ut_DisplayWidget::testShowFullScreenMessage()
{

    m_Widget->showFullScreenMessage("ize", "bize");
}

void Ut_DisplayWidget::testTitle()
{

    QCOMPARE(m_Widget->title(), qtTrId("qtn_comm_settings_language"));
}

void Ut_DisplayWidget::testSelectedItem()
{
    // use a new m_Widget after we initialized stub values
/*    delete m_Widget;
    QStringList langList;
    langList << "en" << "fi" << "hu";
    setDcpDisplayLangConfStubAvailableLanguages(langList);
    setDcpDisplayLangConfStubLanguage("fi");
    m_Widget = new DisplayWidget();

    QModelIndexList selection =     
        m_Widget->m_List->selectionModel()->selectedIndexes();
    QCOMPARE(selection.size(), 1);
    QCOMPARE(selection.at(0).data().toString(), QString("fi"));
    
    // test flexibility of the widget, use a current locale id
    // that doesn't match exactly with list ids
    // if en_GB is not listed, it should be mapped to en
    delete m_Widget;
    setDcpDisplayLangConfStubLanguage("en_GB");
    m_Widget = new DisplayWidget();

    selection = m_Widget->m_List->selectionModel()->selectedIndexes();
    QCOMPARE(selection.size(), 1);
    QCOMPARE(selection.at(0).data().toString(), QString("en"));
*/
}

void Ut_DisplayWidget::testOnLanguageSelected()
{
    // fake displayconf to get the result:
    DcpDisplayLangConf* conf = DcpDisplayLangConf::instance();
    conf->setDisplayLanguage(QString("hu_HU"));

    MAbstractItemModel *model = &(LanguageModel::instance());
    m_Widget->onItemClicked (model->index(0, 0, model->index(0, 0)));
    m_Widget->onLanguageSelected();
    m_Widget->changeLanguageAndClose();
    QCOMPARE(conf->displayLanguage(), QString("en_US"));
}

void Ut_DisplayWidget::testOnChangeLanguageDialogRejected()
{
    m_Widget->onChangeLanguageDialogRejected();
}

void Ut_DisplayWidget::testStartSpinner()
{
    m_Widget->startSpinner();
    Q_ASSERT(m_Widget->m_SpinnerWindow);
}

void Ut_DisplayWidget::testChangeLanguageAndClose()
{
    m_Widget->changeLanguageAndClose();
    Q_ASSERT(!m_Widget->m_SpinnerWindow);
}

void Ut_DisplayWidget::testSelectCurrentLanguage()
{
    m_Widget->selectCurrentLanguage();
}

void Ut_DisplayWidget::testPolishEvent()
{
    m_Widget->polishEvent();
}

void Ut_DisplayWidget::testScrollToSelected()
{
    m_Widget->scrollToSelected();

}

void Ut_DisplayWidget::testChangeOrientation()
{
    m_Widget->changeOrientation(M::Portrait);
}

void Ut_DisplayWidget::testLiveFilteringTextChangedSlot()
{
    m_Widget->liveFilteringTextChangedSlot();
}

void Ut_DisplayWidget::testFilteringVkbSlot()
{
    m_Widget->filteringVKBSlot();
}

void Ut_DisplayWidget::testShowTextEdit()
{
    m_Widget->showTextEdit(true);
    m_Widget->showTextEdit(false);
}

void Ut_DisplayWidget::testDisplayLangCellCreator()
{
    DisplayLangCellCreator *creator = new DisplayLangCellCreator;

    Q_ASSERT(creator);

    MAbstractItemModel *model = &(LanguageModel::instance());
    creator->updateCell(model->index(0, 0, model->index(0, 0)), 0);

    DisplayLangItem item;
    creator->updateCell(model->index(0, 0, model->index(0, 0)), &item);

    creator->highlightByText("Persze");
    // preamble is defined in DisplayLangCellCreator::DisplayLangCellCreator
    // color value is faked as #ffffff in mtheme-fake.cpp
    QString preample("<style> hi { color: #ffffff; font-weight: bold; text-decoration: underline; } </style>");
    QCOMPARE(creator->formatText("NaPersze!!!"), preample + QString("Na<hi>Persze</hi>!!!"));

    delete creator;
}

QTEST_APPLESS_MAIN(Ut_DisplayWidget)
