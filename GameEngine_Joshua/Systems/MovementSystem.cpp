#define _USE_MATH_DEFINES
#include "MovementSystem.h"
#include <math.h>


void MovementSystem::tick(ECS::World* world, float deltatime)
{
	this->timer += deltatime;
<<<<<<< HEAD
	world->each<Transform, Sprite2D, InputController>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle <Transform> transform,
			ECS::ComponentHandle <Sprite2D> sprite,
			ECS::ComponentHandle<InputController> input
			) -> void
		{
			sprite->picture.setOrigin(sf::Vector2f(sprite->width / 2, sprite->height / 2));
			//ECS::ComponentHandle<InputController> input = entity->get<InputController>();

			input = entity->get<InputController>();

			if (input->bInputActive == true)
			{
				if (input->s == true)
				{
					transform->xSpeed = -sin((sprite->picture.getRotation() + 90.0f) / 180.0f * M_PI) * transform->xSpeedMod;
					transform->ySpeed = cos((sprite->picture.getRotation() + 90.0f) / 180.0f * M_PI) * transform->ySpeedMod;
					transform->Move();
				}
				else if (input->w == true)
				{
					transform->xSpeed = +sin((sprite->picture.getRotation() + 90.0f) / 180.0f * M_PI) * transform->xSpeedMod;
					transform->ySpeed = -cos((sprite->picture.getRotation() + 90.0f) / 180.0f * M_PI) * transform->ySpeedMod;
					transform->Move();
				}
				else
				{
					transform->xSpeed = 0;
					transform->ySpeed = 0;
				}

				if (input->a == true)
				{
					sprite->picture.rotate(-0.5f);
				}
				else if (input->d == true)
				{
					sprite->picture.rotate(0.5f);
				}

				if (input->space == true)
				{

				}
			}

		});
=======
	if (States::getPausedState() == false)
	{
		world->each<Transform, Sprite2D, InputController>(
			[&](ECS::Entity* entity,
				ECS::ComponentHandle <Transform> transform,
				ECS::ComponentHandle <Sprite2D> sprite,
				ECS::ComponentHandle<InputController> input
				) -> void
			{
				sprite->picture.setOrigin(sf::Vector2f(sprite->width / 2, sprite->height / 2));
		//ECS::ComponentHandle<InputController> input = entity->get<InputController>();

		input = entity->get<InputController>();

		if (input->bInputActive == true)
		{
			if (input->s == true)
			{
				transform->xSpeed = -sin((sprite->picture.getRotation() + 90.0f) / 180.0f * M_PI) * transform->xSpeedMod;
				transform->ySpeed = cos((sprite->picture.getRotation() + 90.0f) / 180.0f * M_PI) * transform->ySpeedMod;
				transform->Move();
			}
			else if (input->w == true)
			{
				transform->xSpeed = +sin((sprite->picture.getRotation() + 90.0f) / 180.0f * M_PI) * transform->xSpeedMod;
				transform->ySpeed = -cos((sprite->picture.getRotation() + 90.0f) / 180.0f * M_PI) * transform->ySpeedMod;
				transform->Move();
			}
			else
			{
				transform->xSpeed = 0;
				transform->ySpeed = 0;
			}

			if (input->a == true)
			{
				sprite->picture.rotate(-transform->rotationSpeed);
			}
			else if (input->d == true)
			{
				sprite->picture.rotate(transform->rotationSpeed);
			}

			if (input->space == true)
			{

			}
		}

			});
	}
>>>>>>> c035129 (Created Tile map Struct)

}
