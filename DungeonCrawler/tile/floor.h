#ifndef FLOOR_H
#define FLOOR_H

#include <tile/tile.h>

class Floor : public Tile
{
public:
    Floor(int, int);

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // FLOOR_H
