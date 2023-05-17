#include "wall.h"

Wall::Wall(int p_row, int p_col) : Tile(p_row, p_col, "#")
{

}

Tile* Wall::onEnter(Tile* fromTile, Character* who)
{
    return nullptr;
}

Tile* Wall::onLeave(Tile* destTile, Character* who)
{
    return this;
}
