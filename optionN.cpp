#include <iostream>
#include <iomanip>

using namespace std;
void optionN()
{
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
}

int main()
{
    int a;
    system("clear");
    optionN();
    cout << setw(99) << "Enter Your Choice :";
    do
    {
        cin >> a;
        if (a == 1)
        {
            // alpha.new_game();
        }
        else if (a == 2)
        {
            system("clear");
            // system("exit");
        }
        else
        {
            system("clear");
            optionN();
            cout << setw(102) << "The Choice is Wrong!!" << endl
                 << setw(97) << "Enter Again :";
        }

    } while (a != 1 && a != 2);
    return 0;
}