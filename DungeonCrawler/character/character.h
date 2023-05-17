#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
using namespace std;

class Tile;

class Character
{
public:
    Character(string, int, int, bool);
    ~Character() = default;

    void setCurTile(Tile* newCurTile);
    Tile* getCurTile();

    string getTexture();

    virtual int move() = 0;

    int getHP();
    int getMaxHP();
    int getStrength();
    bool getIsZombie() const;

    void setHP(int newHP);

private:
    Tile* curTile;
    string texture;

    int strength;
    int stamina;
    int HP;
    bool isZombie;
};

#endif // CHARACTER_H
