TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += qt console warn_on depend_includepath testcase

QT     += testlib
QT     -= gui

SOURCES += main.cpp \
    animal_in.cpp \
    animal_out.cpp \
    bird_in.cpp \
    bird_out.cpp \
    container_clear.cpp \
    container_in.cpp \
    container_init.cpp \
    container_out.cpp \
    fish_in.cpp \
    fish_out.cpp \
    node_in.cpp \
    node_out.cpp \
    beast_in.cpp \
    beast_out.cpp \
    container_out_fish.cpp \
    animal_length_name.cpp \
    animal_compare.cpp \
    container_sort.cpp \
    test.cpp \
    multimethod.cpp

HEADERS += \
    animal_atd.h \
    bird_atd.h \
    container_atd.h \
    fish_atd.h \
    node_atd.h \
    beast_atd.h \
    test.h
