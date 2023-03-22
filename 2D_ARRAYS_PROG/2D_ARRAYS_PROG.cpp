// authour: Abigail Garvey
// KNo: K00286554
// date: 22/03/2023 12:31

#include <iostream>
#include <sstream>
#include <iomanip>

#define COLS 5
#define ROWS 7

#define CELLSIZE 8


// who doesnt like a good presentation?
#define RED "\033[31m"
#define BOLDRED "\033[1m\033[31m" 
#define CYAN "\033[36m"
#define DEFAULT "\033[0m"


using namespace std;

void rowInput(string l, int usageRow[COLS])
{
    stringstream stream = stringstream(l);
    for (int i = 0; i < COLS; i++)
        stream >> usageRow[i];
    
}

void input(int usage[ROWS][COLS])
{
    cout << CYAN << "INSTRUCTIONS\n";
    cout << BOLDRED << "Please seperate the 5 numbers using a space\n";
    cout << "When finished a row hit enter\n";
    cout << "The colums of this matrix repesent the lab number\n";
    cout << "The rows of this matrix repesent the day\n";
    cout << DEFAULT << endl;

    for (int i = 0; i < ROWS; i++)
    {
        string line;
        getline(cin, line);
        rowInput(line, usage[i]);
    }

}
// util
string formatString(string str)
{


    int d = CELLSIZE - str.length();
    int pad = d / 2;
    int pad2 = d - pad;
    return string(pad, ' ') + str + string(pad2, ' ');
}


void solve(int usage[ROWS][COLS])
{

    cout << '|' << setfill('-') << setw(CELLSIZE) << "" << "|" << setfill('-') << setw(CELLSIZE) << "" << "|" << setfill('-') << setw(CELLSIZE) << "" << "|" << setfill('-') << setw(CELLSIZE) << "" << '|' << setfill('-') << setw(CELLSIZE) << "" << '|'<< endl;
    cout << "|" << formatString("Lab 1") << "|";
    cout << formatString("Lab 2") << "|";
    cout << formatString("Lab 3") << "|";
    cout << formatString("Lab 4") << "|";
    cout << formatString("Lab 5") << "|\n";
    cout << '|' << setfill('-') << setw(CELLSIZE) << "" << "|" << setfill('-') << setw(CELLSIZE) << "" << "|" << setfill('-') << setw(CELLSIZE) << "" << "|" << setfill('-') << setw(CELLSIZE) << "" << '|' << setfill('-') << setw(CELLSIZE) << "" << '|' << endl;
    cout << '|';
    for (int i = 0; i < COLS; i++)
    {
        int total = 0;
        for (int j = 0; j < ROWS; j++)
            total += usage[j][i];

        stringstream ss;
        ss << fixed << setprecision(2) << (double)total/ROWS;
        cout << formatString(ss.str()) << "|";
        
    }
    cout << "\n";
    cout << '|' << setfill('-') << setw(CELLSIZE) << "" << "|" << setfill('-') << setw(CELLSIZE) << "" << "|" << setfill('-') << setw(CELLSIZE) << "" << "|" << setfill('-') << setw(CELLSIZE) << "" << '|' << setfill('-') << setw(CELLSIZE) << "" << '|' << endl;


}

int main()
{
    // init usage to 0
    int usage[ROWS][COLS] = { 0 };
    input(usage);
    solve(usage);
}

