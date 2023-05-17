#include "ramp.h"

Ramp::Ramp(int p_row, int p_col) : Tile(p_row, p_col, "<")
{

}

Tile* Ramp::onEnter(Tile* fromTile, Character* who)
{
    return this;
}

Tile* Ramp::onLeave(Tile* destTile, Character* who)
{
    return this;
}
