TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    odometry.c \
    trajectory.c \
    afg1.c \
    afg2.c \
    afg3.c \
    afg4.c \
    afg5.c

HEADERS += \
    odometry.h \
    trajectory.h \
    afg1.h \
    afg2.h \
    afg3.h \
    afg4.h \
    afg5.h
