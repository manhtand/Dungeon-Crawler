#include "zombie.h"

Zombie::Zombie(string p_texture, int p_strength, int p_stamina, bool p_isZombie) : Character(p_texture, p_strength, p_stamina, p_isZombie), controller(StationaryController())
{

}

Zombie::~Zombie()
{

}

int Zombie::move()
{
    return controller.move();
}
