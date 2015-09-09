#include <iostream>
#include <string>
#include <vector>
#include <random>
//RAMOS SALAY NADA NAZIS
using namespace std;
void clearscreen()
{
    //works in windows only
   system("CLS");
   
    //cout << "\033[2J\033[1;1H";  //does not work in my xcode or windows ;__;
}
int chance()
{
    // BLACK MAGIC MUMBO JUMBO RANDOM
    random_device random;
    uniform_int_distribution<int> distribution(0,1);
    int r = distribution(random);
    return r;
}
int main()
{
    bool running = 1;
    vector<int> playerA;
    vector<int> playerB;
    playerA.push_back(0);
    playerB.push_back(0);
    // fill array
    for(int i = 0;i<14;i++)
    {
        playerA.push_back(i);
        playerB.push_back(i);
    }
    
    int p1turn = -1, p2turn = -1;
    int xA,xB;
    int p1score = 0;
    int p2score = 0;
    string acards,bcards,enter;
    // append a string with content from decks
    for(int i = 0; i < playerA.size(); i++)
    {
        acards+= to_string((long long)(playerA[i])) + " ";
    }
    
    for(int i = 0; i < playerB.size(); i++)
    {
        bcards+= to_string((long long)(playerB[i])) + " ";
    }
    
    while(running)
    {
        int joker1, joker2;
        
        clearscreen();
        if(playerA.size() == 0)
        {
            cout<< "Player A: " << p1score<<endl;
            
            cout << "Player B: " << p2score<<endl;
            if(p1score > p2score)
            {
                cout<< "PLAYER A WINS!";
            }
            else if (p1score < p2score)
            {
                cout << "PLAYER B WINS";
            }
            else
            {
                cout << "Both players draw!";
            }
            break;
        }
       
        cout << "A - Available cards: " << acards<<endl;
        cout << "a> ";
        //player A turn
        while(p1turn == -1)
        {
            cin >> xA;
            for(int i = 0; i < playerA.size(); i++)
            {
                if(playerA[i] == xA)
                {
                    p1turn = xA;
                    playerA.erase(playerA.begin()+i);
                    acards = "";
                    for(int i = 0; i < playerA.size(); i++)
                    {
                        acards+= to_string((long long)(playerA[i])) + " ";
                    }
                    break;
                }
            }
            if(p1turn == -1)
            {
                cout<<"You do not have that card!"<<endl;
            }
        }
        while(1)
        {
            cout<<"Press enter if player B is ready..."<< "\n";
            getline(cin,enter);
            if(cin.get() == '\n')
            {
                break;
            }
        }
        clearscreen();
      
        
        cout << "B - Available cards: " << bcards<<endl;
        cout << "b> ";
        //player B turn
        while(p2turn == -1)
        {
            cin >> xB;
            for(int i = 0; i < playerB.size(); i++)
            {
                if(playerB[i] == xB)
                {
                    p2turn = xB;
                    playerB.erase(playerB.begin()+i);
                     bcards = "";
                    for(int i = 0; i < playerB.size(); i++)
                    {
                       
                        bcards+= to_string((long long)(playerB[i])) + " ";
                    }
                    break;
                }
            }
            if(p2turn == -1)
            {
                cout<<"You do not have that card!"<<endl;
            }
        }
        clearscreen();
        cout<< "Joust: " << p1turn << " vs " << p2turn <<endl;
        if(p1turn == 1 && p2turn == 13)
        {
            p1score +=1;
            cout<< "Player A wins" << endl;
        }
        else if(p1turn == 13 && p2turn == 1)
        {
            p2score +=1;
            cout<< "Player B wins" << endl;
            
        }
        else if(p1turn > p2turn && p1turn != 0 && p2turn !=0)
        {
            p1score +=1;
            cout<< "Player A wins" << endl;
        }
        else if(p1turn < p2turn && p1turn != 0 && p2turn !=0)
        {
            p2score +=1;
            cout<< "Player B wins" <<endl;
        }
        else if (p1turn == p2turn && p1turn != 0 && p2turn !=0)
        {
            cout << "It's a draw!" << endl;
            
        }
        else if( p1turn == 0 && p2turn != 0)
        {
            joker1 = chance();
            
            if( joker1 == 0)
            {
                //p1 loses by chance
                cout<< "Player B wins by chance" << endl;
                p2score +=1;
            }
            else if ( joker1 == 1 )
            {
                //p1 wins by chance
                cout<< "Player A wins by chance" << endl;
                p1score +=1;
            }
        }
        
        else if( p2turn == 0 && p1turn != 0)
        {
            joker2 = chance();
            
            if( joker2 == 0)
            {
                //p2 loses by chance
                p1score +=1;
                cout<< "Player A wins by chance" << endl;
            }
            else if ( joker2 == 1 )
            {
                //p2 wins by chance
                p2score +=1;
                cout<< "Player B wins by chance" << endl;
            }
        }
        
        else if( p1turn == 0 && p2turn == 0)
        {
            joker1 = chance();
            joker2 = chance();
            
            if( joker1 == joker2)
            {
                //draw by chance
                cout << "It's a draw!" << endl;
            }
            else if ( joker1 > joker2 )
            {
                //p1 wins by chance
                cout<< "Player A wins by chance" << endl;
                p1score +=1;
                
            }
            else
            {
                //p2 wins by chance
                cout<< "Player B wins by chance" << endl;
                p2score +=1;
            }
        }
        //check for enter key press
        while(1)
        {
            cout<<"Press enter if player A is ready..."<< "\n";
            getline(cin,enter);
            if(cin.get() == '\n')
            {
                break;
            }
        }
        //for turn conditions
        p1turn = -1, p2turn = -1;
    }
    
}
