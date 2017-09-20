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
    int count = 0;      //count variable for selection of awayteam
    
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
            count++;
            cout<< count << ". " << teams[x] << endl;
        }
    }
    
    //Take in input for awayteam choice
    cin >> temp;
    
    //Convert input to vector index
    if(temp>hometeam) {    //corrects for user number one start versus vector zero start
        awayteam = temp;
    }else{
        awayteam = temp - 1; //corrects for user and vector start and then for the vector index skipped for hometeam
    }
	//Output choice
    cout<< "You chose the " << teams[awayteam] << " as your awayteam."<< endl;
    
    determineGameWinner(hometeam, awayteam);
    return 0;
}

//Function to determine the winner based on era
void determineGameWinner(double hometeam, double awayteam){
    if (eras[hometeam] < eras[awayteam]){
		cout << "The " << teams[hometeam]<< " win!" << endl;
	}
	else {
		cout << "The " << teams[awayteam]<< " win!" << endl;
	}
}
