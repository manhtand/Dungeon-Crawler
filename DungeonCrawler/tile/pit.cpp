#include "pit.h"

Pit::Pit(int p_row, int p_col) : Tile(p_row, p_col, "_")
{

}

Tile* Pit::onEnter(Tile* fromTile, Character* who)
{
    return this;
}

Tile* Pit::onLeave(Tile* destTile, Character* who)
{
    const bool isPit  = (typeid(Pit)  == typeid(*destTile));
    const bool isRamp = (typeid(Ramp) == typeid(*destTile));

    if (isPit || isRamp)
    {
        return this;
    }
    return nullptr;
}
