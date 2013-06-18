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

#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusConnection>
#include <QString>
#include <QApplication>
#include <QTimer>
#include <QFileInfo>
#include <QtDebug>

#ifdef HAVE_QMSYSTEM
#include <qmdisplaystate.h>
#include <qmusbmode.h>
#endif

#include "systemcontrol.h"

const char *MStartupAppName = "Meego Startup Wizard";
const char *NoRebootFile = "/tmp/LANG_NO_REBOOT";

SystemControl::SystemControl(QObject *parent) : QObject(parent) {}

SystemControl::~SystemControl() {}

bool SystemControl::isUsbConnected() {
    bool ret = false;
#ifdef HAVE_QMSYSTEM
    MeeGo::QmUSBMode usbMode;
    MeeGo::QmUSBMode::Mode mode = usbMode.getMode();
    qDebug() << "usbmode" << mode;
    ret = mode == MeeGo::QmUSBMode::MassStorage;
#endif

    return ret;
}

bool SystemControl::needToRebootAfterLanguageChange() {
#ifndef HAVE_SHUTDOWN
    return false;
#else
    if (qApp->applicationName() == MStartupAppName) {
        return false;
    }
    QFileInfo fileInfo(NoRebootFile);
    return !fileInfo.exists();
#endif    
}

void SystemControl::reboot() {
    turnOffScreen();
    QDBusInterface dsmeIf("com.nokia.dsme",
                          "/com/nokia/dsme/request",
                          "com.nokia.dsme.request",
                          QDBusConnection::systemBus());
    dsmeIf.call("req_reboot");
}

void SystemControl::turnOffScreen() {
#ifdef HAVE_QMSYSTEM
    MeeGo::QmDisplayState display;
    bool st = display.set(MeeGo::QmDisplayState::Off);
    if (!st) {
        qWarning() << "Turning off the display failed";
    }
#endif    
}
