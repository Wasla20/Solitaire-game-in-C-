
#include "PlayingCard.h"

const int PlayingCard::Diamond = 0;
const int PlayingCard::Heart = 1;
const int PlayingCard::Spade = 2;
const int PlayingCard::Club = 3;
PlayingCard::PlayingCard(int rank, int suit) :rank(rank), suit(suit), color('r'), faceUp(false), top(false)
{
	if (rank < 1 || rank >13)
	{
		cout << "Rank should be in between range of 1-13\n";
		return;
	}
	if (suit == PlayingCard::Club || suit == PlayingCard::Spade || suit == PlayingCard::Heart || suit == PlayingCard::Diamond)
	{
		if (suit == PlayingCard::Club || suit == PlayingCard::Spade)
		{
			color = 'b';
		}
		else if (suit == PlayingCard::Heart || suit == PlayingCard::Diamond)
		{
			color = 'r';
		}
		this->rank = rank;
		this->suit = suit;
		faceUp = false;
		top = false;
	}
	else
	{
		cout << "Suit should be club,heart,spade or diamond\n";
		return;
	}
}
void PlayingCard::display(int x, int y)
{
	wstring symbol;
	ConsoleFunctions c;
	char rankForDisplay = 'A';

	if (suit == PlayingCard::Diamond)
	{
		symbol = L"\u2666";
	}
	else if (suit == PlayingCard::Heart)
	{
		symbol = L"\u2665";
	}
	else if (suit == PlayingCard::Spade)
	{
		symbol = L"\u2660";
	}
	else if (suit == PlayingCard::Club)
	{
		symbol = L"\u2663";
	}

	if (top == true && faceUp == true)
	{
		c.SetCursorAt(y, x);



		if (rank == 1)
		{
			rankForDisplay = 'A';
		}
		else if (rank == 11)
		{
			rankForDisplay = 'J';
		}
		else if (rank == 12)
		{
			rankForDisplay = 'Q';
		}
		else if (rank == 13)
		{
			rankForDisplay = 'K';
		}


		if (color == 'r')
			c.SetColor(red, white);
		else if (color == 'b')
			c.SetColor(black, white);


		if (rank >= 2 && rank <= 9)
		{
			cout << rank;
			_setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "    ";
		}
		else if (rank == 10)
		{
			cout << rank;
			_setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "   ";
		}
		else if (rank < 2 || rank > 10)
		{
			cout << rankForDisplay;
			_setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "    ";
		}
		c.SetCursorAt(y, ++x);

		for (int i = 0; i < 6; i++)
		{
			cout << "      ";
			c.SetCursorAt(y, ++x);
		}


		if (rank >= 2 && rank <= 9)
		{
			cout << "    ";
			_setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			_setmode(_fileno(stdout), _O_TEXT);
			cout << rank;
		}
		else if (rank == 10)
		{
			cout << "   ";
			_setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			_setmode(_fileno(stdout), _O_TEXT);
			cout << rank;
		}
		else if (rank < 2 || rank>10)
		{
			cout << "    ";
			_setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			_setmode(_fileno(stdout), _O_TEXT);
			cout << rankForDisplay;
		}
	}
	if (top == true && faceUp == false)
	{
		c.SetCursorAt(x, y);
		c.SetColor(black, red);
		for (int i = 0; i < 8; i++)
		{
			cout << "      ";
			c.SetCursorAt(y, ++x);
		}
	}
	if (top == false && faceUp == true)
	{
		c.SetCursorAt(y, x);

		if (rank == 1)
		{
			rankForDisplay = 'A';
		}
		else if (rank == 11)
		{
			rankForDisplay = 'J';
		}
		else if (rank == 12)
		{
			rankForDisplay = 'Q';
		}
		else if (rank == 13)
		{
			rankForDisplay = 'K';
		}

		if (color == 'r')
			c.SetColor(red, white);
		else if (color == 'b')
			c.SetColor(black, white);

		if (rank >= 2 && rank <= 9)
		{
			cout << rank;
			_setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "    ";
		}
		else if (rank == 10)
		{
			cout << rank;
			_setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "   ";
		}
		else if (rank < 2 || rank > 10)
		{
			cout << rankForDisplay;
			_setmode(_fileno(stdout), _O_U8TEXT);
			wcout << symbol;
			_setmode(_fileno(stdout), _O_TEXT);
			cout << "    ";
		}
		c.SetCursorAt(y, ++x);

		c.SetColor(black, white);

		cout << "______";
	}
	if (top == false && faceUp == false)
	{
		c.SetCursorAt(y, x);

		c.SetColor(black, red);
		cout << "      ";

		c.SetCursorAt(y, ++x);
		cout << "______";
	}




	c.SetColor(15, 0);
}

bool PlayingCard::isFaceUp()
{
	return faceUp;
}
void PlayingCard::setFaceUp(bool faceUp)
{
	this->faceUp = faceUp;
}
bool PlayingCard::isTop()
{
	return top;
}
void PlayingCard::setTop(bool top)
{
	this->top = top;
}
char PlayingCard::getColor()
{
	return color;
}

int PlayingCard::getSuit()
{
	return suit;
}
int PlayingCard::getRank()
{
	return rank;
}