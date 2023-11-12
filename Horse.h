#ifndef Horse_H
#define Horse_H
#include <string>
#include <cstring>
using namespace std;

class Horse
{
private:
	string name;
	string rider;
	int maxRunningDistPerSecond;
	int distanceTraveled;
	int racesWon;
public:
	Horse();
	void setName(string, string);
	void setMaxRun(int);
	void runASecond();
	void sendToGate();
	bool hasWon(int);
	int getWins();
	string getName();
	void displayHorse(int goalLength);
};
#endif
