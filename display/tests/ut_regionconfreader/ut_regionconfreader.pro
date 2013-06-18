include(../ut-head.pri)

TEST_SOURCES = \
		$$PKGROOT/src/regionconfreader.cpp

HEADERS += *.h \
	$$PKGROOT/src/regionconfreader.h \

SOURCES += *.cpp \
	$$TEST_SOURCES

testdata.files = testregions.conf
testdata.path = $$DCP_PREFIX/lib/duicontrolpanel-displaylanguageapplet-tests
INSTALLS += testdata

REGION_TESTCONF_PATH = $$DCP_PREFIX/lib/duicontrolpanel-displaylanguageapplet-tests/testregions.conf

DEFINES += REGION_CONF_PATH=\\\"$${REGION_TESTCONF_PATH}\\\"
TARGET = ut_regionconfreader

include(../ut-tail.pri)

