#include<iostream>
#include "ConsoleFunctions.h"
using namespace std;

int main()
{
	ConsoleFunctions cf;
	cf.SetCursorAt(10, 10);
	cout << "Aasdkfh'ibfk;jnfagjagjfa'kja";
	char c = cf.ReadFrom(16, 10);
	
	//Setting up the color
	cf.SetColor(red, yellow);
	cf.SetCursorAt(10, 15);
	cout << c;
	cf.SetColor(15, 0); //original colors
	cout << "             B\n";

	//set title
	cf.setConsoleTitle("OOP is Fun");

	int rows = 0; int cols = 0;
	cf.getConsoleWindowSize(rows, cols);
	cout << "rows : " << rows << " cols: " << cols;

	cf.SetCursorAt(cols, rows);
	cout << "G";

	//Detect events
	char testChar=' ';
	point p;
	int i=0;
	while (1)
	{
		cf.DetectEvent();
		if (cf.IsKeyPressEvent(testChar))
		{
			if (testChar == 'b')
				break;
			else
				cout << testChar;
		}
		else if (cf.getMousePosition(p))
		{
			/*cf.SetCursorAt(p.x, p.y);
			cf.SetColor((i++)%15 +1 , (++i) % 15 +1);
			cout << 'A';*/
		}
		else if(cf.IsMouseLeftClickEvent(p))
		{ 
			cf.SetCursorAt(p.x, p.y);
			cf.SetColor((i++) % 15 + 1, (i++) % 15 + 1);
			cout << 'A';
		}
	}

	//Sleep(5000);

}
