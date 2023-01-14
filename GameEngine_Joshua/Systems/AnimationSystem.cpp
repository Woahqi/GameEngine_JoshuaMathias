#include "AnimationSystem.h"

AnimationSystem::AnimationSystem() = default;


AnimationSystem::~AnimationSystem() = default;

void AnimationSystem::tick(ECS::World* world, float deltaTime)
{
	
	if (States::getPausedState() == false)
	{
		world->each<Animator, Sprite2D>(
			[&](ECS::Entity* entity,
				ECS::ComponentHandle<Animator> animator,
				ECS::ComponentHandle<Sprite2D> Sprite2D
				) -> void
			{
				animator->currentTime += deltaTime;
		if (animator->currentTime >= animator->nextFrameTime)
		{
			animator->currentTime = 0;
			animator->currentColumn = (animator->currentColumn + 1) % animator->totalColumns;
		}

		Sprite2D->picture.setTextureRect(
			sf::IntRect(
				animator->currentColumn * animator->spriteWidth, //left / right sides of sprite
				animator->currentRow * animator->spriteHeight, //top and bottom sides of sprite
				animator->spriteWidth,
				animator->spriteHeight
			));

			});
	}
		
}
