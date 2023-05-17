#ifndef LOOTCHEST_H
#define LOOTCHEST_H

#include <tile/tile.h>

class Lootchest : public Tile
{
public:
    Lootchest(int, int);

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // LOOTCHEST_H

