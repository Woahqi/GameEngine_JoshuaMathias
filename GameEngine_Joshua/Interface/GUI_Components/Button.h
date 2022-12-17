#pragma once
#include "../../Engine.h"
class Button
{
public:
	sf::RectangleShape buttonBG;
	sf::Text buttonText;
	bool bPressed;
	bool bClicked;
	bool bReleased;
	bool bHighlighted;
private:
	sf::Color defaultColor;
	sf::Color highlightedColor;
public:
	Button() = default;
	Button(sf::Vector2f size, sf::Color color, std::string text);
	~Button() = default;
	
public:
	bool IsHighlighted();
	void Highlight(sf::RenderWindow* window);
	void Update(sf::Event event, float deltatime);
	void Render(sf::RenderWindow* window, float deltatime);
	void CheckPressed(sf::Event event);
};

