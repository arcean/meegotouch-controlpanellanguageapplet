include(../ut-head.pri)

CONFIG += duicontrolpanel

TEST_SOURCES = \
    $$PKGROOT/src/displaywidget.cpp

HEADERS += *.h \
    $$PKGROOT/src/debug.h \
    $$PKGROOT/src/dcpdisplaylangconf.h \
    $$PKGROOT/src/displaywidget.h \
    $$PKGROOT/src/displaylangcellcreator.h \
    $$PKGROOT/src/displaylangitem.h \
    $$PKGROOT/src/languagemodel.h \
    $$PKGROOT/src/systemcontrol.h \
    $$PKGROOT/tests/stubs/stub_dcpdisplaylangconf.h \


SOURCES += *.cpp \
    $$PKGROOT/src/debug.cpp \
    $$PKGROOT/tests/stubs/stub_dcpdisplaylangconf.cpp \
    $$PKGROOT/tests/stubs/stub_languagemodel.cpp \
    $$PKGROOT/src/displaylangitem.cpp \
    $$PKGROOT/tests/stubs/stub_systemcontrol.cpp \
    $$PKGROOT/tests/stubs/qgraphicslayoutitem-fake.cpp \
    $$PKGROOT/tests/stubs/qgraphicslinearlayout-fake.cpp \
    $$PKGROOT/tests/stubs/mwidgetcontroller-fake.cpp \
    $$PKGROOT/tests/stubs/mseparator-fake.cpp \
    $$PKGROOT/tests/stubs/mtheme-fake.cpp \
    $$PKGROOT/tests/stubs/mtextedit-fake.cpp \
    $$PKGROOT/tests/stubs/mapplication-fake.cpp \
    $$PKGROOT/tests/stubs/mapplicationwindow-fake.cpp \
    $$PKGROOT/tests/stubs/mabstractlayoutpolicy-fake.cpp \
    $$PKGROOT/tests/stubs/mlayout-fake.cpp \
    $$PKGROOT/tests/stubs/mlinearlayoutpolicy-fake.cpp \
    $$PKGROOT/tests/stubs/qgraphicsobject-fake.cpp \
    $$PKGROOT/tests/stubs/mimagewidget-fake.cpp \
    $$PKGROOT/tests/stubs/mlistfilter-fake.cpp \
    $$PKGROOT/tests/stubs/mlist-fake.cpp \
    $$PKGROOT/tests/stubs/mbasiclistitem-fake.cpp \
    $$PKGROOT/tests/stubs/mwidget-fake.cpp \
    $$PKGROOT/tests/stubs/mlabel-fake.cpp \
    $$PKGROOT/tests/stubs/stub_mmessagebox.cpp \
    $$PKGROOT/tests/stubs/stub_mdialog.cpp \
    $$PKGROOT/tests/stubs/stub_qsortfilterproxymodel.cpp \
    $$TEST_SOURCES

LIBS += -lmeegotouchviews

TARGET = ut_displaywidget

include(../ut-tail.pri)

