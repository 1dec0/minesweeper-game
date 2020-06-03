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
	int getValue();
	void setValue(char value);

private:
	size_t x;
	size_t y;
	char value; //range from 0-8 or B
	char markedValue = '*';
};

class Canvas
{
public:
	Canvas();
	Canvas(int numOfBombs);
	Canvas(int width, int length);
	Canvas(int width, int length, int numOfBombs);
	Canvas(const Canvas&);

	Canvas& operator=(const Canvas& c); //assignment operator

	~Canvas();

private:
	int width;
	int length;
	int numOfBombs;
	void initialize();

	Tile ** board; //Should this be Tile ** board;?

	
};


std::ostream& operator<<(std::ostream& out, const Canvas& myCanvas);

#endif // !canvas.h
