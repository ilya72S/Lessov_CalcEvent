QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drag_drob_info.cpp \
    dropmonitor.cpp \
    fild.cpp \
    keyboard.cpp \
    main.cpp \
    main_scene.cpp \
    mainwindow.cpp \
    monitor.cpp

HEADERS += \
    Com_Calc.h \
    drag_drob_info.h \
    dropmonitor.h \
    fild.h \
    keyboard.h \
    main_scene.h \
    mainwindow.h \
    monitor.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
