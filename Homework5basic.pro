#-------------------------------------------------
#
# Project created by QtCreator 2016-04-28T23:28:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Homework5basic
TEMPLATE = app


SOURCES += main.cpp \
    mainscreen.cpp \
    gameboard.cpp \
    player.cpp \
    fireball.cpp \
    enemy.cpp \
    score.cpp \
    health.cpp \
    gameover.cpp

HEADERS  += \
    mainscreen.h \
    gameboard.h \
    player.h \
    fireball.h \
    enemy.h \
    score.h \
    health.h \
    gameover.h

FORMS    +=

RESOURCES += \
    resources.qrc
