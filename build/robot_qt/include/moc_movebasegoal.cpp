/****************************************************************************
** Meta object code from reading C++ file 'movebasegoal.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/robot_qt/include/movebasegoal.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'movebasegoal.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_robot_qt__movebasegoal_t {
    QByteArrayData data[5];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robot_qt__movebasegoal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robot_qt__movebasegoal_t qt_meta_stringdata_robot_qt__movebasegoal = {
    {
QT_MOC_LITERAL(0, 0, 22), // "robot_qt::movebasegoal"
QT_MOC_LITERAL(1, 23, 11), // "rosShutdown"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "updateMBMsg"
QT_MOC_LITERAL(4, 48, 3) // "Msg"

    },
    "robot_qt::movebasegoal\0rosShutdown\0\0"
    "updateMBMsg\0Msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robot_qt__movebasegoal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    1,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void robot_qt::movebasegoal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        movebasegoal *_t = static_cast<movebasegoal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rosShutdown(); break;
        case 1: _t->updateMBMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (movebasegoal::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&movebasegoal::rosShutdown)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (movebasegoal::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&movebasegoal::updateMBMsg)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject robot_qt::movebasegoal::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_robot_qt__movebasegoal.data,
      qt_meta_data_robot_qt__movebasegoal,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *robot_qt::movebasegoal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robot_qt::movebasegoal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robot_qt__movebasegoal.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int robot_qt::movebasegoal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void robot_qt::movebasegoal::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void robot_qt::movebasegoal::updateMBMsg(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
