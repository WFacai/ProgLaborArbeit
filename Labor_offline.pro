TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    labor.c \
    odometry.c \
    trajectory.c

HEADERS += \
    labor.h \
    odometry.h \
    trajectory.h
