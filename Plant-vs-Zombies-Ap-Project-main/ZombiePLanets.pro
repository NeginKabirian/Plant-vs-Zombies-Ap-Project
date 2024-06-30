QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    astronautzombie.cpp \
    boomerang.cpp \
    brain.cpp \
    bucketheadzombie.cpp \
    jalapieno.cpp \
    leafheadzombie.cpp \
    main.cpp \
    mainwindow.cpp \
    peashooter.cpp \
    plantbase.cpp \
    plantzombie.cpp \
    plummine.cpp \
    purplehairzombie.cpp \
    regularzambie.cpp \
    sun.cpp \
    tallzombie.cpp \
    two_peashooter.cpp \
    walnut.cpp \
    zombiebase.cpp

HEADERS += \
    astronautzombie.h \
    boomerang.h \
    brain.h \
    bucketheadzombie.h \
    jalapieno.h \
    leafheadzombie.h \
    mainwindow.h \
    peashooter.h \
    plantbase.h \
    plantzombie.h \
    plummine.h \
    purplehairzombie.h \
    regularzambie.h \
    sun.h \
    tallzombie.h \
    two_peashooter.h \
    walnut.h \
    zombiebase.h \
    rects.h \
    sun.h

FORMS += \
    mainwindow.ui \
    plantzombie.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

