/****************************************************************************
** Meta object code from reading C++ file 'Application.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Application.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Application.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
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
struct qt_meta_stringdata_CLASSApplicationENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSApplicationENDCLASS = QtMocHelpers::stringData(
    "Application",
    "Add_Sofa",
    "",
    "Delete_Sofa",
    "Add_Armchair",
    "Delete_Armchair",
    "Add_Wardrobe",
    "Delete_Wardrobe",
    "Add_Table",
    "Delete_Table",
    "Add_Chair",
    "Delete_Chair",
    "Delete",
    "Open",
    "Save"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSApplicationENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x0a,    1 /* Public */,
       3,    0,   93,    2, 0x0a,    2 /* Public */,
       4,    0,   94,    2, 0x0a,    3 /* Public */,
       5,    0,   95,    2, 0x0a,    4 /* Public */,
       6,    0,   96,    2, 0x0a,    5 /* Public */,
       7,    0,   97,    2, 0x0a,    6 /* Public */,
       8,    0,   98,    2, 0x0a,    7 /* Public */,
       9,    0,   99,    2, 0x0a,    8 /* Public */,
      10,    0,  100,    2, 0x0a,    9 /* Public */,
      11,    0,  101,    2, 0x0a,   10 /* Public */,
      12,    0,  102,    2, 0x0a,   11 /* Public */,
      13,    0,  103,    2, 0x0a,   12 /* Public */,
      14,    0,  104,    2, 0x0a,   13 /* Public */,

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

       0        // eod
};

Q_CONSTINIT const QMetaObject Application::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSApplicationENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSApplicationENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSApplicationENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Application, std::true_type>,
        // method 'Add_Sofa'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Delete_Sofa'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Add_Armchair'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Delete_Armchair'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Add_Wardrobe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Delete_Wardrobe'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Add_Table'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Delete_Table'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Add_Chair'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Delete_Chair'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Delete'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Open'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Save'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Application::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Application *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Add_Sofa(); break;
        case 1: _t->Delete_Sofa(); break;
        case 2: _t->Add_Armchair(); break;
        case 3: _t->Delete_Armchair(); break;
        case 4: _t->Add_Wardrobe(); break;
        case 5: _t->Delete_Wardrobe(); break;
        case 6: _t->Add_Table(); break;
        case 7: _t->Delete_Table(); break;
        case 8: _t->Add_Chair(); break;
        case 9: _t->Delete_Chair(); break;
        case 10: _t->Delete(); break;
        case 11: _t->Open(); break;
        case 12: _t->Save(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Application::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Application::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSApplicationENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Application::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP