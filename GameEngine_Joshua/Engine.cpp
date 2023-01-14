#include "Engine.h"


Engine& Engine::GetInstance()
{
	static Engine instance;
	return instance;

	// Get only instance of the engine so it can Start.
}

void Engine::AddSystem(ECS::EntitySystem* newSys)
{
	world->registerSystem(newSys);
	world->enableSystem(newSys);
}




void Engine::Start(sf::RenderWindow* win)
{

	bQuit = false;
	window = win;
	this->pauseMenu = new PauseMenu(win);
	this->mainCamera = new MainCamera(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));
	//Run the Program, as long as the window is Open
	//Variable is Data (Integer, Booleans, CAN be another class/Instance), Function is an action (verbs etc) Add a () to the end of it
	while (window->isOpen() == true) // -> is Equivalent to . for pointers , ex window.isopen = window->isOpen
	{
		Update();
	}
}

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::Update()
{
	sf::Event event;
	while (window->pollEvent(event) == true)
	{
		// Close Requested Event
		if (event.type == sf::Event::Closed)
		{
			window->close();

		}
	}

	world->tick(10.0f);
	this->mainCamera->Update(world, 10.0f, window);

	if (States::getPausedState() == true)
	{
		this->OnPaused();	
	}
}

void Engine::OnPaused()
{
	
	this->pauseMenu->Render(window, 10.0f, this->mainCamera->cameraView.getCenter());
}
