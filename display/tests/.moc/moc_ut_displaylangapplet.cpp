/****************************************************************************
** Meta object code from reading C++ file 'ut_displaylangapplet.h'
**
** Created: Sun Apr 14 00:31:08 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ut_displaylangapplet/ut_displaylangapplet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ut_displaylangapplet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ut_DisplayLangApplet[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   36,   36,   36, 0x08,
      37,   36,   36,   36, 0x08,
      55,   36,   36,   36, 0x08,
      62,   36,   36,   36, 0x08,
      72,   36,   36,   36, 0x08,
      83,   36,   36,   36, 0x08,
     113,   36,   36,   36, 0x08,
     125,   36,   36,   36, 0x08,
     145,   36,   36,   36, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Ut_DisplayLangApplet[] = {
    "Ut_DisplayLangApplet\0initTestCase()\0"
    "\0cleanupTestCase()\0init()\0cleanup()\0"
    "testInit()\0testConstructStylableWidget()\0"
    "testTitle()\0testViewMenuItems()\0"
    "testConstructBrief()\0"
};

const QMetaObject Ut_DisplayLangApplet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ut_DisplayLangApplet,
      qt_meta_data_Ut_DisplayLangApplet, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ut_DisplayLangApplet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ut_DisplayLangApplet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ut_DisplayLangApplet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ut_DisplayLangApplet))
        return static_cast<void*>(const_cast< Ut_DisplayLangApplet*>(this));
    return QObject::qt_metacast(_clname);
}

int Ut_DisplayLangApplet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 4: testInit(); break;
        case 5: testConstructStylableWidget(); break;
        case 6: testTitle(); break;
        case 7: testViewMenuItems(); break;
        case 8: testConstructBrief(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
