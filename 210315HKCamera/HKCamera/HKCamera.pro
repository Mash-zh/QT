QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    camera.cpp

HEADERS += \
    camera.h \

#    DataType.h \
#    DecodeCardSdk.h \
#    HCNetSDK.h \
#    plaympeg4.h

FORMS += \
    camera.ui

#LIBS += "E:/code/QT/QT for Android/210315HKCamera/HKCamera/libs/HCCore.lib"
#LIBS += "E:/code/QT/QT for Android/210315HKCamera/HKCamera/libs/HCNetSDK.lib"
#LIBS += "E:/code/QT/QT for Android/210315HKCamera/HKCamera/libs/HCAlarm.lib"
#LIBS += "E:/code/QT/QT for Android/210315HKCamera/HKCamera/libs/HCGeneralCfgMgr.lib"
#LIBS += "E:/code/QT/QT for Android/210315HKCamera/HKCamera/libs/HCPreview.lib"
#LIBS += "E:/code/QT/QT for Android/210315HKCamera/HKCamera/libs/PlayCtrl.lib"
#LIBS += "E:/code/QT/QT for Android/210315HKCamera/HKCamera/libs/GdiPlus.lib"
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/libs/ -lGdiPlus

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

win32: LIBS += -L$$PWD/libs/ -lHCAlarm

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

win32: LIBS += -L$$PWD/libs/ -lHCCore

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

win32: LIBS += -L$$PWD/libs/ -lHCGeneralCfgMgr

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

win32: LIBS += -L$$PWD/libs/ -lHCNetSDK

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

win32: LIBS += -L$$PWD/libs/ -lHCPreview

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

win32: LIBS += -L$$PWD/libs/ -lPlayCtrl

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs
