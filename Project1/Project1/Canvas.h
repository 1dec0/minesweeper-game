#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>

class Tile
{
public:
	Tile() {} //default, no values changed
	Tile(char value);

	void setMarked(char newValue);
	char getMarked();
	char getValue();
	void setValue(char value);
	char flip();
	char getFlipped();

private:
	char value = '0'; //range from 0-8 or B
	char markedValue = '*';
	bool flipped = false;
};

class Canvas
{
public:
	Canvas();
	Canvas(size_t numOfBombs);
	Canvas(size_t width, size_t length);
	Canvas(size_t width, size_t length, size_t numOfBombs);
	Canvas(const Canvas&);

	friend std::ostream& operator<<(std::ostream& out, const Canvas& myCanvas);

	Canvas& operator=(const Canvas& c); //assignment operator

	char flipTile(int x, int y);
	bool checkTileFlipped(int x, int y);
	void markTileBomb(int x, int y);

	~Canvas();

private:
	void initialize();

	size_t width;
	size_t length;
	size_t numOfBombs;
	
	Tile ** board;	
};

class Game
{
public:
	Game();
	Game(size_t numOfBombs);
	Game(size_t width, size_t length);
	Game(size_t width, size_t length, size_t numOfBombs);

	void selectTile(size_t x, size_t y);
	void markAsBomb(size_t x, size_t y);

private:
	Canvas myCanvas;
	bool activeGame = true;
};

#endif // !canvas.h
