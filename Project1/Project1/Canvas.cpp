#include "Canvas.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tile::Tile() //This should never be used
{
	x = y = value = 0;
}

Tile::Tile(size_t x, size_t y) //Used as a default for ALL tiles
{
	this->x = x;
	this->y = y;
	this->value = 0;
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
		delete[] board[i];	
	}
	delete[] board;
}

void Canvas::initialize()
{
	//initialize board;
	//Tile * board = new Tile[length][width];

	for (size_t i = 0; i < width; ++i)
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
		size_t x = size_t(rand() % 10);
		size_t y = size_t(rand() % 10);

		if (board[x][y].getValue() != 'B')
		{
			++assignedBombs;
			board[x][y].setValue('B');
		}

		//update surrounding tiles

		bool left = x - 1 >= 0;
		bool right = x + 1 < width;
		bool up = y - 1 >= 0;
		bool down = y + 1 < length;


		if (left && board[x - 1][y].getValue() != 'B') //left
		{
			board[x - 1][y].setValue(board[x - 1][y].getValue() + 1);
		}
		if (up && board[x][y - 1].getValue() != 'B') //up
		{
			board[x][y - 1].setValue(board[x][y - 1].getValue() + 1);
		}
		if (up && left && board[x - 1][y - 1].getValue() != 'B') //up-left
		{
			board[x - 1][y - 1].setValue(board[x - 1][y - 1].getValue() + 1);
		}
		if (right && board[x + 1][y].getValue() != 'B') //right
		{
			board[x + 1][y].setValue(board[x + 1][y].getValue() + 1);
		}
		if (right && down && board[x + 1][y + 1].getValue() != 'B') //right-down
		{
			board[x + 1][y + 1].setValue(board[x + 1][y + 1].getValue() + 1);
		}
		if (left && down && board[x - 1][y + 1].getValue() != 'B') //left-down
		{
			board[x - 1][y + 1].setValue(board[x - 1][y + 1].getValue() + 1);
		}
		if (down && board[x][y + 1].getValue() != 'B') //down
		{
			board[x][y + 1].setValue(board[x][y + 1].getValue() + 1);
		}
		if (right && up && board[x - 1][y + 1].getValue() != 'B') //right-up?
		{
			board[x - 1][y + 1].setValue(board[x - 1][y + 1].getValue() + 1);
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Canvas& myCanvas) //Not finished
{
	//out << string(myCanvas.width, '_') << '\n'; //border
	out << "test";



	return out;
}
