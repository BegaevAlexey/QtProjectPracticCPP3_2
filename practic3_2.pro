#-------------------------------------------------
#
# Project created by QtCreator 2017-02-02T12:40:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
QMAKE_CXXFLAGS += -std=gnu++11

TARGET = practic3_2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    well.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    getdata.h \
    getvectorwell.h \
    well.h

FORMS    += mainwindow.ui
