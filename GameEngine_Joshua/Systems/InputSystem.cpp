#include "InputSystem.h"

InputSystem::InputSystem(sf::RenderWindow* window)
{
	this->window = window;
}

void InputSystem::tick(ECS::World* world, float deltaTime)
{
	if (States::getPausedState() == false)
	{
		GetKeyEvents(world);
	}
}

void InputSystem::GetKeyEvents(ECS::World* world)
{
	world->each<InputController>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle<InputController> input)
		-> void
		{
			input->w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
			input->a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
			input->s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
			input->d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
			input->up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
			input->down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
			input->left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
			input->right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
			input->space = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
		});
		

}
