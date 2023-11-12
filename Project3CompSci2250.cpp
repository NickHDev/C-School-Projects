#include "Horse.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

int main()
{
	int horseNum, maxDist, horseRun;
	string horseName, riderName;
	srand(time(0));
	int randNum = 0;
	char yes = 'y';
	bool hasWon = false,continueRace = true,horsesNamed = false;
	cout << "How many horses to race?" << endl;
	cin >> horseNum;
	while(horseNum <= 0)
	{
		cout << "Please Enter valid Horse number ";
		cin >> horseNum;
	}		
	Horse *horseptr = nullptr;
	horseptr = new Horse[horseNum];
	while (continueRace == true)
	{
		yes = 'y';
		if (horsesNamed == false)
		{
			for (int x = 0; x < horseNum; x++)
			{
				cout << "Horse " << x + 1 << " name?: ";
				cin >> horseName;
				cout << "Rider " << x + 1 << " name?: ";
				cin >> riderName;
				horseptr[x].setName(horseName,riderName);	
			}
			horsesNamed = true;
		}

		cout << "Enter max distance to race of 100 or greater" << endl;
		cin >> maxDist;
		while (maxDist < 100)
		{
			cout << "Please Enter Valid Number Above 100";
			cin >> maxDist;
		}
		
		cout << "Start" << endl;
		for (int x = 0; x < horseNum; x++)
		{
			horseptr[x].displayHorse(maxDist);
		}
		while (yes == 'y' || hasWon == false)
		{
			cout << "Are you ready for next second?(y/n): ";
			cin >> yes;
			if (yes == 'y')
			{
				for (int x = 0; x < horseNum; x++)
				{
					randNum = rand() % 100 + 1;
					horseptr[x].setMaxRun(randNum);
					horseptr[x].runASecond();
					horseptr[x].displayHorse(maxDist);
					hasWon = horseptr[x].hasWon(maxDist);
					if(hasWon == true)
					{
						cout << horseptr[x].getName() << " has won" << endl;
						yes = 'n';
						break;
					}
					
				}
			}
			else { break; }
		}
		for (int x = 0; x < horseNum; x++)
		{
			cout << horseptr[x].getName() << " has won " << horseptr[x].getWins() << " races." << endl;
		}

		cout << "Do you wish to continue?(y/n)";
		cin >> yes;
		if (yes == 'y')
		{
			continueRace = true;
			for (int x = 0; x < horseNum; x++)
			{
				horseptr[x].sendToGate();
			}
		}
		else { continueRace = false; }
	}
}
