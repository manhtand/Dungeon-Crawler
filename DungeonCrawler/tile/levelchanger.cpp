#include "levelchanger.h"

Levelchanger::Levelchanger(int p_row, int p_col, int p_type) : Tile(p_row, p_col, "-"), Active(), type(p_type)
{

}

Tile *Levelchanger::onEnter(Tile *fromTile, Character *who)
{
    activate();
    return this;
}

Tile *Levelchanger::onLeave(Tile *destTile, Character *who)
{
    return this;
}

int Levelchanger::getType() const
{
    return type;
}
