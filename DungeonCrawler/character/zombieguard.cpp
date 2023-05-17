#include "zombieguard.h"

ZombieGuard::ZombieGuard(string p_texture, int p_strength, int p_stamina, bool p_isZombie, vector<int> p_control) : Character(p_texture, p_strength, p_stamina, p_isZombie), controller(GuardController(p_control))
{

}

int ZombieGuard::move()
{
    return controller.move();
}

void ZombieGuard::incrementLastMove()
{
    controller.incrementLastMove();
}
