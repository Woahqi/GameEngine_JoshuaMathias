#pragma once
#include "engine.h"
#include "Entity.h"
class Dummy: public Entity
{
public:
	Dummy() = default;
	Dummy(std::string picture, sf::Vector2f location);
	~Dummy() = default;

	
};

