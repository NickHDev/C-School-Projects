#include "Horse.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Horse::Horse()
{
	name = " ";
	rider = " ";
	maxRunningDistPerSecond = 0;
	distanceTraveled = 0;
	racesWon = 0;
}

void Horse::setName(string horseName,string horseRider)
{
	name = horseName;
	rider = horseRider;
}
void Horse::setMaxRun(int randNum)
{
	maxRunningDistPerSecond = randNum;
}
void Horse::runASecond()
{
	distanceTraveled += maxRunningDistPerSecond;
}

void Horse::sendToGate()
{
	distanceTraveled = 0;
}

bool Horse::hasWon(int goalLength)
{
	bool hasWon = false;
	if(distanceTraveled >= goalLength)
	{
		hasWon = true;
		racesWon += 1;
	}
	else
	{
		hasWon = false;
	}
	return hasWon;
}

int Horse::getWins()
{
	return racesWon;
}

string Horse::getName()
{
	return name;
}

void Horse::displayHorse(int goalLength)
{
	cout << "|";
	for (int x = 0; x < goalLength; x+=10)
	{
		if (x < distanceTraveled) 
		{
			cout << "-";
		}	
	}
	cout << ">";
	for (int x = 0; x < goalLength; x+=10)
	{
		if (x > distanceTraveled)
		{
			cout << " ";
		}
	}
	cout << "| " << "Horse " << name << "ridden by " << rider << endl;
}