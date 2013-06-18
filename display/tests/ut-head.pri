TEMPLATE = app

PKGROOT="../.."
include($$PKGROOT/../common.pri)

CONFIG += \
    qtestlib \
    meegotouchcore \
    silent

QT += testlib

INCLUDEPATH += $$PKGROOT/src
QMAKE_LIBDIR += $$PKGROOT/lib

DEFINES += UNIT_TEST
DEFINES += QT_NO_DEBUG_OUTPUT

UT_INSTALL_DIR = $$DCP_PREFIX/lib/duicontrolpanel-displaylanguageapplet-tests

target.path += $$UT_INSTALL_DIR

include(coverage.pri)

OBJECTS_DIR = .obj
MOC_DIR = ../.moc

QMAKE_CLEAN += .obj/* ../.moc/*
QMAKE_DISTCLEAN += -r .obj ../.moc

