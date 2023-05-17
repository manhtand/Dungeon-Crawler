#include "graphicalui.h"
#include "dungeoncrawler.h"

#include <QPainter>

GraphicalUI::GraphicalUI(DungeonCrawler* p_dungenCrawler, QWidget* parent) : QMainWindow(parent), dungenCrawler(p_dungenCrawler)
{
    initTextures();
    startscreen = new StartScreen(this, parent);
    startscreen->show();
    mainwindow = new MainWindow(this, parent);
}

void GraphicalUI::draw(Level* p_level)
{
    if (!levelCreated)
    {
        mainwindow->initLevel(p_level);
        levelCreated = true;
    }

    if (!dungenCrawler->getLevelTextureInit())
    {
        mainwindow->initLevelTextures(p_level);
        dungenCrawler->setLevelTextureInit(true);
    }

    for (QPixmap* tempPixmap : paintedTiles)
    {
        delete tempPixmap;
    }
    paintedTiles.clear();

    for (int i = 0; i < p_level->getRowCount(); i++)
    {
        for (int j = 0; j < p_level->getColCount(); j++)
        {
            Tile* tempTile = p_level->getTile(i, j);
            string texture;

            bool hasChar          = tempTile->hasCharacter();
            bool isDoor           = typeid(Door)         == typeid(*tempTile);
            bool isFloor          = typeid(Floor)        == typeid(*tempTile);
            bool isPit            = typeid(Pit)          == typeid(*tempTile);
            bool isPortal         = typeid(Portal)       == typeid(*tempTile);
            bool isRamp           = typeid(Ramp)         == typeid(*tempTile);
            bool isSwitch         = typeid(Switch)       == typeid(*tempTile);
            bool isWall           = typeid(Wall)         == typeid(*tempTile);
            bool isLevelChanger   = typeid(Levelchanger) == typeid(*tempTile);
            bool isChest          = typeid(Lootchest) == typeid(*tempTile);

            if (isDoor)
            {
                Door* tempDoor = static_cast<Door*>(tempTile);

                if (tempDoor->getIsOpen())
                {
                    texture = "tex_door2";
                }
                else
                {
                    texture = "tex_door1";
                }

            }
            else if (isFloor)
            {
                texture = p_level->getTile(i, j)->getTexture();
            }

            else if (isPit)
            {
                texture = "tex_pit";
            }

            else if (isPortal)
            {
                Portal* tempDoor = static_cast<Portal*>(tempTile);
                texture = "tex_portal" + to_string( tempDoor->getPortalType() );
            }

            else if (isRamp)
            {
                texture = "tex_ramp";
            }

            else if (isSwitch)
            {
                texture = "tex_switch";
            }

            else if (isWall)
            {
                texture = "tex_wall1";
            }

            else if (isLevelChanger)
            {
                texture = "tex_levelchanger";
            }

            else if (isChest)
            {
                texture = "tex_chest";

            }
            mainwindow->changeTexture(i, j, getTexture(texture));

            if (hasChar)
            {
                string charTexture;

                if (tempTile->getCharacter()->getIsZombie())
                {
                    charTexture = "tex_zombie_left";
                }
                else
                {
                    charTexture = getPlayerTexture();
                }

                QPixmap* paintedTile = new QPixmap(70, 70);
                paintedTiles.push_back(paintedTile);
                paintedTile->fill(Qt::transparent);
                QPainter* painter = new QPainter(paintedTile);

                if (isPit)
                {
                    painter->drawPixmap(5, 10, 70, 70, *getTexture(charTexture));
                    painter->drawPixmap(0, 0, 70, 70, *getTexture(texture));
                }

                else if (isRamp)
                {
                    painter->drawPixmap(0,  0, 70, 70, *getTexture(texture));
                    painter->drawPixmap(2, -2, 70, 70, *getTexture(charTexture));
                }

                else
                {
                    painter->drawPixmap(0, 0, 70, 70, *getTexture(texture));
                    painter->drawPixmap(0, 0, 70, 70, *getTexture(charTexture));
                }
                painter->end();
                mainwindow->changeTexture(i, j, paintedTile);
            }
        }
    }
}

string GraphicalUI::getPlayerTexture()
{
    string texture = ("tex_char_front_" + to_string( rand() % 3 + 1 ));

    switch (lastInput)
    {
        case 1: texture = ("tex_char_left_"  + to_string( rand() % 3 + 1 )); break;
        case 2: texture = ("tex_char_back_" + to_string( rand() % 3 + 1 )); break;
        case 3: texture = ("tex_char_right_" + to_string( rand() % 3 + 1 )); break;
        case 4: texture = ("tex_char_left_"  + to_string( rand() % 3 + 1 )); break;
        case 5: texture = ("tex_char_front_" + to_string( rand() % 3 + 1 )); break;
        case 6: texture = ("tex_char_right_" + to_string( rand() % 3 + 1 )); break;
        case 7: texture = ("tex_char_left_"  + to_string( rand() % 3 + 1 )); break;
        case 8: texture = ("tex_char_front_"  + to_string( rand() % 3 + 1 )); break;
        case 9: texture = ("tex_char_right_" + to_string( rand() % 3 + 1 )); break;
    }
    return texture;
}

void GraphicalUI::initTextures()
{
    vector<string> textureNames =
    {
        "tex_bloody_frame",
        "tex_new_game_button",
        "tex_pit",
        "tex_ramp",
        "tex_startscreen",
        "tex_switch",
        "tex_arrow_down",
        "tex_arrow_down_left",
        "tex_arrow_down_right",
        "tex_arrow_left",
        "tex_arrow_right",
        "tex_arrow_skip",
        "tex_arrow_up",
        "tex_arrow_up_left",
        "tex_arrow_up_right",
        "tex_char_complete",
        "tex_char_back_1",
        "tex_char_back_2",
        "tex_char_back_3",
        "tex_char_front_1",
        "tex_char_front_2",
        "tex_char_front_3",
        "tex_char_left_1",
        "tex_char_left_2",
        "tex_char_left_3",
        "tex_char_right_1",
        "tex_char_right_2",
        "tex_char_right_3",
        "tex_door1",
        "tex_door2",
        "tex_floor1",
        "tex_floor2",
        "tex_floor3",
        "tex_floor4",
        "tex_floor5",
        "tex_portal1",
        "tex_portal2",
        "tex_portal3",
        "tex_wall1",
        "tex_zombie_left",
        "tex_zombie_right",
        "tex_levelchanger",
        "tex_chest"
    };

    vector<QString> texturePath =
    {
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/bloody_frame.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/new_game_button.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/pit.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/ramp.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/startscreen.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/switch.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/arrows/arrow_down.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/arrows/arrow_down_left.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/arrows/arrow_down_right.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/arrows/arrow_left.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/arrows/arrow_right.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/arrows/arrow_skip.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/arrows/arrow_up.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/arrows/arrow_up_left.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/arrows/arrow_up_right.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/char_complete.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/back/char_back_1.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/back/char_back_2.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/back/char_back_3.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/front/char_front_1.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/front/char_front_2.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/front/char_front_3.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/left/char_left_1.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/left/char_left_2.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/left/char_left_3.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/right/char_right_1.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/right/char_right_2.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/char/right/char_right_3.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/doors/door1.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/doors/door2.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/floor/floor1.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/floor/floor2.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/floor/floor3.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/floor/floor4.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/floor/floor5.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/portal/portal1.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/portal/portal2.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/portal/portal3.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/wall/wall1.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/zombie/zombie_left.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures/zombie/zombie_right.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures2/levelchanger.png",
        "/Users/dmt/Documents/2.Semester/Programmieren2/Praktikum/Praktikum4/DungeonCrawler/textures2/chest.png"
    };

    for (size_t vectorPos = 0; vectorPos < textureNames.size(); vectorPos++)
    {
        QPixmap* tempTexture = new QPixmap;
        tempTexture->load( texturePath.at(vectorPos));
        textureMap[textureNames.at(vectorPos)] = tempTexture;
    }
}

QPixmap* GraphicalUI::getTexture(string p_textureName)
{
    return textureMap.at(p_textureName);
}

void GraphicalUI::proxyMove(int p_move)
{
    lastInput = p_move;
    dungenCrawler->play(lastInput);
}

int GraphicalUI::move()
{
    return lastInput;
}

void GraphicalUI::btnNewGame()
{
    startscreen->hide();
    mainwindow->show();
}

void GraphicalUI::updateHpBar(int hp, int maxHP)
{
    mainwindow->updateHpBar(hp, maxHP);
}

void GraphicalUI::printStrengthLabel(int strength)
{
    mainwindow->printStrengthLabel(strength);
}
