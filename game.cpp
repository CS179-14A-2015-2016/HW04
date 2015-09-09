

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a;
int b;
int turn;
int selected;
int scoreA;
int scoreB;
int index;
char enter;
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
	cout << "\nJoust: " << a << " vs " << b << "\n";

	if (a == 0 && b == 0)
	{
		float x = rand();
		if (x > 75) {
			cout << "Player A wins by chance!\n";
			scoreA++;
		}

		else if (x > 50) {
			cout << "Player B wins by chance!\n";
			scoreB++;
		}

		else {
			cout << "Both players draw by chance!\n";
		}


	}

	else if (a == 0 || b == 0) {
		float x = rand();
		if (x > 50) {
			cout << "Player A wins by chance!\n";
			scoreA++;
		}
		else {
			cout << "Player B wins chance!\n";
			scoreB++;
		}

	}

	else if (a == b) {
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

void clearScreen() {
	system("cls");
}

int main()
{
	turn = 0;
	selected = 0;
	scoreA = 0;
	scoreB = 0;

	initCards();

	do {
		cout << "Press enter when Player A is ready...";
		do {
			cin.get();
		} while (cin.get() != '\n');
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
		
		cout << string(50, '\n');
		cout << "Press enter when Player B is ready...";
		do {
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
		cout << string(50, '\n');
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
	return 0;
}
