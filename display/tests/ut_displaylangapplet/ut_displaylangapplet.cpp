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
#include "ut_displaylangapplet.h"
#include "displaylangapplet.h"

#include <DcpStylableWidget>
#include <DcpBrief>
#include <MSheet>

void Ut_DisplayLangApplet::initTestCase()
{
}

void Ut_DisplayLangApplet::cleanupTestCase()
{
}

void Ut_DisplayLangApplet::init ()
{
}

void Ut_DisplayLangApplet::cleanup ()
{
}

void Ut_DisplayLangApplet::testInit ()
{
    DisplayLangApplet *appl = new DisplayLangApplet;

    QVERIFY(appl);

    appl->init();

    delete appl;
}

void Ut_DisplayLangApplet::testConstructStylableWidget ()
{
    DisplayLangApplet *appl = new DisplayLangApplet;

    QVERIFY(appl);

    /* this is sheet now
    DcpStylableWidget *swidget = appl->constructStylableWidget(1);
    QVERIFY(swidget);

    delete swidget;
     */

    MSheet* sheet = appl->constructSheet (1);
    QVERIFY (sheet);
    delete sheet;

    delete appl;
}

void Ut_DisplayLangApplet::testTitle ()
{
    DisplayLangApplet *appl = new DisplayLangApplet;

    QVERIFY(appl);

    QCOMPARE(appl->title(), qtTrId("qtn_comm_settings_language"));

    delete appl;
}

void Ut_DisplayLangApplet::testViewMenuItems ()
{
    DisplayLangApplet *appl = new DisplayLangApplet;

    QVERIFY(appl);

    QVERIFY(appl->viewMenuItems().isEmpty());

    delete appl;
}

void Ut_DisplayLangApplet::testConstructBrief ()
{
    DisplayLangApplet *appl = new DisplayLangApplet;

    QVERIFY(appl);

    DcpBrief *brief = appl->constructBrief(1);
    QVERIFY(brief);

    delete brief;
    delete appl;
}

QTEST_APPLESS_MAIN(Ut_DisplayLangApplet)

