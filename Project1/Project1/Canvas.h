#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>

class Tile
{
public:
	Tile();
	Tile(size_t x, size_t y);
	Tile(size_t x, size_t y, char value);

	void setMarked(int newValue);
	char getMarked();
	char getValue();
	void setValue(char value);
	void flip();

private:
	size_t x;
	size_t y;
	char value; //range from 0-8 or B
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

	void flipTile(int x, int y);

	~Canvas();

private:
	size_t width;
	size_t length;
	size_t numOfBombs;
	void initialize();

	Tile ** board;
	bool activeGame = true;
	
};



#endif // !canvas.h
