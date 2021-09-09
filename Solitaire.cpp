
#include "Solitaire.h"
#include<iostream>
using namespace std;
Solitaire::Solitaire() :stock(52), waste(52), home{ (13),(13),(13),(13) }, playingPile{ (13),(14),(15),(16),(17),(18),(19) }
{
	stock.setStartPt(2, 2);
	stock.setEndPt(10, 8);
	waste.setStartPt(2, 10);
	waste.setEndPt(10, 16);
	home[0].setStartPt(2, 24);
	home[0].setEndPt(10, 30);
	int k = 24, j = 30;

	for (int i = 1; i < 4; i++)
	{
		k = k + 7;
		home[i].setStartPt(2, k);
		j = j + 7;
		home[i].setEndPt(10, j);
	}

	playingPile[0].setStartPt(15, 2);
	k = 2;
	for (int i = 1; i < 7; i++)
	{
		k = k + 7;
		playingPile[i].setStartPt(15, k);
	}
}
void Solitaire::Shuffle()
{

	int i;
	while (!deckofCards.IsEmpty())
	{
		i = rand() % deckofCards.getSize();
		PlayingCard c = deckofCards.Remove(i);
		c.setFaceUp(false);
		stock.Add(c);
	}

}
void Solitaire::dealToPlayingPiles()
{
	int x1, y1;
	for (int j = 0; j <= 6; j++)
	{

		PlayingCard c = stock.Remove();
		c.setFaceUp(false);
		playingPile[j].Add(c);

		x1 = (playingPile[j].getStartPt().x) + 7;
		y1 = (playingPile[j].getStartPt().y) + 5;
		playingPile[j].setEndPt(x1, y1);
	}
	for (int i = 1; i <= 6; i++)
	{

		for (int j = i; j <= 6; j++)
		{

			PlayingCard c = stock.Remove();
			c.setFaceUp(false);
			playingPile[j].Add(c);

			x1 = (playingPile[j].getEndPt().x)+2;
			y1 = (playingPile[j].getEndPt().y);
			playingPile[j].setEndPt(x1, y1);
		}

	}
	for (int i = 0; i < 7; i++)
	{
		playingPile[i].Peek().setFaceUp(true);
	}
	stock.Peek().setFaceUp(false);
}
void Solitaire::DisplayGame()
{
	stock.SimpleDisplay();
	waste.SimpleDisplay();
	for (int i = 0; i < 4; i++)
		home[i].SimpleDisplay();
	for (int i = 0; i < 7; i++)
		playingPile[i].CascadingDisplay();
}


point Solitaire::getClickedPoint()
{
	point p;
	ConsoleFunctions cf;
	while (1)
	{
		cf.DetectEvent();
	
		if (cf.IsMouseLeftClickEvent(p))
			return p;

	}
}
PileOfCards* Solitaire::getClickedPile(point p, int& a, int& c)
{
	if (p.y >= stock.getStartPt().x && p.y < stock.getEndPt().x && p.x >= stock.getStartPt().y && p.x < stock.getEndPt().y)
	{
		
		return &stock;
	}
	else if (p.y >= waste.getStartPt().x && p.y < waste.getEndPt().x && p.x >= waste.getStartPt().y && p.x < waste.getEndPt().y)
	{
		return &waste;
	}
	a = -1;
	while (a < 3)
	{
		a++;
		if (p.y >= home[a].getStartPt().x && p.y < home[a].getEndPt().x && p.x >= home[a].getStartPt().y && p.x < home[a].getEndPt().y)
		{
			return &home[a];
		}
	}
	a = -1;
	c = 0;
	while (a < 6)
	{
		a++;
		if (p.y >= playingPile[a].getStartPt().x && p.y <= playingPile[a].getEndPt().x && p.x >= playingPile[a].getStartPt().y && p.x <= playingPile[a].getEndPt().y)
		{
			for (int i = playingPile[a].getStartPt().x; i < (playingPile[a].getEndPt().x) - 8; )
			{
				if (p.y >= i && p.y < i + 2)
				{
					break;
				}
				c++;
				i = i + 2;
			}
			return &playingPile[a];
		}
	}
	cf.SetCursorAt(60, 1);
	cout << "not clicked on any pile";
}
void Solitaire::moveFromStock()
{
	cf.SetCursorAt(60, 0);
	cout << "MOVING FROM STOCK";
	if (!(stock.IsEmpty()))
	{
		PlayingCard t = stock.Remove();
		stock.Peek().setFaceUp(false);
		waste.Add(t);
		waste.Peek().setFaceUp(true);
	}
	else
	{
		while (waste.IsEmpty() == false)
		{
			PlayingCard t = waste.Remove();
			t.setFaceUp(false);
			stock.Add(t);
			waste.Peek().setFaceUp(true);
		}
	}
}
void Solitaire::moveFromWasteToHome(int a)
{
	cf.SetCursorAt(60, 0);
	cout << "MOVING FROM WASTE TO HOME";
	if (waste.IsEmpty() == false)
	{
		if (home[a].IsEmpty() == true)
		{
			if (waste.Peek().getRank() == 1)
			{
				home[a].Add(waste.Remove());
				return;
			}
		}
		if (home[a].IsEmpty() == false)
		{
			if ((home[a].Peek().getRank() + 1) == waste.Peek().getRank())
			{
				if (home[a].Peek().getSuit() == waste.Peek().getSuit())
				{
					home[a].Add(waste.Remove());
					return;
				}
			}
		}
	}
	cf.SetCursorAt(60, 2);
	cout << "CANNOT MOVE";
}
void Solitaire::moveFromWasteToPlayingPile(int a, int c)
{
	cf.SetCursorAt(60, 0);
	cout << "MOVING FROM WASTE TO PLAY";
	if (waste.IsEmpty() == false)
	{
		if (playingPile[a].getTop() == c)
		{
			if ((playingPile[a].Peek().getRank() - 1) == waste.Peek().getRank())
			{
				if (playingPile[a].Peek().getColor() != waste.Peek().getColor())
				{
					playingPile[a].Add(waste.Remove());
					int x = playingPile[a].getEndPt().x;
					int y = playingPile[a].getEndPt().y;

					playingPile[a].setEndPt(x+2, y);
					return;
				}
			}
		}
		if (playingPile[a].IsEmpty())
		{
			if (waste.Peek().getRank() == 13)
			{
				playingPile[a].Add(waste.Remove());
				return;
			}
		}
	}
	
	cf.SetCursorAt(60, 2);
	cout << "CANNOT MOVE";
}
void Solitaire::moveFromPlayingPileToHome(int a, int b, int c)
{
	cf.SetCursorAt(60, 0);
	cout<< "MOVING FROM PLAY TO HOME";
	if (playingPile[a].IsEmpty() == false)
	{
		if (playingPile[a].getTop() == c)
		{
			if (home[b].IsEmpty() == true)
			{
				if (playingPile[a].Peek().getRank() == 1)
				{
					home[b].Add(playingPile[a].Remove());
					int x = playingPile[a].getEndPt().x;
					int y = playingPile[a].getEndPt().y;
					if (!playingPile[a].IsEmpty())
						playingPile[a].setEndPt(x - 2, y );
					return;
				}
			}
			else if (home[b].IsEmpty() == false)
			{
				if ((home[b].Peek().getRank() + 1) == playingPile[a].Peek().getRank())
				{
					if (home[b].Peek().getSuit() == playingPile[a].Peek().getSuit())
					{
						home[b].Add(playingPile[a].Remove());
						int x = playingPile[a].getEndPt().x;
						int y = playingPile[a].getEndPt().y;
						if (!playingPile[a].IsEmpty())
							playingPile[a].setEndPt(x - 2, y);
						return;
					}
				}
			}
		}
	}
	cf.SetCursorAt(60, 2);
	cout << "CANNOT MOVE";
}
void Solitaire::moveFromPlayingPileToPlayingPile(int a, int b, int c1, int c2)
{
	cf.SetCursorAt(60,0);
	cout << "MOVING FROM PLAY TO PLAY";

	if (playingPile[a].IsEmpty() == false)
	{
		if (playingPile[b].getTop() == c2)
		{
			if (playingPile[a].viewCard(c1).isFaceUp() == true)
			{
				if ((playingPile[b].Peek().getRank() - 1) == playingPile[a].viewCard(c1).getRank())
				{
					if (playingPile[b].Peek().getColor() != playingPile[a].viewCard(c1).getColor())
					{
						int s = (playingPile[a].getTop() - c1) + 1;
						PileOfCards Extra(s);
						while (!Extra.IsFull())
						{
							Extra.Add(playingPile[a].Remove());
							int x = playingPile[a].getEndPt().x;
							int y = playingPile[a].getEndPt().y;
							if(!playingPile[a].IsEmpty())
								playingPile[a].setEndPt(x - 2, y);
						}
						while (!Extra.IsEmpty())
						{
							playingPile[b].Add(Extra.Remove());
							int x = playingPile[b].getEndPt().x;
							int y = playingPile[b].getEndPt().y;

							playingPile[b].setEndPt(x + 2, y );
						}
						
						return;
					}
				}
			}
		}
		if (playingPile[b].IsEmpty())
		{
			if (playingPile[a].viewCard(c1).getRank() == 13)
			{
				int s = (playingPile[a].getTop() - c1) + 1;
				PileOfCards Extra(s);
				while (!Extra.IsFull())
				{
					Extra.Add(playingPile[a].Remove());
					int x = playingPile[a].getEndPt().x;
					int y = playingPile[a].getEndPt().y;
					if (!playingPile[a].IsEmpty())
						playingPile[a].setEndPt(x - 2, y);
				}
				playingPile[b].Add(Extra.Remove());
				while (!Extra.IsEmpty())
				{
					playingPile[b].Add(Extra.Remove());
					int x = playingPile[b].getEndPt().x;
					int y = playingPile[b].getEndPt().y;

					playingPile[b].setEndPt(x + 2, y);
				}
				

				return;
			}
		}
		
	}
	cf.SetCursorAt(60, 2);
	cout << "CANNOT MOVE";

}
void Solitaire::moveFromHomeToPlayingPile(int a, int b, int c)
{
	cf.SetCursorAt(60, 0);
	cout << "MOVING FROM HOME TO PLAY";

	if (home[a].IsEmpty() == false)
	{
		if (playingPile[b].getTop() == c)
		{
			if ((playingPile[b].Peek().getRank() - 1) == home[a].Peek().getRank())
			{
				if (playingPile[b].Peek().getColor() != home[a].Peek().getColor())
				{
					playingPile[b].Add(home[a].Remove());
					int x = playingPile[b].getEndPt().x;
					int y = playingPile[b].getEndPt().y;

					playingPile[b].setEndPt(x + 2, y);
					return;
				}
			}
		}
		if (playingPile[a].IsEmpty())
		{
			if (home[a].Peek().getRank() == 13)
			{
				playingPile[b].Add(home[a].Remove());
				return;
			}
		}
	}
	cf.SetCursorAt(60, 2);
	cout << "CANNOT MOVE";
}
void Solitaire::Play()
{
	
	while (!(home[0].IsFull() && home[1].IsFull() && home[2].IsFull() && home[3].IsFull()))
	{
		point p1 = getClickedPoint();
		int a = 0; int c = 0;
		PileOfCards* firstPile = getClickedPile(p1, a, c);
		if (firstPile == &stock)
		{
			cf.clearConsole();

			moveFromStock();
			cf.SetCursorAt(0, 0);
			cout << "stock clicked!";
			DisplayGame();
			continue;
		}
		else if (firstPile == &waste)
		{
			cf.SetCursorAt(0, 0);
			cout << "waste clicked!";
			point p2 = getClickedPoint();
			int a1 = 0; int c1 = 0;
			PileOfCards* secondPile = getClickedPile(p2, a1, c1);
			if (secondPile == &home[a1])
			{
				cf.clearConsole();

				moveFromWasteToHome(a1);
				cf.SetCursorAt(0, 1);
				cout << "home pile no " << a1 << " clicked!";
				DisplayGame();
				continue;
			}
			else if (secondPile == &playingPile[a1])
			{
				cf.clearConsole();

				moveFromWasteToPlayingPile(a1, c1);
				cf.SetCursorAt(0, 1);
				cout << "card no. " << c1 << " of playing pile no " << a1 << " clicked!";
				DisplayGame();
				continue;
			}
			cf.SetCursorAt(0, 1);
			cout << "invalid move";
			continue;
		}
		else if (firstPile == &home[a])
		{
			cf.SetCursorAt(0, 0);
			cout << "home pile no " << a << " clicked!";
			point p2 = getClickedPoint();
			int a1 = 0; int c1 = 0;
			PileOfCards* secondPile = getClickedPile(p2, a1, c1);
			if (secondPile == &playingPile[a1])
			{
				cf.clearConsole();

				moveFromHomeToPlayingPile(a, a1, c1);
				cf.SetCursorAt(0, 1);
				cout << "card no. " << c1 << "playing pile no " << a1 << " clicked!";

				DisplayGame();
				continue;
			}
			cf.SetCursorAt(0, 1);
			cout << "invalid move";
			continue;
		}
		else if (firstPile == &playingPile[a])
		{
			cf.SetCursorAt(0, 0);
			cout << "card no. " << c << "playing pile no " << a << " clicked!";
			point p2 = getClickedPoint();
			int a1 = 0; int c1 = 0;
			PileOfCards* secondPile = getClickedPile(p2, a1, c1);
			if (secondPile == &playingPile[a1])
			{
				cf.clearConsole();

				moveFromPlayingPileToPlayingPile(a, a1, c, c1);
				cf.SetCursorAt(0, 1);
				cout << "card no. " << c1 << "playing pile no " << a1 << " clicked!";

				DisplayGame();
				continue;
			}
			else if (secondPile == &home[a1])
			{
				cf.clearConsole();
				moveFromPlayingPileToHome(a, a1, c);
				cf.SetCursorAt(0, 1);

				cout << "home pile no " << a1 << " clicked!";


				DisplayGame();
				continue;
			}
			cf.SetCursorAt(0, 1);
			cout << "invalid move";
			continue;
		}







	}
}


Solitaire::~Solitaire()
{
	
}