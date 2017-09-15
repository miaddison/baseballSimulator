// generalasPossible.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Prototype function
double determineEra ();
void determineGameWinner (double teama, double teamb);

int main()
{
	string team_a = "team A";
	string team_b = "team B";
	double team_a_era;
	double team_b_era;
	srand (time(NULL));

	team_a_era = determineEra();
	cout << "team a era: " << team_a_era << endl;
	team_b_era = determineEra();
	cout << "team b era: " << team_b_era << endl;
	
	determineGameWinner(team_a_era, team_b_era);
    return 0;
}

double determineEra(){
	double r = ((double) rand() / RAND_MAX);
	return r;
}

void determineGameWinner(double teama, double teamb){
	if (teama < teamb){
		cout << "Team A wins!" << endl;
	}
	else {
		cout << "Team B wins!" << endl;
	}
}
