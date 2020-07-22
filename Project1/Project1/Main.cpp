#include <iostream>
#include <iomanip>
#include "Canvas.h"

using namespace std;

int main()
{
	/*Game myGame(10, 50, 10);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << "i: " << i << ", j: " << j << endl;
			myGame.selectTile(i, j);
			cout << myGame << endl;
			if (!myGame.isGameActive())
				break;
		}
	}

	const int length = 10;
	const int width = 20;
	int* arr[width];
	for (size_t i = 0; i < width; ++i)
	{
		arr[i] = new int[length];
	}
 
	int a = 0;
	for (size_t i = 0; i < length; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			arr[j][i] = ++a;
		}
	}

	for (size_t i = 0; i < length; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			cout << ' ' << arr[j][i];
		}
		cout << endl;
	}
	cout << arr[5][9];
	*/
	

	//This is my actual main code
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
		//cout << "Enter -1 to cancel decision" << endl;
			
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
	
	
	
	
	
	
	
	
	
	
	/*int counter = 0;
	int result = 0;
	while (counter < 100 && result != 10)
	{
		result = rand() % 10;
		cout << result << endl;
		++counter;
	}
	
	char a = '0';
	char b = a + 1;
	cout << "a = " << a << ", b = " << b << '\n';

	int x = 10;
	bool left = x - 1 >= 0;

	cout << "x = " << x << ", left = " << left << '\n';

	Canvas myCanvas;
	//Canvas mySecondCanvas(myCanvas);

	cout << myCanvas << endl;

	Canvas secondCanvas;
	secondCanvas = myCanvas;

	cout << secondCanvas << endl;

	Tile firstTile(1, 2, '3');
	Tile secondTile = firstTile;

	cout << firstTile.getValue() << secondTile.getValue() << endl;

	//Canvas myCanvas;
	//Canvas secondCanvas(myCanvas);
	//cout << myCanvas << secondCanvas;

	Game newGame;
	newGame.markAsBomb(0, 0);
	newGame.selectTile(0, 0);
	for (size_t i = 0; i < 10; ++i)
	{
		for (size_t j = 0; j < 10; ++j)
		{
			newGame.selectTile(i, j);
		}
	}*/



	system("pause");
	return 0;
}