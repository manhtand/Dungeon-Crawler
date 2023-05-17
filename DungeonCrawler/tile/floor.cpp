#include "floor.h"

Floor::Floor(int p_row, int p_col) : Tile(p_row, p_col, ".")
{

}

Tile* Floor::onEnter(Tile* fromTile, Character* who)
{
    if (hasCharacter())
    {
        Character* tileChar = getCharacter();

        if ((who->getIsZombie() && tileChar->getIsZombie()) || (!(who->getIsZombie()) && !(tileChar->getIsZombie())))
        {
            return nullptr;
        }
        tileChar->setHP(tileChar->getHP() - who->getStrength());

        if (tileChar->getHP() <= 0)
        {
            return this;

        }
        else
        {
            who->setHP(who->getHP() - tileChar->getStrength());
            return nullptr;
        }
    }
    return this;
}

Tile* Floor::onLeave(Tile* destTile, Character* who)
{
    return this;
}
