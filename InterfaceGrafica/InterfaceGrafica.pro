#-------------------------------------------------
#
# Project created by QtCreator 2017-09-15T20:37:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InterfaceGrafica
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    dialogografo.cpp

HEADERS  += mainwindow.h \
    grafo.h \
    lgrafo.h \
    mgrafo.h \
    dialogografo.h

FORMS    += mainwindow.ui \
    dialogografo.ui
