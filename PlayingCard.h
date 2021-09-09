#include<iostream>
#include<io.h>
#include <fcntl.h>
#include"ConsoleFunctions.h"
using namespace std;




#pragma once

class PlayingCard
{
	int rank;
	int suit;
	char color;
	bool faceUp;
	bool top;


public:
	static const int Diamond;
	static const int Club;
	static const int Spade;
	static const int Heart;
	PlayingCard(int rank = 1, int suit = 0);
	void display(int x, int y);
	bool isFaceUp();
	void setFaceUp(bool);
	bool isTop();
	void setTop(bool);
	char getColor();
	int getSuit();
	int getRank();
};

