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
	
	int curCardA,curCardB,indA,indB,ptsA,ptsB;
	
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
				cout<<"That card is not available. Please select another card.\n";
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
				cout<<"That card is not available. Please select another card.\n";
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
					cout<<"Both players draw by chance!\n";
				}
				else if(r<=75)
				{
					cout<<"Player A wins by chance!\n";
				}
				else
				{
					cout<<"Player B wins by chance!\n";
				}
			}
			else
			{
				if(r<=50)
				{
					cout<<"Player A wins by chance!\n";
				}
				else
				{
					cout<<"Player B wins by chance!\n";
				}
			}
		}
		else
		{		
			curCardA%=13;
			curCardB%=13;
			if(curCardA==curCardB)
			{
				cout<<"Both players draw!\n";
			}
			else if(curCardA>curCardB)
			{
				ptsA++;
				cout<<"Player A wins!\n";
			}
			else
			{
				ptsB++;
				cout<<"Player B wins!\n";
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
		cout<<"Player A wins!\n";
	}
	else if(ptsA<ptsB)
	{
		cout<<"Player B wins!\n";
	}
	else
	{
		cout<<"It's a draw!\n";
	}
		
	cout<<"**\n";
}
