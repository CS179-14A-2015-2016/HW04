#include <iostream>
#include <stdlib>
#include <cstdio>
#include <string>
#include <random>

using namespace std;

int main()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution dist(0,100);
	vector<int> cardsA;
	vector<int> cardsB;
	cardsA.push(0);
	cardsA.push(0);
	cardsB.push(0);
	cardsB.push(0);
	
	for(int i=1;i<=13;i++)
	{
		cardsA.push(i);
		cardsB.push(i);
	}
	
	int curCardA,curCardB,indA,indB,ptsA,ptsB;
	
	while(true)
	{
		
		while(true)
		{
			cout<<"A - Available cards:";
			for(int i=0;i<cardsA.size();i++)
				cout<<" "<<cardsA.at(i);
			cout<<"\na>\n";
			cin>>curCardA;
			
			bool found=false;
			for(int i=0;i<cardsA.size();i++)
			{
				if(cardsA.at(i)==curCardA)
				{
					found=true;
					cardsA.erase(cardsA.begin()+i);
				}
			}
			if(!found)
			{
				cout<<"That card is not available. Please select another card.\n";
				continue;
			}
			system("CLS");
			cout<<"Press enter when player B is ready...";
			system("pause > nul");
			a=false;
			break;
		}
		
		while(true)
		{
			system("CLS");
			cout<<"B - Available cards:";
			for(int i=0;i<cardsB.size();i++)
				cout<<" "<<cardsB.at(i);
			cout<<"\nb>\n";
			cin>>curCardB;
			
			bool found=false;
			for(int i=0;i<cardsB.size();i++)
			{
				if(cardsA.at(i)==curCardB)
				{
					found=true;
					cardsB.erase(cardsB.begin()+i);
				}
			}
			
			if(!found)
			{
				cout<<"That card is not available. Please select another card.\n";
				continue;
			}
			a=false;
			break;
			
		}
		
		system("CLS");
		cout<<"Joust "<<curCardA<<" vs "<<curCardB<<"\n";
		if(curCardA==0||curCardB==0)
		{
			int r=dist(mt);
			
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
		
		if(curCardA.size()==0&&curCardB.size()==0)
			break;
		
		cout<<"Press enter when player A is ready...";
		system("pause > nul");
		
	}
	
	cout<<"Player A: "<<ptsA<<endl;
	cout<<"Player B: "<<ptsB<<endl;
	cout<<"**";
	if(ptsA>ptsB)
	{
		cout<<"Player A wins!\n";
	}
	else if(ptsA==ptsB)
	{
		cout<<"Player B wins!\n";
	}
	else
	{
		cout<<"It's a draw!\n";
	}
		
	cout<<"**\n";
}
