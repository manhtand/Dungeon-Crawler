#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include <active.h>
#include <tile/tile.h>

class Levelchanger : public Tile, public Active
{
public:
    Levelchanger(int, int, int);

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

    int getType() const;

private:
    int type;
};

#endif // LEVELCHANGER_H
