#include"PlayingCard.h"


#pragma once
class Deck
{
	PlayingCard* deck[52];
	int size;
public:
	Deck();
	int getSize();
	bool IsEmpty();
	PlayingCard Remove(int i);
	~Deck();
};

