/* Advanced C++ Group project by
 Merna Addison   merna.addison@gmail.com
 Brian Burk
 Ismael Ramirez
 James Robbins
 
 9/5/17 - 10/17/17
     This program will create a simulated baseball game predicting the outcome of two selected teams
     playing against each other.This program reads in data from a csv file to an array of structs.
     This program utilizes input validation on all inputs. Then determines the potential outcome of
     the two teams at bat for each inning and then uses that information to determine the potential
     winner of the game. Hometeam advantage is also factored in and is determined by a random percentage
     of up to 10%. 
 */


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <ctime>
using namespace std;

// Global Variable
const int ARRAY_SIZE = 5;  // Array size
const int PLAYER_ARRAY = 3; // Team member batting average array

// Struct for team values
struct team{
    string teamName;
    double teamEra;
    double pitcherEra;
    double playerBA [PLAYER_ARRAY];
}team[ARRAY_SIZE];

// Prototype functions
void determineGameWinner (struct team homeTeam, struct team awayTeam, int[], int Gamesize);
double HometeamAdv();
bool inning (bool atBat1, bool atBat2, bool atBat3);
bool atBat (double pitcherERA, double batterBA);
void clearInput();

int main()
try
{
    //Input file stream objects
    ifstream inTeamData;
    
    // Variables
    int teamNum = 0;       // Variable to hold team choice input to be converted to vector value
    int hometeam = 0;       // Holds input for hometeam choice
    int awayteam = 0;       // Holds input for awayteam choice
    int count = 0;          // Count variable for selection of awayteam
    string input = "";      // For taking in input
    bool valid = false;     // Validates input for type
    bool playAgain = false; // Allows user to play again
    int gameSize = 9; // Holds the amount of innings in a game
    int gameArray[gameSize]; // Array of innings representing a baseball game
    
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
            determineGameWinner(team[hometeam], team[awayteam], gameArray, gameSize /*, homeAdvantage*/);
            
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
            //Function to determine the winner of a baseball game based on pitcher ERA and player batting averages
            void determineGameWinner(struct team home, struct team away, int gameArray[], int gameSize){
                int homeScore = 0;
                int awayScore = 0;
                for (int x = 0; x < gameSize; x++){
                    gameArray[x] = inning(atBat(home.pitcherEra, away.playerBA[0]), atBat(home.pitcherEra, away.playerBA[1]), atBat(home.pitcherEra, away.playerBA[2]));
                    if (gameArray[x] == 1){
                        homeScore++;
                    }
                }
                for (int x = 0; x < gameSize; x++){
                    gameArray[x] = inning(atBat(away.pitcherEra, away.playerBA[0]), atBat(away.pitcherEra, home.playerBA[1]), atBat(away.pitcherEra, home.playerBA[2]));
                    if (gameArray[x] == 1){
                        awayScore++;
                    }
                }
                if (homeScore > awayScore){
                    cout << "Home team " << home.teamName << " wins!" << endl;
                }
                else{
                    cout << "Away team " << away.teamName << " wins!" << endl;
                }
                /*if (scoreCount > 4){
                 cout << "The home team: " << home.teamName << " wins!" << endl;
                 }
                 else{
                 cout << "The away team: " << away.teamName << " wins!" << endl;
                 }*/
            }
            //Fuction to determine hometeam advantage between 1-10%
            double HometeamAdv(){
                // the code below gives the home team adv
                srand((unsigned)time(0));
                double Adv = rand() % 10 + 1;  // picks a random number between 1 - 10
                Adv = Adv / 100;    // after number is picked, puts it in decimal format (0.01-0.10)
                
                return Adv;
            }
            
            //Function to determine winner of an inning
            bool inning(bool atBat1, bool atBat2, bool atBat3){
                if (atBat1 + atBat2 + atBat3 > 1){
                    cout << "Home team won inning" << endl;
                    return 1;
                }
                else {
                    cout << "Away team won inning" << endl;
                    return 0;
                }
            }
            
            //Function to determine winner of an at bat
            bool atBat (double pitcherERA, double batterBA){
                if ((pitcherERA / 9) + HometeamAdv() > (batterBA)){
                    cout << "Pitcher wins at bat" << endl;
                    return 1;
                }
                else {
                    cout << "Batter wins at bat" << endl;
                    return 0;
                }
            }
            
            // function to clear input
            void clearInput(){
                cin.clear();
                cin.ignore(80, '\n');
            }

