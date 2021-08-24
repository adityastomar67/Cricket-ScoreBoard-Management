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

// Classes Declaration //
class Player;     // Player Class having all the Functions for Players in the Game.
class Team;       // Team Class inherited from Player Class having Functions for both Teams.
class Score;      // Score Class inherited Team and indirectly from Player Class, Having all Score Management Functions.
class saveOutput; // New class for saving Data to a (.txt) File.

// Main Class Additional Functions Declaration //
int toss();                           // Tossing Function for Randomly choosing a Team for Batting.
int show(Score, Score, int);          // For showing Random details like total fours, sixes etc.
string tWin(Score, Score, int, int);  // Returns the Name of Winning Team.
void welcomeScreen(Score);            // Greeting Screen with New Sheet, Load Sheet, Exit options.
void scoreSheet(Score, Score, Score); // Final Score Sheet call with options containing Save-(Y/N) and Exit.
void outputScreen(int);               // Output Screen skeleton for #WelcomeScreen, #optionN Functions and Others.
void outputScreen(int, Score);        // Output Screen skeleton for Inning Head Template.
void outputScreen(Score, Score);      // Output Screen skeleton for Final Score Sheet Display.
void optionN(Score, int);             // Output skeleton of NO_OPTION in Final Sheet Display.

// Class Definitions //
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

public:
Player(){
   for (int i = 0; i < mPLAYERS; i++)
    {
        for (int j = 0; j < mBALLS; j++)
        {
            pRun[i][j] = 0;
        }
        Nplayer[i] = 0;
    } 
}
    ~Player()
    {
        cout << "Destructor Called" << endl;
    }
    void get_pName(int x)
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
    } // Player NAme input Function.
    void show_pName(int x, int y)
    {
        if (y == 1)
        {
            for (int i = 0; i < x; i++)
            {
                cout << "Name of the Player " << i + 1 << " : ";
                cout << p_name[i] << endl;
            }
        }
        else if (y == 2)
        {
            cout << p_name[x - 1];
        }
    }                      // For Printing Player's Name.
    void get_pStatus();    // For taking Player's Input, if he's Out, Bold or anything.
    int show_pStatus(int); // For Showing the Player's Status.
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

public:
    ~Team()
    {
        cout << "Destructor(Team) Called" << endl;
    }
    string show_tName()
    {
        transform(tName.begin(), tName.end(), tName.begin(), ::toupper);
        tName.resize(3);
        return tName;
    } // Print Team's Name.
    void get_tName(int x)
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
    }               // For taking Team Name's input.
    int mPlayers(); // Function for setting up Max Player Number.
};
class Score : public Team
{
    int maxP;      // Max Player Counter for Score Team.
    int Ball_c;    // Total Count for Balls.
    int run;       // Variable For String info about Runs.
    int over_c;    // Counter for Runs.
    int m_Over;    // Max Number of Overs.
    int m_out;     // Max Out Count for a Team.
    int t1Score;   // Total Score of a Team.
    int t2Score;   // Total Score of a Team.
    int extra_run; // Extra Runs Given.
    int dotBall;   // Count for Dot Balls.
    int wideBall;  // Count for Wide Balls.
    int cTotal4;   // Total Number of Four's by Each Player.
    int cTotal6;   // Total Number of Six's by Each Player.

    /* Friend Members*/
    friend int toss(int, int);
    friend string tWin(Score, Score);
    friend int show(Score, Score, int);
    friend void outputScreen(Score, Score);
    /* friend int welcomeScreen(int); 
     friend void optionN(Score); */

public:
    Score()
    {
        cTotal4 = 0;
        cTotal6 = 0;
    }
    ~Score()
    {
        cout << endl
             << "Destructor(Score) Called" << endl;
    }
    void new_sheet(); // Function to Start the Preogram.
    // void load_sheet(Score, bool);  // Function of opening a Saved Score Sheet.
    // void save_sheet(Score, Score); // Function of Saving a Score Sheet
    int add_run(char, int, int); // Add Runs in Player account.
    void over_complete();        // Over complete and getting Next Over Function.
    int m_over();                // Max Over Function to change the Inning.
    void sixes();                // To Count the Totals Sixes and Returns Count.
    void fours();                // To Count the Totals Fours and Returns Count.
    int wicket();                // Keeps Wicket info of the Player.
    int score_total();           // Function call for Total Runs.
    int start_scoreboard(int);   // Function Call where the Score Sheet Begins.
    int setExtra();              // Adding extra Runs.
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

int main()
{
    Score alpha;
    welcomeScreen(alpha);
    return 0;
}
void welcomeScreen(Score alpha)
{
    char choice;
    // outputScreen(1); // After Fininshing change it from 1 to 0.
    do
    {
        cin >> choice;
        if (choice == '1')
        {
            // cout << endl
            //      << endl
            //      << endl
            //      << endl;
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

            alpha.new_sheet();
            break;
        }
        else if (choice == '2')
        {
            // alpha.load_sheet(alpha, true);
            break;
        }
        else if (choice == '3')
        {
            system("clear");
            cout << endl
                 << endl
                 << setw(99) << "Thank You for Using!!" << endl
                 << setw(101) << "------------------------" << endl
                 << endl;
            break;
        }
        else
        {
            system("clear");
            // outputScreen(1);
            cout << setw(106.5) << "ERROR!!  Incorrect Option."
                 << setw(100) << endl
                 << "Choose Again." << endl;
            cout << endl;
            cout << setw(104.5) << "Enter Your Choice Again : ";
        }

    } while (choice != '1' || choice != '2' || choice != '3');
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
void Score ::new_sheet()
{
    Score t1, t2;
    int plNum;
    int ovNum;
    int check1 = 0, check2 = 0;
    // system("clear");
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
    cin >> plNum;
    t1.mPlayer = t2.mPlayer = plNum;
    t1.maxP = t2.maxP = plNum;

    cout << endl;
    cout << "  For Team " << t1.show_tName() << ", Enter Names for - " << endl;
    cout << " ----------------------------------------------------" << endl;
    t1.get_pName(plNum);

    cout << endl;
    cout << "  For Team " << t2.show_tName() << ", Enter Names for - " << endl;
    cout << " ----------------------------------------------------" << endl;
    t2.get_pName(plNum);
    cout << endl
         << "  Enter the Number Overs, You want in Match : ";
    cin >> ovNum;
    t1.m_Over = t2.m_Over = ovNum;
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
                    t1.start_scoreboard(2);
                }
                else
                {
                    check1 = 1;
                    t1.start_scoreboard(1);
                }
            }
            break;
        case 2:
            if (check2 == 0)
            {
                if (check1 == 1)
                {
                    check2 = 1;
                    t2.start_scoreboard(2);
                }
                else
                {
                    check2 = 1;
                    t2.start_scoreboard(1);
                }
            }
            break;
        }
    } while (check1 != 1 || check2 != 1);
    cout << t1.score_total() << endl;
    cout << t2.score_total() << endl;
    cout << endl
         << endl;
    cout << "this is the no of 4 before returning the function :" << t1.cTotal4 << endl;
    cout << "this is the no of 6 before returning the function :" << t1.cTotal6 << endl;
    cout << endl
         << endl;
    cout << "this is the no of 4 before returning the function :" << t2.cTotal4 << endl;
    cout << "this is the no of 6 before returning the function :" << t2.cTotal6 << endl;
}
int Score ::start_scoreboard(int inning)
{
    char rType;
    int Ball = 0;
    int pTurns = 0;
    int cBall = 6;
    if (inning == 1)
    {
        cout << endl
             << endl;
        // system("clear");
        // this_thread::sleep_for(chrono::seconds(2));
        cout << setw(74) << "Team " << show_tName() << " Wons the Toss!! and Choses to Bat." << endl;
        cout << setw(113.5) << "''''''''''''''''''''''''''''''''''''''''''''''" << endl
             << endl
             << endl;
        // this_thread::sleep_for(chrono::seconds(3));
        // system("clear");
        // outputScreen(5);
        do
        {
            // system("clear");
            // outputScreen(8);
            // outputScreen(1, t);
            if (Ball == 0)
            {
                // this_thread::sleep_for(chrono::seconds(2));
                show_pName(1, 2);
                cout << " and ";
                show_pName(2, 2);
                cout << " will Bat First." << endl
                     << endl;
            }
            cout << "Enter the Runs for ";
            show_pName(pTurns + 1, 2);
            cout << " : ";
            do
            {
                // while (cBall != 0)
                // {
                cin >> rType;
                add_run(rType, pTurns, Ball);
                Ball++;
                // cBall--;
                // }
                // cBall = 6;
                // over_complete();
            } while ((rType != 'w') && (Ball < (m_Over * 6)));
            // cout << t.score_total()<<endl;
            // cout << t.tScore<<endl;

            if (Ball == (m_Over * 6))
            {
                break;
            }
            pTurns++;
        } while (pTurns < mPlayer);
        // cout << t.score_total();
        cout << endl
             << endl;
        cout << "this is the no of 4 before returning the function :" << cTotal4 << endl;
        cout << "this is the no of 6 before returning the function :" << cTotal6 << endl;

        return 0;
    }
    else
    {
        // cout << endl
        //      << endl;
        // // system("clear");
        // // this_thread::sleep_for(chrono::seconds(2));
        // cout << setw(96) << "II Inning" << endl;
        // cout << setw(103) << "''''''''''''''''''''''''" << endl
        //      << endl
        //      << endl;
        // // this_thread::sleep_for(chrono::seconds(3));
        // // system("clear");
        // outputScreen(5);
        // do
        // {
        //     // system("clear");
        //     outputScreen(8);
        //     outputScreen(2, t);
        //     if (Ball == 0)
        //     {
        //         // this_thread::sleep_for(chrono::seconds(2));
        //         t.show_pName(1, 2);
        //         cout << " and ";
        //         t.show_pName(2, 2);
        //         cout << " will Bat First." << endl
        //              << endl;
        //     }
        //     cout << "Enter the Runs for ";
        //     t.show_pName(pTurns + 1, 2);
        //     cout << " : ";
        //     do
        //     {
        //         // while (cBall != 0)
        //         // {
        //         cin >> rType;
        //         t.add_run(rType, pTurns, Ball);
        //         Ball++;
        //         // cBall--;
        //         // }
        //         // cBall = 6;
        //         // over_complete();
        //     } while ((rType != 'w') && (Ball < (m_Over * 6)));

        //     if (Ball == (m_Over * 6))
        //     {
        //         break;
        //     }
        //     pTurns++;
        // } while (pTurns < mPlayer);
        // return t.score_total();
    }
}
int Score ::add_run(char choice, int player, int ball)
{
    switch (choice)
    {
    case '0':
        pRun[player][ball] = 0;
        break;
    case '1':
        pRun[player][ball] = 1;
        break;
    case '2':
        pRun[player][ball] = 2;
        break;
    case '4':
        pRun[player][ball] = 4;
        // fours();
        cTotal4++;
        break;
    case '6':
        pRun[player][ball] = 6;
        // sixes();
        cTotal6++;
        break;
    case 'w':
        pRun[player][ball] = wicket();
        m_out++;
        break;
    case 'W':
        pRun[player][ball] = wicket();
        m_out++;
        break;
    // case 'e':
    //     pRun[player][ball] = setExtra();
    //     cout << "Continue.. :";
    //     break;
    // case 'E':
    //     pRun[player][ball] = setExtra();
    //     cout << "Continue.. :";
    //     break;
    default:
        cout << "Wrong Choice. Enter Again : ";
        cin >> choice;
    }
}
int Score ::wicket()
{
    if (m_out <= maxP)
    {
        // outputScreen(6);
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
int Score ::score_total()
{
    int local_total = 0;
    for (int i = 0; i < mPLAYERS; i++)
    {
        for (int j = 0; j < mBALLS; j++)
        {
            if ((pRun[i][j] != -1) && (pRun[i][j] != -2) && (pRun[i][j] != -3))
            {
                local_total += pRun[i][j]; // Adding each Player's Score.
            }
        }
    }
    // local_total += extra_run; // Add Extra runs to local_total.
    // tScore = local_total;
    return local_total;
}