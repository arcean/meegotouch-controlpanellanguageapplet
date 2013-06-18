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


DisplayWidget::DisplayWidget()
              :MSheet(),
               m_SpinnerWindow(0),
               m_ListEnabled(true)
{
}

DisplayWidget::~DisplayWidget()
{
}

void DisplayWidget::initWidget()
{
}

void DisplayWidget::hideVKB()
{

}

void DisplayWidget::addHeader()
{

}

void DisplayWidget::acceptLanguage()
{

}

void DisplayWidget::cancelSheet()
{
}

QGraphicsLinearLayout *DisplayWidget::getLayout()
{
    return 0;
}

void DisplayWidget::displayEnteredSlot()
{
}

void DisplayWidget::dismissEvent (MDismissEvent *)
{
}

void DisplayWidget::showFullScreenMessage(const QString &,
                                          const QString &)
{
}

QString DisplayWidget::title() const
{
    return QString();
}

void DisplayWidget::onLanguageSelected()
{ 
}

void DisplayWidget::onChangeLanguageDialogAccepted()
{
}

void DisplayWidget::onChangeLanguageDialogRejected()
{
}

void DisplayWidget::startSpinner()
{
}

void DisplayWidget::changeLanguageAndClose() 
{
}

void DisplayWidget::selectCurrentLanguage()
{
}

void DisplayWidget::polishEvent()
{
}

void DisplayWidget::scrollToSelected()
{
}

void DisplayWidget::changeOrientation(M::Orientation)
{
}

QModelIndex DisplayWidget::currentLanguageProxyIndex()
{
    return QModelIndex();
}

void DisplayWidget::liveFilteringTextChangedSlot()
{
}

void DisplayWidget::filteringVKBSlot()
{
}

void DisplayWidget::showTextEdit(bool) {
}

QModelIndex
DisplayWidget::translateModelIndex(const QModelIndex &)
{
    return QModelIndex();
}

void DisplayWidget::retranslateUi() {
}

void DisplayWidget::onItemClicked (const QModelIndex&)
{
}

void DisplayWidget::selectItem (const QModelIndex&)
{
}

QModelIndex DisplayWidget::langIdProxyIdx (const QString&)
{
    return QModelIndex();
}

void DisplayWidget::setDoneButtonEnabled (bool)
{
}

