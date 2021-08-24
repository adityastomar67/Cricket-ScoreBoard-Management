/*                                                                          PBL
        Project -- Cricket ScoreBoard DisplayBoard of Two Playing Teams.
        
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

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define pNAME 15   // Max Length of a Player's Name.
#define tNAME 10   // Max Length of a Team's Name.
#define mOVER 5    // Max Overs can set for a Match.
#define mPLAYERS 5 // Max Players in a Team.
#define mBALLS 30  // Max Number of Balls a Player can bat.
// const int fileCount = 0; // Counter for Number of Saved Sheets of Match.

using namespace std;

// Classes Declaration //
class Player;
class Team;
class Score;
class saveOutput;

// Main Class Additional Functions Declaration //
int toss();                           // Tossing Function for Randomly choosing a Team for Batting.
void welcomeScreen(Score);            // Greeting Screen with New Sheet, Load Sheet, Exit options.
void scoreSheet(Score, Score, Score); // Final Score Sheet call with options containing Save-(Y/N) and Exit.
void outputScreen(int);               // Output Screen skeleton for #WelcomeScreen & #optionN Functions.
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
    int NmPlayer;               // Number of Max Players.

    /* Friend Members*/

public:
    Player();                  // Constructor Function Declaration.
    void get_pName(int);       // Player NAme input Function.
    void show_pName(int, int); // For Printing Player's Name.
    void get_pStatus(int);     // For taking Player's Input, if he's Out, Bold or anything.
    int show_pStatus();        // For Showing the Player's Status.
};
class Team : public Player
{
protected:
    string tName; // Name of a Team.
    int mPlayer;  // Max Players of the Team.
    string name[mPLAYERS];

    /* Friend Members*/
    friend Player;

public:
    int tNum;                // Number of the Team.
    Team();                  // Constructor Function Declaration.
    void get_tName(int);     // For taking Team Name's input.
    string show_tName();     // Print Team's Name.
    void mPlayers();         // Function for setting up Max Player Number.
    void get_tStatus();      // To get the Status of the Team, how many are Out and Remainings.
    void show_tStatus();     // Showing Team's Status.
    void tWin(Score, Score); // Returns the Name of Winning Team.
    /* int get_p(); */
};
class Score : public Team
{
    int Ball_c;    // Total Count for Balls.
    int run;       // Variable For String info about Runs.
    int over_c;    // Counter for Runs.
    int m_Over;    // Max Number of Overs.
    int Out;       // To set Player Out.
    int m_out;     // Max Out Count for a Team.
    int tScore;    // Total Score of a Team.
    int extra_run; // Extra Runs Given.
    int cTotal4;   // Total Number of Four's by Each Player.
    int cTotal6;   // Total Number of Six's by Each Player.
    // int N_over;

    /* Friend Members*/
    friend int toss(int, int);
    /* friend int welcomeScreen(int); 
     friend void optionN(Score); */

public:
    Score();                          // Constructor Function Declaration.
    void new_sheet();                 // Function to Start the Preogram.
    void load_sheet(Score, bool);     // Function of opening a Saved Score Sheet.
    void save_sheet(Score, Score);    // Function of Saving a Score Sheet
    int start_scoreboard(int, Score); // Function Call where the Score Sheet Begins.
    void show();                      // Call for showing Details.
    void dot_ball();                  // Dot Ball adding Function.
    void add_run(int, int);           // Add Runs in Player account.
    void sixes();                     // To Count the Totals Sixes and Returns Count.
    void fours();                     // To Count the Totals Fours and Returns Count.
    void wicket();                    // Keeps Wicket info of the Player.
    void setExtra();                  // Adding extra Runs.
    void over_complete();             // Over complete and getting Next Over Function.
    void m_over();                    // Max Over Function to change the Inning.
    int score_total();                // Function call for Total Runs.
};
class saveOutput // Separate class for saving Score Sheet to a (.txt) File.
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

// Main Function //
int main()
{
    Score alpha;
    welcomeScreen(alpha);
    return 0;
}

// Player Class - Member Function Definition //
Player ::Player()
{
    for (int i = 0; i < mPLAYERS; i++)
    {
        for (int j = 0; j < mBALLS; j++)
        {
            pRun[i][j] = 0;
        }
    }
    NBalls = 0;
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
void Player ::show_pName(int x, int y)
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
}
void Player ::get_pStatus(int x)
{
}
int Player ::show_pStatus()
{
    for (int i = 0; i < mBALLS; i++)
    {
        Nplayer[pNumber] += pRun[pNumber][i];
    }
    return Nplayer[pNumber];
}

// Team Class - Member Function Definition //
Team ::Team()
{
    NmPlayer = mPlayer;
}
void Team ::get_tName(int x)
{
    cout << x + 1 << ". ";
    cin >> tName;
    tNum = x;
}
string Team ::show_tName()
{
    return tName;
}
void Team ::mPlayers()
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
    // t1.show_pName(1, 2);
    // t2.show_pName(mPlayer);
}
void Team ::get_tStatus()
{
}
void Team ::show_tStatus()
{
}
void Team ::tWin(Score t1, Score t2)
{
    if (t1.score_total() > t2.score_total())
    {
        cout << t1.show_tName();
    }
    else
    {
        cout << t2.show_tName();
    }
}

// Score Class - Member Function Definition //
Score ::Score(){

};
void Score ::new_sheet()
{
    system("clear");
    cout << endl
         << setw(103) << "Welcome to New ScoreBoard" << endl;
    cout << setw(104) << "---------------------------" << endl
         << endl;
    // int team_w;
    Score t1, t2;

    cout << "  Enter the Name of Two Playing Teams :" << endl
         << endl;
    t1.get_tName(0);
    t2.get_tName(1);
    cout << endl;
    cout << "  Enter The Number of Players for Teams : ";
    mPlayers();

    cout << endl;
    cout << "  For Team " << t1.show_tName() << ", Enter Names for - " << endl;
    cout << " ----------------------------------------------------" << endl;
    t1.get_pName(mPlayer);

    cout << endl;
    cout << "  For Team " << t2.show_tName() << ", Enter Names for - " << endl;
    cout << " ----------------------------------------------------" << endl;
    t2.get_pName(mPlayer);
    cout << endl
         << "  Enter the Number Overs, You want in Match : ";
    m_over();

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
                    start_scoreboard(2, t1);
                }
                else
                {
                    check1 = 1;
                    start_scoreboard(1, t1);
                }
            }
            break;
        case 2:
            if (check2 == 0)
            {
                if (check1 == 1)
                {
                    check2 = 1;
                    start_scoreboard(2, t2);
                }
                else
                {
                    check2 = 1;
                    start_scoreboard(1, t2);
                }
            }
            break;
        }
    } while (check1 != 1 || check2 != 1);
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
    bool saveChoice = false;
    ofstream sheet("ScoreSheetDisplay.txt");
    saveOutput savefile(sheet);
    outputScreen(t1, t2);
}
int Score ::start_scoreboard(int inning, Score t)
{
    if (inning == 1)
    {
        // system("clear");
        cout << setw(97.5) << "---------------" << endl;
        cout << setw(95) << "I'st INNING" << endl;
        cout << setw(97.5) << "---------------" << endl
             << endl;
        cout << setw(74) << t.show_tName() << " Wons the Toss!! and Choses to Bat." << endl;
        cout << setw(112) << "''''''''''''''''''''''''''''''''''''''''''''" << endl
             << endl
             << endl;
        t.show_pName(1, 2);

        return 0;
    }
    // else
    // {
    //     // system("clear");
    //     cout << setw(97) << "----------------" << endl;
    //     cout << setw(95) << "II'st INNING" << endl;
    //     cout << setw(97) << "----------------" << endl<<endl;
    //     cout << show_tName() << " will Bat now." << endl;
    //     return 0;
    // }
}
void Score ::show()
{
}
void Score ::dot_ball()
{
}
void Score ::add_run(int pNumber, int run)
{
    NBalls++;
    pRun[pNumber][NBalls] += run;

    score_total();
}
void Score ::sixes()
{
}
void Score ::fours()
{
}
void Score ::wicket()
{
}
void Score ::setExtra()
{
    cout << "\n\n**********************************\n";
    cout << "             Extra Run              \n";
    cout << "**********************************\n\n";
    cout << "Extra?";
    cin >> extra_run;
    //   t1.Set_Extra(extra_run);
}
void Score ::over_complete()
{
}
void Score ::m_over()
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
}
int Score ::score_total()
{
    int local_total = 0;
    for (int i = 0; i < mPLAYERS; i++)
    {
        for (int j = 0; j < mBALLS; j++)
        {
            local_total += pRun[i][j]; // Adding each Player's Score.
        }
    }
    local_total += extra_run; // Add Extra runs to local_total.

    return local_total;
}

// Main Function's Definition //
int toss()
{
    srand((unsigned)time(0));
    int randomNumber;
    randomNumber = (rand() % 2) + 1;
    // cout<<randomNumber;
    return randomNumber;
}
void welcomeScreen(Score alpha)
{
    int x;
    outputScreen(1);
    cout << setw(102) << "Enter Your Choice : ";
    do
    {
        cin >> x;
        if (x == 1)
        {
            alpha.new_sheet();
        }
        else if (x == 2)
        {
            // load_sheet(alpha, true);
        }
        else if (x == 3)
        {
            system("clear");
            cout << endl
                 << endl
                 << setw(99) << "Thank You for Using!!" << endl
                 << setw(101) << "------------------------" << endl
                 << endl;
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

    } while (x > 3 || x < 1 || (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'));
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
                // save_sheet(t1, t2);
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
            // system("exit");
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
void outputScreen(int choice)
{
    switch (choice)
    {
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
    case 4:
        cout << "       |                                                                                                                                                                             |" << endl
             << "       |                                                                              1. New ScoreBoard                                                                              |" << endl
             << "       |                                                                              2. Exit                                                                                        |" << endl
             << "       |                                                                                                                                                                             |" << endl
             << "       -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
             << endl
             << endl;
    }
}
void outputScreen(Score t1, Score t2)
{
    system("clear");
    cout << endl
         << endl
         << "       _______________________________________________________________________________________________________________________________________________________________________________" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                             SCORE DISPLAY BOARD                                                                             |" << endl
         << "       |                                                                            '''''''''''''''''''''                                                                            |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                     TEAM(" << t1.show_tName() << ")                        Vs                       TEAM(" << t2.show_tName() << ")                         |" << endl
         << "       |                                                '''''''''                                                                        '''''''''                                   |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 01  |        #            #          #            #           #           #          |        #            #          #            #           #           #          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 02  |        #            #          #            #           #           #          |        #            #          #            #           #           #          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 03  |        #            #          #            #           #           #          |        #            #          #            #           #           #          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 04  |        #            #          #            #           #           #          |        #            #          #            #           #           #          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |  Over 05  |        #            #          #            #           #           #          |        #            #          #            #           #           #          |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |    TOTAL  |                                                                                |                                                                                |" << endl
         << "       |    RUNS   |          ###           ###           ###           ###           ###           |          ###           ###           ###           ###           ###           |" << endl
         << "       |     BY    |                                                                                |                                                                                |" << endl
         << "       |    EACH   |           #             #             #             #             #            |           #             #             #             #             #            |" << endl
         << "       |   PLAYER  |                                                                                |                                                                                |" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |_____________________________________________________________________________________________________________________________________________________________________________|" << endl
         << "       |           |                                                                                |                                                                                |" << endl
         << "       |   TOTAL   |                                    ### / #                                     |                                    ### / #                                     |" << endl
         << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                                                                                                                             |" << endl
         //    << "     |                                                  Team (" << tWin(t1, t2) << ") Won the Match By # Runs, # Wickets                                                  |" << endl
         << "       |                                                               '''''''''''''''''''''''''''''''''''''''''''''''                                                               |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                    TOTAL SIXES :#                                            TOTAL FOURS :#                                          BEST INNING AVG. :#                    |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                  BEST OVER AVG. :#                                                                     MAN OF THE MATCH :#                                  |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
}
void optionN(Score alpha, int choice)
{
    int option;
    switch (choice)
    {
    case 1:
        system("clear");
        outputScreen(2);
        cout << setw(99) << "Enter Your Choice :";
        do
        {
            cin >> option;
            if (option == 1)
            {
                alpha.new_sheet();
            }
            else if (option == 2)
            {
                system("clear");
                // system("exit");
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
            if (option == 1)
            {
                alpha.new_sheet();
            }
            else if (option == 2)
            {
                system("clear");
                // system("exit");
            }
            else
            {
                system("clear");
                // load_sheet(alpha, false);
                outputScreen(4);
                cout << setw(102) << "The Choice is Wrong!!" << endl
                     << setw(97) << "Enter Again :";
            }

        } while (option != 1 && option != 2);
        break;
    }
}