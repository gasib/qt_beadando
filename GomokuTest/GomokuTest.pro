QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_gomokumodeltest.cpp
SOURCES += \
    ../Gomoku/gomokumodel.cpp \
    ../Gomoku/ipersistence.cpp \
    ../Gomoku/player.cpp

HEADERS += \
    ../Gomoku/gomokumodel.h \
    ../Gomoku/ipersistence.h \
    ../Gomoku/player.h
