TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    process.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    process.h

