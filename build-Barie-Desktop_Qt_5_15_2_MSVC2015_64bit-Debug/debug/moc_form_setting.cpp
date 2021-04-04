/****************************************************************************
** Meta object code from reading C++ file 'form_setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Barie/form_setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form_setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Form_setting_t {
    QByteArrayData data[11];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Form_setting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Form_setting_t qt_meta_stringdata_Form_setting = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Form_setting"
QT_MOC_LITERAL(1, 13, 17), // "exit_form_setting"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "on_btn_exit_clicked"
QT_MOC_LITERAL(4, 52, 33), // "on_btn_barie_xevao_update_cli..."
QT_MOC_LITERAL(5, 86, 32), // "on_btn_barie_xera_update_clicked"
QT_MOC_LITERAL(6, 119, 32), // "on_btn_rfid_xevao_update_clicked"
QT_MOC_LITERAL(7, 152, 31), // "on_btn_rfid_xera_update_clicked"
QT_MOC_LITERAL(8, 184, 35), // "on_btn_barie_xevao_update_3_c..."
QT_MOC_LITERAL(9, 220, 31), // "on_btn_ip_camera_update_clicked"
QT_MOC_LITERAL(10, 252, 28) // "on_btn_mucgia_update_clicked"

    },
    "Form_setting\0exit_form_setting\0\0"
    "on_btn_exit_clicked\0"
    "on_btn_barie_xevao_update_clicked\0"
    "on_btn_barie_xera_update_clicked\0"
    "on_btn_rfid_xevao_update_clicked\0"
    "on_btn_rfid_xera_update_clicked\0"
    "on_btn_barie_xevao_update_3_clicked\0"
    "on_btn_ip_camera_update_clicked\0"
    "on_btn_mucgia_update_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Form_setting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
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

void Form_setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Form_setting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exit_form_setting(); break;
        case 1: _t->on_btn_exit_clicked(); break;
        case 2: _t->on_btn_barie_xevao_update_clicked(); break;
        case 3: _t->on_btn_barie_xera_update_clicked(); break;
        case 4: _t->on_btn_rfid_xevao_update_clicked(); break;
        case 5: _t->on_btn_rfid_xera_update_clicked(); break;
        case 6: _t->on_btn_barie_xevao_update_3_clicked(); break;
        case 7: _t->on_btn_ip_camera_update_clicked(); break;
        case 8: _t->on_btn_mucgia_update_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Form_setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Form_setting::exit_form_setting)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Form_setting::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Form_setting.data,
    qt_meta_data_Form_setting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Form_setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Form_setting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Form_setting.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Form_setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Form_setting::exit_form_setting()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
