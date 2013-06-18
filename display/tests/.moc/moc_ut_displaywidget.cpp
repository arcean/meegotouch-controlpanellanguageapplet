/****************************************************************************
** Meta object code from reading C++ file 'ut_displaywidget.h'
**
** Created: Sun Apr 14 00:32:10 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ut_displaywidget/ut_displaywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ut_displaywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ut_DisplayWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   32,   32,   32, 0x08,
      33,   32,   32,   32, 0x08,
      51,   32,   32,   32, 0x08,
      58,   32,   32,   32, 0x08,
      68,   32,   32,   32, 0x08,
      92,   32,   32,   32, 0x08,
     117,   32,   32,   32, 0x08,
     145,   32,   32,   32, 0x08,
     157,   32,   32,   32, 0x08,
     176,   32,   32,   32, 0x08,
     201,   32,   32,   32, 0x08,
     238,   32,   32,   32, 0x08,
     257,   32,   32,   32, 0x08,
     286,   32,   32,   32, 0x08,
     314,   32,   32,   32, 0x08,
     332,   32,   32,   32, 0x08,
     355,   32,   32,   32, 0x08,
     379,   32,   32,   32, 0x08,
     414,   32,   32,   32, 0x08,
     437,   32,   32,   32, 0x08,
     456,   32,   32,   32, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Ut_DisplayWidget[] = {
    "Ut_DisplayWidget\0initTestCase()\0\0"
    "cleanupTestCase()\0init()\0cleanup()\0"
    "testConstructDestruct()\0"
    "testDisplayEnteredSlot()\0"
    "testShowFullScreenMessage()\0testTitle()\0"
    "testSelectedItem()\0testOnLanguageSelected()\0"
    "testOnChangeLanguageDialogRejected()\0"
    "testStartSpinner()\0testChangeLanguageAndClose()\0"
    "testSelectCurrentLanguage()\0"
    "testPolishEvent()\0testScrollToSelected()\0"
    "testChangeOrientation()\0"
    "testLiveFilteringTextChangedSlot()\0"
    "testFilteringVkbSlot()\0testShowTextEdit()\0"
    "testDisplayLangCellCreator()\0"
};

const QMetaObject Ut_DisplayWidget::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ut_DisplayWidget,
      qt_meta_data_Ut_DisplayWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ut_DisplayWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ut_DisplayWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ut_DisplayWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ut_DisplayWidget))
        return static_cast<void*>(const_cast< Ut_DisplayWidget*>(this));
    return QObject::qt_metacast(_clname);
}

int Ut_DisplayWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initTestCase(); break;
        case 1: cleanupTestCase(); break;
        case 2: init(); break;
        case 3: cleanup(); break;
        case 4: testConstructDestruct(); break;
        case 5: testDisplayEnteredSlot(); break;
        case 6: testShowFullScreenMessage(); break;
        case 7: testTitle(); break;
        case 8: testSelectedItem(); break;
        case 9: testOnLanguageSelected(); break;
        case 10: testOnChangeLanguageDialogRejected(); break;
        case 11: testStartSpinner(); break;
        case 12: testChangeLanguageAndClose(); break;
        case 13: testSelectCurrentLanguage(); break;
        case 14: testPolishEvent(); break;
        case 15: testScrollToSelected(); break;
        case 16: testChangeOrientation(); break;
        case 17: testLiveFilteringTextChangedSlot(); break;
        case 18: testFilteringVkbSlot(); break;
        case 19: testShowTextEdit(); break;
        case 20: testDisplayLangCellCreator(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
