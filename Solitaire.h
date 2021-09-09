#include "Deck.h"
#include "PileOfCards.h"

#pragma once
class Solitaire
{
private:
	Deck deckofCards;
	PileOfCards stock;
	PileOfCards waste;
	PileOfCards home[4];
	PileOfCards playingPile[7];
	ConsoleFunctions cf;
public:
	Solitaire();
	void Shuffle();
	void dealToPlayingPiles();
	void DisplayGame();
	point getClickedPoint();
	PileOfCards* getClickedPile(point p, int& a, int& c);
	void moveFromStock();
	void moveFromWasteToHome(int a);
	void moveFromWasteToPlayingPile(int a, int c);
	void moveFromPlayingPileToHome(int a, int b, int c);
	void moveFromPlayingPileToPlayingPile(int a, int b, int c1, int c2);
	void moveFromHomeToPlayingPile(int a, int b, int c);
	void Play();
	~Solitaire();
};


