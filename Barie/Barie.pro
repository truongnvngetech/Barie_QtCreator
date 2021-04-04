QT       += core gui serialport sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base64.cpp \
    bks_detect.cpp \
    detectchars.cpp \
    detectplates.cpp \
    form_login.cpp \
    form_setting.cpp \
    form_sql_dangky.cpp \
    form_sql_log.cpp \
    form_sql_login.cpp \
    httprequestworker.cpp \
    main.cpp \
    form_main.cpp \
    possiblechar.cpp \
    preprocess.cpp \
    serial_comport.cpp \
    sql_data.cpp \
    thread1_cam1.cpp \
    thread2_cam2.cpp \
    thread3_cam3.cpp \
    thread4_cam4.cpp

HEADERS += \
    base64.h \
    bks_detect.h \
    define_input.h \
    detectchars.h \
    detectplates.h \
    form_login.h \
    form_main.h \
    form_setting.h \
    form_sql_dangky.h \
    form_sql_log.h \
    form_sql_login.h \
    httprequestworker.h \
    lib_opencv.h \
    possiblechar.h \
    possibleplates.h \
    preprocess.h \
    scalar.h \
    serial_comport.h \
    sql_data.h \
    thread1_cam1.h \
    thread2_cam2.h \
    thread3_cam3.h \
    thread4_cam4.h

FORMS += \
    form_login.ui \
    form_main.ui \
    form_setting.ui \
    form_sql_dangky.ui \
    form_sql_log.ui \
    form_sql_login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world451d
else:unix: LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world451

INCLUDEPATH += C:/opencv/build/include
DEPENDPATH += C:/opencv/build/include

RESOURCES += \
    Resource.qrc
