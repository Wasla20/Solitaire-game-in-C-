
#include"Solitaire.h"
using namespace std;
int main()
{
	Solitaire S;
	S.Shuffle();
	S.dealToPlayingPiles();
	S.DisplayGame();
	S.Play();
}