#include "menu.h"
#include <fstream>

using namespace std;

Menu::Menu(float w, float h, float  posX, float  posY)
{
	width = w;
	height = h;
	positionX = posX;
	positionY = posY;
	menuShape.setSize(sf::Vector2f(width, height));
	menuShape.setPosition(positionX, positionY);
	menuShape.setFillColor(sf::Color(76, 145, 65, 255));
	menuShape.setOutlineColor(sf::Color(28, 84, 045));
	menuShape.setOutlineThickness(10);
	selectedItemIndex = 0;

	
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::Black);
	toReturn.setCharacterSize(28);
	toReturn.setFillColor(sf::Color::Black);
	


	if (!texture_start.loadFromFile("./resources/images/start.png"))
	{
		// error...
	}
	buttonShape[0].setTexture(&texture_start);



	if (!texture_zasady.loadFromFile("./resources/images/zasadygry.png"))
	{
		// error...
	}

	buttonShape[1].setTexture(&texture_zasady);

	if (!texture_statystyki.loadFromFile("./resources/images/statystyki.png"))
	{
		// error...
	}

	buttonShape[2].setTexture(&texture_statystyki);

	if (!texture_wyjscie.loadFromFile("./resources/images/wyjscie.png"))
	{
		// error...
	}
	buttonShape[3].setTexture(&texture_wyjscie);

	for (int index = 0; index < 4; index++)
	{
		buttonShape[index].setSize(sf::Vector2f(160, 50));
		buttonShape[index].setOrigin(sf::Vector2f(80, 0));
		buttonShape[index].setPosition(positionX + width / 2, (positionY + 50) + 80 * index);
		buttonShape[index].setFillColor(sf::Color(150, 153, 146, 255));

	}
	buttonShape[selectedItemIndex].setFillColor(sf::Color(120, 133, 139, 255));

}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(menuShape);

	for (int i = 0; i < 4; i++)
	{
		window.draw(buttonShape[i]);
	}
}

void Menu::MoveUp()
{

	if (selectedItemIndex - 1 >= 0)
	{
		buttonShape[selectedItemIndex].setFillColor(sf::Color(150, 153, 146, 255));
		selectedItemIndex--;
		buttonShape[selectedItemIndex].setFillColor(sf::Color(120, 133, 139, 255));
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < 4)
	{
		buttonShape[selectedItemIndex].setFillColor(sf::Color(150, 153, 146, 255));
		selectedItemIndex++;
		buttonShape[selectedItemIndex].setFillColor(sf::Color(120, 133, 139, 255));
	}
}

int Menu::GetPressedItem() {
	return selectedItemIndex;
}

void Menu::DisplayZasady(sf::RenderWindow& window)
{
	zasady.setSize(sf::Vector2f(400, 400));
	zasady.setPosition(positionX, positionY);
	if (!texture_menuZasady.loadFromFile("./resources/images/menuZasady.png"))
	{
		// error...
	}
	zasady.setTexture(&texture_menuZasady);
	window.draw(zasady);
	window.display();
}

void Menu::displayScores(sf::RenderWindow& window, sf::Font &font) {

	std::ifstream ifs("./resources/scores.txt");
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));

	scoreBoard.setSize(sf::Vector2f(400, 400));
	scoreBoard.setPosition(positionX, positionY);
	scoreText.setPosition(positionX+20, positionY);
	toReturn.setPosition(positionX+5, positionY+340);
	scoreText.setFont(font);
	toReturn.setFont(font);
	scoreText.setString(content);
	toReturn.setString("Spacja - powrot do menu");
	window.draw(scoreBoard);
	window.draw(scoreText);
	window.draw(toReturn);
	window.display();
}