#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char player;
int a;
int b;
int turn;
int selected;
int scoreA;
int scoreB;
int index;
bool invalid;
string again;
vector<int> arrA;
vector<int> arrB;

void initCards()
{
	arrA.push_back(0);
	for (int i = 0; i < 14; i++) {
		arrA.push_back(i);
	}

	arrB.push_back(0);
	for (int i = 0; i < 14; i++) {
		arrB.push_back(i);
	}
}

void printCards(const int *array, const int n) {
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void checkifValid(const int *array, int *selected, int n) {
	for (int i = 0; i < n; i++)
	{
		if (array[i] == *selected) { 
			invalid = false; 
			index = i;
			break;
		}
	}
}

void checkWinner(int a, int b) {
	cout << "Joust: " << a << " vs " << b << "\n";
	if (a == b) { 
		cout << "Both players draw!\n";
	}
	else if (a == 1 && b == 13) {
		cout << "Player A wins!\n";
		scoreA++;
	}
	else if (a == 13 && b == 1) {
		cout << "Player B wins!\n";
		scoreB++;
	}
	else if (a > b) {
		cout << "Player A wins!\n";
		scoreA++;
	}
	else {
		cout << "Player B wins!\n";
		scoreB++;
	}
}

//doesn't work to me lol :(
void clearScreen() {
	cout << "\033[2J\033[1;1H";
}

int main()
{
	turn = 0;
	selected = 0;
	scoreA = 0;
	scoreB = 0;

	initCards();

	do {

		cout << "A - Available cards: ";
		printCards(&(arrA[0]), arrA.size());
		invalid = true;
		do {
			cout << "a> ";
			cin >> a;
			checkifValid(&arrA[0], &a, arrA.size());
			if (invalid) {
				cout << "You don't have that card!\n";
			}
		} while (invalid);
		arrA.erase(arrA.begin() + index);
		clearScreen(); // it doesnt work D:
		do { //haha when u input another character it still loops.....
			cout << "Press enter when Player B is ready...";
			cin.get();
		} while (cin.get() != '\n');


		cout << "B - Available cards: ";
		printCards(&(arrB[0]), arrB.size());
		invalid = true;
		do {
			cout << "b> ";
			cin >> b;
			checkifValid(&arrB[0], &b, arrB.size());
			if (invalid) {
				cout << "You don't have that card!\n";
			}
		} while (invalid);
		arrB.erase(arrB.begin() + index);
		do { //pls change this also ty
			cout << "Press enter when Player B is ready...";
			cin.get();
		} while (cin.get() != '\n');

		checkWinner(a, b);
		turn++;
		
	} while (turn < 15);

	cout << "Final score:\n";
	cout << "Player A: " << scoreA << "\n";
	cout << "Player B: " << scoreB << "\n";
	if (scoreA > scoreB) {
		cout << "**Player A wins!**\n";
	}
	else if (scoreA < scoreB) {
		cout << "**Player B wins!**\n";
	}
	else {
		cout << "**It's a draw**\n";
	}

	cout << "Play again? (y or n) ";
	cin >> again;
	if (again == "y") {
		main();
	}
}
