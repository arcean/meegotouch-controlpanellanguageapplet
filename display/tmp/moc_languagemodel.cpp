/****************************************************************************
** Meta object code from reading C++ file ''
**
** Created: Sun Apr 14 00:30:34 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "languagemodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file '' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LanguageModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   35,   35,   35, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LanguageModel[] = {
    "LanguageModel\0doRetranslateModel()\0\0"
};

const QMetaObject LanguageModel::staticMetaObject = {
    { &MAbstractItemModel::staticMetaObject, qt_meta_stringdata_LanguageModel,
      qt_meta_data_LanguageModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LanguageModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LanguageModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LanguageModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LanguageModel))
        return static_cast<void*>(const_cast< LanguageModel*>(this));
    return MAbstractItemModel::qt_metacast(_clname);
}

int LanguageModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doRetranslateModel(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
