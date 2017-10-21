/****************************************************************************
** Meta object code from reading C++ file 'graphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "userInterface/graphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphicsView_t {
    QByteArrayData data[19];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicsView_t qt_meta_stringdata_GraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GraphicsView"
QT_MOC_LITERAL(1, 13, 9), // "addVertex"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "str"
QT_MOC_LITERAL(4, 28, 13), // "addConnection"
QT_MOC_LITERAL(5, 42, 3), // "id1"
QT_MOC_LITERAL(6, 46, 3), // "id2"
QT_MOC_LITERAL(7, 50, 6), // "weight"
QT_MOC_LITERAL(8, 57, 12), // "removeVertex"
QT_MOC_LITERAL(9, 70, 2), // "id"
QT_MOC_LITERAL(10, 73, 16), // "removeConnection"
QT_MOC_LITERAL(11, 90, 18), // "performWelshPowell"
QT_MOC_LITERAL(12, 109, 13), // "performDsatur"
QT_MOC_LITERAL(13, 123, 15), // "performDijkstra"
QT_MOC_LITERAL(14, 139, 6), // "origem"
QT_MOC_LITERAL(15, 146, 7), // "destino"
QT_MOC_LITERAL(16, 154, 10), // "printGraph"
QT_MOC_LITERAL(17, 165, 11), // "resetCursor"
QT_MOC_LITERAL(18, 177, 19) // "askConnectionWeight"

    },
    "GraphicsView\0addVertex\0\0str\0addConnection\0"
    "id1\0id2\0weight\0removeVertex\0id\0"
    "removeConnection\0performWelshPowell\0"
    "performDsatur\0performDijkstra\0origem\0"
    "destino\0printGraph\0resetCursor\0"
    "askConnectionWeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    3,   72,    2, 0x06 /* Public */,
       8,    1,   79,    2, 0x06 /* Public */,
      10,    2,   82,    2, 0x06 /* Public */,
      11,    0,   87,    2, 0x06 /* Public */,
      12,    0,   88,    2, 0x06 /* Public */,
      13,    2,   89,    2, 0x06 /* Public */,
      13,    1,   94,    2, 0x26 /* Public | MethodCloned */,
      16,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,   98,    2, 0x0a /* Public */,
      18,    2,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,

       0        // eod
};

void GraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsView *_t = static_cast<GraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->addConnection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->removeVertex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->removeConnection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->performWelshPowell(); break;
        case 5: _t->performDsatur(); break;
        case 6: _t->performDijkstra((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->performDijkstra((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->printGraph(); break;
        case 9: _t->resetCursor(); break;
        case 10: _t->askConnectionWeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphicsView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::addVertex)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::addConnection)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::removeVertex)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::removeConnection)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::performWelshPowell)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::performDsatur)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::performDijkstra)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::printGraph)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject GraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GraphicsView.data,
      qt_meta_data_GraphicsView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int GraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void GraphicsView::addVertex(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphicsView::addConnection(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphicsView::removeVertex(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphicsView::removeConnection(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphicsView::performWelshPowell()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void GraphicsView::performDsatur()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void GraphicsView::performDijkstra(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 8
void GraphicsView::printGraph()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
