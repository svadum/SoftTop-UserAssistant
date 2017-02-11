/****************************************************************************
** Meta object code from reading C++ file 'softtop.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../softtop.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'softtop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SoftTop_t {
    QByteArrayData data[13];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SoftTop_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SoftTop_t qt_meta_stringdata_SoftTop = {
    {
QT_MOC_LITERAL(0, 0, 7), // "SoftTop"
QT_MOC_LITERAL(1, 8, 25), // "on_action_Close_triggered"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(4, 60, 26), // "on_viewAllcheckBox_clicked"
QT_MOC_LITERAL(5, 87, 23), // "on_updateButton_clicked"
QT_MOC_LITERAL(6, 111, 16), // "on_byDay_clicked"
QT_MOC_LITERAL(7, 128, 17), // "on_byHour_clicked"
QT_MOC_LITERAL(8, 146, 20), // "on_byAllTime_clicked"
QT_MOC_LITERAL(9, 167, 25), // "on_actionUpdate_triggered"
QT_MOC_LITERAL(10, 193, 23), // "on_actionHour_triggered"
QT_MOC_LITERAL(11, 217, 22), // "on_actionDay_triggered"
QT_MOC_LITERAL(12, 240, 27) // "on_actionAll_Time_triggered"

    },
    "SoftTop\0on_action_Close_triggered\0\0"
    "on_actionAbout_triggered\0"
    "on_viewAllcheckBox_clicked\0"
    "on_updateButton_clicked\0on_byDay_clicked\0"
    "on_byHour_clicked\0on_byAllTime_clicked\0"
    "on_actionUpdate_triggered\0"
    "on_actionHour_triggered\0on_actionDay_triggered\0"
    "on_actionAll_Time_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SoftTop[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

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

       0        // eod
};

void SoftTop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SoftTop *_t = static_cast<SoftTop *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_action_Close_triggered(); break;
        case 1: _t->on_actionAbout_triggered(); break;
        case 2: _t->on_viewAllcheckBox_clicked(); break;
        case 3: _t->on_updateButton_clicked(); break;
        case 4: _t->on_byDay_clicked(); break;
        case 5: _t->on_byHour_clicked(); break;
        case 6: _t->on_byAllTime_clicked(); break;
        case 7: _t->on_actionUpdate_triggered(); break;
        case 8: _t->on_actionHour_triggered(); break;
        case 9: _t->on_actionDay_triggered(); break;
        case 10: _t->on_actionAll_Time_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SoftTop::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SoftTop.data,
      qt_meta_data_SoftTop,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SoftTop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoftTop::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SoftTop.stringdata0))
        return static_cast<void*>(const_cast< SoftTop*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SoftTop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
