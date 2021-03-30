#include <SFML/Graphics.hpp>
#include <sstream>
#ifndef MENU_H
#define MENU_H
class Menu
{
	float width;
	float height;
	float positionX;
	float positionY;
	sf::RectangleShape menuShape, buttonShape[4], zasady, scoreBoard;
	sf::Texture texture_start, texture_zasady, texture_statystyki, texture_wyjscie, texture_menuZasady;
	int selectedItemIndex;
	sf::Text scoreText, toReturn;

public:
	Menu(float w, float h, float posX, float posY);
	void MoveDown();
	void MoveUp();
	void draw(sf::RenderWindow& window);
	void displayScores(sf::RenderWindow& window, sf::Font& font);
	int GetPressedItem();
	void DisplayZasady(sf::RenderWindow& window);
};
#endif
