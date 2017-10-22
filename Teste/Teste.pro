QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Teste
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
    userInterface/graphicsview.cpp \
    userInterface/graphicsscene.cpp \
    userInterface/vertex.cpp \
    mainwindow.cpp \
    controller.cpp \
    userInterface/graphicsline.cpp \
    graphdialog.cpp \
    userInterface/straightedge.cpp

CONFIG += c++11
QMAKE_CXXFLAGS += -Wno-sign-compare #Ignora "comparison between signed and unsigned"

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    grafo.h \
    mgrafo.h \
    stack.h \
    lgrafo.h \
    terminal_ui.h \
    userInterface/graphicsview.h \
    userInterface/graphicsscene.h \
    userInterface/vertex.h \
    mainwindow.h \
    controller.h \
    userInterface/graphicsline.h \
    graphdialog.h \
    userInterface/straightedge.h

FORMS += \
    mainwindow.ui \
    graphdialog.ui

