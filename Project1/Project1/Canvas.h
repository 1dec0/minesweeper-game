#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>

class Tile
{
public:
	Tile();

	void setMarked(int newValue);
	int getValue();

	ostream& operator<<(ostream& out);

private:
	int x;
	int y;
	int value;
	int markedValue;
};

class Canvas
{
public:
	Canvas();
	Canvas(int numOfBombs);
	Canvas(int width, int length);
	Canvas(int width, int length, int numOfBombs);
	Canvas(const Canvas&);

	Canvas& operator=(const Canvas&); //assignment operator

	~Canvas();

private:
	int width;
	int length;

	int ** board; //Should this be Tile ** board;?

	int numOfBombs;
};


#endif // !canvas.h
