#ifndef ZOMBIEGUARD_H
#define ZOMBIEGUARD_H

#include <character/character.h>
#include <controller/guardcontroller.h>

class ZombieGuard : public Character
{
public:
    ZombieGuard(string, int, int, bool, vector<int>);
    int move() override;
    void incrementLastMove();

private:
    GuardController controller;
};

#endif // ZOMBIEGUARD_H
