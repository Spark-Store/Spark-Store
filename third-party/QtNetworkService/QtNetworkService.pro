#**********************************************************
#Author: Qt君
#微信公众号: Qt君(文章首发)
#Website: qtbig.com(后续更新)
#Email:  2088201923@qq.com
#QQ交流群: 732271126
#LISCENSE: MIT
#**********************************************************
CONFIG += c++11

#CONFIG += QT_APP_MODE
DEFINES += QT_APP_DEBUG

QT += network

CONFIG += staticlib
TEMPLATE = lib
unix:TARGET = $$OUT_PWD/Lib/QtNetworkService

win32: {
DESTDIR = $$OUT_PWD/Lib/
TARGET = QtNetworkService
}

message(" ================ QtNetworkService Library ================ ")

SOURCES += \
    $$PWD/HttpResponse.cpp \
    $$PWD/HttpRequest.cpp \
    $$PWD/HttpClient.cpp

HEADERS += \
    $$PWD/HttpResponse.h \
    $$PWD/HttpRequest.h \
    $$PWD/HttpClient.h

include(QtNetworkService.pri)
