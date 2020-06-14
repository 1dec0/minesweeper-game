#include "Canvas.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tile::Tile() //This should never be used
{
	x = y = 0;
	value = '0';
}

Tile::Tile(size_t x, size_t y) //Used as a default for ALL tiles
{
	this->x = x;
	this->y = y;
	this->value = '0';
}

Tile::Tile(size_t x, size_t y, char value) //Probably won't be used, can probably be deleted
{
	this->x = x;
	this->y = y;
	this->value = value;
}

void Tile::setMarked(int newValue)
{
	this->markedValue = newValue;
}

char Tile::getValue()
{
	return value;
}

void Tile::setValue(char value)
{
	this->value = value;
}



//-------------------------------------------------------------------



Canvas::Canvas()
{
	this->width = 10;
	this->length = 10;
	this->numOfBombs = 10;

	initialize();
}

Canvas::Canvas(size_t numOfBombs)
{
	this->width = 10;
	this->length = 10;
	this->numOfBombs = numOfBombs;

	initialize();
}

Canvas::Canvas(size_t width, size_t length)
{
	this->width = width;
	this->length = length;
	this->numOfBombs = 10;

	initialize();
}

Canvas::Canvas(size_t width, size_t length, size_t numOfBombs)
{
	this->width = width;
	this->length = length;
	this->numOfBombs = numOfBombs;

	initialize();
}

Canvas::Canvas(const Canvas& other)
{
	this->width = other.width;
	this->length = other.length;
	this->numOfBombs = other.numOfBombs;

	initialize();
}

Canvas& Canvas::operator=(const Canvas& c) //Not finished
{
	// TODO: insert return statement here
	return *this;
}

Canvas::~Canvas() //Not finished
{
	for (size_t i = 0; i < length; ++i)
	{
		delete[] board[i]; //This
		//board[i] = nullptr;
	}
	delete[] board;
	//board = nullptr;/**/
}

void Canvas::initialize()
{
	board = new Tile * [length];

	for (size_t i = 0; i < length; ++i)
	{
		board[i] = new Tile[width];
	}

	for (size_t i = 0; i < width; ++i) //useless code???
	{
		for (size_t j = 0; j < length; ++j)
		{
			board[i][j] = Tile(i, j); //new Tile(i, j);???
		}
	}

	size_t tiles = length * width;
	size_t assignedBombs = 0;

	while (assignedBombs < numOfBombs)
	{
		int x = int(rand() % length);
		int y = int(rand() % width);

		if (board[x][y].getValue() != 'B')
		{
			++assignedBombs;
			board[x][y].setValue('B');


			//update surrounding tiles

			bool left = x - 1 >= 0;
			bool right = x + 1 < width;
			bool up = y - 1 >= 0;
			bool down = y + 1 < length;


			if (left && board[x - 1][y].getValue() != 'B') //left
			{
				//cout << "left" << endl;
				board[x - 1][y].setValue(board[x - 1][y].getValue() + 1);
				//cout << *this;
			}
			if (up && board[x][y - 1].getValue() != 'B') //up
			{
				//cout << "up" << endl;
				board[x][y - 1].setValue(board[x][y - 1].getValue() + 1);
				//cout << *this;
			}
			if (up && left && board[x - 1][y - 1].getValue() != 'B') //up-left
			{
				//cout << "up-left" << endl;
				board[x - 1][y - 1].setValue(board[x - 1][y - 1].getValue() + 1);
				//cout << *this;
			}
			if (right && board[x + 1][y].getValue() != 'B') //right
			{
				//cout << "right" << endl;
				board[x + 1][y].setValue(board[x + 1][y].getValue() + 1);
				//cout << *this;
			}
			if (right && down && board[x + 1][y + 1].getValue() != 'B') //right-down
			{
				//cout << "right-down" << endl;
				board[x + 1][y + 1].setValue(board[x + 1][y + 1].getValue() + 1);
				//cout << *this;
			}
			if (left && down && board[x - 1][y + 1].getValue() != 'B') //left-down
			{
				//cout << "left-down" << endl;
				board[x - 1][y + 1].setValue(board[x - 1][y + 1].getValue() + 1);
				//cout << *this;
			}
			if (down && board[x][y + 1].getValue() != 'B') //down
			{
				//cout << "left" << endl;
				board[x][y + 1].setValue(board[x][y + 1].getValue() + 1);
				//cout << *this;
			}
			if (right && up && board[x + 1][y - 1].getValue() != 'B') //right-up?
			{
				//cout << "right-up" << endl;
				board[x + 1][y - 1].setValue(board[x + 1][y - 1].getValue() + 1);
				//cout << *this;
			}
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Canvas& myCanvas) //Finished
{
	out << string(myCanvas.width * 2 + 1, '=') << '\n'; //border
	//out << "test";
	for (size_t i = 0; i < myCanvas.length; ++i)
	{
		out << ' ';
		for (size_t j = 0; j < myCanvas.width; ++j)
		{
			out << myCanvas.board[i][j].getValue() << ' ';
		}
		out << '\n';
	}

	out << string(myCanvas.width * 2 + 1, '=') << '\n'; //border

	return out;
}
