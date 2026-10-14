#include "Player.hpp"

void *Player::create()
{
	return new Player();
}

// 0x02128458
ObjectProfile Player_Profile = { Player::create, 21, 28 };
