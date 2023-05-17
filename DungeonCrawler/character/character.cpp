#include <tile/tile.h>
#include "character.h"

Character::Character(string p_texture, int p_strength, int p_stamina, bool p_isZombie) : texture(p_texture), strength(p_strength), stamina(p_stamina), HP(getMaxHP()), isZombie(p_isZombie)
{

}

int Character::getHP()
{
    return HP;
}

int Character::getMaxHP()
{
    return (20 + stamina * 5);
}

int Character::getStrength()
{
    return strength;
}

bool Character::getIsZombie() const
{
    return isZombie;
}

void Character::setHP(int newHP)
{
    HP = newHP;
}

void Character::setCurTile(Tile* newCurTile)
{
    curTile = newCurTile;
}

Tile* Character::getCurTile()
{
    return curTile;
}

string Character::getTexture()
{
    return texture;
}
