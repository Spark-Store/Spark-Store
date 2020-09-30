#-------------------------------------------------
#
# Project created by QtCreator 2019-06-30T12:53:03
#
#-------------------------------------------------

QT       += core gui network concurrent webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TRANSLATIONS = ./trans/spark-store_en.ts \
               ./trans/spark-store_zh_CN.ts

CONFIG += link_pkgconfig
PKGCONFIG += dtkwidget

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
    widget.cpp \
    downloadlist.cpp \
    image_show.cpp \
    big_image.cpp \
    progressload.cpp

HEADERS  += \
    widget.h \
    downloadlist.h \
    image_show.h \
    big_image.h \
    progressload.h



CONFIG += c++11

FORMS += \
    widget.ui \
    downloadlist.ui

RESOURCES += \
    icons.qrc

DISTFILES += \
    tags/a2d-small.png \
    tags/a2d.png \
    tags/community-small.png \
    tags/community.png \
    tags/deepin-small.png \
    tags/dtk-small.png \
    tags/ubuntu-small.png \
    tags/ubuntu.png \
    tags/uos-small.png \
    tags/community.svg \
    tags/deepin.svg \
    tags/logo_icon.svg \
    tags/uos.svg
