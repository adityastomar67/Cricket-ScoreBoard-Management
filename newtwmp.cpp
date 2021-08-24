#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string namez;
    int option, roww;
    int seat[13][5] = {0};
    int i, j, choice, num_of_seat, empty_seat = 0, row, col;
    char name[20], column;
    char opselect, ticketType;
    cout << "\t\tFJ513 Seat Reservation" << endl;
    cout << endl;
    cout << "\t1.Display Aircraft Seating Plan" << endl;
    cout << "\t2.Reserve a Seat" << endl;
    cout << "\t3.Retrieve Seat Information" << endl;
    cout << "\t4.Quit" << endl;
    cout << endl;
    cout << "enter your choice" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
        printf("\tA\tB\tC\tD\tE\n");
        for (row = 0; row < 13; row++)
        {
            printf("\nRow %d", row + 1);
            for (col = 0; col < 5; col++)
            {
                printf("\tx", seat[row][col]);
            }
        }
        system("pause");
        break;
    case 2:
        void getData(char &ticketType, int &row, char &column);
        {
            cout << "The airplane has 13 rows, with six seats in each row. " << endl;
            cout << "Enter ticket type,\n"
                 << "F for first class, \n"
                 << "E for economy class:" << endl;
            cin >> ticketType;
            ticketType = static_cast<char>(toupper(ticketType));
            switch (ticketType)
            {
            case 'F':
                cout << "Row 1 and 4 are first class,\n";
                break;
            case 'E':
                cout << "row 8 through 13 are economy class." << endl;
                break;
            }
            cout << "Enter the row number you want to sit: " << endl;
            cin >> row;
            cout << "Enter the seat number (from A to E). " << endl;
            cin >> column;
            cout << "enter passenger name:" << endl;
            cin >> namez;
            column = static_cast<char>(toupper(column));
        }
        void printForm(char form[][6], int row, char column);
        {
            int i, j;
            cout << "* indicates that the seat is available; " << endl;
            cout << setw(14) << "A" << setw(8) << "B" << setw(8) << "C"
                 << setw(8) << "D" << setw(8) << "E" << endl;
            for (i = 0; i < 13; i++)
            {
                cout << left << setw(3) << "Row " << setw(2) << i + 1;
                for (j = 0; j < 5; j++)
                {
                    if (i == row - 1 && j == static_cast<int>(column) - 65)
                        cout << right << setw(8) << namez;
                    else
                        cout << right << setw(8) << "*";
                }
                cout << endl;
            }
        }
        system("pause");
        return 0;
    }
}