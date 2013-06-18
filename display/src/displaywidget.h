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

#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QModelIndex>
#include <MSheet>
#include "systemcontrol.h"

class MMessageBox;
class MSceneWindow;
class MLabel;
class QGraphicsLinearLayout;

class DisplayWidget : public MSheet
{
    Q_OBJECT

public:
    DisplayWidget();
    virtual ~DisplayWidget();
    void selectItem (const QModelIndex& index);
    void setDoneButtonEnabled (bool enabled = true);

protected slots:
    virtual void onLanguageSelected();
    void onItemClicked (const QModelIndex&);
    void onChangeLanguageDialogAccepted();
    void onChangeLanguageDialogRejected();
    void startSpinner();
    void changeLanguageAndClose();
    void changeOrientation(M::Orientation orientation);
    void scrollToSelected();
    void liveFilteringTextChangedSlot();
    void filteringVKBSlot();
    void showTextEdit(bool show);
    void displayEnteredSlot();
    void showFullScreenMessage(const QString &label1, const QString &label2);
    void acceptLanguage();
    void cancelSheet();
    void hideVKB();
    
protected:
    void initWidget();
    QString title() const;

    virtual void polishEvent();

    MMessageBox* changeLanguageDialog();
    virtual void dismissEvent (MDismissEvent *event);
	
private:
    void retranslateUi();
    void retranslateUiWidgets();
    void addHeader();
    QGraphicsLinearLayout *getLayout();

private:
    QModelIndex currentLanguageProxyIndex();
    QModelIndex langIdProxyIdx (const QString& id);
    QModelIndex translateModelIndex(const QModelIndex &languageModelIndex);
    void selectCurrentLanguage();
    class DisplayLangCellCreator* m_CellCreator;
    class MList* m_List;
    MMessageBox *m_ChangeLanguageDialog;
    MSceneWindow *m_SpinnerWindow;
    SystemControl m_SystemControl;
    bool m_ListEnabled;
    MLabel *m_titleLabel;
    QString m_SelectedLangId;

#ifdef UNIT_TEST
    friend class Ut_DisplayWidget;
#endif
};

#endif //DISPLAYWIDGET_H

