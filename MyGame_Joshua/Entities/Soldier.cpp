#include "Soldier.h"


Soldier::Soldier(std::string picture, sf::Vector2f location)// : Entity(picture, location)
{
	Engine& engine = Engine::GetInstance();
	entity = engine.world->create();
	entity->assign<Sprite2D>(picture);
<<<<<<< HEAD
	entity->assign<Transform>(location.x, location.y, 0.3f, 0.3f);
	entity->assign<BoxCollider>();
	entity->assign<CallbackEntity>(&Soldier::Fire);
=======
	entity->assign<Transform>(location.x, location.y, 0.03f, 0.03f, 0.0f, 0.05f);
	entity->assign<BoxCollider>();
	entity->assign<CallbackEntity>(&Soldier::Fire);

>>>>>>> c035129 (Created Tile map Struct)
}

void Soldier::Fire(ECS::Entity* entity)
{
	ECS::ComponentHandle<Sprite2D> sprite = entity->get<Sprite2D>();
	ECS::ComponentHandle<Transform> transform = entity->get<Transform>();

}

