QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT +=  multimedia
QT +=  multimediawidgets

RC_ICONS = icon.ico

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += C:\software\QT\opencv\OpenCV-MinGW-Build-OpenCV-4.1.1-x64\include

LIBS += C:\software\QT\opencv\OpenCV-MinGW-Build-OpenCV-4.1.1-x64\x64\mingw\lib\libopencv_*.a \
        C:\software\QT\opencv\OpenCV-MinGW-Build-OpenCV-4.1.1-x64\x64\mingw\bin\libopencv_*.dll

DISTFILES +=

RESOURCES += \
    icon.qrc
