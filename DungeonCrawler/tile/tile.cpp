#include "tile.h"
#include "dungeoncrawler.h"

Tile::Tile(int p_row, int p_col, string p_texture) : row(p_row), col(p_col), texture(p_texture), character(nullptr)
{

}

bool Tile::moveTo(Tile* destTile, Character* who, DungeonCrawler* dc)
{
    Tile* realFromTile = onLeave(destTile, who);

    if (realFromTile == nullptr)
    {
        return false;
    }

    Tile* realDestTile = destTile->onEnter(realFromTile, who);

    if (realDestTile == nullptr)
    {
        return false;
    }

    dc->checkDeaths();

    realFromTile->setCharacter(nullptr);
    realDestTile->setCharacter(who);
    who->setCurTile(realDestTile);

    if (dynamic_cast<ZombieGuard*>(who) != nullptr)
    {
        static_cast<ZombieGuard*>(who)->incrementLastMove();
    }
    return true;
}

void Tile::setTexture(const string &newTexture)
{
    texture = newTexture;
}

bool Tile::hasCharacter()
{
    return (character != nullptr);
}

string Tile::getTexture()
{
    return texture;
}

Character* Tile::getCharacter()
{
    return character;
}

void Tile::setCharacter(Character* newCharacter)
{
    character = newCharacter;
}

int Tile::getRow()
{
    return row;
}

int Tile::getcol()
{
    return col;
}
