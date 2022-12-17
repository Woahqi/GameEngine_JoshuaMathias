#pragma once
#include "../Engine.h"
class MainCamera
{
public:
	sf::View cameraView;
	MainCamera() = default;
	MainCamera(sf::Vector2f pivot);
	~MainCamera();
	void Update(ECS::World* world, float deltatime, sf::RenderWindow* window);
		
};

