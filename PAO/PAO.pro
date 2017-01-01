#-------------------------------------------------
#
# Project created by QtCreator 2016-08-11T10:49:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PAO
TEMPLATE = app
INCLUDEPATH += .
DEPENDPATH += .

SOURCES += main.cpp\
    ownerdata.cpp \
    paocontainer.cpp \
    paodb.cpp \
    contactinfo.cpp \
    abstractowner.cpp \
    owner.cpp \
    animaldata.cpp \
    animal.cpp \
    pet.cpp \
    abstractvisit.cpp \
    basicvisit.cpp \
    specializedvisit.cpp \
    vaccinevisit.cpp \
    owneraccount.cpp \
    vetview.cpp \
    vetcontrol.cpp \
    addownerdialog.cpp \
    addanimaldialog.cpp \
    addvisitdialog.cpp \
    editvisitdialog.cpp

HEADERS  += \
    ownerdata.h \
    paocontainer.h \
    paodb.h \
    contactinfo.h \
    abstractowner.h \
    owner.h \
    animaldata.h \
    animal.h \
    pet.h \
    abstractvisit.h \
    basicvisit.h \
    specializedvisit.h \
    vaccinevisit.h \
    owneraccount.h \
    vetview.h \
    vetcontrol.h \
    addownerdialog.h \
    addanimaldialog.h \
    addvisitdialog.h \
    editvisitdialog.h
