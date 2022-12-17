#include "PhysicsSystem.h"

bool PhysicsSystem::IsColliding(ECS::ComponentHandle<BoxCollider> touchingBox, ECS::ComponentHandle<BoxCollider> touchedBox, float x, float y)
{
	return touchingBox->rightEdge + x > touchedBox->leftEdge &&
		touchedBox->rightEdge > touchingBox->leftEdge + x &&
		touchingBox->bottomEdge + y > touchedBox->topEdge &&
		touchedBox->bottomEdge > touchingBox->topEdge + y;
}

bool PhysicsSystem::IsColliding(ECS::ComponentHandle<BoxCollider> touchingBox, sf::RectangleShape touchedRectangle, float x, float y)
{
	float _touchedRectLeft = touchedRectangle.getPosition().x;
	float _touchedRectRight = _touchedRectLeft + touchedRectangle.getGlobalBounds().width;
	float _touchedRectTop = touchedRectangle.getPosition().y;
	float _touchedRectBottom = _touchedRectTop + touchedRectangle.getGlobalBounds().height;

	return touchingBox->rightEdge + x > _touchedRectLeft &&
		_touchedRectRight > touchingBox->leftEdge + x &&
		touchingBox->bottomEdge + y > _touchedRectTop &&
		_touchedRectBottom > touchingBox->topEdge + y;
}

bool PhysicsSystem::IsColliding(ECS::ComponentHandle<BoxCollider> touchingBox, ECS::ComponentHandle<BoxCollider> touchedBox)
{
	return
		touchingBox->rightEdge > touchedBox->leftEdge &&
		touchedBox->rightEdge > touchingBox->leftEdge &&
		touchingBox->bottomEdge > touchedBox->topEdge &&
		touchedBox->bottomEdge > touchingBox->topEdge;
}

bool PhysicsSystem::IsColliding(ECS::ComponentHandle<BoxCollider> touchingBox, sf::RectangleShape touchedRectangle)
{
	float _touchedRectLeft = touchedRectangle.getPosition().x;
	float _touchedRectRight = _touchedRectLeft + touchedRectangle.getGlobalBounds().width;
	float _touchedRectTop = touchedRectangle.getPosition().y;
	float _touchedRectBottom = _touchedRectTop + touchedRectangle.getGlobalBounds().height;

	return touchingBox->rightEdge > _touchedRectLeft &&
		_touchedRectRight > touchingBox->leftEdge &&
		touchingBox->bottomEdge > _touchedRectTop &&
		_touchedRectBottom > touchingBox->topEdge;
}

void PhysicsSystem::CheckCollisionSides(ECS::ComponentHandle<Transform> transform, ECS::ComponentHandle<BoxCollider> touchingBox, ECS::ComponentHandle<BoxCollider> touchedBox)
{
	// Scenario dealing with collision from the right side by accelerating rightward
	if (transform->xSpeed > 0 &&
		touchedBox->rightEdge + transform->xSpeed > touchedBox->leftEdge &&
		touchingBox->topEdge < touchedBox->bottomEdge &&
		touchingBox->bottomEdge > touchedBox->topEdge)
	{
		transform->xSpeed = 0;
	}

	// Scenario dealing with collision from the bottom side by accelerating downward
	if (transform->ySpeed > 0 &&
		touchedBox->bottomEdge + transform->ySpeed > touchedBox->topEdge &&
		touchingBox->leftEdge < touchedBox->rightEdge &&
		touchingBox->rightEdge > touchedBox->leftEdge)
	{
		transform->ySpeed = 0;
	}

	// Scenario dealing with collision from the left side by accelerating leftward
	if (transform->xSpeed < 0 &&
		touchedBox->leftEdge + transform->xSpeed > touchedBox->rightEdge &&
		touchingBox->topEdge < touchedBox->bottomEdge &&
		touchingBox->bottomEdge > touchedBox->topEdge)
	{
		transform->xSpeed = 0;
	}

	// Scenario dealing with collision from the top side by accelerating upward
	if (transform->ySpeed < 0 &&
		touchedBox->topEdge + transform->ySpeed > touchedBox->bottomEdge &&
		touchingBox->leftEdge < touchedBox->rightEdge &&
		touchingBox->rightEdge > touchedBox->leftEdge)
	{
		transform->ySpeed = 0;
	}

}

void PhysicsSystem::CheckCollisionSides(ECS::ComponentHandle<Transform> transform, ECS::ComponentHandle<BoxCollider> touchingBox, sf::RectangleShape touchedRectangle)
{
	float _touchedRectLeft = touchedRectangle.getPosition().x;
	float _touchedRectRight = _touchedRectLeft + touchedRectangle.getGlobalBounds().width;
	float _touchedRectTop = touchedRectangle.getPosition().y;
	float _touchedRectBottom = _touchedRectTop + touchedRectangle.getGlobalBounds().height;

	// Scenario dealing with collision from the right side by accelerating rightward
	if (transform->xSpeed > 0 &&
		_touchedRectRight + transform->xSpeed > _touchedRectLeft &&
		touchingBox->topEdge < _touchedRectBottom &&
		touchingBox->bottomEdge > _touchedRectTop)
	{
		transform->xSpeed = 0;
	}

	// Scenario dealing with collision from the bottom side by accelerating downward
	if (transform->ySpeed > 0 &&
		_touchedRectBottom + transform->ySpeed > _touchedRectTop &&
		touchingBox->leftEdge < _touchedRectRight &&
		touchingBox->rightEdge > _touchedRectLeft)
	{
		transform->ySpeed = 0;
	}

	// Scenario dealing with collision from the left side by accelerating leftward
	if (transform->xSpeed < 0 &&
		_touchedRectLeft + transform->xSpeed > _touchedRectRight &&
		touchingBox->topEdge < _touchedRectBottom &&
		touchingBox->bottomEdge > _touchedRectTop)
	{
		transform->xSpeed = 0;
	}

	// Scenario dealing with collision from the top side by accelerating upward
	if (transform->ySpeed < 0 &&
		_touchedRectTop + transform->ySpeed > _touchedRectBottom &&
		touchingBox->leftEdge < _touchedRectRight &&
		touchingBox->rightEdge > _touchedRectLeft)
	{
		transform->ySpeed = 0;
	}
}

void PhysicsSystem::CheckCollisionSides(ECS::Entity* touchingEntity, ECS::Entity* touchedEntity)
{
	float _newTouchingX = touchingEntity->get<Transform>()->xPos;
	float _newTouchingY = touchingEntity->get<Transform>()->yPos;
	float _newTouchingXSpeed = touchingEntity->get<Transform>()->xSpeed;
	float _newTouchingYSpeed = touchingEntity->get<Transform>()->ySpeed;

	float _newTouchedX = touchedEntity->get<Transform>()->xPos;
	float _newTouchedY = touchedEntity->get<Transform>()->yPos;
	float _newTouchedXSpeed = touchedEntity->get<Transform>()->xSpeed;
	float _newTouchedYSpeed = touchedEntity->get<Transform>()->ySpeed;

	// TODO: Tag ifs
	if (_newTouchingXSpeed > 0 && _newTouchingX < _newTouchedX) {
		touchedEntity->get<Transform>()->xPos++;
	}
	else if (_newTouchingXSpeed < 0 && _newTouchingX > _newTouchedX) {
		touchedEntity->get<Transform>()->xPos--;
	}

	if (_newTouchingYSpeed > 0 && _newTouchingY < _newTouchedY) {
		touchedEntity->get<Transform>()->yPos++;
	}
	else if (_newTouchingYSpeed < 0 && _newTouchingY > _newTouchedY) {
		touchedEntity->get<Transform>()->yPos--;
	}
}

void PhysicsSystem::tick(ECS::World* world, float deltaTime)
{
<<<<<<< HEAD
	// TODO: Paused state
	world->each<BoxCollider, Sprite2D, Transform>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle<BoxCollider> collider,
			ECS::ComponentHandle<Sprite2D> sprite,
			ECS::ComponentHandle<Transform> transform
			) -> void
		{
			collider->Update(transform->xPos, transform->yPos, sprite->picture.getTextureRect().width, sprite->picture.getTextureRect().height);
		});

	world->each<BoxCollider, Transform>(
		[&](ECS::Entity* touchingEntity,
			ECS::ComponentHandle<BoxCollider> touchingBox,
			ECS::ComponentHandle<Transform> transform
			) -> void
		{
			world->each<BoxCollider>(
				[&](ECS::Entity* touchedEntity,
					ECS::ComponentHandle<BoxCollider> touchedBox
					) -> void
				{
					// Statement to avoid comparing the same entity to itself
					if (touchingEntity->getEntityId() == touchedEntity->getEntityId() ||
						IsColliding(touchingBox, touchedBox) == false)
					{
						return;
					}

					// Final collision check
					CheckCollisionSides(touchingEntity, touchedEntity);
				});
		});

	world->each<Transform>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle<Transform> transform
			) -> void
		{
			transform->Move();
		});
=======
	if (States::getPausedState() == false)
	{
		// TODO: Paused state
		world->each<BoxCollider, Sprite2D, Transform>(
			[&](ECS::Entity* entity,
				ECS::ComponentHandle<BoxCollider> collider,
				ECS::ComponentHandle<Sprite2D> sprite,
				ECS::ComponentHandle<Transform> transform
				) -> void
			{
				collider->Update(transform->xPos, transform->yPos, sprite->picture.getTextureRect().width, sprite->picture.getTextureRect().height);
			});

		world->each<BoxCollider, Transform>(
			[&](ECS::Entity* touchingEntity,
				ECS::ComponentHandle<BoxCollider> touchingBox,
				ECS::ComponentHandle<Transform> transform
				) -> void
			{
				world->each<BoxCollider>(
					[&](ECS::Entity* touchedEntity,
						ECS::ComponentHandle<BoxCollider> touchedBox
						) -> void
					{
						// Statement to avoid comparing the same entity to itself
						if (touchingEntity->getEntityId() == touchedEntity->getEntityId() ||
						IsColliding(touchingBox, touchedBox) == false)
						{
							return;
						}

		// Final collision check
		CheckCollisionSides(touchingEntity, touchedEntity);
					});
			});

		world->each<Transform>(
			[&](ECS::Entity* entity,
				ECS::ComponentHandle<Transform> transform
				) -> void
			{
				transform->Move();
			});
	}
>>>>>>> c035129 (Created Tile map Struct)
}
