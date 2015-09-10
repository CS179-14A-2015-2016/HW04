#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int numCards = 15;
int a, b, playerAScore, playerBScore, indexA, indexB, cardsLeftToPlay;
int deckA[15] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int deckB[15] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
bool playerAEndTurn, playerBEndTurn;

void initRound() {
    indexA = -2;
    indexB = -2;
    a = -2;
    b = -2;
    playerAEndTurn = false;
    playerBEndTurn = false;
}

void init() {
    initRound();
    playerAScore = 0;
    playerBScore = 0;
    cardsLeftToPlay = 15;
}

void removeCardFromDeck(int indA, int indB) {
    deckA[indA] = -1;
    deckB[indB] = -1;
    cardsLeftToPlay -= 1;
}

int randomizeJoker() {
    int joker = (rand() % 4) + 1; 
    return joker;
}

void playerAMove() {
    while (playerAEndTurn == false) {
	    cout << "A - Available cards: ";
		for (int i = 0; i <= numCards; i++) {
		    if (i == numCards) {
		        cout << "\n";
		    }
		    else if (deckA[i] == -1) {
		        continue;
		    }
		    else {
		        cout << deckA[i] << " ";
		    }
		}
		
		cout << "a> ";    		
		cin >> a;
		cin.get();		
		
		if (cin.fail()) {
		    cin.clear();
            cin.ignore(32767, '\n');
			cout << "Invalid input. \n";
		}
		else if (a > 13 || a < 0) {
		    cout << "Invalid card. \n";
		}
		else {
		    //<----- looks for "a" (i.e. Player A's input) inside the deck of cards. ----->
    		for (int i = 0; i < numCards; i++) {
    		    if (deckA[i] == a) {
    		        indexA = i;
    		        break;
    		    }
    		}
    		if (indexA == -2) {
    			cout << "That card has already been used!\n";
    		}
    		else if (deckA[indexA] >= 0 && deckA[indexA] <= 13 && indexA != -2) {
    		    cout << string(1000, '\n');
    			cout << "Press enter when player B is ready...";
    			cin.get();
    			playerAEndTurn = true;
    		}
    		else {
    		    cout << "Invalid card. \n";
    		}
		}
    }
}

void playerBMove() {
	while (playerBEndTurn == false) {
	    cout << "B - Available cards: ";
		for (int i = 0; i <= numCards; i++) {
		    if (i == numCards) {
		        cout << "\n";
		    }
		    else if (deckB[i] == -1) {
		        continue;
		    }
		    else {
		        cout << deckB[i] << " ";
		    }
		}
		
		cout << "b> ";    		
		cin >> b;
		cin.get();		
		
		if (cin.fail()) {
		    cin.clear();
            cin.ignore(32767, '\n');
			cout << "Invalid input. \n";
		}
		if (b > 13 || b < 0) {
		    cout << "Invalid card. \n";
		}
		else {
		    //<----- looks for "b" (i.e. Player B's input) inside the deck of cards. ----->
    		for (int i = 0; i < numCards; i++) {
    		    if (deckB[i] == b) {
    		        indexB = i;
    		        break;
    		    }
    		}
    	    if (indexB == -2) {
    			cout << "That card has already been used!\n";
    		}
    		else if (deckB[indexB] >= 0 && deckB[indexB] <= 13 && indexB != -2) {
    			cout << string(1000, '\n');
    			playerBEndTurn = true;
    		}
    		else {
    		    cout << "Invalid card. \n";
    		}
		}
	}
}

void joust(int cardA, int cardB) {
    cout << "Joust: [" << a << "] vs [" << b << "]\n";
    if (cardA == 1 || cardB == 1) {
        if (cardA == 1 && cardB == 1) {
            cout << "Both players draw! \n";
        }
        else if(cardA == 0 || cardB == 0) {
            int test = randomizeJoker();
            if (test == 1 || test == 3) {
                cout << "Player A wins by chance! \n";
                playerAScore++;
            }
            else {
                cout << "Player B wins by chance! \n";
                playerBScore++;
            }
        }
        else if(cardA == 1 && cardB == 13) {
            cout << "Player A wins! \n";
            playerAScore++;
        }
        else if(cardA == 13 && cardB == 1) {
            cout << "Player B wins! \n";
            playerBScore++;
        }
        else if(cardB == 1) {
            cout << "Player A wins! \n";
            playerAScore++;
        }
        else if(cardA == 1) {
            cout << "Player B wins! \n";
            playerBScore++;
        }
    }
    else if(cardA == 0 || cardB == 0) {
        int test = randomizeJoker();
        if (cardA == 0 && cardB == 0) {
            if (test == 1) {
                cout << "Player A wins by chance! \n";
                playerAScore++;
            }
            else if (test == 2 || test == 3) {
                cout << "Both players draw by chance! \n";
            }
            else {
                cout << "Player B wins by chance! \n";
                playerBScore++;
            }
        }
        else {
            if (test == 1 || test == 3) {
                cout << "Player A wins by chance! \n";
                playerAScore++;
            }
            else {
                cout << "Player B wins by chance! \n";
                playerBScore++;
            }
        }
    }
    else if(cardA == cardB) {
        cout << "Both players draw! \n";
    }
    else if(cardA > cardB) {
        cout << "Player A wins! \n";
        playerAScore++;
    }
    else if(cardA < cardB) {
        cout << "Player B wins! \n";
        playerBScore++;
    }
    
    if (cardsLeftToPlay != 0) {
        cout << "Press enter when player A is ready...";
    }
	cin.get();
}

void declareWinner() {
    cout << "Player A: " << playerAScore << " points\n";
    cout << "Player B: " << playerBScore << " points\n";
    if (playerAScore == playerBScore) {
        cout << "**Draw!**";
    }
    else if(playerAScore > playerBScore) {
        cout << "**Player A Wins!**";
    }
    else if(playerAScore < playerBScore) {
        cout << "**Player B Wins!**";
    }
}

int main() {
    bool isGameFinished = false;    
    srand(time(NULL));
    init();
	while (isGameFinished == false) {
	    initRound();
		playerAMove();
		playerBMove();
		joust(a, b);
		removeCardFromDeck(indexA, indexB);
		if (cardsLeftToPlay == 0) {
            declareWinner();
            isGameFinished = true;
		}
    }
    return 0;
}
