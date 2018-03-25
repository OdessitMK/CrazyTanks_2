include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_testcase.h \
    object.h \
    bullet.h \
    enemytank.h \
    subjectofobservation.h \
    activeobjects.h \
    aiinput.h \
    battlefield.h \
    gold.h \
    inputinterface.h \
    observerplayer.h \
    playerinput.h \
    renderer.h \
    wall.h \
    playertank.h

SOURCES +=     main.cpp \
    object.cpp \
    bullet.cpp \
    enemytank.cpp \
    activeobjects.cpp \
    aiinput.cpp \
    battlefield.cpp \
    gold.cpp \
    inputinterface.cpp \
    observerplayer.cpp \
    playerinput.cpp \
    renderer.cpp \
    subjectofobservation.cpp \
    wall.cpp \
    playertank.cpp
