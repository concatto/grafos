/****************************************************************************
** Meta object code from reading C++ file 'graphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../userInterface/graphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GraphicsView_t {
    QByteArrayData data[13];
    char stringdata0[135];
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
QT_MOC_LITERAL(4, 28, 12), // "removeVertex"
QT_MOC_LITERAL(5, 41, 13), // "addConnection"
QT_MOC_LITERAL(6, 55, 5), // "name1"
QT_MOC_LITERAL(7, 61, 5), // "name2"
QT_MOC_LITERAL(8, 67, 6), // "weight"
QT_MOC_LITERAL(9, 74, 16), // "removeConnection"
QT_MOC_LITERAL(10, 91, 11), // "welshPowell"
QT_MOC_LITERAL(11, 103, 14), // "duplicatedEdge"
QT_MOC_LITERAL(12, 118, 16) // "duplicatedVertex"

    },
    "GraphicsView\0addVertex\0\0str\0removeVertex\0"
    "addConnection\0name1\0name2\0weight\0"
    "removeConnection\0welshPowell\0"
    "duplicatedEdge\0duplicatedVertex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    3,   55,    2, 0x06 /* Public */,
       9,    2,   62,    2, 0x06 /* Public */,
      10,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   68,    2, 0x0a /* Public */,
      12,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsView *_t = static_cast<GraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->removeVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->removeConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->welshPowell(); break;
        case 5: _t->duplicatedEdge(); break;
        case 6: _t->duplicatedVertex(); break;
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
            typedef void (GraphicsView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::removeVertex)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(QString , QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::addConnection)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::removeConnection)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (GraphicsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::welshPowell)) {
                *result = 4;
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
        return static_cast<void*>(const_cast< GraphicsView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void GraphicsView::removeVertex(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphicsView::addConnection(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphicsView::removeConnection(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphicsView::welshPowell()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
