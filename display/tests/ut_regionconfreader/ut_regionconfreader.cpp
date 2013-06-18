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

#include <QtTest/QtTest>
#include <QObject>
#include "ut_regionconfreader.h" 
#include "regionconfreader.h" 

QString SupportedRegionsConf;

void Ut_RegionConfReader::initTestCase()
{
}

void Ut_RegionConfReader::cleanupTestCase()
{
}


void Ut_RegionConfReader::cleanup()
{
    delete m_subject;
}

void Ut_RegionConfReader::init()
{
    m_subject = new RegionConfReader();
}

void Ut_RegionConfReader::testAvailableRegions()
{
    QStringList testData;
    testData << "nl_BE" << "fr_BE" << "es_AR" << "nl_NL";
    QStringList rlist = m_subject->availableRegions();
    QCOMPARE(rlist, testData);
}

QTEST_APPLESS_MAIN(Ut_RegionConfReader);

