#ifndef PIT_H
#define PIT_H

#include <tile/tile.h>
#include <tile/ramp.h>

class Pit : public Tile
{

public:
    Pit(int, int);

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // PIT_H
