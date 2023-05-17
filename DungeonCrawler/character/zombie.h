#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <controller/stationarycontroller.h>
#include <character/character.h>

class Zombie : public Character, public StationaryController
{
public:
    Zombie(string, int, int, bool);
    ~Zombie();
    int move() override;

private:
    StationaryController controller;
};

#endif // ZOMBIE_H
