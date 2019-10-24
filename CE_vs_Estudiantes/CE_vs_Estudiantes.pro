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
    arquero.cpp \
    artillero.cpp \
    backtracking.cpp \
    choosetower.cpp \
    destroytower.cpp \
    elfo_oscuro.cpp \
    grid.cpp \
    harpia.cpp \
    lanzafuego.cpp \
    mago.cpp \
    main.cpp \
    mainwindow.cpp \
    mercenario.cpp \
    ogro.cpp \
    player.cpp \
    parcela.cpp \
    sprite.cpp \
    updateordestroy.cpp \
    updatetower.cpp \
    warningmaxlvl.cpp \
    evaluation.cpp

HEADERS += \
    Curso.h \
    Estudiante.h \
    Lista.h \
    Nodo.h \
    arquero.h \
    artillero.h \
    backtracking.h \
    choosetower.h \
    destroytower.h \
    elfo_oscuro.h \
    grid.h \
    harpia.h \
    lanzafuego.h \
    mago.h \
    mainwindow.h \
    mercenario.h \
    ogro.h \
    player.h \
    parcela.h \
    sprite.h \
    updateordestroy.h \
    updatetower.h \
    warningmaxlvl.h \
    evaluation.h

FORMS += \
    choosetower.ui \
    destroytower.ui \
    grid.ui \
    mainwindow.ui \
    updateordestroy.ui \
    updatetower.ui \
    warningmaxlvl.ui

DISTFILES += \
    images/tower1.png \
    images/tower2.png \
    images/tower3.png \
    images/tower4.png \
    images/questionmark.png


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qtresource.qrc \
    qtresource.qrc \
    qtresource.qrc \
    sprites.qrc
