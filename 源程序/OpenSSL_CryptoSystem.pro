QT       += core gui

greaterThan(QT_MAJOR_VERSION,5) : QT += core5compat
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    applink.c \
    crypto.cpp \
    filewidget.cpp \
    main.cpp \
    mainwindow.cpp \
    paradialog.cpp \
    util.cpp

HEADERS += \
    crypto.h \
    filewidget.h \
    mainwindow.h \
    paradialog.h \
    util.h

FORMS += \
    filewidget.ui \
    mainwindow.ui \
    paradialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

win32 {
INCLUDEPATH += $$quote(C:/Program Files/OpenSSL-Win64/include)
LIBS += -L$$quote(C:/Program Files/OpenSSL-Win64/lib) -llibcrypto
}
#这里只声明了include（函数声明），lib（函数实现（dll）的索引)，所以要将对应的dll拷贝到本工程的exe文件同级目录下

RC_ICONS = lock.ico
