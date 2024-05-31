QT       += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    B_Parts.cpp \
    Circle_Sample.cpp \
    Door_Sample.cpp \
    Params_Window.cpp \
    Square_Sample.cpp \
    Stairs_Sample.cpp \
    System_Item.cpp \
    Wall_Sample.cpp \
    Window_Sample.cpp \
    main.cpp \
    uchebnayapractika.cpp

HEADERS += \
    B_Parts.h \
    Circle_Sample.h \
    Door_Sample.h \
    Params_Window.h \
    Square_Sample.h \
    Stairs_Sample.h \
    System_Item.h \
    Wall_Sample.h \
    Window_Sample.h \
    uchebnayapractika.h

FORMS += \
    Params_Window.ui \
    System_Item.ui \
    uchebnayapractika.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
