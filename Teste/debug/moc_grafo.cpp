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
    QByteArrayData data[10];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Grafo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Grafo_t qt_meta_stringdata_Grafo = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Grafo"
QT_MOC_LITERAL(1, 6, 9), // "addVertex"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 3), // "str"
QT_MOC_LITERAL(4, 21, 12), // "removeVertex"
QT_MOC_LITERAL(5, 34, 13), // "addConnection"
QT_MOC_LITERAL(6, 48, 5), // "name1"
QT_MOC_LITERAL(7, 54, 5), // "name2"
QT_MOC_LITERAL(8, 60, 6), // "weight"
QT_MOC_LITERAL(9, 67, 16) // "removeConnection"

    },
    "Grafo\0addVertex\0\0str\0removeVertex\0"
    "addConnection\0name1\0name2\0weight\0"
    "removeConnection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Grafo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    3,   45,    2, 0x0a /* Public */,
       5,    2,   52,    2, 0x2a /* Public | MethodCloned */,
       9,    2,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,

       0        // eod
};

void Grafo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Grafo *_t = static_cast<Grafo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->removeVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->addConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->removeConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE