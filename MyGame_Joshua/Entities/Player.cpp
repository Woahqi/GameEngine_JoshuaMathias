#include "Player.h"

Player::Player(sf::Vector2f position) : Soldier("../debug/pics/player_1.png",position)
{
	entity->assign<InputController>();
	entity->get<Transform>()->rotationAngle = 0.005f;
}
