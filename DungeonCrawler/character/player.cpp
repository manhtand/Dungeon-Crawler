#include "player.h"

Player::Player(string p_texture, int p_strength, int p_stamina, bool p_isZombie) : Character(p_texture, p_strength, p_stamina, p_isZombie)
{

}

int Player::move()
{
    return -1;
}
