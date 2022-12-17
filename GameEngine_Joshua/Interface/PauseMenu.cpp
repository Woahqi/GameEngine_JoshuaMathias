#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow* window)
{
	States::setPausedState(false);
	this->InitButtons();
}

void PauseMenu::Update(sf::Event event, float deltatime, sf::RenderWindow* window)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::P) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Pause))
		{
			States::setPausedState(States::getPausedState() == false);
		}
	}
	if (States::getPausedState() == true)
	{
		ButtonMap::GetMap()["RESUME"]->Update(event, deltatime);
		ButtonMap::GetMap()["LOAD"]->Update(event, deltatime);
		ButtonMap::GetMap()["SAVE"]->Update(event, deltatime);
		ButtonMap::GetMap()["QUIT"]->Update(event, deltatime);
		if (ButtonMap::GetMap()["RESUME"]->bClicked == true)

		{
			States::setPausedState(false);
			ButtonMap::GetMap()["RESUME"]->bClicked = false;
<<<<<<< HEAD
			
=======

>>>>>>> c035129 (Created Tile map Struct)
		}
		if (ButtonMap::GetMap()["QUIT"]->bClicked == true)
		{
			this->Quit(window);
			ButtonMap::GetMap()["RESUME"]->bClicked = false;
		}
	}
<<<<<<< HEAD
	
=======

>>>>>>> c035129 (Created Tile map Struct)
}

void PauseMenu::Render(sf::RenderWindow* window, float deltatime, sf::Vector2f resumePosition)
{
	sf::Font arial;
	arial.loadFromFile("../debug/Fonts/arial.ttf");
	sf::Vector2f sizeOffset = ButtonMap::GetMap()["RESUME"]->buttonBG.getSize() / 2.0f;


	ButtonMap::GetMap()["RESUME"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -80) - sizeOffset);
	ButtonMap::GetMap()["RESUME"]->buttonText.setFont(arial);
	ButtonMap::GetMap()["RESUME"]->buttonText.setPosition(ButtonMap::GetMap()["RESUME"]->buttonBG.getPosition());
	ButtonMap::GetMap()["RESUME"]->Highlight(window);
	ButtonMap::GetMap()["RESUME"]->Render(window, deltatime);

	ButtonMap::GetMap()["LOAD"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -40) - sizeOffset);
	ButtonMap::GetMap()["LOAD"]->buttonText.setFont(arial);
	ButtonMap::GetMap()["LOAD"]->buttonText.setPosition(ButtonMap::GetMap()["LOAD"]->buttonBG.getPosition());
	ButtonMap::GetMap()["LOAD"]->Highlight(window);
	ButtonMap::GetMap()["LOAD"]->Render(window, deltatime);

	ButtonMap::GetMap()["SAVE"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 0) - sizeOffset);
	ButtonMap::GetMap()["SAVE"]->buttonText.setFont(arial);
	ButtonMap::GetMap()["SAVE"]->buttonText.setPosition(ButtonMap::GetMap()["SAVE"]->buttonBG.getPosition());
	ButtonMap::GetMap()["SAVE"]->Highlight(window);
	ButtonMap::GetMap()["SAVE"]->Render(window, deltatime);


	ButtonMap::GetMap()["QUIT"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 40) - sizeOffset);
	ButtonMap::GetMap()["QUIT"]->buttonText.setFont(arial);
	ButtonMap::GetMap()["QUIT"]->buttonText.setPosition(ButtonMap::GetMap()["QUIT"]->buttonBG.getPosition());
	ButtonMap::GetMap()["QUIT"]->Highlight(window);
	ButtonMap::GetMap()["QUIT"]->Render(window, deltatime);

	window->display();
}

void PauseMenu::InitButtons()
{
<<<<<<< HEAD

=======
	sf::Vector2f size(125, 35);

	ButtonMap::GetMap().insert(
		{
			"RESUME", new Button(size, sf::Color(100, 100, 100, 255),"RESUME GAME")
		});
	ButtonMap::GetMap().insert(
		{
			"LOAD", new Button(size, sf::Color(100, 100, 100, 255),"LOAD TILE MAP")
		});
	ButtonMap::GetMap().insert(
		{
			"SAVE", new Button(size, sf::Color(100, 100, 100, 255),"SAVE TILE MAP")
		});
	ButtonMap::GetMap().insert(
		{
			"QUIT", new Button(size, sf::Color(100, 100, 100, 255),"QUIT GAME")
		});
>>>>>>> c035129 (Created Tile map Struct)
}

void PauseMenu::Quit(sf::RenderWindow* window)
{
<<<<<<< HEAD

=======
	window->close();
>>>>>>> c035129 (Created Tile map Struct)
}
