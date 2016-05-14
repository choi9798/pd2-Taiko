#-------------------------------------------------
#
# Project created by QtCreator 2016-05-09T14:36:44
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
TEMPLATE = app


SOURCES += main.cpp\
        taiko.cpp \
    play.cpp

HEADERS  += taiko.h \
    play.h

FORMS    += taiko.ui \
    play.ui

RESOURCES += \
    menu_bg.qrc
