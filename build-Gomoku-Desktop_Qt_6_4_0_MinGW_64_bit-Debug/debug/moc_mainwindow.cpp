/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Gomoku/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[2];
    char stringdata5[2];
    char stringdata6[7];
    char stringdata7[15];
    char stringdata8[11];
    char stringdata9[7];
    char stringdata10[20];
    char stringdata11[21];
    char stringdata12[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 19),  // "on_tableInitialized"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 15),  // "on_tableChanged"
        QT_MOC_LITERAL(48, 1),  // "x"
        QT_MOC_LITERAL(50, 1),  // "y"
        QT_MOC_LITERAL(52, 6),  // "Player"
        QT_MOC_LITERAL(59, 14),  // "playerSelected"
        QT_MOC_LITERAL(74, 10),  // "on_gameWon"
        QT_MOC_LITERAL(85, 6),  // "player"
        QT_MOC_LITERAL(92, 19),  // "on_newGameTriggered"
        QT_MOC_LITERAL(112, 20),  // "on_saveGameTriggered"
        QT_MOC_LITERAL(133, 20)   // "on_loadGameTriggered"
    },
    "MainWindow",
    "on_tableInitialized",
    "",
    "on_tableChanged",
    "x",
    "y",
    "Player",
    "playerSelected",
    "on_gameWon",
    "player",
    "on_newGameTriggered",
    "on_saveGameTriggered",
    "on_loadGameTriggered"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    3,   51,    2, 0x08,    2 /* Private */,
       8,    1,   58,    2, 0x08,    6 /* Private */,
      10,    0,   61,    2, 0x08,    8 /* Private */,
      11,    0,   62,    2, 0x08,    9 /* Private */,
      12,    0,   63,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, 0x80000000 | 6,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_tableInitialized'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<Player, std::false_type>,
        // method 'on_gameWon'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Player, std::false_type>,
        // method 'on_newGameTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveGameTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_loadGameTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_tableInitialized(); break;
        case 1: _t->on_tableChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Player>>(_a[3]))); break;
        case 2: _t->on_gameWon((*reinterpret_cast< std::add_pointer_t<Player>>(_a[1]))); break;
        case 3: _t->on_newGameTriggered(); break;
        case 4: _t->on_saveGameTriggered(); break;
        case 5: _t->on_loadGameTriggered(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
