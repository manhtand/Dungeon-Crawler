#ifndef PORTAL_H
#define PORTAL_H

#include <tile/tile.h>

class Portal : public Tile
{
public:
    Portal(int, int, int);

    Tile* getDest();
    void setDest(Tile*);

    Tile* onEnter(Tile* fromTile, Character* who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

    int getPortalType();

private:
    Tile* destination;
    int portalType;
};

#endif // PORTAL_H
