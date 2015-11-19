QT += core
QT -= gui

TARGET = Project
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ../HeadGenerator/HeadGenerator.cpp \
    ../HeadGenerator/MeshModel.cpp \
    ../HeadGenerator/Transform.cpp \
    ../HeadDetector/HeadDetector.cpp

HEADERS += \
    ../HeadGenerator/Container.h \
    ../HeadGenerator/HeadGenerator.h \
    ../HeadGenerator/MeshModel.h \
    ../HeadGenerator/Transform.h \
    ../HeadDetector/HeadDetector.h \
    ../HeadDetector/stasm_dll.h

INCLUDEPATH += /usr/local/include/

LIBS += /usr/local/lib/*.a
