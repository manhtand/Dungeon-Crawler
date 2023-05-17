#ifndef WALL_H
#define WALL_H

#include <tile/tile.h>

class Wall : public Tile
{
public:
    Wall(int, int);

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // WALL_H
