#include "Canvas.h"
#include <iostream>
#include <iomanip>

using namespace std;

Tile::Tile(char value) //Probably won't be used, can probably be deleted
{
	this->value = value;
}

void Tile::setMarked(char newValue)
{
	this->markedValue = newValue;
}

char Tile::getMarked()
{
	return markedValue;
}

char Tile::getValue()
{
	return value;
}

void Tile::setValue(char value)
{
	this->value = value;
}

/*
 * Returns value, or 'X' if already flipped
 */

char Tile::flip()
{
	if (!flipped)
	{
		flipped = true;
		markedValue = value;
		return value;
	}
	else
	{
		cerr << "This Tile is already flipped." << endl;
		return 'X';
	}
}

char Tile::getFlipped()
{
	return flipped;
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

Canvas::Canvas(const Canvas& other) //done
{
	this->width = other.width;
	this->length = other.length;
	this->numOfBombs = other.numOfBombs;

	//Different Initialization
	board = new Tile * [width];
	for (size_t i = 0; i < width; ++i)
	{
		board[i] = new Tile[length];
		for (size_t j = 0; j < length; ++j)
		{
			board[i][j] = other.board[i][j];
		}
	}
}

Canvas& Canvas::operator=(const Canvas& c) //I feel like this could be optimized better, go look at other code
{
	for (size_t i = 0; i < width; ++i)
	{
		delete[] board[i]; //This
		//board[i] = nullptr;
	}
	delete[] board;

	this->length = c.length;
	this->width = c.width;
	this->numOfBombs = c.numOfBombs;

	this->board = new Tile*[width];
	for (size_t i = 0; i < width; ++i)
	{
		board[i] = new Tile[length];
	}

	for (size_t i = 0; i < width; ++i)
	{
		for (size_t j = 0; j < length; ++j)
		{
			this->board[i][j] = c.board[i][j];
			//cout << this->board[i][j].getValue() << c.board[i][j].getValue();
		}
	}


	return *this;
}

/*
 * Returns value of board[x][y]
 */

char Canvas::flipTile(int x, int y)
{	
	 char value = board[x][y].flip();
	 ++flippedTiles;

	 //cout << "x, y, width, legnth: " << x << y << width << length << '\n';

	 if (value == '0')
	 {
		 //flip surrounding tiles
		 for (int i = x - 1; i <= x + 1; ++i)
		 {
			 for (int j = y - 1; j <= y + 1; ++j)
			 {
				 if (!(i == x && j == y) 
					 && i >= 0 && i < width 
					 && j >= 0 && j < length)
				 {
					 if (!checkTileFlipped(i, j))
					 {
						 flipTile(i, j);
					 }
				 }
			 }
		 }
	 }

	 return value;
}

bool Canvas::checkTileFlipped(int x, int y)
{
	return board[x][y].getFlipped();
}

void Canvas::markTileBomb(int x, int y)
{
	board[x][y].setMarked('b');
}

Canvas::~Canvas() //Finished
{
	for (size_t i = 0; i < width; ++i)
	{
		delete[] board[i]; //This
		//board[i] = nullptr;
	}
	delete[] board;
	//board = nullptr;
}

void Canvas::initialize() //helper function for constructors
{
	board = new Tile * [width];

	for (size_t i = 0; i < width; ++i)
	{
		board[i] = new Tile[length]; //defaulted with value=0
	}

	//cout << *this; //temporary

	/*for (size_t i = 0; i < width; ++i) //useless code???
	{
		for (size_t j = 0; j < length; ++j)
		{
			board[i][j] = Tile(i, j); //new Tile(i, j);???
		}
	}*/

	size_t tiles = length * width;
	if (numOfBombs >= tiles)
	{
		cerr << "Too many bombs to fit on the board, numOfBombs has been set to 33% of the board." << endl;
		numOfBombs = tiles / 3;
	}

	size_t assignedBombs = 0;

	srand(time(NULL));
	while (assignedBombs < numOfBombs)
	{
		int x = int(rand() % width);
		int y = int(rand() % length);

		//cout << "Current x & y" << x << ' ' << y << endl;

		if (board[x][y].getValue() != 'B')
		{
			++assignedBombs;
			board[x][y].setValue('B');


			//update surrounding tiles

			bool left = x >= 1;
			bool right = x + 1 < int(width);
			bool up = y >= 1;
			bool down = y + 1 < int(length);

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
			//out << myCanvas.board[i][j].getValue() << ' '; //for testing
			out << myCanvas.board[j][i].getMarked() << ' ';
		}
		out << '\n';
	}

	out << string(myCanvas.width * 2 + 1, '=') << '\n'; //border

	return out;
}

std::ostream& operator<<(std::ostream& out, const Game& myGame)
{
	out << myGame.myCanvas;
	return out;
}


//-------------------------------------------------------------------


Game::Game()
{
	//cout << myCanvas;
}

Game::Game(size_t numOfBombs)
{
	myCanvas = Canvas(numOfBombs);
	//cout << myCanvas;
}

Game::Game(size_t width, size_t length)
{
	myCanvas = Canvas(width, length);
	//cout << myCanvas;
}

Game::Game(size_t width, size_t length, size_t numOfBombs)
{
	myCanvas = Canvas(width, length, numOfBombs);
}

void Game::selectTile(size_t x, size_t y)
{
	if (activeGame)
	{
		char flip = myCanvas.flipTile(x, y); //error message if already flipped
		if (flip == 'B')
		{
			activeGame = false;
			cout << "You hit a bomb, sorry! Try again.\n";
			cout << myCanvas;
		}
		else if (myCanvas.flipTileCount() == 
			myCanvas.getWidth() * myCanvas.getLength() - myCanvas.getNumOfBombs())
		{
			activeGame = false;
			cout << myCanvas;
			cout << "You have uncovered all available tiles! You win the game!" << endl;
		}
	}
	else
	{
		cerr << "Game is already over!\n";
	}
	//cout << myCanvas << endl;
}

void Game::markAsBomb(size_t x, size_t y)
{
	myCanvas.markTileBomb(x, y);
	//cout << myCanvas;
}

bool Game::isGameActive()
{
	return activeGame;
}
