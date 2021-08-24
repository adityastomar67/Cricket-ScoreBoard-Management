#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
void scoreSheeet()
{
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
         << "       |                                                 TEAM(A)                                    Vs                                    TEAM(B)                                    |" << endl
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
         << "       |                                                                Team (A/B) Won the Match By # Runs, # Wickets                                                                |" << endl
         << "       |                                                               '''''''''''''''''''''''''''''''''''''''''''''''                                                               |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                    TOTAL SIXES :#                                            TOTAL FOURS :#                                          BEST INNING AVG. :#                    |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                  BEST OVER AVG. :#                                                                     MAN OF THE MATCH :#                                  |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl
        //  << "       |                                                                                                                                                                             |" << endl
        //  << "       |                                                                     Do You Want To Save This Game? (Y/N)                                                                    |" << endl
        //  << "       |                                                                                   Exit(E)                                                                                   |" << endl
        //  << "       |                                                                                                                                                                             |" << endl
        //  << "       -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
        //  << endl
        //  << endl;
        ;
}
void score()
{
    cout << "       |                                                                                                                                                                             |" << endl
         << "       |                                                                     Do You Want To Save This Game? (Y/N)                                                                    |" << endl
         << "       |                                                                                   Exit(E)                                                                                   |" << endl
         << "       |                                                                                                                                                                             |" << endl
         << "       -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl
         << endl
         << endl;
}
class saveOutput
{
private:
    streambuf *outPut;

public:
    saveOutput(ofstream &file) : outPut{file.rdbuf()}
    {
        cout.rdbuf(outPut);
    }
};
int main()
{
    system("clear");
    char choice;
    scoreSheeet();
    score();
    cout << setw(103) << "Enter Your Choice :";
    do
    {

        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            /*Code*/
            /*Code*/
            ofstream sheet("ScoreSheetDisplay.txt");
            saveOutput savefile(sheet);
            scoreSheeet();
        }
        else if (choice == 'N' || choice == 'n')
        {
            // void option_N();
        }
        else if (choice == 'E' || choice == 'e')
        {
            system("clear");
            // system("exit");
        }
        else
        {
            system("clear");
            scoreSheeet();
            cout << setw(105) << "The Choice is Wrong!!" << endl
                 << setw(100) << "Enter Again :";
        }
    } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n' && choice != 'E' && choice != 'e');

    return 0;
}