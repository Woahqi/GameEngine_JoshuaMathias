#include "Button.h"

Button::Button(sf::Vector2f size, sf::Color color, std::string text)
{
	this->bPressed = false;
	this->bClicked = false;
	this->bReleased = false;
	this->bHighlighted = false;
	this->defaultColor = color;
	this->highlightedColor = sf::Color(this->defaultColor.r + 50, this->defaultColor.g + 50, this->defaultColor.b + 50, this->defaultColor.a);
	this->buttonBG.setSize(size);
	this->buttonBG.setFillColor(defaultColor);
	this->buttonBG.setPosition(0, 0);
	this->buttonText.setCharacterSize(12);
	this->buttonText.setFillColor(sf::Color::White);
	this->buttonText.setPosition(this->buttonBG.getPosition().x / 2, this->buttonBG.getPosition().y / 2);
	this->buttonText.setString(text);


}

bool Button::IsHighlighted()
{

	return this->bHighlighted;

}

void Button::Highlight(sf::RenderWindow* window)
{
	this->bHighlighted = this->buttonBG.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
	if (this->bHighlighted == true)
	{
		this->buttonBG.setFillColor(this->highlightedColor);
	}
	else
	{
		this->buttonBG.setFillColor(this->defaultColor);
	}
}

void Button::Update(sf::Event event, float deltatime)
{
	this->CheckPressed(event);

}

void Button::Render(sf::RenderWindow* window, float deltatime)
{
	window->draw(this->buttonBG);
	window->draw(this->buttonText);
	window->display();

}

void Button::CheckPressed(sf::Event event)
{
	if (this->bHighlighted == false)
	{
		return;
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		this->bPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		if (this->bPressed == false)
		{
			this->bClicked = false;
		}

	}
	if (this->bPressed == true)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			this->bReleased = true;
			this->bClicked = true;
		}
	}
	else
	{
		this->bReleased = false;
		this->bClicked = false;
	}
	
}
