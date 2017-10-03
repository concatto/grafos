/****************************************************************************
** Meta object code from reading C++ file 'grafo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../grafo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#include <QtCore/QStack>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grafo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Grafo_t {
    QByteArrayData data[21];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Grafo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Grafo_t qt_meta_stringdata_Grafo = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Grafo"
QT_MOC_LITERAL(1, 6, 13), // "paintVertices"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "QVector<int>"
QT_MOC_LITERAL(4, 34, 5), // "lista"
QT_MOC_LITERAL(5, 40, 13), // "paintDijkstra"
QT_MOC_LITERAL(6, 54, 11), // "QStack<int>"
QT_MOC_LITERAL(7, 66, 5), // "stack"
QT_MOC_LITERAL(8, 72, 9), // "addVertex"
QT_MOC_LITERAL(9, 82, 3), // "str"
QT_MOC_LITERAL(10, 86, 12), // "removeVertex"
QT_MOC_LITERAL(11, 99, 3), // "id1"
QT_MOC_LITERAL(12, 103, 13), // "addConnection"
QT_MOC_LITERAL(13, 117, 3), // "id2"
QT_MOC_LITERAL(14, 121, 6), // "weight"
QT_MOC_LITERAL(15, 128, 16), // "removeConnection"
QT_MOC_LITERAL(16, 145, 18), // "performWelshPowell"
QT_MOC_LITERAL(17, 164, 13), // "performDsatur"
QT_MOC_LITERAL(18, 178, 15), // "performDijkstra"
QT_MOC_LITERAL(19, 194, 6), // "origem"
QT_MOC_LITERAL(20, 201, 7) // "destino"

    },
    "Grafo\0paintVertices\0\0QVector<int>\0"
    "lista\0paintDijkstra\0QStack<int>\0stack\0"
    "addVertex\0str\0removeVertex\0id1\0"
    "addConnection\0id2\0weight\0removeConnection\0"
    "performWelshPowell\0performDsatur\0"
    "performDijkstra\0origem\0destino"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Grafo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   75,    2, 0x0a /* Public */,
      10,    1,   78,    2, 0x0a /* Public */,
      12,    3,   81,    2, 0x0a /* Public */,
      12,    2,   88,    2, 0x2a /* Public | MethodCloned */,
      15,    2,   93,    2, 0x0a /* Public */,
      16,    0,   98,    2, 0x0a /* Public */,
      17,    0,   99,    2, 0x0a /* Public */,
      18,    2,  100,    2, 0x0a /* Public */,
      18,    1,  105,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void Grafo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Grafo *_t = static_cast<Grafo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paintVertices((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 1: _t->paintDijkstra((*reinterpret_cast< QStack<int>(*)>(_a[1]))); break;
        case 2: _t->addVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->removeVertex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->addConnection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->addConnection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->removeConnection((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->performWelshPowell(); break;
        case 8: _t->performDsatur(); break;
        case 9: _t->performDijkstra((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->performDijkstra((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStack<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Grafo::*_t)(QVector<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Grafo::paintVertices)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Grafo::*_t)(QStack<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Grafo::paintDijkstra)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Grafo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Grafo.data,
      qt_meta_data_Grafo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Grafo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Grafo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Grafo.stringdata0))
        return static_cast<void*>(const_cast< Grafo*>(this));
    return QObject::qt_metacast(_clname);
}

int Grafo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Grafo::paintVertices(QVector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Grafo::paintDijkstra(QStack<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
