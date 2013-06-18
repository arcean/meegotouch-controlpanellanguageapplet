/****************************************************************************
** Meta object code from reading C++ file ''
**
** Created: Sun Apr 14 00:32:25 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ut_languagemodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file '' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ut_LanguageModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   24,   24,   24, 0x08,
      25,   24,   24,   24, 0x08,
      35,   24,   24,   24, 0x08,
      50,   24,   24,   24, 0x08,
      68,   24,   24,   24, 0x08,
      83,   24,   24,   24, 0x08,
     100,   24,   24,   24, 0x08,
     122,   24,   24,   24, 0x08,
     139,   24,   24,   24, 0x08,
     156,   24,   24,   24, 0x08,
     171,   24,   24,   24, 0x08,
     186,   24,   24,   24, 0x08,
     206,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Ut_LanguageModel[] = {
    "Ut_LanguageModel\0init()\0\0cleanup()\0"
    "initTestCase()\0cleanupTestCase()\0"
    "testInstance()\0testGroupCount()\0"
    "testRowCountInGroup()\0testGroupTitle()\0"
    "testUpdateData()\0testItemData()\0"
    "testGetIndex()\0testPopulateModel()\0"
    "testGroupLabel()\0"
};

const QMetaObject Ut_LanguageModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ut_LanguageModel,
      qt_meta_data_Ut_LanguageModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ut_LanguageModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ut_LanguageModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ut_LanguageModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ut_LanguageModel))
        return static_cast<void*>(const_cast< Ut_LanguageModel*>(this));
    return QObject::qt_metacast(_clname);
}

int Ut_LanguageModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: init(); break;
        case 1: cleanup(); break;
        case 2: initTestCase(); break;
        case 3: cleanupTestCase(); break;
        case 4: testInstance(); break;
        case 5: testGroupCount(); break;
        case 6: testRowCountInGroup(); break;
        case 7: testGroupTitle(); break;
        case 8: testUpdateData(); break;
        case 9: testItemData(); break;
        case 10: testGetIndex(); break;
        case 11: testPopulateModel(); break;
        case 12: testGroupLabel(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
