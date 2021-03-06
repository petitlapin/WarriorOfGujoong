#-------------------------------------------------
#
# Project created by QtCreator 2012-08-01T22:16:23
#
#-------------------------------------------------

QT       += core gui xml widgets

TARGET = src
TEMPLATE = app

OBJECTS_DIR=../obj
MOC_DIR=../obj
UI_DIR=../obj
DESTDIR=./
INCLUDEPATH+=.

SOURCES += main.cpp\
        mainwindow.cpp \
        core/map_data/tiledata.cpp \
        core/map_data/modelarea.cpp \
        core/map_data/modelworld.cpp \
        core/WGObject.cpp \
        core/Position.cpp \
        core/Perso.cpp \
        core/Item.cpp \
        core/player.cpp \
        core/leveldata.cpp \
        scene/graphicsobject.cpp \
        scene/graphicsscene.cpp \
        scene/actionmenuwindow.cpp \
        scene/graphictile.cpp \
    scene/graphicdialog.cpp \
    core/map_data/dialogtext.cpp \
    scene/graphicdeadeffect.cpp \
    scene/fightscene.cpp \
    scene/statsscene.cpp \
    scene/wggraphicsscene.cpp \
    computemoves.cpp \
    core/equipment.cpp \
    scene/handler/statsinputhandler.cpp \
    scene/handler/inputhandler.cpp

HEADERS  += mainwindow.h \
        constants/ChainConstants.hpp \
        util/direction.hpp \
        core/map_data/tiledata.hpp \
        core/map_data/modelarea.h \
        core/map_data/modelworld.h \
        core/WGObject.hpp \
        core/Position.hpp \
        core/Item.hpp \
        core/Perso.hpp \
        core/PState.hpp \
        core/player.hpp \
        core/leveldata.hpp \
        scene/graphicsobject.hpp \
        scene/graphicsscene.hpp \
        computemoves.hpp \
        scene/actionmenuwindow.hpp \
        scene/graphictile.hpp \
    scene/graphicdialog.hpp \
    core/map_data/dialogtext.hpp \
    scene/graphicdeadeffect.hpp \
    scene/fightscene.hpp \
    scene/statsscene.hpp \
    scene/wggraphicsscene.hpp \
    core/equipment.hpp \
    scene/handler/statsinputhandler.hpp \
    scene/handler/inputhandler.hpp

FORMS    += mainwindow.ui

OTHER_FILES += \
    World.xml \
    Dialogs.xml \
    Persos.xml
