#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <limits>

using namespace std;

//random declaration
random_device ran;
mt19937 dev(ran());
mt19937 gen(ran());

/*
//determines what value would be in the step if ever 
int steprand(int& boardsize)
{
	int spaces = boardsize / 2;
	uniform_int_distribution<> dis(-spaces, spaces);
	int a = dis(dev);
	return a;
}

//determines if a tile will have a random value or not
bool tilerand()
{
	uniform_real_distribution<> dis(0, 1);

	if (dis(gen) > 0.7)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/

//prints all elements in a vector
void vprint(vector<string> & v)
{
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		std::cout << *i;
	}
}

//printing the player's deck/vectors
void plaprint(vector<string> &topvec, vector<string> &plamidvec, vector<string> &botvec)
{
	cout << "Player A - Available cards" << endl;
	vprint(topvec);
	cout << endl;
	vprint(plamidvec);
	cout << endl;
	vprint(botvec);
	cout << endl << endl;
}

void plbprint(vector<string> &topvec, vector<string> &plbmidvec, vector<string> &botvec)
{
	cout << "Player B - Available cards" << endl;
	vprint(topvec);
	cout << endl;
	vprint(plbmidvec);
	cout << endl;
	vprint(botvec);
	cout << endl << endl;
}


int main()
{
	//variable declaration
	int playerOne;
	int playerTwo;
	int scorePOne = 0;
	int scorePTwo = 0;
	int turns = 0;
	int boardsize = 15;
	int pbuffer;
	int vecplace = 3;
	int choicePOne;
	int choicePTwo;
	bool player = true;

	//total board
	vector<string> topvec = { "+", " - ", "+" };
	vector<string> plamidvec = { "|", " 0 ", "|" };
	vector<string> plbmidvec = { "|", " 0 ", "|" };
	vector<string> botvec = { "+", " - ", "+" };

	//strings to add to the board
	vector<string> totop = { " - ", "+" };
	vector<string> tomid = { "   ", "|" };
	vector<string> tobot = { " - ", "+" };

	//boardsize increase
	topvec.reserve(topvec.size() + (totop.size()*boardsize));
	plamidvec.reserve(plamidvec.size() + (tomid.size()*boardsize));
	plbmidvec.reserve(plbmidvec.size() + (tomid.size()*boardsize));
	botvec.reserve(botvec.size() + (tobot.size()*boardsize));

	//set boardsize by adding to the to- vectors
	for (int count = 1; count < boardsize; count++)
	{
		topvec.insert(topvec.end(), totop.begin(), totop.end());
		plamidvec.insert(plamidvec.end(), tomid.begin(), tomid.end());
		plbmidvec.insert(plbmidvec.end(), tomid.begin(), tomid.end());
		botvec.insert(botvec.end(), tobot.begin(), tobot.end());
	}

	//set 'cards' into the vectors
	for (int card = 0; card < 14; card++)
	{
		if (card >= 10)
		{
			plamidvec[vecplace] = ' ' + to_string(card);
			plbmidvec[vecplace] = ' ' + to_string(card);
		}
		if ((card >= 0) && (card <= 9))
		{
			plamidvec[vecplace] = ' ' + to_string(card) + ' ';
			plbmidvec[vecplace] = ' ' + to_string(card) + ' ';
		}

		vecplace += 2;
	}
	while (turns != 15)
	{
		if(player == true)
		{
		plaprint(topvec, plamidvec, botvec);
		cout << "a>";
		cin >> choicePOne;
		cout << string(50, '\n');
		//change choice in vector to X
		player = false;
		}
		else if(player ==false)
		{
		plbprint(topvec, plbmidvec, botvec);
		cout << "b>";
		cin >> choicePTwo;
		cout << string(50, '\n');
		player = true;
		
		cout << "Joust: [" << choicePOne << "] vs [" + choicePTwo << "]"<<"\n";
		
		if(choicePOne == 0 && choicePTwo != 0)
		{
			turns +=1;
		}
		else if(choicePOne != 0 && choicePTwo == 0)
		{
			turns +=1;
		}
		else if(choicePOne == 0 && choicePTwo == 0)
		{
			turns +=1;
		}
		else if((choicePOne > choicePTwo)||((choicePOne == 1)&&(choicePTwo == 13)))
		{
			cout << "Player A wins!"<<"\n";
			scorePOne += 1;
			turns +=1;
			
		}
		else if((choicePOne < choicePTwo)||((choicePOne == 13)&&(choicePTwo == 1)))
		{
			cout << "Player B wins!"<<"\n";
			scorePTwo += 1;
			turns +=1;
			
		}
		else if(choicePOne == choicePTwo)
		{
			cout << "Both players draw!"<<"\n";
			turns += 1;
		}
		
		
		}
	}

	//winner display
	if (scorePOne == scorePTwo)
	{
		cout << "Player A: " << scorePOne << "points." << "\n";
		cout << "Player B: " << scorePTwo << "points." << "\n";
		cout << "Both players draw!";
	}
	else if (scorePOne > scorePTwo)
	{
		cout << "Player A: " << scorePOne << "points." << "\n";
		cout << "Player B: " << scorePTwo << "points." << "\n";
		cout << "Player A wins!";
	}
	else if (scorePOne > scorePTwo)
	{
		cout << "Player A: " << scorePOne << "points." << "\n";
		cout << "Player B: " << scorePTwo << "points." << "\n";
		cout << "Player B wins!";
	}
	//pause buffer 
	cin >> pbuffer;
	return EXIT_SUCCESS;
}
