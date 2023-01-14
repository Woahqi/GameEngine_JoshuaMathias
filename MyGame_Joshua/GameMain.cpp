#include "SFML\Graphics.hpp"
#include "../GameEngine_Joshua/Engine.h"
#include "Entities/player.h"
#include "Entities/Dummy.h"

int main(int argc, char* args[])
{
	// Declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();
	// :: Navigates through Classes
	//Window Size and Title For Game Engine
	sf::RenderWindow window(sf::VideoMode(800, 600), "Best Game Ever");

	// Create the world for attaching entitys and systems to
	gameEngine.world = ECS::World::createWorld();

	ECS::Entity* background;
	//ECS::Entity* stickFigure;
	//ECS::Entity* tux;


	// add systems to the engine
	gameEngine.AddSystem(new RenderingSystem());
	gameEngine.AddSystem(new AnimationSystem());
	gameEngine.AddSystem(new InputSystem());
	gameEngine.AddSystem(new MovementSystem());
	gameEngine.AddSystem(new PhysicsSystem());


// Create and assign entitys to the world
	background = gameEngine.world->create();
	//stickFigure = gameEngine.world->create();
	//tux = gameEngine.world->create();
	// 
	//Create instances of entities

	Entity *player = new Player(sf::Vector2f(300, 300));
	Entity *dummy =  new Dummy("../debug/pics/OrangeBox.png", sf::Vector2f(400, 400));


	

	//assign components to entitys after creation.
	background->assign<Transform>(0, 0);
	background->assign<Sprite2D>("../debug/pics/bg.jpg");
	//stickFigure->assign<Transform>(300, 300);
	//stickFigure->assign<Sprite2D>("../debug/pics/herosheet.png");
	//stickFigure->assign<Animator>(32, 32, 200.0f, 4, 1);
	//tux->assign<Transform>(200, 200);
	//tux->assign<Sprite2D>("../debug/pics/tux_from_linux.png");
	//tux->assign<Animator>(56, 72, 2000.0f, 3, 9);
	//tux->get<Animator>()->currentRow = 0;

	std::cout << "entity number: " << background->getEntityId() << std::endl;
	//std::cout << "entity number: " << stickFigure->getEntityId() << std::endl;
	//std::cout << "entity number: " << tux->getEntityId() << std::endl;


	// pass window Reference to engine and start
	gameEngine.Start(&window);





	return 0;
}