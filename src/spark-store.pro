#-------------------------------------------------
#
# Project created by QtCreator 2019-06-30T12:53:03
#
#-------------------------------------------------

QT       += core gui network concurrent webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget glib-2.0 gdk-pixbuf-2.0 libnotify

TARGET = spark-store
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
    appitem.cpp \
    downloadworker.cpp \
    widget.cpp \
    downloadlist.cpp \
    image_show.cpp \
    big_image.cpp \
    progressload.cpp \
    flowlayout.cpp \
    workerthreads.cpp

HEADERS  += \
    appitem.h \
    downloadworker.h \
    widget.h \
    downloadlist.h \
    image_show.h \
    big_image.h \
    progressload.h \
    flowlayout.h \
    workerthreads.h

FORMS += \
    appitem.ui \
    widget.ui \
    downloadlist.ui

RESOURCES += \
    ../assets/icons.qrc

DISTFILES += \
    ../assets/tags/a2d-small.png \
    ../assets/tags/a2d.png \
    ../assets/tags/community-small.png \
    ../assets/tags/community.png \
    ../assets/tags/deepin-small.png \
    ../assets/tags/dtk-small.png \
    ../assets/tags/ubuntu-small.png \
    ../assets/tags/ubuntu.png \
    ../assets/tags/uos-small.png \
    ../assets/tags/community.svg \
    ../assets/tags/deepin.svg \
    ../assets/tags/logo_icon.svg \
    ../assets/tags/uos.svg

TRANSLATIONS = ../translations/spark-store_en.ts \
               ../translations/spark-store_zh_CN.ts
               ../translations/spark-store_fr.ts\

DEFINES += QT_APP_DEBUG
include(../third-party/QtNetworkService/QtNetworkService.pri)

