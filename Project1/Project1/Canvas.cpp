#include "Canvas.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tile::Tile()
{
	x = y = value = 0;
}

Tile::Tile(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
	this->value = 0;
}

Tile::Tile(size_t x, size_t y, char value)
{
	this->x = x;
	this->y = y;
	this->value = value;
}

void Tile::setMarked(int newValue)
{
	this->markedValue = newValue;
}

int Tile::getValue()
{
	return value;
}

void Tile::setValue(char value)
{
	this->value = value;
}

Canvas::Canvas()
{
	this->width = 10;
	this->length = 10;
	this->numOfBombs = 10;

	initialize();
}

Canvas::Canvas(int numOfBombs)
{
	this->width = 0;
	this->length = 0;
	this->numOfBombs = 0;
}

Canvas::Canvas(int width, int length)
{
	this->width = 0;
	this->length = 0;
	this->numOfBombs = 0;
}

Canvas::Canvas(int width, int length, int numOfBombs)
{
	this->width = 0;
	this->length = 0;
	this->numOfBombs = 0;
}

Canvas::Canvas(const Canvas&)
{
	this->width = 0;
	this->length = 0;
	this->numOfBombs = 0;
}

Canvas& Canvas::operator=(const Canvas& c)
{
	// TODO: insert return statement here
	return *this;
}

Canvas::~Canvas()
{
}

void Canvas::initialize()
{
	//initialize board;
	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = 0; j < length; ++j)
		{
			board[i][j] = Tile(i, j);
		}
	}

	size_t tiles = length * width;
	size_t assignedBombs = 0;

	while (assignedBombs < numOfBombs)
	{
		int x = rand() % 10;
		int y = rand() % 10;

		if (board[x][y].getValue() != 'B')
		{
			++assignedBombs;
			board[x][y].setValue('B');
		}

		//update surrounding tiles
		if (x - 1 > 0 && board[x - 1][y].getValue() != 'B') //left
		{
			board[x - 1][y].setValue(board[x - 1][y].getValue() + 1);
		}
		if (y - 1 > 0 && board[x][y - 1].getValue() != 'B') //up
		{
			board[x][y - 1].setValue(board[x][y - 1].getValue() + 1);
		}
		if (x - 1 > 0 && y - 1 > 0 && board[x - 1][y - 1].getValue() != 'B') //up-left
		{
			board[x - 1][y - 1].setValue(board[x - 1][y - 1].getValue() + 1);
		}
		if (x + 1 < width && board[x + 1][y].getValue() != 'B') //right
		{
			board[x + 1][y].setValue(board[x + 1][y].getValue() + 1);
		}
		if (x + 1 < width && y + 1 < length && board[x + 1][y + 1].getValue() != 'B') //right-down
		{
			board[x + 1][y + 1].setValue(board[x + 1][y + 1].getValue() + 1);
		}
		if (x - 1 > 0 && board[x - 1][y].getValue() != 'B')
		{
			board[x - 1][y].setValue(board[x - 1][y].getValue() + 1);
		}
		if (x - 1 > 0 && board[x - 1][y].getValue() != 'B')
		{
			board[x - 1][y].setValue(board[x - 1][y].getValue() + 1);
		}
		if (x - 1 > 0 && board[x - 1][y].getValue() != 'B')
		{
			board[x - 1][y].setValue(board[x - 1][y].getValue() + 1);
		}
	}
}

ostream& operator<<(ostream& out, const Canvas& myCanvas)
{
	// TODO: insert return statement here
	return out;
}