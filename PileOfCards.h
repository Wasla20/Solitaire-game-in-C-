#include"PlayingCard.h"


#pragma once

class PileOfCards
{
	PlayingCard* pile;
	int top;
	int size;
	point startPt;
	point endPt;
public:
	PileOfCards(int);
	PileOfCards(PileOfCards&);
	PlayingCard& Peek();
	PlayingCard Remove();
	void Add(PlayingCard);
	bool IsEmpty();
	bool IsFull();
	int getTop();
	void setStartPt(int x, int y);
	point getStartPt();
	void setEndPt(int x, int y);
	point getEndPt();
	PileOfCards& operator=(const PileOfCards& poc);
	PlayingCard viewCard(int i);
	void SimpleDisplay();
	void CascadingDisplay();
	void setSize(int);
	~PileOfCards();
};

