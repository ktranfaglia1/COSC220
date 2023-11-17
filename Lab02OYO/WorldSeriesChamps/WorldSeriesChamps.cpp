/* Kyle Tranfaglia
 * COSC220 - Lab02 - OYO
 * 02/13/2023
 * This Program allows the user to select a baseball team from
 * a list and displays the team's world series wins  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Prototypes
int getLineCount(ifstream &inputFile);
void populateArray(ifstream &inputFile, string a[]);
void displayTeams(string a[], int size);
int getWins(string team, string a[], int size);

int main() {
    //Variables
    ifstream inputFile;
    int teamSize = 0, winSize = 0, teamChoice = 0;
    string teamName = "";
    // Finds the lines of the file and populates the array for Wins
    inputFile.open("Teams.txt");
    if (!inputFile) {
		cerr << "Error opening file.\n";
		return 5;
    }
    teamSize = getLineCount(inputFile);
    string teams[teamSize];
    populateArray(inputFile, teams);
    inputFile.close();
    // Finds the lines of the file and populates the array for Wins 
    inputFile.open("WorldSeriesWinners.txt");
    winSize = getLineCount(inputFile);
    string wins[winSize];
    populateArray(inputFile, wins);
    inputFile.close();

    cout << "MLB Teams" << endl;
    displayTeams(teams, teamSize);
    cout << "\nChoose a Team (1-29): ";
    cin >> teamChoice;

    // cout << "stuff" << endl;

    // cout << teams[26] << endl;
    // cout << teams[28] << endl;
    // cout << teams[teamChoice - 1] << endl;
    cout << "The " << teams[teamChoice - 1] << " have won the World Series " << getWins(teams[teamChoice - 1], wins, winSize) << " times" << endl;
    
    return 0;
}
// Function to get number of days listed in file, taking in reference to opened file and returns integer value
int getLineCount(ifstream &inputFile) {
	
	// Variables
	string line = "";
	int lineCount = 0;
	
	// Reads in file line by line and if read is successful, linecount increments. Loop terminates when pointer
	// hits EOF, meaning no more lines can be read in
	while (getline(inputFile, line)) {
			lineCount++;
		}
	// Resets pointer in opened file to beginning
	inputFile.clear();
	inputFile.seekg(0L, ios::beg);
	
	return lineCount;
}

void populateArray(ifstream &inputFile, string a[]) {

string dummy = "";
int count = 0;
while (getline(inputFile, dummy)) {
    a[count++] = dummy;
	}
}
void displayTeams(string a[], int size) {

    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << a[i] << endl;
    }
}

int getWins(string team, string a[], int size) {

    int winCount = 0;

    for (int i = 0; i < size; i++) {
        if (a[i] == team) {
            winCount++;
        }
    }
    return winCount;
}