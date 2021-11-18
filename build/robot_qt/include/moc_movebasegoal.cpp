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
    QByteArrayData data[11];
    char stringdata0[125];
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
QT_MOC_LITERAL(4, 48, 3), // "Msg"
QT_MOC_LITERAL(5, 52, 14), // "updateOdomData"
QT_MOC_LITERAL(6, 67, 13), // "updategoalMsg"
QT_MOC_LITERAL(7, 81, 4), // "Msg1"
QT_MOC_LITERAL(8, 86, 4), // "Msg2"
QT_MOC_LITERAL(9, 91, 17), // "updateOdomDisData"
QT_MOC_LITERAL(10, 109, 15) // "updatestatusMsg"

    },
    "robot_qt::movebasegoal\0rosShutdown\0\0"
    "updateMBMsg\0Msg\0updateOdomData\0"
    "updategoalMsg\0Msg1\0Msg2\0updateOdomDisData\0"
    "updatestatusMsg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robot_qt__movebasegoal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,
       6,    2,   51,    2, 0x06 /* Public */,
       9,    1,   56,    2, 0x06 /* Public */,
      10,    1,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void, QMetaType::QString,    4,
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
        case 2: _t->updateOdomData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->updategoalMsg((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->updateOdomDisData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->updatestatusMsg((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
        {
            typedef void (movebasegoal::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&movebasegoal::updateOdomData)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (movebasegoal::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&movebasegoal::updategoalMsg)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (movebasegoal::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&movebasegoal::updateOdomDisData)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (movebasegoal::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&movebasegoal::updatestatusMsg)) {
                *result = 5;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
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

// SIGNAL 2
void robot_qt::movebasegoal::updateOdomData(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void robot_qt::movebasegoal::updategoalMsg(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void robot_qt::movebasegoal::updateOdomDisData(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void robot_qt::movebasegoal::updatestatusMsg(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
