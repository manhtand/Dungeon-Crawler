#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
using namespace std;

#include <vector>
#include <tile/tile.h>
#include <tile/portal.h>
#include <tile/wall.h>
#include <tile/floor.h>
#include <tile/door.h>
#include <tile/switch.h>
#include <tile/pit.h>
#include <tile/ramp.h>
#include <tile/levelchanger.h>
#include <tile/lootchest.h>

#include <character/player.h>
#include <character/zombie.h>
#include <character/zombieguard.h>

class DungeonCrawler;

class Level
{
public:
    Level(int, int, string, DungeonCrawler*);
    Level(const Level&);
    Level& operator=(Level);

    ~Level();

    Tile* getTile(int,int);

    void placeCharacter(Character*, int, int);

    int getRowCount();
    int getColCount();

    vector<Character*> getCharactersList();

    void swapLevel(Level& lhs, Level& rhs);

    Character* getPlayer();
    void deleteCharacter(Character*);

    void placeNPC(Character *character, int row, int col);

private:
    DungeonCrawler* dc;

    void generateLevelFromString(string);

    int rowCount, colCount;
    vector<vector<Tile*>> gameLevel;
    vector<Character*> characters;
    Character* player;

    bool lastPortal = false;
    bool lastSwitch = false;
    bool lastDoor = false;
    bool lastLevelChanger = false;

    vector<Switch*> switchList;
    vector<Portal*> portalList;
    vector<Door*> doorList;
    void setupPortal();
    void setupSwitch();
    string levelString;
};

#endif // LEVEL_H
