#include <iostream>
using namespace std;

int win[6];
void printOdo()
{
    cout << "|";                // The first line in front of win[0] when printed
    for (int i = 0; i < 6; i++) //
    {
        cout << win[i] << "|";
    }

    cout << endl;
}

int main()
{
    for (int i0 = 0; i0 <= 9; i0++) // array place 0 is equal to 0 and will be incremented till it reaches 9
    {
        for (int i1 = 0; i1 <= 9; i1++)
        {
            for (int i2 = 0; i2 <= 9; i2++)
            {
                for (int i3 = 0; i3 <= 9; i3++)
                {
                    for (int i4 = 0; i4 <= 9; i4++)
                    {
                        for (int i5 = 0; i5 <= 9; i5++)
                        {
                            win[5] = i5; // This increments the 5 column or fifth place of the array till 9 is reached
                            printOdo();  // The inner most for loop runs fastest
                        }
                        win[4] = i4; // Increments column 4
                        printOdo();  // Printodo will print the 6 total spaces for the odometer as well as the "|"
                    }
                    win[3] = i3; // increments column 3
                    printOdo();
                }
                win[2] = i2; // increments column 2
                printOdo();
            }
            win[1] = i1; // increments column 1
            printOdo();
        }
        win[0] = i0; // increments column 0
        printOdo();
        cout << "SELL THE CAR!" << endl;
    }
    return 0;
}
