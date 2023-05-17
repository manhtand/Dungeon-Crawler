#include "switch.h"

Switch::Switch(int p_row, int p_col, int p_type) : Tile(p_row, p_col, "?"), type(p_type)
{

}

Tile* Switch::onEnter(Tile* fromTile, Character* who)
{
    activate();
    return this;
}

Tile* Switch::onLeave(Tile* destTile, Character* who)
{
    return this;
}

int Switch::getType()
{
    return type;
}
