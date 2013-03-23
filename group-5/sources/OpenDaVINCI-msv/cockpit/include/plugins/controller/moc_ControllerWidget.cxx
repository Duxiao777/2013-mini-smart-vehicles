/****************************************************************************
** Meta object code from reading C++ file 'ControllerWidget.h'
**
** Created: Fri Mar 22 20:49:25 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ControllerWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ControllerWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cockpit__plugins__controller__ControllerWidget[] = {

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
      48,   47,   47,   47, 0x0a,
      63,   61,   47,   47, 0x0a,
      74,   47,   47,   47, 0x0a,
      94,   47,   47,   47, 0x0a,
     115,   47,   47,   47, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_cockpit__plugins__controller__ControllerWidget[] = {
    "cockpit::plugins::controller::ControllerWidget\0"
    "\0TimerEvent()\0v\0setHz(int)\0"
    "userButtonPressed()\0userButtonReleased()\0"
    "sendButtonReleased()\0"
};

const QMetaObject cockpit::plugins::controller::ControllerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cockpit__plugins__controller__ControllerWidget,
      qt_meta_data_cockpit__plugins__controller__ControllerWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cockpit::plugins::controller::ControllerWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cockpit::plugins::controller::ControllerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cockpit::plugins::controller::ControllerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cockpit__plugins__controller__ControllerWidget))
        return static_cast<void*>(const_cast< ControllerWidget*>(this));
    if (!strcmp(_clname, "core::io::ContainerListener"))
        return static_cast< core::io::ContainerListener*>(const_cast< ControllerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int cockpit::plugins::controller::ControllerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: TimerEvent(); break;
        case 1: setHz((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: userButtonPressed(); break;
        case 3: userButtonReleased(); break;
        case 4: sendButtonReleased(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
