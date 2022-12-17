#pragma once
#include "GUI_Components/ButtonMap.h"
#include "States.h"
class PauseMenu
{
public:
	PauseMenu() = default;
	PauseMenu(sf::RenderWindow* window);
	~PauseMenu() = default;

public:
	void Update(sf::Event event, float deltatime, sf::RenderWindow* window);
	void Render(sf::RenderWindow* window, float deltatime, sf::Vector2f resumePosition);

private:
	void InitButtons();
	void Quit(sf::RenderWindow* window);
};

