QT += core gui
QT += testlib
greaterThan(QT_MAJOR_VERSION, 5): QT += widgets
CONFIG += c++11

SOURCES += \
        GUI/controlbutton.cpp \
        GUI/graphicalui.cpp \
        GUI/mainwindow.cpp \
        abstractui.cpp \
        active.cpp \
        character/character.cpp \
        character/player.cpp \
        character/zombie.cpp \
        character/zombieguard.cpp \
        controller/controller.cpp \
        controller/guardcontroller.cpp \
        controller/stationarycontroller.cpp \
        dungeoncrawler.cpp \
        helper/list.cpp \
        level.cpp \
        main.cpp \
        passive.cpp \
        GUI/startscreen.cpp \
        tile/door.cpp \
        tile/floor.cpp \
        tile/levelchanger.cpp \
        tile/lootchest.cpp \
        tile/pit.cpp \
        tile/portal.cpp \
        tile/ramp.cpp \
        tile/switch.cpp \
        tile/tile.cpp \
        tile/wall.cpp

HEADERS += \
    GUI/controlbutton.h \
    GUI/graphicalui.h \
    GUI/mainwindow.h \
    abstractui.h \
    active.h \
    character/character.h \
    character/player.h \
    character/zombie.h \
    character/zombieguard.h \
    controller/controller.h \
    controller/guardcontroller.h \
    controller/stationarycontroller.h \
    dungeoncrawler.h \
    helper/list.h \
    level.h \
    passive.h \
    GUI/startscreen.h \
    tile/door.h \
    tile/floor.h \
    tile/levelchanger.h \
    tile/lootchest.h \
    tile/pit.h \
    tile/portal.h \
    tile/ramp.h \
    tile/switch.h \
    tile/tile.h \
    tile/wall.h

DISTFILES += \
    textures/arrows/arrow_down.png \
    textures/arrows/arrow_down_left.png \
    textures/arrows/arrow_down_right.png \
    textures/arrows/arrow_left.png \
    textures/arrows/arrow_right.png \
    textures/arrows/arrow_skip.png \
    textures/arrows/arrow_up.png \
    textures/arrows/arrow_up_left.png \
    textures/arrows/arrow_up_right.png \
    textures/bloody_frame.png \
    textures/char/back/char_back_1.png \
    textures/char/back/char_back_2.png \
    textures/char/back/char_back_3.png \
    textures/char/char_complete.png \
    textures/char/front/char_front_1.png \
    textures/char/front/char_front_2.png \
    textures/char/front/char_front_3.png \
    textures/char/left/char_left_1.png \
    textures/char/left/char_left_2.png \
    textures/char/left/char_left_3.png \
    textures/char/right/char_right_1.png \
    textures/char/right/char_right_2.png \
    textures/char/right/char_right_3.png \
    textures/doors/door1.png \
    textures/doors/door2.png \
    textures/floor/floor1.png \
    textures/floor/floor2.png \
    textures/floor/floor3.png \
    textures/floor/floor4.png \
    textures/floor/floor5.png \
    textures/new_game_button.png \
    textures/pit.png \
    textures/portal/portal1.png \
    textures/portal/portal2.png \
    textures/portal/portal3.png \
    textures/ramp.png \
    textures/startscreen.png \
    textures/switch.png \
    textures/wall/wall1.png \
    textures/zombie/zombie_left.png \
    textures/zombie/zombie_right.png \
    textures2/chest.png \
    textures2/levelchanger.png

FORMS += \
    GUI/mainwindow.ui \
    GUI/startscreen.ui
