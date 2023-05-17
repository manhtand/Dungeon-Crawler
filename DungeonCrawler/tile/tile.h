#ifndef TILE_H
#define TILE_H

#include <character/character.h>

using namespace std;

class DungeonCrawler;

class Tile
{
public:
    Tile(int, int, string);
    virtual ~Tile() = default;

    bool hasCharacter();

    Character* getCharacter();
    void setCharacter(Character *newCharacter);

    virtual string getTexture();

    int getRow();
    int getcol();

    bool moveTo(Tile* destTile, Character* who, DungeonCrawler*);

    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;
    virtual Tile* onLeave(Tile* destTile, Character* who) = 0;

    void setTexture(const string &newTexture);

private:
    const int row, col;
    string texture;
    Character* character;
};

#endif // TILE_H
