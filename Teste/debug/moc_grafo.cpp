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
    QByteArrayData data[18];
    char stringdata0[179];
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
QT_MOC_LITERAL(5, 40, 9), // "addVertex"
QT_MOC_LITERAL(6, 50, 3), // "str"
QT_MOC_LITERAL(7, 54, 12), // "removeVertex"
QT_MOC_LITERAL(8, 67, 13), // "addConnection"
QT_MOC_LITERAL(9, 81, 5), // "name1"
QT_MOC_LITERAL(10, 87, 5), // "name2"
QT_MOC_LITERAL(11, 93, 6), // "weight"
QT_MOC_LITERAL(12, 100, 16), // "removeConnection"
QT_MOC_LITERAL(13, 117, 18), // "performWelshPowell"
QT_MOC_LITERAL(14, 136, 13), // "performDsatur"
QT_MOC_LITERAL(15, 150, 15), // "performDijkstra"
QT_MOC_LITERAL(16, 166, 4), // "name"
QT_MOC_LITERAL(17, 171, 7) // "destino"

    },
    "Grafo\0paintVertices\0\0QVector<int>\0"
    "lista\0addVertex\0str\0removeVertex\0"
    "addConnection\0name1\0name2\0weight\0"
    "removeConnection\0performWelshPowell\0"
    "performDsatur\0performDijkstra\0name\0"
    "destino"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Grafo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   67,    2, 0x0a /* Public */,
       7,    1,   70,    2, 0x0a /* Public */,
       8,    3,   73,    2, 0x0a /* Public */,
       8,    2,   80,    2, 0x2a /* Public | MethodCloned */,
      12,    2,   85,    2, 0x0a /* Public */,
      13,    0,   90,    2, 0x0a /* Public */,
      14,    0,   91,    2, 0x0a /* Public */,
      15,    2,   92,    2, 0x0a /* Public */,
      15,    1,   97,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   16,   17,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void Grafo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Grafo *_t = static_cast<Grafo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->paintVertices((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 1: _t->addVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->removeVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->addConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->addConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->removeConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->performWelshPowell(); break;
        case 7: _t->performDsatur(); break;
        case 8: _t->performDijkstra((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->performDijkstra((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Grafo::paintVertices(QVector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
