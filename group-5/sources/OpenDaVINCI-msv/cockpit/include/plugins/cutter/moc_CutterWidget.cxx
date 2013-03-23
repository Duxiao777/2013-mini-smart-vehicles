/****************************************************************************
** Meta object code from reading C++ file 'CutterWidget.h'
**
** Created: Fri Mar 22 20:49:23 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CutterWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CutterWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cockpit__plugins__cutter__CutterWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      40,   39,   39,   39, 0x0a,
      51,   39,   39,   39, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_cockpit__plugins__cutter__CutterWidget[] = {
    "cockpit::plugins::cutter::CutterWidget\0"
    "\0loadFile()\0saveFile()\0"
};

const QMetaObject cockpit::plugins::cutter::CutterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cockpit__plugins__cutter__CutterWidget,
      qt_meta_data_cockpit__plugins__cutter__CutterWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cockpit::plugins::cutter::CutterWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cockpit::plugins::cutter::CutterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cockpit::plugins::cutter::CutterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cockpit__plugins__cutter__CutterWidget))
        return static_cast<void*>(const_cast< CutterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int cockpit::plugins::cutter::CutterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadFile(); break;
        case 1: saveFile(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
