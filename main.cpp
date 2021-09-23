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

#include "asset/functions.h"

//* Main Function //
int main()
{
        Score alpha;
        welcomeScreen(alpha);
        return 0;
}
