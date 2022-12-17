#pragma once
#include "../ECS.h"
#include "../Engine.h"
#include "../Components.h"

class AnimationSystem: public ECS::EntitySystem
{
	public:
		AnimationSystem();

		~AnimationSystem();
private:
	void tick(ECS::World* world, float deltaTime) override;
		
};

