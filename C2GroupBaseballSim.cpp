// generalasPossible.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdlib.h>
//#include <time.h>
#include <vector>
using namespace std;

// Prototype function
//double determineEra ();
void determineGameWinner (double teama, double teamb);

//Global Variables
vector<string>teams = {"Chicago Cubs", "Cincinnati Reds", "Milwaukee Brewers", "Pittsburgh Pirates", "St.Louis Cardinals"};    // vector with team names
vector<double>eras = {4.08, 5.25, 4.04, 4.27, 3.86};   //vector with eras

int main()
{ 
    int temp = 0;       //temp variable to hold team choice input to be converted to vector value
    int hometeam = 0;   //holds input for hometeam choice
    int awayteam = 0;   //holds input for awayteam choice
    
    /*string team_a = "team A";
    string team_b = "team B";
    double team_a_era;
	double team_b_era;
	srand (time(NULL));

	team_a_era = determineEra();
	cout << "team a era: " << team_a_era << endl;
	team_b_era = determineEra();
	cout << "team b era: " << team_b_era << endl;*/
    
    //Output directions
    cout<<"Please choose your hometeam:"<<endl;
    
    //Output all teams
    for(int x = 0; x<teams.size(); x++){
        cout<< x+1 << ". " << teams[x] << endl;
    }
    
    //Take in input for hometeam choice
    cin >> temp;
    
    //Convert input to vector index
    hometeam = temp - 1;
    
    //Output choice
    cout<< "You chose the " << teams[hometeam] << " as your hometeam."<< endl;
    
	//output directions for awayteam
    cout << "Please choose your awayteam:"<<endl;
    
    //Output all teams skipping chosen hometeam
    for(int x = 0; x<teams.size(); x++){
        if(x != hometeam){
            cout<< x + 1 << ". " << teams[x] << endl;
        }
      	//I want to work on this to find a way to display numbers correctly to user but still retreive correct index based on user input	
    }
    
    //Take in input for awayteam choice
    cin >> temp;
    
    //Convert input to vector index
    awayteam = temp - 1;
    
	//Output choice
    cout<< "You chose the " << teams[awayteam] << " as your awayteam."<< endl;
    
    determineGameWinner(hometeam, awayteam);
    return 0;
}

/*double determineEra(){
	double r = ((double) rand() / RAND_MAX);
	return r;
}*/

/*void determineGameWinner(double teama, double teamb){
    if (teama < teamb){
        cout << "Team A wins!" << endl;
    }
    else {
        cout << "Team B wins!" << endl;
    }
}*/

//Function to determine the winner based on era
void determineGameWinner(double hometeam, double awayteam){
    if (eras[hometeam] < eras[awayteam]){
		cout << "The " << teams[hometeam]<< " win!" << endl;
	}
	else {
		cout << "The " << teams[awayteam]<< " win!" << endl;
	}
}
