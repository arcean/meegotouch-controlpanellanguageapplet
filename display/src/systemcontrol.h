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

#ifndef SYSTEM_CONTROL_H__
#define SYSTEM_CONTROL_H__

#include <QString>
#include <QObject>

/**
 \class SystemControl 
 \brief This class wraps various system services that reports usb status and 
 provide system message screen and reboot.
 */
class SystemControl : public QObject
{
    Q_OBJECT

    public:
        SystemControl(QObject *parent=0);
        ~SystemControl();

        bool isUsbConnected();
        static bool needToRebootAfterLanguageChange();        

    public slots:
        void reboot();

    private slots:
        void turnOffScreen();
};

extern const char *MStartupAppName;

#endif // SYSTEM_CONTROL_H__
