#include "portal.h"

Portal::Portal(int p_row, int p_col, int p_type) : Tile(p_row, p_col, "O"), portalType(p_type)
{

}

Tile* Portal::onEnter(Tile* fromTile, Character* who)
{
    return destination;
}

Tile* Portal::onLeave(Tile* destTile, Character* who)
{
    return this;
}

int Portal::getPortalType()
{
    return portalType;
}

void Portal::setDest(Tile* dest)
{
    destination = dest;
}

Tile* Portal::getDest()
{
    return destination;
}
