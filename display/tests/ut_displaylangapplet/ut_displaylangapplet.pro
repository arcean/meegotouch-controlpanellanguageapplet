include(../ut-head.pri)

CONFIG+=duicontrolpanel

TEST_SOURCES = \
    $$PKGROOT/src/displaylangapplet.cpp

HEADERS += *.h \
    $$PKGROOT/src/displaywidget.h \
    $$PKGROOT/src/displaylangbrief.h \
    $$PKGROOT/src/systemcontrol.h \
    $$PKGROOT/src/displaylangapplet.h

SOURCES += *.cpp \
    $$PKGROOT/tests/stubs/stub_displaywidget.cpp \
    $$PKGROOT/tests/stubs/stub_displaylangbrief.cpp \
    $$PKGROOT/tests/stubs/stub_systemcontrol.cpp \
    $$PKGROOT/src/debug.cpp \
    $$TEST_SOURCES

TARGET = ut_displaylangapplet

include(../ut-tail.pri)

