# desktop files:
harmattan {
    desktopsrc = displaylanguage.desktop.harmattan
}
!harmattan {
    desktopsrc = displaylanguage.desktop.meego
}
desktopfile = displaylanguage.desktop

QMAKE_EXTRA_TARGET += desktop
desktop.files += $$desktopfile
desktop.path = $$DCP_DESKTOP_DIR
desktop.commands = cp $$desktopsrc $$desktopfile
desktop.CONFIG += no_check_exist
INSTALLS += desktop


