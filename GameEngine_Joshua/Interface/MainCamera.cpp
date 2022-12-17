#include "MainCamera.h"

MainCamera::MainCamera(sf::Vector2f pivot)
{
	cameraView.setCenter(pivot);
}

MainCamera::~MainCamera()
{

}

void MainCamera::Update(ECS::World* world, float deltatime, sf::RenderWindow* window)
{
	if (States::getPausedState() == false)
	{
		cameraView.setSize(window->getSize().x, window->getSize().y);
		float cameraMoveSpeed = 0.1f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
		{
			cameraView.move(-cameraMoveSpeed * deltatime, 0);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
		{
			cameraView.move(cameraMoveSpeed * deltatime, 0);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true)
		{
			cameraView.move(0, -cameraMoveSpeed * deltatime);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true)
		{
			cameraView.move(0, cameraMoveSpeed * deltatime);

		}
		window->setView(cameraView);
	}
}
