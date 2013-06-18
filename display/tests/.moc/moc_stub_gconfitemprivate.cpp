/****************************************************************************
** Meta object code from reading C++ file 'stub_gconfitemprivate.h'
**
** Created: Sun Apr 14 00:30:55 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../stubs/stub_gconfitemprivate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stub_gconfitemprivate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MGConfItemPrivate[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   33,   33,   33, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_MGConfItemPrivate[] = {
    "MGConfItemPrivate\0valueChanged()\0\0"
};

const QMetaObject MGConfItemPrivate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MGConfItemPrivate,
      qt_meta_data_MGConfItemPrivate, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MGConfItemPrivate::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MGConfItemPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MGConfItemPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MGConfItemPrivate))
        return static_cast<void*>(const_cast< MGConfItemPrivate*>(this));
    return QObject::qt_metacast(_clname);
}

int MGConfItemPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: valueChanged(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MGConfItemPrivate::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
