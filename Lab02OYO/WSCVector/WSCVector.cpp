/* Kyle Tranfaglia
 * COSC220 - Lab02 - OYO - Ex.2
 * 02/13/2023
 * This Program allows the user to select a baseball team from
 * a list and displays the team's world series wins by using vectors
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Prototypes
int getLineCount(ifstream &inputFile);
void populateVector(ifstream &inputFile, vector<string> &vec);
void displayTeams(const vector<string> &vec);
int getWins(string team, const vector<string> &vec);

int main() {
    //Variables
    ifstream inputFile;
    int teamChoice = 0;
    vector<string> teams, wins;
    // Finds the lines of the file and populates the vector for teams
    inputFile.open("Teams.txt");
    populateVector(inputFile, teams);
    inputFile.close();
    // Finds the lines of the file and populates the vector for Wins 
    inputFile.open("WorldSeriesWinners.txt");
    populateVector(inputFile, wins);
    inputFile.close();

    cout << "MLB Teams" << endl;
    displayTeams(teams);
    cout << "\nChoose a Team (1-29): ";
    cin >> teamChoice;

    cout << "\nThe " << teams[teamChoice - 1] << " have won the World Series " << getWins(teams[teamChoice - 1], wins) << " times" << endl;
    
    return 0;
}

void populateVector(ifstream &inputFile, vector<string> &vec) {

    string dummy = "";
   
    while (getline(inputFile, dummy)) {
        vec.push_back(dummy);
	}
}
void displayTeams(const vector<string> &vec) {

    for (int i = 0; i < vec.size(); i++) {
        cout << i + 1 << ". " << vec[i] << endl;
    }
}

int getWins(string team, const vector<string> &vec) {

    int winCount = 0;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == team) {
            winCount++;
        }
    }
    return winCount;
}