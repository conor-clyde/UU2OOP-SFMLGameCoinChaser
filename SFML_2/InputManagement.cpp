#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


void checkIfAtStart()
{

}

void restartGame(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, bool& downInBuffer, bool& leftInBuffer, bool& rightInBuffer, std::string previousScore, sf::Text& txtPreviousScore, sf::Font font, sf::RenderWindow&_window)
{

	if (playerIndexX == 860 && playerIndexY >= 810 && playerIndexY <= 840)
	{
		playerIndexX = 15;
		playerIndexY = 75;

		upFlag = false;
		downFlag = false;
		leftFlag = false;
		rightFlag = false;

		upInBuffer = false;
		downInBuffer = false;
		leftInBuffer = false;
		rightInBuffer = false;

	
	}


}

void moveUpNextTurn(float& playerIndexX, float& playerIndexY, bool& upFlag, bool& downFlag, bool& leftFlag, bool& rightFlag, bool& upInBuffer, std::vector<std::vector<int>>& mapGrid)
{
	upFlag = false;
	downFlag = false;
	rightFlag = false;
	leftFlag = false;
	playerIndexY -= 0.3;


	if (!mapGrid[((playerIndexY - 14) - 1) / 30][playerIndexX / 30] && upInBuffer == true)
		upInBuffer = false;
}

void moveDownNextTurn(float& playerIndexX, float& playerIndexY, bool& downFlag, bool& upFlag, bool& leftFlag, bool&  rightFlag, bool& downInBuffer, std::vector<std::vector<int>>& mapGrid)
{
	upFlag = false;
	downFlag = false;
	rightFlag = false;
	leftFlag = false;
	playerIndexY += 0.3;
	

	if (!mapGrid[((playerIndexY + 14) + 1) / 30][playerIndexX / 30] && downInBuffer == true)
		downInBuffer = false;
}

void moveUp(float& playerIndexX, float& playerIndexY, bool& upFlag, std::vector<std::vector<int>>& mapGrid)
{
	if (mapGrid[((playerIndexY - 14) - 1) / 30][playerIndexX / 30])
	{
		playerIndexY -= 03;
	}
	else
		upFlag = false;
}

void moveDown(float& playerIndexX, float& playerIndexY, bool& downFlag, std::vector<std::vector<int>>& mapGrid)
{
	//if we aren't in the bottom row and the cell below us doesn't contain an obstacle then we can move down
	if (mapGrid[((playerIndexY + 14) + 1) / 30][playerIndexX / 30])
	{
		playerIndexY += 045;
	}
	else
		downFlag = false;

}


void moveLeft(float& playerIndexX, float& playerIndexY, bool& leftFlag, std::vector<std::vector<int>>& mapGrid)
{
	//if we aren't in the left-most column and the cell to our left doesn't contain an obstacle then we can move left
	if (mapGrid[playerIndexY / 30][((playerIndexX - 14) + 1) / 30])
	{
		playerIndexX -= 0.3;
	}
	else
		leftFlag = false;
}

void moveRight(float& playerIndexX, float& playerIndexY, bool& rightFlag, std::vector<std::vector<int>>& mapGrid)
{
	//if we aren't in the right-most column and the cell to our right doesn't contain an obstacle then we can move right
	if (mapGrid[playerIndexY / 30][((playerIndexX + 14) + 1) / 30])
	{
		playerIndexX += 0.3;
	}
	else
		rightFlag = false;
}

