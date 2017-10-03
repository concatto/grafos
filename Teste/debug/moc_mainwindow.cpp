/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#include <QtCore/QStack>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "addVertex"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "str"
QT_MOC_LITERAL(4, 26, 12), // "removeVertex"
QT_MOC_LITERAL(5, 39, 13), // "addConnection"
QT_MOC_LITERAL(6, 53, 5), // "name1"
QT_MOC_LITERAL(7, 59, 5), // "name2"
QT_MOC_LITERAL(8, 65, 6), // "weight"
QT_MOC_LITERAL(9, 72, 16), // "removeConnection"
QT_MOC_LITERAL(10, 89, 18), // "performWelshPowell"
QT_MOC_LITERAL(11, 108, 13), // "performDsatur"
QT_MOC_LITERAL(12, 122, 15), // "performDijkstra"
QT_MOC_LITERAL(13, 138, 13), // "paintVertices"
QT_MOC_LITERAL(14, 152, 12), // "QVector<int>"
QT_MOC_LITERAL(15, 165, 5), // "cores"
QT_MOC_LITERAL(16, 171, 13), // "paintDijkstra"
QT_MOC_LITERAL(17, 185, 11), // "QStack<int>"
QT_MOC_LITERAL(18, 197, 5) // "stack"

    },
    "MainWindow\0addVertex\0\0str\0removeVertex\0"
    "addConnection\0name1\0name2\0weight\0"
    "removeConnection\0performWelshPowell\0"
    "performDsatur\0performDijkstra\0"
    "paintVertices\0QVector<int>\0cores\0"
    "paintDijkstra\0QStack<int>\0stack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       4,    1,   72,    2, 0x06 /* Public */,
       5,    3,   75,    2, 0x06 /* Public */,
       5,    2,   82,    2, 0x26 /* Public | MethodCloned */,
       9,    2,   87,    2, 0x06 /* Public */,
      10,    0,   92,    2, 0x06 /* Public */,
      11,    0,   93,    2, 0x06 /* Public */,
      12,    2,   94,    2, 0x06 /* Public */,
      12,    1,   99,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  102,    2, 0x0a /* Public */,
      16,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->removeVertex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->addConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->addConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->removeConnection((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->performWelshPowell(); break;
        case 6: _t->performDsatur(); break;
        case 7: _t->performDijkstra((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->performDijkstra((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->paintVertices((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 10: _t->paintDijkstra((*reinterpret_cast< QStack<int>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 10:
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
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::addVertex)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::removeVertex)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::addConnection)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::removeConnection)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::performWelshPowell)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::performDsatur)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::performDijkstra)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MainWindow::addVertex(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::removeVertex(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::addConnection(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void MainWindow::removeConnection(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::performWelshPowell()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::performDsatur()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::performDijkstra(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
