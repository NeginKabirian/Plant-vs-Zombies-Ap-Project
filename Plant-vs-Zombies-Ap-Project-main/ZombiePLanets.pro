QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Client.cpp \
    astronautzombie.cpp \
    boomerang.cpp \
    brain.cpp \
    bucketheadzombie.cpp \
    forgetpass.cpp \
    jalapieno.cpp \
    leafheadzombie.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow2.cpp \
    myexception.cpp \
    peashooter.cpp \
    plantbase.cpp \
    plantzombie.cpp \
    plummine.cpp \
    purplehairzombie.cpp \
    regularzambie.cpp \
    signup.cpp \
    sun.cpp \
    tallzombie.cpp \
    two_peashooter.cpp \
    waitstart.cpp \
    walnut.cpp \
    zombiebase.cpp

HEADERS += \
    Client.h \
    astronautzombie.h \
    boomerang.h \
    brain.h \
    bucketheadzombie.h \
    forgetpass.h \
    jalapieno.h \
    leafheadzombie.h \
    login.h \
    mainwindow.h \
    mainwindow2.h \
    myexception.h \
    peashooter.h \
    plantbase.h \
    plantzombie.h \
    plummine.h \
    purplehairzombie.h \
    regularzambie.h \
    signup.h \
    sun.h \
    tallzombie.h \
    two_peashooter.h \
    waitstart.h \
    walnut.h \
    zombiebase.h \
    rects.h \
    sun.h

FORMS += \
    forgetpass.ui \
    login.ui \
    mainwindow.ui \
    mainwindow2.ui \
    plantzombie.ui \
    signup.ui \
    waitstart.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

