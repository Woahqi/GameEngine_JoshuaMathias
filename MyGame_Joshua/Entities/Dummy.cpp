#include "Dummy.h"

Dummy::Dummy(std::string picture, sf::Vector2f location)
{
	Engine& engine = Engine::GetInstance();
	entity = engine.world->create();
	entity->assign<Sprite2D>(picture);
	entity->assign<Transform>(location.x, location.y);
	entity->assign<BoxCollider>();

	entity->get<Transform>()->xSpeed = 0.0f;
	entity->get<Transform>()->ySpeed = 0.0f;
}
