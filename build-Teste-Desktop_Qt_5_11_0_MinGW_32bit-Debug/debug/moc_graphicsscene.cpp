/****************************************************************************
** Meta object code from reading C++ file 'graphicsscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Teste/userInterface/graphicsscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphicsScene_t {
    QByteArrayData data[9];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicsScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicsScene_t qt_meta_stringdata_GraphicsScene = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GraphicsScene"
QT_MOC_LITERAL(1, 14, 13), // "addConnection"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "id1"
QT_MOC_LITERAL(4, 33, 3), // "id2"
QT_MOC_LITERAL(5, 37, 15), // "performDijkstra"
QT_MOC_LITERAL(6, 53, 6), // "origem"
QT_MOC_LITERAL(7, 60, 7), // "destino"
QT_MOC_LITERAL(8, 68, 11) // "resetCursor"

    },
    "GraphicsScene\0addConnection\0\0id1\0id2\0"
    "performDijkstra\0origem\0destino\0"
    "resetCursor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x26 /* Public | MethodCloned */,
       8,    0,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void GraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsScene *_t = static_cast<GraphicsScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addConnection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->performDijkstra((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->performDijkstra((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->resetCursor(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GraphicsScene::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicsScene::addConnection)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GraphicsScene::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicsScene::performDijkstra)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GraphicsScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GraphicsScene::resetCursor)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_GraphicsScene.data,
      qt_meta_data_GraphicsScene,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int GraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GraphicsScene::addConnection(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphicsScene::performDijkstra(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 3
void GraphicsScene::resetCursor()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
