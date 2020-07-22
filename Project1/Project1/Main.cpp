#include <iostream>
#include <iomanip>
#include "Canvas.h"

using namespace std;

int main()
{		
	cout << "Enter the width of the board (if the value entered is less than 10, 10 will be used as default): ";
	int width;
	cin >> width;	
	if (width < 10)
		width = 10;


	cout << "Enter the height of the board (if the value entered is less than 10, 10 will be used as default): ";
	int height;
	cin >> height;
	if (height < 10)
		height = 10;

	cout << "Enter the number of bombs (if the value entered is less than 1, 10 will be used as default): ";
	int bombs;
	cin >> bombs;
	if (bombs < 1)
		bombs = 10;

	Game myGame(width, height, bombs);

	int input = 0;
	while (myGame.isGameActive())
	{
		cout << myGame;
		cout << "Inputs:" << endl;
		cout << "1: Flip selected tile" << endl;
		cout << "2: Mark selected tile as bomb" << endl;
			
		cout << "Enter your decision: ";
		cin >> input;

		if (input == 1)
		{
			size_t x, y;
			cout << "Enter the x value of the tile you want to flip (the top corner is 0, 0):";
			cin >> x;

			cout << "Enter the y value of the tile you want to flip (the top corner is 0, 0):";
			cin >> y;

			if (x < 0 || y < 0 || x >= width || y >= height)
			{
				cout << "The values entered for x and y were invalid. Please try again." << endl;
			}
			else
			{
				myGame.selectTile(x, y);
			}
		}
		else if (input == 2)
		{

			size_t x, y;
			cout << "Enter the x value of the tile you want to mark (the top corner is 0, 0):";
			cin >> x;

			cout << "Enter the y value of the tile you want to mark (the top corner is 0, 0):";
			cin >> y;

			if (x < 0 || y < 0 || x >= width || y >= height)
			{
				cout << "The values entered for x and y were invalid. Please try again." << endl;
			}
			else
			{
				myGame.markAsBomb(x, y);
			}
		}
		else
		{
			cout << "That input was invalid. Please try again." << endl;
		}
	}

	system("pause");
	return 0;
}