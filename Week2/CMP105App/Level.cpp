#include "Level.h"

std::string Coord;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	Coord = "Mouse: X" + std::to_string(input->getMouseX()) + " Y" + std::to_string(input->getMouseY());

	mousePos.setFont(font);
	mousePos.setString(Coord);
	mousePos.setFillColor(sf::Color::Red);
	mousePos.setCharacterSize(18);
	mousePos.setPosition(10, 10);

	m2Circle.setOutlineColor(sf::Color::Blue);
	m2Circle.setOutlineThickness(4);
	m2Circle.setFillColor(sf::Color::Black);
	m2Circle.setRadius(20);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{

	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "Forward" << std::endl;
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J); input->setKeyUp(sf::Keyboard::K); input->setKeyUp(sf::Keyboard::L);
		std::cout << "Combo" << std::endl;
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->~RenderWindow();
	}

	if (input->isMouseRDown())
	{
		input->setMouseRDown(false);
		m2Circle.setPosition(input->getMouseX()-20, input->getMouseY()-20);
	}
}

// Update game objects
void Level::update()
{
	Coord = "Mouse: X" + std::to_string(input->getMouseX()) + " Y" + std::to_string(input->getMouseY());
	mousePos.setString(Coord);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(mousePos);
	window->draw(m2Circle);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}