QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add1.cpp \
    building.cpp \
    distancebetweenprime.cpp \
    escape.cpp \
    fibonaccioffibonacci.cpp \
    findfactorial.cpp \
    findtheperiodofstring.cpp \
    floor.cpp \
    judge.cpp \
    largefactorial.cpp \
    largestroot.cpp \
    longestpair.cpp \
    main.cpp \
    mainwindow.cpp \
    minesweeper.cpp \
    mymath.cpp \
    myother.cpp \
    mystring.cpp \
    mytree.cpp \
    prime.cpp \
    problemset.cpp \
    scheduler.cpp \
    shortestsummation.cpp \
    shygame.cpp \
    sumoflargehex.cpp

HEADERS += \
    add1.h \
    building.h \
    data.h \
    distancebetweenprime.h \
    escape.h \
    fibonaccioffibonacci.h \
    findfactorial.h \
    findtheperiodofstring.h \
    floor.h \
    judge.h \
    largefactorial.h \
    largestroot.h \
    longestpair.h \
    mainwindow.h \
    minesweeper.h \
    mymath.h \
    myother.h \
    mystring.h \
    mytree.h \
    prime.h \
    problems.h \
    problemset.h \
    scheduler.h \
    shortestsummation.h \
    shygame.h \
    sumoflargehex.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
