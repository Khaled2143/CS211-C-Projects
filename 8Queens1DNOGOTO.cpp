#include <iostream>
#include <cmath>
using namespace std;

void print(int q[], int sol)
{ // Print function that takes two parameters
    cout << "Solution #" << sol << ": ";
    for (int i = 0; i < 8; i++)
    {
        cout << q[i] << " "; // Will print every sol in a 1D
    }
    cout << endl; // Space in between veyr single one

    for (int i = 0; i < 8; i++)
    { // Will print 2D verison of the solution
        for (int j = 0; j < 8; j++)
        { // I is the row and j is the column

            if (q[j] == i)
                cout << "Q";
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}
bool okay(int q[], int c)
{ // Okay function that checks row up and down diag
    for (int i = 0; i < c; i++)
    { // c is the current position which is why we always do i < c
        // Row check             //Up and down diag check
        if (q[i] == q[c] || abs(q[i] - q[c]) == (c - i))
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int solutions = 1;
    int q[8] = {};
    int c = 0;

    while (true)
    {
    nc:
        c++; // nc does nothing here, i just put it since C++ allows us to label it like that
        if (c == 8)
        {                        // If columns == 8 that means we went through ever column of the board and found a solution so we go to print
            print(q, solutions); // So we print the array q we found and increment solutions
            solutions++;
        backtrack:
            c--; // After we print a solution we do c-- to change a position of a queen and find a new solution
        }
        else
        {
            q[c] = -1; // If we didint find a solution that means that when going to next column we want to start at -1 row
        }

        while (true)
        {
        nr:
            q[c]++; // Start at -1 row to do q[c]++ which get us in the 0 position on the chessboard
            if (q[c] == 8)
            {        // If we reached the end of the ro that means we havent found a position in the row to place a queen
                c--; // So c-- to go back one column and change the posiiton of a queen previously placed
                if (c == -1)
                { // If we c-- to the point where we are off the board that means we found all solutions
                    return 0;
                }
            }
            else if (okay(q, c))
            { // Checks rows, up and down diag of queen placement
                break;
            }
        }
    }
}
