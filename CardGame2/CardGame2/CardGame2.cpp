// CardGame2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool gameRunning;
bool playerTurn;
int player1Hand[15];
int player2Hand[15];
int player1ChoiceCard;
int player2ChoiceCard;
int player1Score;
int player2Score;
int screenClear;

int EndGameCounterDEBUG;

int CompareCard(int cardA, int cardB)
{
	//return 0 if draw, 1 if P1 win , 2 if P2 win
	if ((cardA != 0) && (cardB != 0))
	{

	}
	else if (cardA == 0)
	{

	}
	else if (cardB == 0)
	{

	}
	else
	{

	}

	return 0;
}

int Game()
{
	//cout << "hello world \n";

	

	cout << "Press 'Enter' when Player 1 is ready... \n";

	if (cin.get() == '\n')
	{
		//int tempCount;
		while (screenClear <= 30)
		{
			cout << "\n";
			screenClear++;
		}
		screenClear = 0;
	}



	EndGameCounterDEBUG++;

	if (EndGameCounterDEBUG >= 15)
	{
		gameRunning = 0;
	}

	return 0;
}

int main()
{
	gameRunning = 1;

	while (gameRunning == 1)
	{
		Game();
	}
	
	cout << "end \n";

	cin.get();
    return 0;
}

