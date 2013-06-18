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
#include "ut_systemcontrol.h"

#include "systemcontrol.h"

#include <QtDBus/QDBusInterface>
#ifdef HAVE_QMSYSTEM
#include <qmdisplaystate.h>
#endif


static QString methodToCheck;
static int callCalled;
QDBusMessage QDBusAbstractInterface::call ( const QString &method, const QVariant &, const QVariant &, const QVariant &, const QVariant &, const QVariant &, const QVariant &, const QVariant &, const QVariant &)
{
    if (!methodToCheck.isEmpty()) {
        Q_ASSERT(method == methodToCheck);
    }
    Q_UNUSED(method);
    ++callCalled;
    return QDBusMessage();
}

#ifdef HAVE_QMSYSTEM
static int setDisplayCalled;
static MeeGo::QmDisplayState::DisplayState displayState;
bool MeeGo::QmDisplayState::set(MeeGo::QmDisplayState::DisplayState state)
{
    ++setDisplayCalled;
    Q_ASSERT(state == displayState);
    Q_UNUSED(state);
    return true;
}
#endif

// disables output messages to be able to see the test result
void myMsgHandler(QtMsgType, const char *) { }

void Ut_SystemControl::initTestCase()
{
    qInstallMsgHandler(myMsgHandler);
}

void Ut_SystemControl::cleanupTestCase()
{
}

void Ut_SystemControl::init ()
{
}

void Ut_SystemControl::cleanup ()
{
}

void Ut_SystemControl::testConstructDestruct()
{
    SystemControl syscontrol;
}


void Ut_SystemControl::testNeedToRebootAfterLanguageChange()
{
    SystemControl syscontrol;
    Q_ASSERT(!syscontrol.needToRebootAfterLanguageChange());
}

void Ut_SystemControl::testReboot()
{
    SystemControl syscontrol;

#ifdef HAVE_QMSYSTEM
    setDisplayCalled = 0;
    displayState = MeeGo::QmDisplayState::Off;
#endif
    callCalled = 0;
    methodToCheck = "req_reboot";
    syscontrol.reboot();
    QCOMPARE(callCalled, 1);
#ifdef HAVE_QMSYSTEM
    QCOMPARE(setDisplayCalled, 1);
#endif
}

QTEST_APPLESS_MAIN(Ut_SystemControl)

