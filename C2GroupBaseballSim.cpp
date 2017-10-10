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
const int PLAYER_ARRAY = 3;

// Struct for team values
struct team{
    string teamName;
    double teamEra;
    double pitcherEra;
    double playerBA [PLAYER_ARRAY];
}team[ARRAY_SIZE];

// Prototype function
void determineGameWinner (struct team homeTeam, struct team awayTeam);
void clearInput();
double HometeamAdv();

int main()
try
{
    //Input file stream objects
    ifstream inTeamData;
    
    // Variables
    int teamNum = 0;       //variable to hold team choice input to be converted to vector value
    int hometeam = 0;       //holds input for hometeam choice
    int awayteam = 0;       //holds input for awayteam choice
    int count = 0;          //count variable for selection of awayteam
    string input = "";      // for taking in input
    bool valid = false;     //validates input for type
    bool playAgain = false; // Allows user to play again
    
    // Open files
    inTeamData.open("TeamData.csv");
    
    // Read file into struct array
    if(inTeamData.is_open()){
        while(inTeamData.good()){
            for(int i = 0; i < ARRAY_SIZE; i++){
                getline(inTeamData,input);
                stringstream ss(input);
                getline(ss, input, ',');
                team[i].teamName = input;
                getline(ss, input, ',');
                team[i].teamEra = atof(input.c_str());
                getline(ss, input, ',');
                team[i].pitcherEra = atof(input.c_str());
                for(int x = 0; x < PLAYER_ARRAY; x++){
                    getline(ss, input, ',');
                    team[i].playerBA[x] = atof(input.c_str());
                }
            }
        }
    }
    // Testing for data into Team
    /*for(int i=0; i < ARRAY_SIZE; i++){
        cout << "Name: " << team[i].teamName << "\nTeam Era: " << team[i].teamEra
             << "\nPitcher ERA: " << team[i].pitcherEra << "\nPlayer1 BA: " << team[i].playerBA[0] << "\nPlayer2 BA: "
             << team[i].playerBA[1] << "\nPlayer3 BA: " << team[i].playerBA[2] << "\n-----------------------" <<endl;
    }*/
    
    do{     // Main loop for game
        do{     // Loop to select hometeam with user validation
            
            //Output directions
            cout<<"Please choose your hometeam:"<<endl;
    
            //Output all teams
            for(int x = 0; x<ARRAY_SIZE; x++){
                cout<< x+1 << ". " << team[x].teamName << endl;
            }
        
            // Take in input for hometeam choice and check that input is right type
            if(cin >> teamNum){
                cin.ignore();
                //cout << "valid input type" << endl; //testing input type
                // input is valid
                valid = true;
            
                // Check input within correct range
                if(teamNum < 1 || teamNum > ARRAY_SIZE){
                    //cout << "input out of range" << endl;   // testing input range
                    cout << "Please choose team number 1 through " << ARRAY_SIZE << "." << endl;
                }
            }else{
                clearInput();
                //cout << "input not valid" << endl; //testing input type
                cout << "Please choose team number 1 through " << ARRAY_SIZE << "." << endl;
            }
        }while(teamNum < 1 || teamNum > ARRAY_SIZE || !valid); //end loop for hometeam
        
        // Reset valid to false so next user input can be validated for type
        valid = false;
    
        //Convert input to vector index
        hometeam = teamNum - 1;
    
        //Output choice
        cout<< "You chose the " << team[hometeam].teamName << " as your hometeam."<< endl;
    
        //testing
        //cout << team[hometeam].teamName << team[hometeam].teamEra <<endl;
    
        // Loop to determine awayteam with validation
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
    
            // Take in input for hometeam choice and check that input is right type
            if(cin >> teamNum){
                cin.ignore();
                // input is valid flag true
                valid = true;
                //cout << "valid input type" << endl; //testing input type
            
                // Check input range
                if(teamNum < 1 || teamNum > (ARRAY_SIZE-1)){
                    //cout << "input out of range" << endl;   //testing input range
                    cout << "Please choose team number 1 through " << (ARRAY_SIZE-1)<< "." << endl;
                }
            }else{
                clearInput();
                //cout << "input not valid" << endl; //testing input type
                cout << "Please choose team number 1 through " << ARRAY_SIZE << "." << endl;
            }
        }while(teamNum < 1 || teamNum > (ARRAY_SIZE-1) || !valid); // end loop for away team
    
        //Convert input to vector index
        if(teamNum > hometeam) {    //corrects for user number one start versus vector zero start
            awayteam = teamNum;
        }else{
            awayteam = teamNum - 1; //corrects for user and vector start and then for the vector index skipped for hometeam
        }
        //Output choice
        cout<< "You chose the " << team[awayteam].teamName << " as your awayteam."<< endl;
    
        //testing
        //cout << team[awayteam].teamName << team[awayteam].teamEra <<endl;
    
        // Pass home and away teams into method to determine winner based on team era
        determineGameWinner(team[hometeam], team[awayteam] /*, homeAdvantage*/);
        
        // Call Hometeam advantage for testing that output is between 0.01 and 0.10
        //cout << HometeamAdv() << endl;
            
        // determine if user would like to try again and input validation
        cout << "Would you like to play again? (y/n)" << endl;
          
        // take in user input on whether they'd like to play again
        input = "";
        cin >> input;
        clearInput();
        
        // Check input either y or n prompt input again if not
        while(input != "n" && input != "N" && input != "y" && input != "Y"){
            //cout << "\"" << input << "\"" << endl;
            //cout << "input not valid" << endl; //testing input
            cout << "If you would like to play again please enter 'y'. \n" <<
            "Otherwise enter 'n' to quit. " << endl;
            cin >> input;
            clearInput();
        }

        // change bool flag to answer given
        if(input == "y" || input == "Y"){
            playAgain = true;
        }else{
            playAgain = false;
        }
    }while(playAgain == true); // end game loop
    
    return 0;
}
catch(exception& e){
    cerr << e.what() << '\n';
    system("pause");
    return 1;
}
catch(...){
    cerr << "exception \n";
    system("pause");
    return 2;
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
//Fuction to determine hometeam advantage between 1-10%
double HometeamAdv(){
    // the code below gives the home team adv
    srand((unsigned)time(0));
    double Adv = rand() % 10 + 1;  // picks a random number between 1 - 10
    Adv = Adv / 100;	// after number is picked, puts it in decimal format
    
    return Adv;
}
// function to clear input
void clearInput(){
    cin.clear();
    cin.ignore(80, '\n');
}
