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
	char getValue();
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
	Canvas(size_t numOfBombs);
	Canvas(size_t width, size_t length);
	Canvas(size_t width, size_t length, size_t numOfBombs);
	Canvas(const Canvas&);

	friend std::ostream& operator<<(std::ostream& out, const Canvas& myCanvas);

	Canvas& operator=(const Canvas& c); //assignment operator

	~Canvas();

private:
	size_t width;
	size_t length;
	size_t numOfBombs;
	void initialize();

	Tile ** board;

	
};



#endif // !canvas.h
