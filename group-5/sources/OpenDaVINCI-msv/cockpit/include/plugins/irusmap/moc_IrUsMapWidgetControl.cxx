/****************************************************************************
** Meta object code from reading C++ file 'IrUsMapWidgetControl.h'
**
** Created: Fri Mar 22 20:49:24 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "IrUsMapWidgetControl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IrUsMapWidgetControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cockpit__plugins__irusmap__IrUsMapWidgetControl[] = {

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
      53,   49,   48,   48, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_cockpit__plugins__irusmap__IrUsMapWidgetControl[] = {
    "cockpit::plugins::irusmap::IrUsMapWidgetControl\0"
    "\0val\0setScale(int)\0"
};

const QMetaObject cockpit::plugins::irusmap::IrUsMapWidgetControl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cockpit__plugins__irusmap__IrUsMapWidgetControl,
      qt_meta_data_cockpit__plugins__irusmap__IrUsMapWidgetControl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cockpit::plugins::irusmap::IrUsMapWidgetControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cockpit::plugins::irusmap::IrUsMapWidgetControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cockpit::plugins::irusmap::IrUsMapWidgetControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cockpit__plugins__irusmap__IrUsMapWidgetControl))
        return static_cast<void*>(const_cast< IrUsMapWidgetControl*>(this));
    if (!strcmp(_clname, "core::io::ContainerListener"))
        return static_cast< core::io::ContainerListener*>(const_cast< IrUsMapWidgetControl*>(this));
    return QWidget::qt_metacast(_clname);
}

int cockpit::plugins::irusmap::IrUsMapWidgetControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setScale((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
