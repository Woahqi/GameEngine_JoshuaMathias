#pragma once
#include "../engine.h"
class MovementSystem: public ECS::EntitySystem
{
	private:
		float timer{ 0.0f };
public:
	MovementSystem() = default;
	~MovementSystem() = default;
	void tick(ECS::World* world, float deltatime) override;
};

