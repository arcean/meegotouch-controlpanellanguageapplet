/****************************************************************************
** Meta object code from reading C++ file 'ut_regionconfreader.h'
**
** Created: Sun Apr 14 00:32:34 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ut_regionconfreader/ut_regionconfreader.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ut_regionconfreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ut_RegionConfReader[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   35,   35,   35, 0x08,
      36,   35,   35,   35, 0x08,
      54,   35,   35,   35, 0x08,
      61,   35,   35,   35, 0x08,
      71,   35,   35,   35, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Ut_RegionConfReader[] = {
    "Ut_RegionConfReader\0initTestCase()\0\0"
    "cleanupTestCase()\0init()\0cleanup()\0"
    "testAvailableRegions()\0"
};

const QMetaObject Ut_RegionConfReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ut_RegionConfReader,
      qt_meta_data_Ut_RegionConfReader, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ut_RegionConfReader::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ut_RegionConfReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ut_RegionConfReader::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ut_RegionConfReader))
        return static_cast<void*>(const_cast< Ut_RegionConfReader*>(this));
    return QObject::qt_metacast(_clname);
}

int Ut_RegionConfReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 4: testAvailableRegions(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
