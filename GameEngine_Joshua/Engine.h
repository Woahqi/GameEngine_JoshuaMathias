#pragma once

#include <iostream>
#include "ECS.h"
#include "sfml/graphics.hpp"
#include "Components.h"
#include "Systems/RenderingSystem.h"
#include "Systems/AnimationSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/InputSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Interface/PauseMenu.h"
#include "Interface/States.h"
#include "Interface/MainCamera.h"
#include "Tile.h"

//keep function pointer into entity to improve code
typedef void(*CallbackEntity)(ECS::Entity*);

class PauseMenu;
class MainCamera;

class Engine
{
public:
	ECS::World* world = nullptr;
	sf::RenderWindow* window = nullptr;
	PauseMenu *pauseMenu = nullptr;
	MainCamera* mainCamera = nullptr;
	
	void Start(sf::RenderWindow* win);
	static Engine& GetInstance();
	void AddSystem(ECS::EntitySystem* newSys);

private:
	bool bQuit;

	Engine();	// Constructor: Create an Object,	ex: Want all cars to be red, set car to red in Constructor/ TLDR; Sets all the initial values in a class on creation
	// Require to prevent the reference from the copied, move, or assigned.
	Engine(Engine& copy); // Hide Copy Constructer, so the engine will not be able to be copied.
	Engine(Engine&& other); //Hide copy constructer, so the engine will not be able to be Moved.
	Engine& operator=(Engine& copy); // Hide assignment Operator, wont be able top set engine to Something.
	~Engine();			// Destructor Delete Object | Opposite
	void Update();
	void OnPaused();
};

