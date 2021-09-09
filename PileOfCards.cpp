#include "PileOfCards.h"
PileOfCards::PileOfCards(int size)
{
	this->size = size;
	pile = new PlayingCard[size];
	top = -1;
	startPt.x = 0;
	startPt.y = 0;
	endPt.x = 0;
	endPt.y = 0;
}
PileOfCards::PileOfCards(PileOfCards& obj)
{
	this->size = obj.size;
	this->pile = new PlayingCard[size];
	this->pile = obj.pile;
	this->top = obj.top;
	this->startPt = obj.startPt;
	this->endPt = obj.endPt;
}
PileOfCards& PileOfCards::operator=(const PileOfCards& poc)
{
	this->size = poc.size;
	this->startPt = poc.startPt;
	this->endPt = poc.endPt;
	this->top = poc.top;
	this->pile = NULL;
	this->pile = poc.pile;

	return *this;
}

PlayingCard& PileOfCards::Peek()
{

	return pile[top];

}
PlayingCard PileOfCards::Remove()
{
	if (!IsEmpty())
	{
		pile[top].setTop(false);
		top--;
		if (!IsEmpty())
		{
			pile[top].setTop(true);
			if (pile[top].isFaceUp() == false)
				pile[top].setFaceUp(true);
		}
		return pile[top + 1];
	}
	cout << "pile is empty\n";
	return PlayingCard();
}
void PileOfCards::Add(PlayingCard x)
{
	if (!IsFull())
	{
		top++;
		pile[top] = x;
		pile[top].setTop(true);
		if (top != 0)
			pile[top - 1].setTop(false);

	}
	else
	{
		cout << "Pile is full\n";
	}
}
bool PileOfCards::IsEmpty()
{
	if (top == -1)
	{
		return true;
	}
	return false;
}
bool PileOfCards::IsFull()
{
	if (top == (size - 1))
	{
		return true;
	}
	return false;
}
int PileOfCards::getTop()
{
	return top;
}
void PileOfCards::setStartPt(int x, int y)
{
	(this->startPt).x = x;
	(this->startPt).y = y;
}
point PileOfCards::getStartPt()
{
	return startPt;
}
void PileOfCards::setEndPt(int x, int y)
{
	(this->endPt).x = x;
	(this->endPt).y = y;
}
point PileOfCards::getEndPt()
{
	return endPt;
}

PlayingCard PileOfCards::viewCard(int i)
{

	return pile[i];

}

void PileOfCards::SimpleDisplay()
{
	if (IsEmpty())
	{
		int s = startPt.x;
		ConsoleFunctions c;
		c.SetCursorAt(startPt.y, startPt.x);
		c.SetColor(black, dark_green);
		for (int i = 0; i < 8; i++)
		{
			cout << "      ";
			c.SetCursorAt(startPt.y,++s );
		}
		return;
	}
	pile[top].display(startPt.x, startPt.y);
}

void PileOfCards::CascadingDisplay()
{
	if (IsEmpty())
	{
		int s = startPt.x;
		ConsoleFunctions c;
		c.SetCursorAt(startPt.y, startPt.x);
		c.SetColor(black, dark_green);
		for (int i = 0; i < 8; i++)
		{
			cout << "      ";
			c.SetCursorAt(startPt.y, ++s);
		}
		return;
	}
	int m = startPt.x, n = startPt.y;
	for (int i = 0; i <= top; i++)
	{
		pile[i].display(m, n);
		m = m + 2;
	}
}

void PileOfCards::setSize(int size)
{
	this->size = size;
}
PileOfCards::~PileOfCards()
{
	delete pile;
}