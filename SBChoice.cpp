#include <iostream>

using namespace std;
char show(int x)
{
    switch (x)
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

    }
}

int main()
{
    cout<<show(0)<<endl<<"Thanks";

    return 0;
}