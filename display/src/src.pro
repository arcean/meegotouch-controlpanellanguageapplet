TEMPLATE = lib
QMAKE_LFLAGS = -Wl,--as-needed

CONFIG += \
    plugin \
    gui \
    meegotouchcore \
    duicontrolpanel \
    silent

QT += xml

include(../../common.pri)

MOC_DIR = ../tmp
OBJECTS_DIR = ../tmp

QMAKE_DISTCLEAN += -r $$MOC_DIR $$OBJECTS_DIR

HEADERS += $$system(find ./ -name \'*.h\')
SOURCES += $$system(find ./ -name \'*.cpp\')

TARGET        = $$qtLibraryTarget(displaylanguage)
DESTDIR       = ../lib

target.path += $$DCP_APPLET_DIR

message ("Plugin path will be: "$$target.path)

INSTALLS += target

# enable query dialog and shutdown after language change
DEFINES += HAVE_SHUTDOWN

perf_measurement {
    DEFINES += PERF_MEASUREMENT
}

debug {
    DEFINES += DEBUG
    DEFINES += APP_NAME=\\\"\"disp-lang-app\"\\\"
}

# for check:
QMAKE_EXTRA_TARGETS += check
check.commands = $$system(true)

contains(LANGUAGE_BUILD_FEATURES,coverage) {
  QMAKE_EXTRA_TARGETS += coverage
  coverage.commands = $$system(true)
}

