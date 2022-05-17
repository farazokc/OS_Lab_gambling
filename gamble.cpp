#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	double startingMoney, betAmount;
	int choice;
	
	srand(time(NULL));
	
	cout << "Enter starting amount: ";
	cin >> startingMoney;
	
	if(startingMoney <= 0)
	{
		while(startingMoney <= 0)
		{
			cout << "Enter valid amount: ";
			cin >> startingMoney;
		}
	}
	
	while(startingMoney > 0)
	{
		cout << "\nEnter amount to bet: ";
		cin >> betAmount;
		
		if(betAmount > startingMoney)
		{
			cout << "You cannot bet more amount than you own.\n";
			while(betAmount > startingMoney || betAmount <= 0)
			{
				cout << "Please enter valid amount to bet: ";
				cin >> betAmount;
			}
		}
		
		cout << "Choose heads(0) or tails(1): ";
		cin >> choice;
		
		if(choice != 0 && choice != 1)
		{
			while(choice != 0 && choice != 1)
			{
				cout << "Enter heads(0) or tails(1) only: ";
				cin >> choice;
			}
		}
		
		int coin = rand() % 2;
		
		if(coin == 0)
		{
			cout << "\nCoin roll = HEADS\n\n";
		}
		else
		{
			cout << "\nCoin roll = TAILS\n\n";
		}
		
		if(coin == choice)
		{
			startingMoney += betAmount;
			cout << "You won. Your amount = " << startingMoney;
		}
		else
		{
			startingMoney -= betAmount;
			cout << "You lost. Your amount = " << startingMoney << endl;
		}
	}
	
	cout << "\nYou have lost all your money. Better luck next time.";
}
