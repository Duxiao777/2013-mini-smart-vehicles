/****************************************************************************
** Meta object code from reading C++ file 'IrUsChartsWidget.h'
**
** Created: Fri Mar 22 20:49:24 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "IrUsChartsWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IrUsChartsWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cockpit__plugins__iruscharts__IrUsChartsWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      48,   47,   47,   47, 0x0a,
      61,   47,   47,   47, 0x0a,
      82,   47,   47,   47, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_cockpit__plugins__iruscharts__IrUsChartsWidget[] = {
    "cockpit::plugins::iruscharts::IrUsChartsWidget\0"
    "\0TimerEvent()\0saveRecordingsFile()\0"
    "saveCSVFile()\0"
};

const QMetaObject cockpit::plugins::iruscharts::IrUsChartsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cockpit__plugins__iruscharts__IrUsChartsWidget,
      qt_meta_data_cockpit__plugins__iruscharts__IrUsChartsWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cockpit::plugins::iruscharts::IrUsChartsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cockpit::plugins::iruscharts::IrUsChartsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cockpit::plugins::iruscharts::IrUsChartsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cockpit__plugins__iruscharts__IrUsChartsWidget))
        return static_cast<void*>(const_cast< IrUsChartsWidget*>(this));
    if (!strcmp(_clname, "core::io::ContainerListener"))
        return static_cast< core::io::ContainerListener*>(const_cast< IrUsChartsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int cockpit::plugins::iruscharts::IrUsChartsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: TimerEvent(); break;
        case 1: saveRecordingsFile(); break;
        case 2: saveCSVFile(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
