#ifndef PLAYER_H
#define PLAYER_H

#include <character/character.h>

using namespace std;

class Player : public Character
{
public:
    Player(string, int, int, bool);
    int move() override;
};

#endif // PLAYER_H
