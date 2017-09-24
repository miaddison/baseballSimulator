/* Advanced C++ Group project by
    Merna Addison
    Brian Burk
    Ismael Ramirez
    James Robbins
    
    9/5/17 - 10/17/17
    This program will create a simulated baseball game predicting the outcome of two selected teams 
    playing against each other.
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
using namespace std;

// Prototype function
//double determineEra ();
void determineGameWinner (string teamName, double teama, string teamNameb, double teamb);

//Global Variables
vector<string>teams = {"Chicago Cubs", "Cincinnati Reds", "Milwaukee Brewers", "Pittsburgh Pirates", "St.Louis Cardinals"};    // vector with team names
vector<double>eras = {5.00, 5.01, 5.02, 5.03, 5.04};   //vector with eras

int main()
{ 
    int temp = 0;       //temp variable to hold team choice input to be converted to vector value
    int hometeam = 0;   //holds input for hometeam choice
    int awayteam = 0;   //holds input for awayteam choice
    int count = 0;      //count variable for selection of awayteam
    
    // Ask the User for a hometeam 
    cout << "Please choose your hometeam: " << endl;        
        
    //Output all teams in the vector of teams  
    for(int x = 0; x < teams.size(); x++)
	{
        cout<< x + 1 << ". " << teams[x] << endl;
    }
    
    
    //Take input from User for hometeam
    cin >> temp;
    
    // Check if the User input is valid from the vector
    while(temp > teams.size())
    {
    	cout << "Please choose a team on the list" << endl;
    	cin >> temp;
	}
	

    //Convert input to vector index
    hometeam = temp - 1;
    
    
    //Output the choice of the User
    cout<< "You chose the " << teams[hometeam] << " as your hometeam."<< endl;
    
    // Saves the Team Name to a String for later Use
    string hometeamName = teams[hometeam];
    
    
    // Saves the Team ERA to a Double for later Use
    double hometeamERA = eras[hometeam];
    
    
    // Removes BOTH! TEAM NAME and ERA from their vectors
	teams.erase(teams.begin() + hometeam);
	eras.erase(eras.begin() + hometeam);
	
//------------------^^^   ABOVE IS HOME TEAM   ^^^-----------------//	
	
	//output directions for awayteam
    cout << "Please choose your awayteam:"<<endl;
    
    
    //Outputs the remaining teams names from the vector
    for(int x = 0; x < teams.size(); x++)
	{
        cout<< x + 1 << ". " << teams[x] << endl;
    }
    
    //Take in input for awayteam choice
    cin >> temp;
    
    // Check if the User input is valid
    while(temp > (teams.size()))
    {
    	cout << "Please choose a team on the list" << endl;
    	cin >> temp;
	}
	
	//Convert input to vector index
	awayteam = temp - 1;

    //Output the choice of the User
    cout<< "You chose the " << teams[awayteam] << " as your awayteam."<< endl;
    
    // Saves the Team Name to a String for later Use
    string awayteamName = teams[awayteam];
    
    // Saves the Team ERA to a Double for later Use
    double awayteamERA = eras[awayteam];
    
    
    // Removes BOTH! TEAM NAME and ERA from their vectors
    teams.erase(teams.begin() + awayteam);
    eras.erase(eras.begin() + awayteam);
    

    // spacing
    cout << endl;
    cout << endl;
    
    
    

    
    determineGameWinner(hometeamName, hometeamERA, awayteamName, awayteamERA);
    return 0;
}

//Function to determine the winner based on era
void determineGameWinner(string hometeam, double hometeamERA, string awayteam, double awayteamERA)
{
	srand((unsigned)time(0));
	double v1 = rand() % 100; 
	v1 = v1 / 100;
    if((hometeamERA + v1) > awayteamERA)
	{
		cout << "The " << hometeam << " win! with an era of: " << hometeamERA + v1 << endl;
		cout << "The " << awayteam << " Lose! with an era of: " << awayteamERA << endl;
	}
	else 
	{
		cout << "The " << awayteam << " win! with an era of: " << awayteamERA << endl;
		cout << "The " << hometeam << " Lose! with an era of: " << hometeamERA + v1 << endl;
	}
}

