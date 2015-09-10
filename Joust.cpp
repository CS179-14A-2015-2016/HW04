#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	srand(time(0));
	
	vector<int> cardsA;
	vector<int> cardsB;
	cardsA.push_back(0);
	cardsA.push_back(0);
	cardsB.push_back(0);
	cardsB.push_back(0);
	
	for(int i=1;i<=13;i++)
	{
		cardsA.push_back(i);
		cardsB.push_back(i);
	}
	
	int curCardA,curCardB,ptsA,ptsB;
	ptsA = 0;
	ptsB = 0;
	while(true)
	{
		bool a = true;
		while(a)
		{
			cout<<"A - Available cards:";
			for(int i=0;i<cardsA.size();i++)
				cout<<" "<<cardsA.at(i);
			cout<< "\n" << "a> ";
			cin>>curCardA;
			
			for(int i=0;i<cardsA.size();i++)
			{
				if(cardsA.at(i)==curCardA)
				{
					a=false;
					cardsA.erase(cardsA.begin()+i);
				}
			}
			if(a)
			{
				cout<<"That card is not available. Please select another card.\n\n";
			}
		}
		system("CLS");
		cout<<"Press enter when player B is ready...\n";
		system("pause > nul");
		
		a = true;
		while(a)
		{
			system("CLS");
			cout<<"B - Available cards:";
			for(int i=0;i<cardsB.size();i++)
				cout<<" "<<cardsB.at(i);
			cout<<"\n" << "b> ";
			cin>>curCardB;
			
			for(int i=0;i<cardsB.size();i++)
			{
				if(cardsB.at(i)==curCardB)
				{
					a=false;
					cardsB.erase(cardsB.begin()+i);
				}
			}
			
			if(a)
			{
				cout<<"That card is not available. Please select another card.\n\n";
			}
		}
		
		system("CLS");
		cout<<"Joust "<<curCardA<<" vs "<<curCardB<<"\n";
		if(curCardA==0||curCardB==0)
		{
			int r=rand()%101;
			
			if(curCardA==0&&curCardB==0)
			{
				
				if(r<=50)
				{
					cout<<"Both players draw by chance!\n\n";
				}
				else if(r<=75)
				{
					cout<<"Player A wins by chance!\n\n";
					ptsA++;
				}
				else
				{
					cout<<"Player B wins by chance!\n\n";
					ptsB++;
				}
			}
			else
			{
				if(r<=50)
				{
					cout<<"Player A wins by chance!\n\n";
					ptsA++;
				}
				else
				{
					cout<<"Player B wins by chance!\n\n";
					ptsB++;
				}
			}
		}
		else
		{
			if(curCardA==curCardB)
			{
				cout<<"Both players draw!\n\n";
			}
			else if(curCardA==1 && curCardB==13)
			{
				ptsA++;
				cout<<"Player A wins!\n\n";
			}
			else if(curCardA==13 && curCardB==1)
			{
				ptsB++;
				cout<<"Player B wins!\n\n";
			}
			else if(curCardA>curCardB)
			{
				ptsA++;
				cout<<"Player A wins!\n\n";
			}
			else
			{
				ptsB++;
				cout<<"Player B wins!\n\n";
			}
		}
		
		if(cardsA.size()==0&&cardsB.size()==0)
			break;
	
		cout<<"Press enter when player A is ready...\n";
		system("pause > nul");
		
	}
	
	cout<<"Player A: "<<ptsA<<endl;
	cout<<"Player B: "<<ptsB<<endl;
	cout<<"**";
	if(ptsA>ptsB)
	{
		cout<<"Player A wins!";
	}
	else if(ptsA<ptsB)
	{
		cout<<"Player B wins!";
	}
	else
	{
		cout<<"It's a draw!";
	}
		
	cout<<"**\n";
}
