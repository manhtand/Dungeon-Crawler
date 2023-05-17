#ifndef SWITCH_H
#define SWITCH_H

#include <tile/tile.h>
#include <active.h>

class Switch : public Tile, public Active
{
public:
    Switch(int, int, int);

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

    int getType();

private:
    int type;
};

#endif // SWITCH_H
