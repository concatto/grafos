TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

CONFIG += c++11
QMAKE_CXXFLAGS += -Wno-sign-compare #Ignora "comparison between signed and unsigned"

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    grafo.h \
    mgrafo.h \
    stack.h \
    lgrafo.h

