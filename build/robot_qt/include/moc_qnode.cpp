/****************************************************************************
** Meta object code from reading C++ file 'qnode.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/robot_qt/include/qnode.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnode.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_robot_qt__CQNode_t {
    QByteArrayData data[25];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_robot_qt__CQNode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_robot_qt__CQNode_t qt_meta_stringdata_robot_qt__CQNode = {
    {
QT_MOC_LITERAL(0, 0, 16), // "robot_qt::CQNode"
QT_MOC_LITERAL(1, 17, 14), // "loggingUpdated"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "rosShutdown"
QT_MOC_LITERAL(4, 45, 9), // "speed_vel"
QT_MOC_LITERAL(5, 55, 9), // "power_vel"
QT_MOC_LITERAL(6, 65, 9), // "image_val"
QT_MOC_LITERAL(7, 75, 11), // "updateImage"
QT_MOC_LITERAL(8, 87, 5), // "image"
QT_MOC_LITERAL(9, 93, 14), // "updatePCLImage"
QT_MOC_LITERAL(10, 108, 20), // "updateSonar1Distance"
QT_MOC_LITERAL(11, 129, 4), // "Dis1"
QT_MOC_LITERAL(12, 134, 20), // "updateSonar2Distance"
QT_MOC_LITERAL(13, 155, 4), // "Dis2"
QT_MOC_LITERAL(14, 160, 16), // "updateSonarError"
QT_MOC_LITERAL(15, 177, 5), // "Error"
QT_MOC_LITERAL(16, 183, 19), // "updateObstacleState"
QT_MOC_LITERAL(17, 203, 14), // "obstacle_range"
QT_MOC_LITERAL(18, 218, 14), // "obstacle_state"
QT_MOC_LITERAL(19, 233, 17), // "update_StartPoint"
QT_MOC_LITERAL(20, 251, 9), // "longitude"
QT_MOC_LITERAL(21, 261, 8), // "latitude"
QT_MOC_LITERAL(22, 270, 12), // "updatepoints"
QT_MOC_LITERAL(23, 283, 12), // "updateGetgps"
QT_MOC_LITERAL(24, 296, 6) // "status"

    },
    "robot_qt::CQNode\0loggingUpdated\0\0"
    "rosShutdown\0speed_vel\0power_vel\0"
    "image_val\0updateImage\0image\0updatePCLImage\0"
    "updateSonar1Distance\0Dis1\0"
    "updateSonar2Distance\0Dis2\0updateSonarError\0"
    "Error\0updateObstacleState\0obstacle_range\0"
    "obstacle_state\0update_StartPoint\0"
    "longitude\0latitude\0updatepoints\0"
    "updateGetgps\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_robot_qt__CQNode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    2,   86,    2, 0x06 /* Public */,
       5,    1,   91,    2, 0x06 /* Public */,
       6,    1,   94,    2, 0x06 /* Public */,
       7,    1,   97,    2, 0x06 /* Public */,
       9,    1,  100,    2, 0x06 /* Public */,
      10,    1,  103,    2, 0x06 /* Public */,
      12,    1,  106,    2, 0x06 /* Public */,
      14,    1,  109,    2, 0x06 /* Public */,
      16,    2,  112,    2, 0x06 /* Public */,
      19,    2,  117,    2, 0x06 /* Public */,
      22,    1,  122,    2, 0x06 /* Public */,
      23,    3,  125,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void, QMetaType::QImage,    8,
    QMetaType::Void, QMetaType::QImage,    8,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   20,   21,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   20,   21,   24,

       0        // eod
};

void robot_qt::CQNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQNode *_t = static_cast<CQNode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loggingUpdated(); break;
        case 1: _t->rosShutdown(); break;
        case 2: _t->speed_vel((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->power_vel((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->image_val((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->updateImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 6: _t->updatePCLImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 7: _t->updateSonar1Distance((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->updateSonar2Distance((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->updateSonarError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->updateObstacleState((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->update_StartPoint((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->updatepoints((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->updateGetgps((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CQNode::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::loggingUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::rosShutdown)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(float , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::speed_vel)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::power_vel)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::image_val)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::updateImage)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::updatePCLImage)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::updateSonar1Distance)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::updateSonar2Distance)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::updateSonarError)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::updateObstacleState)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::update_StartPoint)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::updatepoints)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (CQNode::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CQNode::updateGetgps)) {
                *result = 13;
                return;
            }
        }
    }
}

const QMetaObject robot_qt::CQNode::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_robot_qt__CQNode.data,
      qt_meta_data_robot_qt__CQNode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *robot_qt::CQNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *robot_qt::CQNode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_robot_qt__CQNode.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int robot_qt::CQNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void robot_qt::CQNode::loggingUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void robot_qt::CQNode::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void robot_qt::CQNode::speed_vel(float _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void robot_qt::CQNode::power_vel(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void robot_qt::CQNode::image_val(QImage _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void robot_qt::CQNode::updateImage(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void robot_qt::CQNode::updatePCLImage(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void robot_qt::CQNode::updateSonar1Distance(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void robot_qt::CQNode::updateSonar2Distance(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void robot_qt::CQNode::updateSonarError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void robot_qt::CQNode::updateObstacleState(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void robot_qt::CQNode::update_StartPoint(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void robot_qt::CQNode::updatepoints(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void robot_qt::CQNode::updateGetgps(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
