/* Advanced C++ Group project by
    Merna Addison   merna.addison@gmail.com
    Brian Burk
    Ismael Ramirez 
    James Robbins
    
    9/5/17 - 10/17/17
    This program will create a simulated baseball game predicting the outcome of two selected teams 
    playing against each other.
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <sstream>
using namespace std;

// Global Variable
const int ARRAY_SIZE = 5;  // Array size

// Struct for team values
struct team{
    //string leagueName;
    string teamName;
    double teamEra;
    //double pitcherEra;
    //double player1BatAvg;
    //double player2BatAvg;
    //double player3BatAvg;
}team[ARRAY_SIZE];

// Prototype function
void determineGameWinner (struct team homeTeam, struct team awayTeam);

int main()
{
    //Input file stream objects
    ifstream inTeamData;
    
    // Variables
    int temp = 0;       //temp variable to hold team choice input to be converted to vector value
    int hometeam = 0;   //holds input for hometeam choice
    int awayteam = 0;   //holds input for awayteam choice
    int count = 0;      //count variable for selection of awayteam
    string input;
    string newline = "\n";
    vector<string>tempArray;

    
    // Open files
    inTeamData.open("TeamData.csv");
    
    // Read file into tempArray
    if(inTeamData.is_open()){
        while(getline(inTeamData, input)){
            stringstream ss(input);
            while(getline(ss, input, ',')){
                tempArray.push_back(input);
            }
        }
    }
    
    
    // Testing file into tempArray
    /*for(int i = 0; i < tempArray.size(); i++){
        cout << tempArray[i] << endl;
    }*/
    
    // tempArray into Team
    count = 0;
    for(int i = 0; i < ARRAY_SIZE; i++){
        //team[i].leagueName = tempArray[count++];
        team[i].teamName = tempArray[count++];
        team[i].teamEra = atof(tempArray[count++].c_str());
        //team[i].pitcherEra = atof(tempArray[count++].c_str());
        //team[i].player1BatAvg = atof(tempArray[count++].c_str());
        //team[i].player2BatAvg = atof(tempArray[count++].c_str());
        //team[i].player3BatAvg = atof(tempArray[count++].c_str());
    }

    // Testing for teampArray into Team
    /*for(int i=0; i < ARRAY_SIZE; i++){
        cout << "Name: " << team[i].teamName << " Era: " << team[i].teamEra << endl;
    }*/

    do{
        //Output directions
        cout<<"Please choose your hometeam:"<<endl;
    
        //Output all teams
        for(int x = 0; x<ARRAY_SIZE; x++){
            cout<< x+1 << ". " << team[x].teamName << endl;
        }
        
        //Take in input for hometeam choice
        cin >> temp;
        
        // Check input
        if(temp < 1 || temp > ARRAY_SIZE){
            cout << "Please choose team number 1 through " << ARRAY_SIZE << "." << endl;
        }
    }while(temp < 1 || temp > ARRAY_SIZE);
    
    //Convert input to vector index
    hometeam = temp - 1;
    
    //Output choice
    cout<< "You chose the " << team[hometeam].teamName << " as your hometeam."<< endl;
    
    //testing
    //cout << team[hometeam].teamName << team[hometeam].teamEra <<endl;
    
    do{
        //output directions for awayteam
        cout << "Please choose your awayteam:"<<endl;
    
        //Output all teams skipping chosen hometeam
        count = 0;
        for(int x = 0; x<ARRAY_SIZE; x++){
            if(x != hometeam){
                count++;
                cout<< count << ". " << team[x].teamName << endl;
            }
        }
    
        //Take in input for awayteam choice
        cin >> temp;
        
        // Check input
        if(temp < 1 || temp > (ARRAY_SIZE-1)){
            cout << "Please choose team number 1 through " << (ARRAY_SIZE-1)<< "." << endl;
        }
    }while(temp < 1 || temp > (ARRAY_SIZE-1));
    
    //Convert input to vector index
    if(temp>hometeam) {    //corrects for user number one start versus vector zero start
        awayteam = temp;
    }else{
        awayteam = temp - 1; //corrects for user and vector start and then for the vector index skipped for hometeam
    }
	//Output choice
    cout<< "You chose the " << team[awayteam].teamName << " as your awayteam."<< endl;
    
    //testing
    //cout << team[awayteam].teamName << team[awayteam].teamEra <<endl;
    
    // Pass home and away teams into method to determine winner based on team era
    determineGameWinner(team[hometeam], team[awayteam] /*, homeAdvantage*/);
    
    return 0;
}

//Function to determine the winner based on era
void determineGameWinner(struct team home, struct team away /*,homeAdv*/){
    if (home.teamEra /*+ homeAdv*/ < away.teamEra){
		cout << "The " << home.teamName << " win!" << endl;
	}
	else {
		cout << "The " << away.teamName << " win!" << endl;
	}
}
