/****************************************************************************
** Meta object code from reading C++ file 'MdiPlugIn.h'
**
** Created: Fri Mar 22 20:49:23 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MdiPlugIn.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MdiPlugIn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cockpit__MdiPlugIn[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_cockpit__MdiPlugIn[] = {
    "cockpit::MdiPlugIn\0"
};

const QMetaObject cockpit::MdiPlugIn::staticMetaObject = {
    { &QMdiSubWindow::staticMetaObject, qt_meta_stringdata_cockpit__MdiPlugIn,
      qt_meta_data_cockpit__MdiPlugIn, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cockpit::MdiPlugIn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cockpit::MdiPlugIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cockpit::MdiPlugIn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cockpit__MdiPlugIn))
        return static_cast<void*>(const_cast< MdiPlugIn*>(this));
    return QMdiSubWindow::qt_metacast(_clname);
}

int cockpit::MdiPlugIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMdiSubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
