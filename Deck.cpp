#include "Deck.h"
Deck::Deck()
{
	int j = 0;
	for (int i = 1; i <= 13; i++)
	{
		deck[j] = new PlayingCard(i, PlayingCard::Diamond);
		j++;
	}
	for (int i = 1; i <= 13; i++)
	{
		deck[j] = new PlayingCard(i, PlayingCard::Heart);
		j++;
	}
	for (int i = 1; i <= 13; i++)
	{
		deck[j] = new PlayingCard(i, PlayingCard::Spade);
		j++;
	}
	for (int i = 1; i <= 13; i++)
	{
		deck[j] = new PlayingCard(i, PlayingCard::Club);
		j++;
	}


	size = 52;
}
int Deck::getSize()
{
	return size;
}
bool Deck::IsEmpty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}
PlayingCard Deck::Remove(int i)
{
	if (!IsEmpty())
	{
		PlayingCard dummy;
		dummy = *deck[i];

		for (int j = i; j < size - 1; j++)
		{
			delete deck[j];
			deck[j] = NULL;
			deck[j] = new PlayingCard(deck[j + 1]->getRank(), deck[j + 1]->getSuit());
		}
		delete deck[size - 1];
		size--;
		return dummy;
	}
	cout << "Deck is Empty\n";
	PlayingCard p;
	return p;
}
Deck::~Deck()
{
	for (int i = 0; i < size; i++)
	{
		delete deck[i];
	}
}