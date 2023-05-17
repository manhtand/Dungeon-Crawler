#include "level.h"
#include "dungeoncrawler.h"

Level::Level(int p_rowCount, int p_colCount, string p_levelString, DungeonCrawler* p_dc) : rowCount(p_rowCount), colCount(p_colCount), levelString(p_levelString), dc(p_dc)
{
    generateLevelFromString(levelString);
}

Level::Level(const Level& p_lvl) : rowCount(p_lvl.rowCount), colCount(p_lvl.colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        vector<Tile*> temp;
        gameLevel.push_back(temp);

        for (int j = 0; j < colCount; j++)
        {
            Tile* tempTile = p_lvl.gameLevel.at(i).at(j);

            bool isDoor   = typeid(Door)   == typeid(*tempTile);
            bool isFloor  = typeid(Floor)  == typeid(*tempTile);
            bool isPit    = typeid(Pit)    == typeid(*tempTile);
            bool isPortal = typeid(Portal) == typeid(*tempTile);
            bool isRamp   = typeid(Ramp)   == typeid(*tempTile);
            bool isSwitch = typeid(Switch) == typeid(*tempTile);
            bool isWall   = typeid(Wall)   == typeid(*tempTile);

            if (isDoor)
            {
                gameLevel.at(i).push_back(new Door(i, j, 0));
            }

            else if (isFloor)
            {
                gameLevel.at(i).push_back(new Floor(i,j));
            }

            else if (isPit)
            {
                gameLevel.at(i).push_back(new Pit(i, j));
            }

            else if (isPortal)
            {
                Portal* tempPortal = static_cast<Portal*>(tempTile);
                gameLevel.at(i).push_back(new Portal(i, j, tempPortal->getPortalType()));
            }

            else if (isRamp)
            {
                gameLevel.at(i).push_back(new Ramp(i, j));
            }

            else if (isSwitch)
            {
                gameLevel.at(i).push_back(new Switch(i, j, 0));
            }

            else if (isWall)
            {
                gameLevel.at(i).push_back(new Wall(i, j));
            }

            if (tempTile->hasCharacter())
            {
                string charTexture = tempTile->getCharacter()->getTexture();
                Character* character = new Player(charTexture, 100, 100, false);
                placeCharacter(character, i, j);
            }
        }
    }

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            Tile* tempTile    = gameLevel.at(i).at(j);
            Tile* tempTileOld = p_lvl.gameLevel.at(i).at(j);

            if (typeid(Portal) == typeid(*tempTile))
            {
                Portal* tempPortal = static_cast<Portal*>(tempTile);
                Portal* tempPortalOld = static_cast<Portal*>(tempTileOld);

                int destRow = tempPortalOld->getDest()->getRow();
                int destCol = tempPortalOld->getDest()->getcol();

                tempPortal->setDest(gameLevel.at(destRow).at(destCol));
            }
        }
    }

    Switch* switchTile = static_cast<Switch*>(getTile(8,4));
    Door* doorTile = static_cast<Door*>(getTile(6,7));
    switchTile->attach(doorTile);
}

Level &Level::operator=(Level rhs)
{
    swapLevel(*this, rhs);
    return *this;
}

Level::~Level()
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            delete gameLevel.at(i).at(j);
        }
    }

    for (Character* character: characters)
    {
        delete character;
    }
}

void Level::placeCharacter(Character* character, int row, int col)
{
    player = character;
    gameLevel.at(row).at(col)->setCharacter(character);
    character->setCurTile(gameLevel.at(row).at(col));
}

void Level::placeNPC(Character* character, int row, int col)
{
    characters.push_back(character);
    gameLevel.at(row).at(col)->setCharacter(character);
    character->setCurTile(gameLevel.at(row).at(col));
}

void Level::swapLevel(Level &lhs, Level &rhs)
{
    swap(lhs.gameLevel, rhs.gameLevel);
    swap(lhs.characters, rhs.characters);
    swap(lhs.player, rhs.player);
    swap(lhs.rowCount, rhs.rowCount);
    swap(lhs.colCount, rhs.colCount);
}

void Level::generateLevelFromString(string p_levelString)
{
    int row = 0, col = 0;
    vector<Tile*> tempVector;
    gameLevel.push_back(tempVector);

    for (char tempChar : p_levelString)
    {
        if (tempChar == ' ')
        {
            vector<Tile*> tempVectorV2;
            gameLevel.push_back(tempVectorV2);
            row ++;
            col = 0;
            continue;
        }

        if (tempChar == 'C')
        {
            gameLevel.at(row).push_back(new Floor(row, col));
            Character* character = new Player("C", 100, 100, false);
            placeCharacter(character, row, col);
            col ++;
            continue;
        }

        if (tempChar == 'Z')
        {
            gameLevel.at(row).push_back(new Floor(row, col));
            Character* character = new Zombie("E", 70, 70, true);
            placeNPC(character, row, col);
            col ++;
            continue;
        }

        if (tempChar == 'G')
        {
            gameLevel.at(row).push_back(new Floor(row, col));
            vector<int> tempMoves = {6, 1, 4, 8, 9, 2};
            Character* character = new ZombieGuard("G", 50, 50, true, tempMoves);
            placeNPC(character, row, col);
            col ++;
            continue;
        }

        if (tempChar == 'L')
        {
            Lootchest* tempTile = new Lootchest (row, col);
            gameLevel.at(row).push_back(tempTile);
            col++;
            continue;
        }

        if (tempChar == 'O')
        {
            lastPortal = true;
            continue;
        }

        if (lastPortal)
        {
            Portal* tempTile = new Portal (row, col, tempChar - '0');
            gameLevel.at(row).push_back( tempTile );
            portalList.push_back(tempTile);
            lastPortal = false;
            col++;
            continue;
        }

        if (tempChar == '?')
        {
            lastSwitch = true;
            continue;
        }

        if (lastSwitch)
        {
            Switch* tempTile = new Switch (row, col, tempChar - '0');
            gameLevel.at(row).push_back( tempTile );
            switchList.push_back(tempTile);
            lastSwitch = false;
            col++;
            continue;
        }

        if (tempChar == 'X')
        {
            lastDoor = true;
            continue;
        }

        if (lastDoor)
        {
            Door* tempTile = new Door (row, col, tempChar - '0');
            gameLevel.at(row).push_back( tempTile );
            doorList.push_back(tempTile);
            lastDoor = false;
            col++;
            continue;
        }

        if (tempChar == '-')
        {
            lastLevelChanger = true;
            continue;
        }

        if (lastLevelChanger)
        {
            Levelchanger* tempTile = new Levelchanger (row, col, tempChar - '0');
            gameLevel.at(row).push_back(tempTile);
            tempTile->attach( dc );
            lastLevelChanger = false;
            col++;
            continue;
        }

        Tile* tempTile;
        switch (tempChar)
        {
            case '#': tempTile = new Wall   (row, col); break;
            case '<': tempTile = new Ramp   (row, col); break;
            case '_': tempTile = new Pit    (row, col); break;
            case '.': tempTile = new Floor  (row, col); break;
        }
        gameLevel.at(row).push_back(tempTile);
        col ++;
    }
    setupPortal();
    setupSwitch();
}

void Level::setupPortal()
{
    for (int i = 0; i < portalList.size(); ++i)
    {
        Portal* portal1 = portalList.at(i);

        for (int k = 0; k < portalList.size(); ++k)
        {
            Portal* portal2 = portalList.at(k);

            if (portal2 != portal1 && portal2->getPortalType() == portal1->getPortalType())
            {
                portal2->setDest(portal1);
                portal1->setDest(portal2);
                break;
            }
        }
    }
}

void Level::setupSwitch()
{
    for (int i = 0; i < switchList.size(); ++i)
    {
        Switch* tempSwitch = switchList.at(i);

        for (Door* tempDoor : doorList)
        {
            if (tempDoor->getType() == tempSwitch->getType())
            {
                tempSwitch->attach(tempDoor);
            }
        }
    }
}

Character* Level::getPlayer()
{
    return player;
}

void Level::deleteCharacter(Character* p_char)
{
    for (int i = 0; i < characters.size(); ++i)
    {
        if (characters.at(i) == p_char)
        {
            characters.erase(characters.begin() + i);
        }
    }
}

vector<Character*> Level::getCharactersList()
{
    return characters;
}

Tile* Level::getTile(int row, int col)
{
    return gameLevel.at(row).at(col);
}

int Level::getRowCount()
{
    return rowCount;
}

int Level::getColCount()
{
    return colCount;
}
