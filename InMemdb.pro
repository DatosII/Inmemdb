#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T18:38:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InMemdb
TEMPLATE = app


SOURCES += main.cpp \
    Adapter/adapter.cpp \
    Server/server.cpp \
    Wrappers/wrapperjson.cpp \
    Wrappers/wrapperxml.cpp \
    core.cpp

HEADERS  += \
    Adapter/adapter.h \
    Server/server.h \
    Wrappers/wrapperjson.h \
    Wrappers/wrapperxml.h \
    core.h
