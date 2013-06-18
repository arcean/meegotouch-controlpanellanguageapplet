/****************************************************************************
** Meta object code from reading C++ file 'ut_dcpdisplaylangconf.h'
**
** Created: Sun Apr 14 00:30:57 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ut_dcpdisplaylangconf/ut_dcpdisplaylangconf.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ut_dcpdisplaylangconf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ut_DcpDisplayLangConf[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   37,   37,   37, 0x08,
      38,   37,   37,   37, 0x08,
      56,   37,   37,   37, 0x08,
      63,   37,   37,   37, 0x08,
      73,   37,   37,   37, 0x08,
      94,   37,   37,   37, 0x08,
     130,   37,   37,   37, 0x08,
     171,   37,   37,   37, 0x08,
     212,   37,   37,   37, 0x08,
     258,   37,   37,   37, 0x08,
     296,   37,   37,   37, 0x08,
     339,   37,   37,   37, 0x08,
     367,   37,   37,   37, 0x08,
     402,   37,   37,   37, 0x08,
     417,   37,   37,   37, 0x08,
     441,   37,   37,   37, 0x08,
     466,   37,   37,   37, 0x08,
     485,   37,   37,   37, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Ut_DcpDisplayLangConf[] = {
    "Ut_DcpDisplayLangConf\0initTestCase()\0"
    "\0cleanupTestCase()\0init()\0cleanup()\0"
    "testIsLanguagesSet()\0"
    "testAvailableDisplayLanguagesSort()\0"
    "testAvailableDisplayLanguagesSort_data()\0"
    "testAvailableDisplayLanguagesIdConvert()\0"
    "testAvailableDisplayLanguagesIdConvert_data()\0"
    "testAvailableDisplayLanguagesFilter()\0"
    "testAvailableDisplayLanguagesFilter_data()\0"
    "testDisplayLanguageChange()\0"
    "testDisplayLanguageChangedSignal()\0"
    "testFullName()\0testConstructDestruct()\0"
    "testSettingBadLanguage()\0testUpdateRegion()\0"
    "testUpdateRegion_data()\0"
};

const QMetaObject Ut_DcpDisplayLangConf::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ut_DcpDisplayLangConf,
      qt_meta_data_Ut_DcpDisplayLangConf, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ut_DcpDisplayLangConf::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ut_DcpDisplayLangConf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ut_DcpDisplayLangConf::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ut_DcpDisplayLangConf))
        return static_cast<void*>(const_cast< Ut_DcpDisplayLangConf*>(this));
    return QObject::qt_metacast(_clname);
}

int Ut_DcpDisplayLangConf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        case 4: testIsLanguagesSet(); break;
        case 5: testAvailableDisplayLanguagesSort(); break;
        case 6: testAvailableDisplayLanguagesSort_data(); break;
        case 7: testAvailableDisplayLanguagesIdConvert(); break;
        case 8: testAvailableDisplayLanguagesIdConvert_data(); break;
        case 9: testAvailableDisplayLanguagesFilter(); break;
        case 10: testAvailableDisplayLanguagesFilter_data(); break;
        case 11: testDisplayLanguageChange(); break;
        case 12: testDisplayLanguageChangedSignal(); break;
        case 13: testFullName(); break;
        case 14: testConstructDestruct(); break;
        case 15: testSettingBadLanguage(); break;
        case 16: testUpdateRegion(); break;
        case 17: testUpdateRegion_data(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
