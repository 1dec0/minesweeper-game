#include <iostream>
#include <iomanip>
#include "Canvas.h"

using namespace std;

int main()
{
	int counter = 0;
	int result = 0;
	/*while (counter < 100 && result != 10)
	{
		result = rand() % 10;
		cout << result << endl;
		++counter;
	}
	/*
	char a = '0';
	char b = a + 1;
	cout << "a = " << a << ", b = " << b << '\n';

	int x = 10;
	bool left = x - 1 >= 0;

	cout << "x = " << x << ", left = " << left << '\n';*/

	Canvas myCanvas;
	//Canvas mySecondCanvas(myCanvas);

	cout << myCanvas << endl;

	/*Canvas secondCanvas;

	cout << secondCanvas << endl;*/

	system("pause");
	return 0;
}