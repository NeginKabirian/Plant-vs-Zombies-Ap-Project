/****************************************************************************
** Meta object code from reading C++ file 'plantzombie.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plantzombie.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plantzombie.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSplantzombieENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSplantzombieENDCLASS = QtMocHelpers::stringData(
    "plantzombie",
    "SInsertPA",
    "",
    "rect",
    "x",
    "y",
    "SInsertPB",
    "SInsertPC",
    "SInsertPD",
    "SInsertPE",
    "SInsertPF",
    "SInsertZA",
    "SInsertZB",
    "SInsertZC",
    "SInsertZD",
    "SInsertZE",
    "SInsertZF",
    "spawnSun",
    "handleSunClick",
    "spawnBrain",
    "handleBrainClick",
    "onButtonPAClicked",
    "onButtonPBClicked",
    "onButtonPCClicked",
    "onButtonPDClicked",
    "onButtonPEClicked",
    "onButtonPFClicked",
    "onButtonZAClicked",
    "onButtonZBClicked",
    "onButtonZCClicked",
    "onButtonZDClicked",
    "onButtonZEClicked",
    "onButtonZFClicked",
    "on_pushButtonPA_clicked",
    "on_pushButtonPB_clicked",
    "on_pushButtonPC_clicked",
    "on_pushButtonPD_clicked",
    "on_pushButtonPE_clicked",
    "on_pushButtonPF_clicked",
    "on_pushButtonZA_clicked",
    "on_pushButtonZB_clicked",
    "on_pushButtonZC_clicked",
    "on_pushButtonZD_clicked",
    "on_pushButtonZE_clicked",
    "on_pushButtonZF_clicked",
    "onShootPea",
    "PlantBase*",
    "burnRow",
    "plumminefunction",
    "plantattack"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSplantzombieENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,  278,    2, 0x06,    1 /* Public */,
       6,    3,  285,    2, 0x06,    5 /* Public */,
       7,    3,  292,    2, 0x06,    9 /* Public */,
       8,    3,  299,    2, 0x06,   13 /* Public */,
       9,    3,  306,    2, 0x06,   17 /* Public */,
      10,    3,  313,    2, 0x06,   21 /* Public */,
      11,    3,  320,    2, 0x06,   25 /* Public */,
      12,    3,  327,    2, 0x06,   29 /* Public */,
      13,    3,  334,    2, 0x06,   33 /* Public */,
      14,    3,  341,    2, 0x06,   37 /* Public */,
      15,    3,  348,    2, 0x06,   41 /* Public */,
      16,    3,  355,    2, 0x06,   45 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    0,  362,    2, 0x08,   49 /* Private */,
      18,    0,  363,    2, 0x08,   50 /* Private */,
      19,    0,  364,    2, 0x08,   51 /* Private */,
      20,    0,  365,    2, 0x08,   52 /* Private */,
      21,    0,  366,    2, 0x08,   53 /* Private */,
      22,    0,  367,    2, 0x08,   54 /* Private */,
      23,    0,  368,    2, 0x08,   55 /* Private */,
      24,    0,  369,    2, 0x08,   56 /* Private */,
      25,    0,  370,    2, 0x08,   57 /* Private */,
      26,    0,  371,    2, 0x08,   58 /* Private */,
      27,    0,  372,    2, 0x08,   59 /* Private */,
      28,    0,  373,    2, 0x08,   60 /* Private */,
      29,    0,  374,    2, 0x08,   61 /* Private */,
      30,    0,  375,    2, 0x08,   62 /* Private */,
      31,    0,  376,    2, 0x08,   63 /* Private */,
      32,    0,  377,    2, 0x08,   64 /* Private */,
      33,    0,  378,    2, 0x08,   65 /* Private */,
      34,    0,  379,    2, 0x08,   66 /* Private */,
      35,    0,  380,    2, 0x08,   67 /* Private */,
      36,    0,  381,    2, 0x08,   68 /* Private */,
      37,    0,  382,    2, 0x08,   69 /* Private */,
      38,    0,  383,    2, 0x08,   70 /* Private */,
      39,    0,  384,    2, 0x08,   71 /* Private */,
      40,    0,  385,    2, 0x08,   72 /* Private */,
      41,    0,  386,    2, 0x08,   73 /* Private */,
      42,    0,  387,    2, 0x08,   74 /* Private */,
      43,    0,  388,    2, 0x08,   75 /* Private */,
      44,    0,  389,    2, 0x08,   76 /* Private */,
      45,    2,  390,    2, 0x08,   77 /* Private */,
      47,    2,  395,    2, 0x08,   80 /* Private */,
      48,    2,  400,    2, 0x08,   83 /* Private */,
      49,    2,  405,    2, 0x08,   86 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 46, QMetaType::QPointF,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 46,    3,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 46,    3,    2,
    QMetaType::Void, 0x80000000 | 46, QMetaType::Int,    2,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject plantzombie::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSplantzombieENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSplantzombieENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSplantzombieENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<plantzombie, std::true_type>,
        // method 'SInsertPA'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertPB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertPC'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertPD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertPE'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertPF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertZA'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertZB'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertZC'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertZD'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertZE'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SInsertZF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'spawnSun'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSunClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'spawnBrain'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleBrainClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonPAClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonPBClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonPCClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonPDClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonPEClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonPFClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonZAClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonZBClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonZCClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonZDClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonZEClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonZFClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonPA_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonPB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonPC_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonPD_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonPE_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonPF_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonZA_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonZB_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonZC_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonZD_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonZE_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonZF_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onShootPea'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlantBase *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPointF, std::false_type>,
        // method 'burnRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlantBase *, std::false_type>,
        // method 'plumminefunction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlantBase *, std::false_type>,
        // method 'plantattack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlantBase *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void plantzombie::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<plantzombie *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SInsertPA((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->SInsertPB((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->SInsertPC((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->SInsertPD((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->SInsertPE((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 5: _t->SInsertPF((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 6: _t->SInsertZA((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->SInsertZB((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->SInsertZC((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 9: _t->SInsertZD((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 10: _t->SInsertZE((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 11: _t->SInsertZF((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 12: _t->spawnSun(); break;
        case 13: _t->handleSunClick(); break;
        case 14: _t->spawnBrain(); break;
        case 15: _t->handleBrainClick(); break;
        case 16: _t->onButtonPAClicked(); break;
        case 17: _t->onButtonPBClicked(); break;
        case 18: _t->onButtonPCClicked(); break;
        case 19: _t->onButtonPDClicked(); break;
        case 20: _t->onButtonPEClicked(); break;
        case 21: _t->onButtonPFClicked(); break;
        case 22: _t->onButtonZAClicked(); break;
        case 23: _t->onButtonZBClicked(); break;
        case 24: _t->onButtonZCClicked(); break;
        case 25: _t->onButtonZDClicked(); break;
        case 26: _t->onButtonZEClicked(); break;
        case 27: _t->onButtonZFClicked(); break;
        case 28: _t->on_pushButtonPA_clicked(); break;
        case 29: _t->on_pushButtonPB_clicked(); break;
        case 30: _t->on_pushButtonPC_clicked(); break;
        case 31: _t->on_pushButtonPD_clicked(); break;
        case 32: _t->on_pushButtonPE_clicked(); break;
        case 33: _t->on_pushButtonPF_clicked(); break;
        case 34: _t->on_pushButtonZA_clicked(); break;
        case 35: _t->on_pushButtonZB_clicked(); break;
        case 36: _t->on_pushButtonZC_clicked(); break;
        case 37: _t->on_pushButtonZD_clicked(); break;
        case 38: _t->on_pushButtonZE_clicked(); break;
        case 39: _t->on_pushButtonZF_clicked(); break;
        case 40: _t->onShootPea((*reinterpret_cast< std::add_pointer_t<PlantBase*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2]))); break;
        case 41: _t->burnRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlantBase*>>(_a[2]))); break;
        case 42: _t->plumminefunction((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlantBase*>>(_a[2]))); break;
        case 43: _t->plantattack((*reinterpret_cast< std::add_pointer_t<PlantBase*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 40:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlantBase* >(); break;
            }
            break;
        case 41:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlantBase* >(); break;
            }
            break;
        case 42:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlantBase* >(); break;
            }
            break;
        case 43:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlantBase* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertPA; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertPB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertPC; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertPD; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertPE; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertPF; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertZA; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertZB; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertZC; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertZD; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertZE; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (plantzombie::*)(int , int , int );
            if (_t _q_method = &plantzombie::SInsertZF; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
    }
}

const QMetaObject *plantzombie::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *plantzombie::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSplantzombieENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int plantzombie::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}

// SIGNAL 0
void plantzombie::SInsertPA(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void plantzombie::SInsertPB(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void plantzombie::SInsertPC(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void plantzombie::SInsertPD(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void plantzombie::SInsertPE(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void plantzombie::SInsertPF(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void plantzombie::SInsertZA(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void plantzombie::SInsertZB(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void plantzombie::SInsertZC(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void plantzombie::SInsertZD(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void plantzombie::SInsertZE(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void plantzombie::SInsertZF(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
