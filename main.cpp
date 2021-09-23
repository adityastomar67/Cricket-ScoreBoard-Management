/*                                                                          PBL
        Project -- Cricket ScoreBoard DisplayBoard of Two Playing Teams.
        
        Description -- 
                Basically this Program Takes Names, Player Names, and Score of Individual Player of both the Teams
                and Evaluate Every Common aspects of the Cricket ScoreBoard Sheet, and Show it on the Display, and Evaluates 
                the Number of Sixes, Fours throughout the Match, Best Player from Both the Teams, Best avg. Over, And lastly
                the Winning Teams Name followed by How Many Runs And Wickets they have Won. 
                
        Project Members --
                Aditya Singh Tomar    - 0905IT191006   - Main Class and additional Functions and all Explanation Comments.
                Aishwarya Shrivastava - 0905IT191007   - Worked on "Score" Class and its Member Functions.
                Rashika Sharma        - 0905IT191047   - Worked on Functioning of "Player" Class and Members.
                Saloni Kushwah        - 0905IT191052   - Worked on "Team" Class Data and Member Functions.

        Terms for the Acronyms -- 
                (p) -- Player
                (t) -- Team
                (m) -- Maximum
                (n) -- Minimum
                (c) -- Count
                (N) -- Number
                (w) -- Win

*/

//TODO - Need to add a automatic date adding feature in future for Better Refereence of Saved Score Sheet.      //Done
//TODO - Need to add (single Player showing functionality) for singl player choose.
//TODO - To add a draw game funtionality.                                                                       //Done
//TODO - Need to add the extra run showing in score sheet Functionality.                                        //Done
//TODO - To add extra Runs showing Functionality.
//TODO - Check ManOfTheMatch Function (Not Working Properly).                                                   //Done
//TODO - Best Inning Average functionality is yet to be added.                                                  //Done
//TODO - Best Over Average functionality is yet to be added.                                                    //Done

#include <iostream>      // For declares a set of functions for standard Input/Output.
#include <cstring>       // Header file required for String functions.
#include <stdio.h>       // C-Language Library file for Standard Input Output.
#include <ctime>         // Header file declares a set of functions, macros and types to work with date and time.
#include <iomanip>       // It defines the manipulator functions to edit the Output Screen.
#include <thread>        // Manages a separate thread (class).
#include <chrono>        // The chrono library, a flexible collection of types that track time with varying degrees.
#include <bits/stdc++.h> // Standard Template Library

#define pNAME 15   // Max Length of a Player's Name.
#define tNAME 10   // Max Length of a Team's Name.
#define nNAME 3    // Min Length of Any Name.
#define mOVER 5    // Max Overs can set for a Match.
#define mPLAYERS 5 // Max Players in a Team.
#define mBALLS 30  // Max Number of Balls a Player can bat.

using namespace std;

//* Classes Declaration //
class Player; // Player Class having all the Functions for Players in the Game.
class Team;   // Team Class inherited from Player Class having Functions for both Teams.
class Score;  // Score Class inherited Team and indirectly from Player Class, Having all Score Management Functions.

//* Main Class Additional Functions Declaration //
string tWin(Score, Score);               // Returns the Name of Winning Team.
string manOfTheMatch(Score, Score, int); // For Choosing the Man of the Match from both Teams.
string time();                           //
void welcomeScreen(Score);               // Greeting Screen with New Sheet, Load Sheet, Exit options.
void scoreSheet(Score, Score, Score);    // Final Score Sheet call with options containing Save-(Y/N) and Exit.
void outputScreen(int);                  // Output Screen skeleton for #WelcomeScreen, #optionN Functions and Others.
void outputScreen(int, Score);           // Output Screen skeleton for Inning Head Template.
void outputScreen(Score, Score, int);    // Output Screen skeleton for Final Score Sheet Display.
void optionN(Score, int);                // Output skeleton of NO_OPTION in Final Sheet Display.f
void overAvg(Score, Score);              // For Getting the Best Over Average.
void inningAvg(Score, Score, int);       // For Getting the Best Inning Average.
int toss();                              // Tossing Function for Randomly choosing a Team for Batting.
int show(Score, Score, int);             // For showing Random details like total fours, sixes etc.

//* Class Definitions //
class Player
{
protected:
    string p_name[mPLAYERS];    // Array of String with each Player's Name.
    int Nplayer[mPLAYERS];      // Array with Values of Highest Score of each Player.
    int pRun[mPLAYERS][mBALLS]; // Array with each Player's Number and Runs on Individual Balls.
    int pNumber;                // Number of Player.
    int NBalls;                 // Counter for Balls.

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
    string tName; // Name of a Team.
    int mPlayer;  // Max Players of the Team.
    int tNum;     // Number of the Team.

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
    friend string tWin(Score, Score);
    friend string manOfTheMatch(Score, Score, int);
    friend void outputScreen2(Score, Score);
    friend void outputScreen(Score, Score, int);
    friend void scoreSheet(Score, Score, Score);
    friend void outputScreen(int);
    friend int toss(int, int);
    friend int show(Score, Score, int);
    friend void overAvg(Score, Score);
    friend void inningAvg(Score, Score, int);

public:
    Score();                                // Constructor Function Declaration.
    void new_sheet(Score);                  // Function to Start the Preogram.
    void add_run(char, int, int, int, int); // Add Runs in Player account.
    void sixes();                           // To Count the Totals Sixes and Returns Count.
    void fours();                           // To Count the Totals Fours and Returns Count.
    char runShow(int, int);                 // For adding the Functionality to Final ScoreSheet, to Show Runs of Each Over.
    int m_over();                           // Max Over Function to change the Inning.
    int wicket();                           // Keeps Wicket info of the Player.
    int score_total(int);                   // Function call for Total Runs.
    int start_scoreboard(int, Score);       // Function Call where the Score Sheet Begins.
    int setExtra();                         // Adding extra Runs.
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
        else if (p_name[i].length() < nNAME)
        {
            cout << endl
                 << "The expected Name is too Short." << endl
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
}
void Player ::show_pStatus(int x)
{
    if (x > pNumber)
    {
        cout << "##";
    }
    else
    {
        if (Nplayer[x - 1] < 10)
        {
            cout << "0";
        }
        cout << Nplayer[x - 1]; //? x = pNumber
    }
}

//* Team Class - Member Function Definition //
Team ::Team()
{
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
    else if (tName.length() < nNAME)
    {
        cout << endl
             << "The expected Name is too Short." << endl
             << "Enter Again!!" << endl;
        get_tName(x);
    }
    tNum = x;
}
int Team ::mPlayers()
{
    int n;
    cin >> n;
    while (n > mPLAYERS || n <= 0)
    {
        cout << endl
             << "Number of Players can't be Higher then " << mPLAYERS << " or Less then or Equals to 0."
             << endl
             << "Enter again : ";
        cin >> n;
    }
    mPlayer = n;
    return n;
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
};
void Score ::new_sheet(Score alpha)
{
    Score t1, t2;

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
         << "  Enter the Number of Overs, You want in Match : ";
    t1.m_over();
    t2.m_Over = t1.m_Over;

    int check1 = 0, check2 = 0;
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
void Score ::add_run(char choice, int player, int ball, int cBall, int over)
{
    switch (choice)
    {
    case '0':
        pRun[player][ball] = cRuns[over][cBall] = 0;
        break;
    case '1':
        pRun[player][ball] = cRuns[over][cBall] = 1;
        break;
    case '2':
        pRun[player][ball] = cRuns[over][cBall] = 2;
        break;
    case '4':
        pRun[player][ball] = cRuns[over][cBall] = 4;
        fours();
        break;
    case '6':
        pRun[player][ball] = cRuns[over][cBall] = 6;
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
    while (n > mOVER || n <= 0)
    {
        cout << endl
             << "Number of Overs can't be Higher then " << mOVER << " or Less then or Equals to 0."
             << endl
             << "Enter again : ";
        cin >> n;
    }
    m_Over = n;
    // NBalls = n;
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
        case 'B':
            return -1;
            break;
        case 'b':
            return -1;
            break;
        case 'R':
            return -2;
            break;
        case 'r':
            return -2;
            break;
        case 'C':
            return -3;
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
        // this_thread::sleep_for(chrono::seconds(2));
        cout << setw(74) << "Team " << show_tName() << " Wons the Toss!! and Choses to Bat." << endl;
        cout << setw(113.5) << "''''''''''''''''''''''''''''''''''''''''''''''" << endl
             << endl
             << endl;
        // this_thread::sleep_for(chrono::seconds(3));
        system("clear");
        outputScreen(5);
        do
        {
            system("clear");
            outputScreen(8);
            outputScreen(1, t);
            if (Ball == 0)
            {
                // this_thread::sleep_for(chrono::seconds(2));
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
        // this_thread::sleep_for(chrono::seconds(2));
        cout << setw(96) << "II - Inning" << endl;
        cout << setw(103) << "''''''''''''''''''''''''" << endl
             << endl
             << endl;
        // this_thread::sleep_for(chrono::seconds(3));
        system("clear");
        outputScreen(5);
        do
        {
            system("clear");
            outputScreen(8);
            outputScreen(2, t);
            if (Ball == 0)
            {
                // this_thread::sleep_for(chrono::seconds(2));
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
    case 'W':
        return 1;
        extra_run++;
        wideBall++;
        break;
    case 'w':
        return 1;
        extra_run++;
        wideBall++;
        break;
    case 'D':
        return 2;
        extra_run += 2;
        dotBall++;
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
    for (int i = 1; i < t1.mPlayer; i++)
    {
        if (t1.Nplayer[i - 1] > t1.Nplayer[i])
        {
            team1 = t1.show_pName(i, 2);
        }
        else if (t1.Nplayer[i - 1] < t1.Nplayer[i])
        {
            team1 = t1.show_pName(i + 1, 2);
        }
    }
    for (int i = 1; i < t2.mPlayer; i++)
    {
        if (t2.Nplayer[i - 1] > t2.Nplayer[i])
        {
            team2 = t2.show_pName(i, 2);
        }
        else if (t2.Nplayer[i - 1] < t2.Nplayer[i])
        {
            team2 = t2.show_pName(i + 1, 2);
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
            for (int i = 0; i < 5; i++)
            {
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
                     << endl
                     << endl
                     << endl
                     << endl
                     << endl;
                // this_thread::sleep_for(chrono::milliseconds(500));
                // cout << setw(99) << "Creating New Game" << endl;
                cout << setw(118) << "****************************************************" << endl
                     << setw(118) << "**                                                **" << endl
                     << setw(118) << "**               CREATING NEW SHEET               **" << endl
                     << setw(118) << "**                                                **" << endl
                     << setw(118) << "****************************************************" << endl
                     << endl;
                // this_thread::sleep_for(chrono::milliseconds(750));
            }

            alpha.new_sheet(alpha);
            break;
        }
        else if (choice == '2')
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
    if (t1.score_total(0) == t2.score_total(0))
    {
        char choice;
        // bool saveChoice = true;
        outputScreen(t1, t2, 2);
        outputScreen(3);
        cout << setw(103) << "Enter Your Choice :";
        do
        {
            cin >> choice;
            if (choice == 'N' || choice == 'n')
            {
                alpha.new_sheet(alpha);
            }
            else if (choice == 'E' || choice == 'e')
            {
                system("clear");
                // system("exit");  //? Doesn't Work. Why?
            }
            else
            {
                outputScreen(t1, t2, 2);
                outputScreen(3);
                cout << setw(105) << "The Choice is Wrong!!" << endl
                     << setw(100) << "Enter Again :";
            }
        } while (choice != 'N' && choice != 'n' && choice != 'E' && choice != 'e');
    }
    else
    {
        char choice;
        // bool saveChoice = true;
        outputScreen(t1, t2, 1);
        outputScreen(3);
        cout << setw(103) << "Enter Your Choice :";
        do
        {
            cin >> choice;
            if (choice == 'N' || choice == 'n')
            {
                alpha.new_sheet(alpha);
            }
            else if (choice == 'E' || choice == 'e')
            {
                system("clear");
                // system("exit");  //? Doesn't Work. Why?
            }
            else
            {
                outputScreen(t1, t2, 1);
                outputScreen(3);
                cout << setw(105) << "The Choice is Wrong!!" << endl
                     << setw(100) << "Enter Again :";
            }
        } while (choice != 'N' && choice != 'n' && choice != 'E' && choice != 'e');
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
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ########################################################################################################################################################" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                      Welcome                                                                       ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                  Choose an Option                                                                  ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                 1. New ScoreBoard                                                                  ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                 2. Exit                                                                            ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(150));
        cout << "               ########################################################################################################################################################" << endl
             << endl;
        // this_thread::sleep_for(chrono::seconds(2));
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
             << "               ##                                                                 2. Exit                                                                            ##" << endl
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
             << "       |                                                                                 New Game(N)                                                                                 |" << endl
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
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ########################################################################################################################################################" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                      ACRONYMS                                                                      ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     0  -  Zero                                                                     ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     1  -  Single                                                                   ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     2  -  Double                                                                   ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     4  -  Four                                                                     ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     6  -  Six                                                                      ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     W  -  Wicket                                                                   ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                     E  -  Extra                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                              NOTE : Enter Runs By Giving Space Between Them Until Wicket.                                          ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ##                                                                                                                                                    ##" << endl;
        // this_thread::sleep_for(chrono::milliseconds(100));
        cout << "               ########################################################################################################################################################" << endl;
        // this_thread::sleep_for(chrono::seconds(1));
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
void outputScreen(int choice, Score t)
{
    switch (choice)
    {
    case 1:
        cout << setw(97.5) << "----------------" << endl;
        cout << setw(94) << "I - INNING" << endl;
        cout << setw(97.5) << "----------------" << endl
             << endl;
        cout << setw(80) << "Team " << t.show_tName() << " is on the Field to Bat." << endl;
        cout << setw(108) << "''''''''''''''''''''''''''''''''''" << endl
             << endl
             << endl;
        break;

    case 2:
        cout << setw(97) << "----------------" << endl;
        cout << setw(95) << "II - INNING" << endl;
        cout << setw(97) << "----------------" << endl
             << endl;
        cout << setw(83.5) << "Team " << t.show_tName() << " will Bat now." << endl;
        cout << setw(102) << "''''''''''''''''''''''''''" << endl
             << endl
             << endl;
        break;
    }
}
void outputScreen(Score t1, Score t2, int x)
{
    switch (x)
    {
    case 1:
        system("clear");
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
             << "       |                   TOTAL SIXES :" << show(t1, t2, 6) << "                                            TOTAL FOURS :" << show(t1, t2, 4) << "                                        BEST INNING AVG :";
        inningAvg(t1, t2, 1);
        cout << "              |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       |                                 BEST OVER AVG :";
        overAvg(t1, t2);
        cout << "                                                                 MAN OF THE MATCH : " << manOfTheMatch(t1, t2, 1) << ", " << manOfTheMatch(t1, t2, 2) << "                          |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
        // cout << t1.dotBall;
        // cout << t1.wideBall;
        // cout << t2.dotBall;
        // cout << t2.wideBall;
        // cout << endl;
        break;
    case 2: // for game draw
        system("clear");
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
             << "       |                                                                                  Game Draw.                                                                                 |" << endl
             << "       |                                                               '''''''''''''''''''''''''''''''''''''''''''''''                                                               |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       |                   TOTAL SIXES :" << show(t1, t2, 6) << "                                            TOTAL FOURS :" << show(t1, t2, 4) << "                                        BEST INNING AVG :";
        inningAvg(t1, t2, 2);
        cout << ", (For Both)       |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       |                                 BEST OVER AVG :";
        overAvg(t1, t2);
        cout << "                                                                    MAN OF THE MATCH : " << manOfTheMatch(t1, t2, 1) << ", " << manOfTheMatch(t1, t2, 2) << "                          |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
        break;
    }
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
                // alpha.load_sheet(alpha, false);
                outputScreen(4);
                cout << setw(102) << "The Choice is Wrong!!" << endl
                     << setw(97) << "Enter Again :";
            }

        } while (option != 1 && option != 2);
        break;
    }
}
void overAvg(Score t1, Score t2)
{
    int i, j, temp1, temp2, temp3, temp4, temp5;
    float avg;
    bool test = true;
    temp1 = temp2 = temp3 = temp4 = temp5 = 0;

    for (i = 0; i < t1.m_Over; i++)
    {
        for (j = 0; j < 6; j++)
        {
            // cout<<t1.cRuns[i][j];
            if (t1.cRuns[i][j] > 0)
            {
                // t1.cRuns[i][j] += temp1;
                temp1 += t1.cRuns[i][j];
            }
        }
        temp2 = temp1 > temp2 ? temp1 : temp2;
        temp1 = 0;
    }
    // temp1 = 0;
    for (i = 0; i < t2.m_Over; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (t2.cRuns[i][j] > 0)
            {
                // t2.cRuns[i][j] += temp3;
                temp3 += t2.cRuns[i][j];
            }
        }
        temp4 = temp3 > temp4 ? temp3 : temp4;
        temp3 = 0;
    }
    temp5 = temp2 > temp4 ? temp2 : temp4;
    temp1 = temp2 = 0;
    for (i = 0; i < t1.m_Over; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            temp1 += t1.cRuns[i][j];
            if (temp5 == temp1 && test)
            {
                cout << i + 1 << " ,";
                test = false;
                break;
            }
        }
    }
    for (int i = 0; i < t2.m_Over; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            temp2 += t2.cRuns[i][j];
            if (temp5 == temp2 && test)
            {
                cout << i + 1 << " ,";
                test = false;
                break;
            }
        }
    }
    avg = (temp5 / 6.0);
    if (avg < 10)
    {
        cout << "0";
    }

    cout << fixed << setprecision(1) << avg;
}
void inningAvg(Score t1, Score t2, int x)
{
    float run;
    run = t1.score_total(0) > t2.score_total(0) ? t1.score_total(0) : t2.score_total(0);
    run = run / t1.m_Over;
    if (x == 1)
    {
        cout << tWin(t1, t2) << " ,";
        if (run < 10)
        {
            cout << "0";
        }
        cout << fixed << setprecision(1) << run;
    }
    else
    {
        if (run < 10)
        {
            cout << "0";
        }
        cout << fixed << setprecision(1) << run;
    }
}
int toss()
{
    srand((unsigned)time(0));
    int randomNumber;
    randomNumber = (rand() % 10) + 1;
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