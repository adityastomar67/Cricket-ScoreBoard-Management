#include "assets.h"

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