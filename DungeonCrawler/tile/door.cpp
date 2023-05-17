#include "door.h"

Door::Door(int p_row, int p_col, int p_type) : Tile(p_row, p_col, "X"), Passive(), isOpen(false), type(p_type)
{

}

Tile* Door::onEnter(Tile* fromTile, Character* who)
{
    if (isOpen)
    {
        return this;
    }
    return nullptr;
}

Tile* Door::onLeave(Tile* destTile, Character* who)
{
    return this;
}

void Door::notify(Active* activeObject)
{
    isOpen = !isOpen;
}

string Door::getTexture()
{
    if (hasCharacter())
    {
        return characterOnDoor;
    }

    if (isOpen)
    {
        return openedTextur;
    }
    return closedTextur;
}

bool Door::getIsOpen()
{
    return isOpen;
}

int Door::getType()
{
    return type;
}
