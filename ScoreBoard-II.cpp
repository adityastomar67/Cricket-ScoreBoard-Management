/*                                                                          PBL
        Project -- Cricket ScoreBoard DisplayBoard of Two Playing Teams.
        
        Description -- 
                Basically this Program Takes Names, Player Names, and Score of Individual Player of both the Teams
                and Evaluate Every Common aspects of the Cricket ScoreBoard Sheet, and Show it on the Display, and Evaluates 
                the Nimber of Sixes, Fours throughout the Match, Best Player from Both the Teams, Best avg. Over, And lastly
                the Winning Teams Name followed by How Many Runs And Wickets. 
                
        Project Members --
                Aditya Singh Tomar    - 0905IT191006   - Main Class and additional Functions and all Explanation Comments.
                Aishwarya Shrivastava - 0905IT191007   - Worked on Score Class and its Member Functions.
                Rashika Sharma        - 0905IT191047   - Worked on Functioning of Player Class and Members.
                Saloni Kushwah        - 0905IT191052   - Worked on Team Class Data and Member Functions.

        Terms for the Acronyms -- 
                (p) -- Player
                (t) -- Team
                (m) -- Maximum
                (n) -- Minimum
                (c) -- Count
                (N) -- Number
                (w) -- Win

*/

//TODO - Need to add a automatic date adding feature in future for Better Refereence of Sved Score Sheet.       //Done
//TODO - Need to add (single Player showing functionality) for singl player choose.
//TODO - To add a draw game funtionality.
//TODO - Need to add the extra run showing in score sheet Functionality.        //Done
//TODO - To add extra Runs showing Functionality.
//TODO - Check ManOfTheMatch Function (Not Working Properly).
//TODO -

#include <iostream>      // For declares a set of functions for standard Input/Output.
#include <fstream>       // To write information to (.txt)files, and read information from files.
#include <cstring>       // Header file required for String functions.
#include <cmath>         // To declares a set of functions to perform mathematical operations.
#include <stdio.h>       // C-Language Library file for Standard Input Output.
#include <cstdlib>       // C-Language Library file to defines several general purpose functions, including dynamic memory management
#include <ctime>         // Header file declares a set of functions, macros and types to work with date and time.
#include <iomanip>       // It defines the manipulator functions to edit the Output Screen.
#include <thread>        // Manages a separate thread (class).
#include <chrono>        // The chrono library, a flexible collection of types that track time with varying degrees.
#include <bits/stdc++.h> // Standard Template Library

#define pNAME 15   // Max Length of a Player's Name.
#define tNAME 10   // Max Length of a Team's Name.
#define mOVER 5    // Max Overs can set for a Match.
#define mPLAYERS 5 // Max Players in a Team.
#define mBALLS 30  // Max Number of Balls a Player can bat.

using namespace std;

//* Classes Declaration //
class Player;     // Player Class having all the Functions for Players in the Game.
class Team;       // Team Class inherited from Player Class having Functions for both Teams.
class Score;      // Score Class inherited Team and indirectly from Player Class, Having all Score Management Functions.
class saveOutput; // New class for Saving and Opening Data to and from a (.txt) File.

//* Main Class Additional Functions Declaration //
string tWin(Score, Score);               // Returns the Name of Winning Team.
string manOfTheMatch(Score, Score, int); // For Choosing the Man of the Match from both Teams.
string time();
void welcomeScreen(Score);            // Greeting Screen with New Sheet, Load Sheet, Exit options.
void scoreSheet(Score, Score, Score); // Final Score Sheet call with options containing Save-(Y/N) and Exit.
void outputScreen(int);               // Output Screen skeleton for #WelcomeScreen, #optionN Functions and Others.
void outputScreen(int, Score);        // Output Screen skeleton for Inning Head Template.
void optionN(Score, int);             // Output skeleton of NO_OPTION in Final Sheet Display.f
int outputScreen(Score, Score);       // Output Screen skeleton for Final Score Sheet Display.
int toss();                           // Tossing Function for Randomly choosing a Team for Batting.
int show(Score, Score, int);          // For showing Random details like total fours, sixes etc.

//* Class Definitions //
class Player
{
protected:
    string p_name[mPLAYERS];    // Array of String with each Player's Name.
    int Nplayer[mPLAYERS];      // Array with Values of Highest Score of each Player.
    int pRun[mPLAYERS][mBALLS]; // Array with each Player's Number and Runs on Individual Balls.
    int pNumber;                // Number of Player.
    int NBalls;                 // Counter for Balls.
    // int NmPlayer;               // Number of Max Players.

    /* Friend Members*/
    friend Team;
    friend string tWin(Score, Score);
    friend void outputScreen(int);
    friend string manOfTheMatch(Score, Score, int);

public:
    Player();                    // Constructor Function Declaration.
    string show_pName(int, int); // For Printing Player's Name.
    void get_pName(int);         // Player NAme input Function.
    void get_pStatus(Score);     // For taking Player's Input, if he's Out, Bold or anything.
    void show_pStatus(int);      // For Showing the Player's Status.
};
class Team : public Player
{
protected:
    int mPlayer;  // Max Players of the Team.
    int tNum;     // Number of the Team.
    string tName; // Name of a Team.
    string name[mPLAYERS];

    /* Friend Members*/
    friend Player;
    friend string tWin(Score, Score);
    friend void outputScreen(int);
    friend string manOfTheMatch(Score, Score, int);

public:
    Team();              // Constructor Function Declaration.
    string show_tName(); // Print Team's Name.
    void get_tName(int); // For taking Team Name's input.
    int mPlayers();      // Function for setting up Max Player Number.
};
class Score : public Team
{
    int maxP;            // Max Player Counter for Score Team.
    int Ball_c;          // Total Count for Balls.
    int run;             // Variable For String info about Runs.
    int cRuns[mOVER][6]; // Counter for Runs.
    int m_Over;          // Max Number of Overs.
    int m_out;           // Max Out Count for a Team.
    int tScore;          // Total Score of a Team.
    int extra_run;       // Extra Runs Given.
    int dotBall;         // Count for Dot Balls.
    int wideBall;        // Count for Wide Balls.
    int cTotal4;         // Total Number of Four's by Each Player.
    int cTotal6;         // Total Number of Six's by Each Player.

    /* Friend Members*/
    friend int toss(int, int);
    friend string tWin(Score, Score);
    friend int show(Score, Score, int);
    friend int outputScreen(Score, Score);
    friend void outputScreen2(Score, Score);
    friend void outputScreen(int);
    friend void scoreSheet(Score, Score, Score);
    friend string manOfTheMatch(Score, Score, int);

    /* friend int welcomeScreen(int); 
     friend void optionN(Score); */

public:
    Score();                                // Constructor Function Declaration.
    void new_sheet(Score);                  // Function to Start the Preogram.
    void load_sheet(Score, bool);           // Function of opening a Saved Score Sheet.
    void save_sheet(Score, Score);          // Function of Saving a Score Sheet
    void add_run(char, int, int, int, int); // Add Runs in Player account.
    void sixes();                           // To Count the Totals Sixes and Returns Count.
    void fours();                           // To Count the Totals Fours and Returns Count.
    char runShow(int, int);                 //
    int m_over();                           // Max Over Function to change the Inning.
    int wicket();                           // Keeps Wicket info of the Player.
    int score_total(int);                   // Function call for Total Runs.
    int start_scoreboard(int, Score);       // Function Call where the Score Sheet Begins.
    int setExtra();                         // Adding extra Runs.
};
class saveOutput
{
private:
    streambuf *outPut;
    friend Score;

public:
    saveOutput(ofstream &file) : outPut{file.rdbuf()}
    {
        cout.rdbuf(outPut);
    }
};

//* Main Function //
int main()
{
    Score alpha;
    welcomeScreen(alpha);
    return 0;
}

//* Player Class - Member Function Definition //
Player ::Player()
{
    for (int i = 0; i < mPLAYERS; i++)
    {
        for (int j = 0; j < mBALLS; j++)
        {
            pRun[i][j] = -5;
        }
        Nplayer[i] = 0;
    }
    NBalls = 0;
}
string Player ::show_pName(int x, int y)
{
    if (x > pNumber)
    {
        cout << "###";
    }
    else
    {

        if (y == 1)
        {
            for (int i = 0; i < x; i++)
            {
                cout << "Name of the Player " << i + 1 << " : ";
                transform(p_name[i].begin(), p_name[i].end(), p_name[i].begin(), ::toupper);
                p_name[i].resize(3);
                return p_name[i];
                cout << endl;
            }
        }
        else if (y == 2)
        {
            transform(p_name[x - 1].begin(), p_name[x - 1].end(), p_name[x - 1].begin(), ::toupper);
            p_name[x - 1].resize(3);
            return p_name[x - 1];
        }
    }
}
void Player ::get_pName(int x)
{
    // p_name[x];
    for (int i = 0; i < x; i++)
    {
        cout << "Player " << i + 1 << " : ";
        cin >> p_name[i];
        if (p_name[i].length() > pNAME)
        {
            cout << endl
                 << "The expected Name is too long." << endl
                 << "Enter Again!!" << endl;
            i--;
        }
    }
}
void Player ::get_pStatus(Score t)
{
    for (int i = 0; i < t.mPlayer; i++)
    {
        for (int j = 0; j < mBALLS; j++)
        {
            if ((pRun[i][j] != -1) && (pRun[i][j] != -2) && (pRun[i][j] != -3) && (pRun[i][j] != -5))
            {
                Nplayer[i] += pRun[i][j];
            }
        }
    }
    for (int x = 0; x < t.mPlayer; x++)
    {
        for (int z = 0; z < mBALLS; z++)
        {
            // cRu
        }
    }
}
void Player ::show_pStatus(int x)
{
    if (x > pNumber)
    {
        cout << "##";
        // return NULL; //! Need to make it stop returning an extra Zero.
    }
    else
    {
        if (Nplayer[x - 1] < 10)
        {
            cout << "0";
        }
        cout << Nplayer[x - 1]; //* x = pNumber
    }
}

//* Team Class - Member Function Definition //
Team ::Team()
{
    // NmPlayer = mPlayer;
}
string Team ::show_tName()
{
    transform(tName.begin(), tName.end(), tName.begin(), ::toupper);
    tName.resize(3);
    return tName;
}
void Team ::get_tName(int x)
{
    cout << x + 1 << ". ";
    cin >> tName;
    if (tName.length() > tNAME)
    {
        cout << endl
             << "The expected Name is too long." << endl
             << "Enter Again!!" << endl;
        get_tName(x);
    }
    tNum = x;
}
int Team ::mPlayers()
{
    int n;
    cin >> n;
    while (n > mPLAYERS)
    {
        cout << endl
             << "Number of Players can't be Higher than " << mPLAYERS << "."
             << endl
             << "Enter again : ";
        cin >> n;
    }
    mPlayer = n;
    // pNumber = n;
    return n;
    // t1.show_pName(1, 2);
    // t2.show_pName(mPlayer);
}

//* Score Class - Member Function Definition //
Score ::Score()
{
    cTotal4 = 0;
    cTotal6 = 0;
    extra_run = 0;
    dotBall = 0;
    wideBall = 0;
    m_out = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cRuns[i][j] = -10;
        }
    }

    // tScore = 0;
};
void Score ::new_sheet(Score alpha)
{
    Score t1, t2;
    int check1 = 0, check2 = 0;
    system("clear");
    cout << endl
         << setw(103) << "Welcome to New ScoreBoard" << endl;
    cout << setw(104) << "---------------------------" << endl
         << endl;

    cout << "  Enter the Name of Two Playing Teams :" << endl
         << endl;
    t1.get_tName(0);
    t2.get_tName(1);
    cout << endl;
    cout << "  Enter The Number of Players for Teams : ";
    t1.mPlayers();
    t1.pNumber = t2.pNumber = t1.maxP = t2.maxP = t2.mPlayer = t1.mPlayer;

    cout << endl;
    cout << "  For Team " << t1.show_tName() << ", Enter Names for - " << endl;
    cout << " ----------------------------------------------------" << endl;
    t1.get_pName(t1.mPlayer);

    cout << endl;
    cout << "  For Team " << t2.show_tName() << ", Enter Names for - " << endl;
    cout << " ----------------------------------------------------" << endl;
    t2.get_pName(t2.mPlayer);
    cout << endl
         << "  Enter the Number Overs, You want in Match : ";
    t1.m_over();
    t2.m_Over = t1.m_Over;
    do
    {
        switch (toss())
        {
        case 1:
            if (check1 == 0)
            {
                if (check2 == 1)
                {
                    check1 = 1;
                    t1.start_scoreboard(2, t1);
                }
                else
                {
                    check1 = 1;
                    t1.start_scoreboard(1, t1);
                }
            }
            break;
        case 2:
            if (check2 == 0)
            {
                if (check1 == 1)
                {
                    check2 = 1;
                    t2.start_scoreboard(2, t2);
                }
                else
                {
                    check2 = 1;
                    t2.start_scoreboard(1, t2);
                }
            }
            break;
        }
    } while (check1 != 1 || check2 != 1);
    t1.get_pStatus(t1);
    t2.get_pStatus(t2);
    scoreSheet(alpha, t1, t2);
}
void Score ::load_sheet(Score alpha, bool yes)
{
    system("clear");
    string matchSheet;
    ifstream openFile;
    openFile.open("ScoreSheetDisplay.txt");
    while (openFile.eof() == 0)
    {
        getline(openFile, matchSheet);
        cout << matchSheet << endl;
    }
    if (yes)
    {
        optionN(alpha, 2);
    }
}
void Score ::save_sheet(Score t1, Score t2)
{
    // bool saveChoice = false;
    // ofstream sheet;
    // sheet.open("ScoreSheetDisplay.txt");
    // saveOutput savefile(sheet);
    // outputScreen(2);
    // sheet.close();

    ofstream file;
    file.open("cout.dat", ios::out);
    string line;

    // // Backup streambuffers of  cout
    // streambuf* stream_buffer_cout = cout.rdbuf();
    // streambuf* stream_buffer_cin = cin.rdbuf();

    // Get the streambuffer of the file
    streambuf *stream_buffer_file = file.rdbuf();

    // Redirect cout to file
    cout.rdbuf(stream_buffer_file);

    // cout << "This line written to file" << endl;
    outputScreen(t1, t2);

    // Redirect cout back to screen
    // cout.rdbuf(stream_buffer_cout);
    // cout << "This line is written to screen" << endl;

    file.close();
    // outputScreen2(t1,t2);
}
void Score ::add_run(char choice, int player, int ball, int cBall, int over)
{
    switch (choice)
    {
    case '0':
        pRun[player][ball] = 0;
        cRuns[over][cBall] = 0;
        break;
    case '1':
        pRun[player][ball] = 1;
        cRuns[over][cBall] = 1;
        break;
    case '2':
        pRun[player][ball] = 2;
        cRuns[over][cBall] = 2;
        break;
    case '4':
        pRun[player][ball] = 4;
        cRuns[over][cBall] = 4;
        fours();
        break;
    case '6':
        pRun[player][ball] = 6;
        cRuns[over][cBall] = 6;
        sixes();
        break;
    case 'w':
        pRun[player][ball] = cRuns[over][cBall] = wicket();
        m_out++;
        break;
    case 'W':
        pRun[player][ball] = cRuns[over][cBall] = wicket();
        m_out++;
        break;
    case 'e':
        pRun[player][ball] = cRuns[over][cBall] = setExtra();
        cout << "Continue.. :";
        break;
    case 'E':
        pRun[player][ball] = cRuns[over][cBall] = setExtra();
        cout << "Continue.. :";
        break;
    default:
        cout << "Wrong Choice. Enter Again : ";
        cin >> choice;
    }
}
void Score ::sixes()
{
    cTotal6++;
}
void Score ::fours()
{
    cTotal4++;
}
char Score ::runShow(int Ball, int Over)
{
    switch (cRuns[Over - 1][Ball - 1])
    {
    case 0:
        return '0';
        break;
    case 1:
        return '1';
        break;
    case 2:
        return '2';
        break;
    case 4:
        return '4';
        break;
    case 6:
        return '6';
        break;
    case -1:
        return 'B';
        break;
    case -2:
        return 'R';
        break;
    case -3:
        return 'C';
        break;
    case -10:
        return '#';
        break;
    }
}
int Score ::m_over()
{
    int n;
    cin >> n;
    while (n > mOVER)
    {
        cout << endl
             << "Number of Overs can't be Higher than " << mOVER << "."
             << endl
             << "Enter again : ";
        cin >> n;
        cout << endl;
        cout << endl;
    }
    m_Over = n;
    NBalls = n;
    return n;
}
int Score ::wicket()
{
    if (m_out <= maxP)
    {
        outputScreen(6);
        char localChoice;
        cout << "Enter Choice : ";
        cin >> localChoice;
        switch (localChoice)
        {
        case 'b':
            return -1;
            break;
        case 'r':
            return -2;
            break;
        case 'c':
            return -3;
            break;
        }
    }
    return 0;
}
int Score ::score_total(int x)
{
    int local_total = 0;
    for (int i = 0; i < mPLAYERS; i++)
    {
        for (int j = 0; j < mBALLS; j++)
        {
            if ((pRun[i][j] != -1) && (pRun[i][j] != -2) && (pRun[i][j] != -3) && (pRun[i][j] != -5))
            {
                local_total += pRun[i][j]; //* Adding each Player's Score.
            }
        }
    }
    // local_total += extra_run; //* Add Extra runs to local_total.
    tScore = local_total;
    if (x == 1)
    {
        if (local_total < 10)
        {
            cout << "00";
        }
        else if (local_total < 100 && local_total > 10)
        {
            cout << "0";
        }
    }
    return local_total;
}
int Score ::start_scoreboard(int inning, Score t)
{
    char rType;
    int Ball = 0;
    int over = 0;
    int pTurns = 0;
    int cBall = 0;
    if (inning == 1)
    {
        cout << endl
             << endl;
        system("clear");
        this_thread::sleep_for(chrono::seconds(2));
        cout << setw(74) << "Team " << show_tName() << " Wons the Toss!! and Choses to Bat." << endl;
        cout << setw(113.5) << "''''''''''''''''''''''''''''''''''''''''''''''" << endl
             << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(3));
        system("clear");
        outputScreen(5);
        do
        {
            system("clear");
            outputScreen(8);
            outputScreen(1, t);
            if (Ball == 0)
            {
                this_thread::sleep_for(chrono::seconds(2));
                cout << show_pName(1, 2);
                cout << " and ";
                cout << show_pName(2, 2);
                cout << " will Bat First." << endl
                     << endl;
            }
            cout << "Enter the Runs for ";
            cout << show_pName(pTurns + 1, 2);
            cout << " : ";
            do
            {
                if (cBall == 6)
                {
                    over++;
                    cBall = 0;
                }
                cin >> rType;
                add_run(rType, pTurns, Ball, cBall, over);
                Ball++;
                cBall++;
            } while ((rType != 'w') && (Ball < (m_Over * 6)) && (over != 5));
            if (Ball == (m_Over * 6))
            {
                break;
            }
            pTurns++;
        } while (pTurns < mPlayer);
        return 0;
    }
    else
    {
        cout << endl
             << endl;
        system("clear");
        this_thread::sleep_for(chrono::seconds(2));
        cout << setw(96) << "II Inning" << endl;
        cout << setw(103) << "''''''''''''''''''''''''" << endl
             << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(3));
        system("clear");
        outputScreen(5);
        do
        {
            system("clear");
            outputScreen(8);
            outputScreen(2, t);
            if (Ball == 0)
            {
                this_thread::sleep_for(chrono::seconds(2));
                cout << show_pName(1, 2);
                cout << " and ";
                cout << show_pName(2, 2);
                cout << " will Bat First." << endl
                     << endl;
            }
            cout << "Enter the Runs for ";
            cout << show_pName(pTurns + 1, 2);
            cout << " : ";
            do
            {
                if (cBall == 6)
                {
                    over++;
                    cBall = 0;
                }
                cin >> rType;
                add_run(rType, pTurns, Ball, cBall, over);
                Ball++;
                cBall++;
            } while ((rType != 'w') && (Ball < (m_Over * 6)) && (over != 5));
            if (Ball == (m_Over * 6))
            {
                break;
            }
            pTurns++;
        } while (pTurns < mPlayer);
        return 0;
    }
}
int Score ::setExtra()
{
    outputScreen(7);
    char localChoice;
    cout << "Enter Choice : ";
    cin >> localChoice;
    switch (localChoice)
    {
    case 'w':
        return 1;
        extra_run++;
        wideBall++;
        break;
    case 'd':
        return 2;
        extra_run += 2;
        dotBall++;
        break;
    }
    return 0;
}

//* Main Function's Definition //
string tWin(Score t1, Score t2)
{
    // cout << t1.score_total() << endl
    //      << t2.score_total() << endl;
    if (t1.score_total(0) > t2.score_total(0))
    {
        return t1.show_tName();
    }
    else
    {
        return t2.show_tName();
    }
}
string manOfTheMatch(Score t1, Score t2, int x)
{
    string team1, team2;
    for (int i = 1; i <= t1.mPlayer; i++)
    {
        if (t1.Nplayer[i] > t1.Nplayer[i + 1])
        {
            team1 = t1.show_pName(i, 2);
        }
        else if (t1.Nplayer[i] < t1.Nplayer[i + 1])
        {
            team1 = t1.show_pName(i + 1, 2);
        }
    }
    for (int j = 1; j <= t2.mPlayer; j++)
    {
        if (t2.Nplayer[j] > t2.Nplayer[j + 1])
        {
            team2 = t2.show_pName(j, 2);
        }
        else if (t2.Nplayer[j] < t2.Nplayer[j + 1])
        {
            team2 = t2.show_pName(j + 1, 2);
        }
    }
    if (x == 1)
    {
        return team1;
    }
    else if (x == 2)
    {
        return team2;
    }
}
string time()
{
    time_t tt;
    struct tm *ti;
    time(&tt);
    ti = localtime(&tt);
    return asctime(ti);
}
void welcomeScreen(Score alpha)
{
    char choice;
    outputScreen(1); //! For Animation, change 1 to 0.
    do
    {
        cin >> choice;
        if (choice == '1')
        {
            cout << endl
                 << endl
                 << endl
                 << endl;
            // for (int i = 0; i < 5; i++)
            // {
            //     system("clear");
            //     cout << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl
            //          << endl;
            //     this_thread::sleep_for(chrono::milliseconds(500));
            //     // cout << setw(99) << "Creating New Game" << endl;
            //     cout << setw(118) << "****************************************************" << endl
            //          << setw(118) << "**                                                **" << endl
            //          << setw(118) << "**               CREATING NEW SHEET               **" << endl
            //          << setw(118) << "**                                                **" << endl
            //          << setw(118) << "****************************************************" << endl
            //          << endl;
            //     this_thread::sleep_for(chrono::milliseconds(750));
            // }

            alpha.new_sheet(alpha);
            break;
        }
        else if (choice == '2')
        {
            alpha.load_sheet(alpha, true);
            break;
        }
        else if (choice == '3')
        {
            system("clear");
            cout << endl
                 << endl
                 << endl
                 << setw(99) << "Thank You for Using!" << endl
                 << setw(101) << "------------------------" << endl
                 << endl;
            break;
        }
        else
        {
            system("clear");
            outputScreen(1);
            cout << setw(106.5) << "ERROR!!  Incorrect Option."
                 << setw(100) << endl
                 << "Choose Again." << endl;
            cout << endl;
            cout << setw(104.5) << "Enter Your Choice Again : ";
        }

    } while (choice != '1' || choice != '2' || choice != '3');
}
void scoreSheet(Score alpha, Score t1, Score t2)
{
    char choice;
    bool saveChoice = true;
    outputScreen(t1, t2);
    outputScreen(3);
    cout << setw(103) << "Enter Your Choice :";
    do
    {
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            if (saveChoice)
            {
                // outputScreen2(t1, t2); //! Didn't Work beacuse of a fUNCTIONS.
                alpha.save_sheet(t1, t2);
                // ofstream sheet;
                // sheet.open ("score.txt");
                // outputScreen(t1,t2);
                // // sheet<< "your program is saved";
                // sheet.close();
            }
            optionN(alpha, 1);
        }
        else if (choice == 'N' || choice == 'n')
        {
            optionN(alpha, 1);
        }
        else if (choice == 'E' || choice == 'e')
        {
            system("clear");
            // system("exit");  //? Doesn't Work. Why?
        }
        else
        {
            outputScreen(t1, t2);
            outputScreen(3);
            cout << setw(105) << "The Choice is Wrong!!" << endl
                 << setw(100) << "Enter Again :";
        }
    } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n' && choice != 'E' && choice != 'e');
}
void outputScreen(int choice, Score t)
{
    switch (choice)
    {
    case 1:
        cout << setw(97.5) << "---------------" << endl;
        cout << setw(95) << "I'st INNING" << endl;
        cout << setw(97.5) << "---------------" << endl
             << endl;
        cout << setw(80) << "Team " << t.show_tName() << " is on the Field to Bat." << endl;
        cout << setw(108) << "''''''''''''''''''''''''''''''''''" << endl
             << endl
             << endl;
        break;

    case 2:
        cout << setw(97) << "----------------" << endl;
        cout << setw(95) << "II'st INNING" << endl;
        cout << setw(97) << "----------------" << endl
             << endl;
        cout << setw(83.5) << "Team " << t.show_tName() << " will Bat now." << endl;
        cout << setw(102) << "''''''''''''''''''''''''''" << endl
             << endl
             << endl;
        break;
    }
}
void outputScreen(int choice)
{
    switch (choice)
    {
    case 0:
        system("clear");
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ########################################################################################################################################################" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                      Welcome                                                                       ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                  Choose an Option                                                                  ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                 1. New ScoreBoard                                                                  ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                 2. Open Saved ScoreBoard                                                           ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                 3. Exit                                                                            ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ########################################################################################################################################################" << endl
             << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << setw(102) << "Enter Your Choice : ";

        break;
    case 1:
        system("clear");
        cout << endl
             << endl
             << endl
             << "               ########################################################################################################################################################" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                      Welcome                                                                       ##" << endl
             << "               ##                                                                  Choose an Option                                                                  ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                 1. New ScoreBoard                                                                  ##" << endl
             << "               ##                                                                 2. Open Saved ScoreBoard                                                           ##" << endl
             << "               ##                                                                 3. Exit                                                                            ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ########################################################################################################################################################" << endl
             << endl;
        break;
    case 2:
        system("clear");
        cout << endl
             << endl
             << endl
             << "               ########################################################################################################################################################" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                 1. New ScoreBoard                                                                  ##" << endl
             << "               ##                                                                 2. Exit                                                                            ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ########################################################################################################################################################" << endl
             << endl
             << endl;
        break;
    case 3:
        cout << "       |                                                                                                                                                                             |" << endl
             << "       |                                                                     Do You Want To Save This Game? (Y/N)                                                                    |" << endl
             << "       |                                                                                   Exit(E)                                                                                   |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
             << endl
             << endl;
        break;
    case 4:
        cout << "       |                                                                                                                                                                             |" << endl
             << "       |                                                                              1. New ScoreBoard                                                                              |" << endl
             << "       |                                                                              2. Exit                                                                                        |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
             << endl
             << endl;
        break;
    case 5:
        cout << endl
             << endl
             << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ########################################################################################################################################################" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                      ACRONYMS                                                                      ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     0  -  Zero                                                                     ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     1  -  Single                                                                   ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     2  -  Double                                                                   ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     4  -  Four                                                                     ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     6  -  Six                                                                      ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     W  -  Wicket                                                                   ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     E  -  Extra                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                              NOTE : Enter Runs By Giving Space Between Them Until Wicket.                                          ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                                                                                                    ##" << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ########################################################################################################################################################" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << endl
             << endl;
        break;
    case 6:
        cout << endl
             << "               ########################################################################################################################################################" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                       WICKET                                                                       ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                     B  -  Bold                                                                     ##" << endl
             << "               ##                                                                     R  -  Run Out                                                                  ##" << endl
             << "               ##                                                                     C  -  Catch                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ########################################################################################################################################################" << endl
             << endl
             << endl;
        break;
    case 7:
        cout << endl
             << "               ########################################################################################################################################################" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                       EXTRA                                                                        ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                           W  -  Wide Ball  -  (1 Extra Run)                                                        ##" << endl
             << "               ##                                                           D  -  Dot Ball   -  (2 Extra Run)                                                        ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ########################################################################################################################################################" << endl
             << endl
             << endl;
        break;
    case 8:
        cout << endl
             << endl
             << endl
             << "               ########################################################################################################################################################" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                      ACRONYMS                                                                      ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                                                     0  -  Zero                                                                     ##" << endl
             << "               ##                                                                     1  -  Single                                                                   ##" << endl
             << "               ##                                                                     2  -  Double                                                                   ##" << endl
             << "               ##                                                                     4  -  Four                                                                     ##" << endl
             << "               ##                                                                     6  -  Six                                                                      ##" << endl
             << "               ##                                                                     W  -  Wicket                                                                   ##" << endl
             << "               ##                                                                     E  -  Extra                                                                    ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ##                                              NOTE : Enter Runs By Giving Space Between Them Until Wicket.                                          ##" << endl
             << "               ##                                                                                                                                                    ##" << endl
             << "               ########################################################################################################################################################" << endl
             << endl
             << endl;
        break;
    }
}
int outputScreen(Score t1, Score t2)
{
    system("clear");
    string t;
    cout << endl
         << endl
         << setw(181) << time()
         << "       _______________________________________________________________________________________________________________________________________________________________________________" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                             SCORE DISPLAY BOARD                                                                             |" << endl
         << "       |                                                                            '''''''''''''''''''''                                                                            |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                 TEAM " << t1.show_tName() << "                                   Vs                                    TEAM " << t2.show_tName() << "                                   |" << endl
         << "       |                                                ''''''''''                                                                       ''''''''''                                  |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 01  |        " << t1.runShow(1, 1) << "            " << t1.runShow(2, 1) << "          " << t1.runShow(3, 1) << "            " << t1.runShow(4, 1) << "           " << t1.runShow(5, 1) << "           " << t1.runShow(6, 1) << "          |        " << t2.runShow(1, 1) << "            " << t2.runShow(2, 1) << "          " << t2.runShow(3, 1) << "            " << t2.runShow(4, 1) << "           " << t2.runShow(5, 1) << "           " << t2.runShow(6, 1) << "          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 02  |        " << t1.runShow(1, 2) << "            " << t1.runShow(2, 2) << "          " << t1.runShow(3, 2) << "            " << t1.runShow(4, 2) << "           " << t1.runShow(5, 2) << "           " << t1.runShow(6, 2) << "          |        " << t2.runShow(1, 2) << "            " << t2.runShow(2, 2) << "          " << t2.runShow(3, 2) << "            " << t2.runShow(4, 2) << "           " << t2.runShow(5, 2) << "           " << t2.runShow(6, 2) << "          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 03  |        " << t1.runShow(1, 3) << "            " << t1.runShow(2, 3) << "          " << t1.runShow(3, 3) << "            " << t1.runShow(4, 3) << "           " << t1.runShow(5, 3) << "           " << t1.runShow(6, 3) << "          |        " << t2.runShow(1, 3) << "            " << t2.runShow(2, 3) << "          " << t2.runShow(3, 3) << "            " << t2.runShow(4, 3) << "           " << t2.runShow(5, 3) << "           " << t2.runShow(6, 3) << "          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 04  |        " << t1.runShow(1, 4) << "            " << t1.runShow(2, 4) << "          " << t1.runShow(3, 4) << "            " << t1.runShow(4, 4) << "           " << t1.runShow(5, 4) << "           " << t1.runShow(6, 4) << "          |        " << t2.runShow(1, 4) << "            " << t2.runShow(2, 4) << "          " << t2.runShow(3, 4) << "            " << t2.runShow(4, 4) << "           " << t2.runShow(5, 4) << "           " << t2.runShow(6, 4) << "          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 05  |        " << t1.runShow(1, 5) << "            " << t1.runShow(2, 5) << "          " << t1.runShow(3, 5) << "            " << t1.runShow(4, 5) << "           " << t1.runShow(5, 5) << "           " << t1.runShow(6, 5) << "          |        " << t2.runShow(1, 5) << "            " << t2.runShow(2, 5) << "          " << t2.runShow(3, 5) << "            " << t2.runShow(4, 5) << "           " << t2.runShow(5, 5) << "           " << t2.runShow(6, 5) << "          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |    TOTAL  |                                                                                |                                                                                |" << endl
         << "       |    RUNS   |          " << t1.show_pName(1, 2) << "           " << t1.show_pName(2, 2) << "           " << t1.show_pName(3, 2) << "           " << t1.show_pName(4, 2) << "           " << t1.show_pName(5, 2) << "           |          " << t2.show_pName(1, 2) << "           " << t2.show_pName(2, 2) << "           " << t2.show_pName(3, 2) << "           " << t2.show_pName(4, 2) << "           " << t2.show_pName(5, 2) << "           |" << endl
         << "       |     BY    |                                                                                |                                                                                |" << endl
         << "       |    EACH   |           ";
    t1.show_pStatus(1);
    cout << "            ";
    t1.show_pStatus(2);
    cout << "            ";
    t1.show_pStatus(3);
    cout << "            ";
    t1.show_pStatus(4);
    cout << "            ";
    t1.show_pStatus(5);
    cout << "           |           ";
    t2.show_pStatus(1);
    cout << "            ";
    t2.show_pStatus(2);
    cout << "            ";
    t2.show_pStatus(3);
    cout << "            ";
    t2.show_pStatus(4);
    cout << "            ";
    t2.show_pStatus(5);
    cout << "           |" << endl
         << "       |   PLAYER  |                                                                                |                                                                                |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |_____________________________________________________________________________________________________________________________________________________________________________|" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |   TOTAL   |                                    " << t1.score_total(1) << " / " << t1.m_out << "                                     |                                    " << t2.score_total(1) << " / " << t2.m_out << "                                     |" << endl
         << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                Team " << tWin(t1, t2) << " Won the Match By " << show(t1, t2, 1) << " Runs, " << show(t1, t2, 2) << " Wickets.                                                                |" << endl
         << "       |                                                               '''''''''''''''''''''''''''''''''''''''''''''''                                                               |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                    TOTAL SIXES :" << show(t1, t2, 6) << "                                            TOTAL FOURS :" << show(t1, t2, 4) << "                                        BEST INNING AVG. :#                    |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                  BEST OVER AVG. :#                                                                     MAN OF THE MATCH : " << manOfTheMatch(t1, t2, 1) << ", " << manOfTheMatch(t1, t2, 2) << "                          |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    return 0;
}
void outputScreen2(Score t1, Score t2)
{
    system("clear");
    ofstream sheet;
    sheet.open("scoreboardfile.dat");
    sheet << endl
          << endl
          << setw(181) << time()
          << "       _______________________________________________________________________________________________________________________________________________________________________________" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       |                                                                             SCORE DISPLAY BOARD                                                                             |" << endl
          << "       |                                                                            '''''''''''''''''''''                                                                            |" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       |                                                 TEAM " << t1.show_tName() << "                                   Vs                                    TEAM " << t2.show_tName() << "                                   |" << endl
          << "       |                                                ''''''''''                                                                       ''''''''''                                  |" << endl
          << "       |           |                                                                                |                                                                                |" << endl
          << "       |  Over 01  |        " << t1.runShow(1, 1) << "            " << t1.runShow(2, 1) << "          " << t1.runShow(3, 1) << "            " << t1.runShow(4, 1) << "           " << t1.runShow(5, 1) << "           " << t1.runShow(6, 1) << "          |        " << t2.runShow(1, 1) << "            " << t2.runShow(2, 1) << "          " << t2.runShow(3, 1) << "            " << t2.runShow(4, 1) << "           " << t2.runShow(5, 1) << "           " << t2.runShow(6, 1) << "          |" << endl
          << "       |           |                                                                                |                                                                                |" << endl
          << "       |  Over 02  |        " << t1.runShow(1, 2) << "            " << t1.runShow(2, 2) << "          " << t1.runShow(3, 2) << "            " << t1.runShow(4, 2) << "           " << t1.runShow(5, 2) << "           " << t1.runShow(6, 2) << "          |        " << t2.runShow(1, 2) << "            " << t2.runShow(2, 2) << "          " << t2.runShow(3, 2) << "            " << t2.runShow(4, 2) << "           " << t2.runShow(5, 2) << "           " << t2.runShow(6, 2) << "          |" << endl
          << "       |           |                                                                                |                                                                                |" << endl
          << "       |  Over 03  |        " << t1.runShow(1, 3) << "            " << t1.runShow(2, 3) << "          " << t1.runShow(3, 3) << "            " << t1.runShow(4, 3) << "           " << t1.runShow(5, 3) << "           " << t1.runShow(6, 3) << "          |        " << t2.runShow(1, 3) << "            " << t2.runShow(2, 3) << "          " << t2.runShow(3, 3) << "            " << t2.runShow(4, 3) << "           " << t2.runShow(5, 3) << "           " << t2.runShow(6, 3) << "          |" << endl
          << "       |           |                                                                                |                                                                                |" << endl
          << "       |  Over 04  |        " << t1.runShow(1, 4) << "            " << t1.runShow(2, 4) << "          " << t1.runShow(3, 4) << "            " << t1.runShow(4, 4) << "           " << t1.runShow(5, 4) << "           " << t1.runShow(6, 4) << "          |        " << t2.runShow(1, 4) << "            " << t2.runShow(2, 4) << "          " << t2.runShow(3, 4) << "            " << t2.runShow(4, 4) << "           " << t2.runShow(5, 4) << "           " << t2.runShow(6, 4) << "          |" << endl
          << "       |           |                                                                                |                                                                                |" << endl
          << "       |  Over 05  |        " << t1.runShow(1, 5) << "            " << t1.runShow(2, 5) << "          " << t1.runShow(3, 5) << "            " << t1.runShow(4, 5) << "           " << t1.runShow(5, 5) << "           " << t1.runShow(6, 5) << "          |        " << t2.runShow(1, 5) << "            " << t2.runShow(2, 5) << "          " << t2.runShow(3, 5) << "            " << t2.runShow(4, 5) << "           " << t2.runShow(5, 5) << "           " << t2.runShow(6, 5) << "          |" << endl
          << "       |           |                                                                                |                                                                                |" << endl
          << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl
          << "       |           |                                                                                |                                                                                |" << endl
          << "       |    TOTAL  |                                                                                |                                                                                |" << endl
          << "       |    RUNS   |          " << t1.show_pName(1, 2) << "           " << t1.show_pName(2, 2) << "           " << t1.show_pName(3, 2) << "           " << t1.show_pName(4, 2) << "           " << t1.show_pName(5, 2) << "           |          " << t2.show_pName(1, 2) << "           " << t2.show_pName(2, 2) << "           " << t2.show_pName(3, 2) << "           " << t2.show_pName(4, 2) << "           " << t2.show_pName(5, 2) << "           |" << endl
          << "       |     BY    |                                                                                |                                                                                |" << endl
          << "       |    EACH   |           ";
    t1.show_pStatus(1);
    sheet << "            ";
    t1.show_pStatus(2);
    sheet << "            ";
    t1.show_pStatus(3);
    sheet << "            ";
    t1.show_pStatus(4);
    sheet << "            ";
    t1.show_pStatus(5);
    sheet << "           |           ";
    t2.show_pStatus(1);
    sheet << "            ";
    t2.show_pStatus(2);
    sheet << "            ";
    t2.show_pStatus(3);
    sheet << "            ";
    t2.show_pStatus(4);
    sheet << "            ";
    t2.show_pStatus(5);
    sheet << "           |" << endl
          << "       |   PLAYER  |                                                                                |                                                                                |" << endl
          << "       |           |                                                                                |                                                                                |" << endl
          << "       |_____________________________________________________________________________________________________________________________________________________________________________|" << endl
          << "       |           |                                                                                |                                                                                |" << endl
          << "       |   TOTAL   |                                    " << t1.score_total(1) << " / " << t1.m_out << "                                     |                                    " << t2.score_total(1) << " / " << t2.m_out << "                                     |" << endl
          << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       |                                                                Team " << tWin(t1, t2) << " Won the Match By " << show(t1, t2, 1) << " Runs, " << show(t1, t2, 2) << " Wickets.                                                                |" << endl
          << "       |                                                               '''''''''''''''''''''''''''''''''''''''''''''''                                                               |" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       |                    TOTAL SIXES :" << show(t1, t2, 6) << "                                            TOTAL FOURS :" << show(t1, t2, 4) << "                                        BEST INNING AVG. :#                    |" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       |                                  BEST OVER AVG. :#                                                                     MAN OF THE MATCH : " << manOfTheMatch(t1, t2, 1) << ", " << manOfTheMatch(t1, t2, 2) << "                          |" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       |                                                                                                                                                                             |" << endl
          << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    sheet.close();
}
void optionN(Score alpha, int choice)
{
    char option;
    switch (choice)
    {
    case 1:
        system("clear");
        outputScreen(2);
        cout << setw(99) << "Enter Your Choice :";
        do
        {
            cin >> option;
            if (option == '1')
            {
                alpha.new_sheet(alpha);
            }
            else if (option == '2')
            {
                system("clear");
                // system("exit");  //? Doesn't Work. Why?
            }
            else
            {
                system("clear");
                outputScreen(2);
                cout << setw(102) << "The Choice is Wrong!!" << endl
                     << setw(97) << "Enter Again :";
            }

        } while (option != 1 && option != 2);
        break;

    case 2:
        outputScreen(4);
        cout << setw(99) << "Enter Your Choice :";
        do
        {
            cin >> option;
            if (option == '1')
            {
                alpha.new_sheet(alpha);
            }
            else if (option == '2')
            {
                system("clear");
                // system("exit");
            }
            else
            {
                system("clear");
                alpha.load_sheet(alpha, false);
                outputScreen(4);
                cout << setw(102) << "The Choice is Wrong!!" << endl
                     << setw(97) << "Enter Again :";
            }

        } while (option != 1 && option != 2);
        break;
    }
}
int toss()
{
    srand((unsigned)time(0));
    int randomNumber;
    randomNumber = (rand() % 10) + 1;
    // cout<<randomNumber;
    if (randomNumber > 5)
    {
        return 2;
    }
    return 1;
}
int show(Score t1, Score t2, int option)
{
    switch (option)
    {
    case 1:
        if (t1.tScore > t2.tScore)
        {
            if ((t1.tScore - t2.tScore) < 10)
            {
                cout << "0";
            }
            return (t1.tScore - t2.tScore);
        }
        else
        {
            if ((t2.tScore - t1.tScore) < 10)
            {
                cout << "0";
            }
            return (t2.tScore - t1.tScore);
        }

        break;
    case 2:
        if (t1.m_out > t2.m_out)
        {
            return (t1.m_out - t2.m_out);
        }
        else
        {
            return (t2.m_out - t1.m_out);
        }

        break;
    case 4:
        if ((t1.cTotal4 + t2.cTotal4) < 10)
        {
            cout << "0";
        }
        return (t1.cTotal4 + t2.cTotal4);
        break;
    case 6:
        if ((t1.cTotal6 + t2.cTotal6) < 10)
        {
            cout << "0";
        }
        return (t1.cTotal6 + t2.cTotal6);
        break;
    }
    return 0;
}