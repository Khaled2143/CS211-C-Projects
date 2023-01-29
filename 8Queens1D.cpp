#include <iostream>
#include <cmath>
using namespace std;

const int n = 8;         // 8 for 8 queens
int q[n], solutions = 0; // Declaring the

bool okay(int q[], int c)
{
    for (int i = 0; i < c; i++)
        if (q[i] == q[c] || (abs(q[c] - q[i]) == c - i))
            return false;
            return true;
}

void print()
{

print:
    solutions++;

    cout << "Solution #" << solutions << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (q[j] == i)
            {
                cout << "Q ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    q[0] = 0; // Placing a queen in position 0,0
    int c = 0;

nc:
    c++;
    if (c == n)
    {                   // So if c = 8 But ithen that means we went through every column and found a solution
        print();        // So we print
        goto backtrack; // So we go to backtrack inorder to change results and get a new solutions
    }
    else
    {
        q[c] = -1; // When we go to a new column you want to start off on the top row, so we set nr  = -1 and then do q[c]++
    }
nr:         // Next row
    q[c]++; // from -1 to 0th row
    if (q[c] == n)
    {                   // If row is equal to 8 then that means we didnt find a solution in that row
        goto backtrack; // Then we need to backtrack inorder to find a new placement for the queen previous
    }
    else if (okay(q, c))
    {            // If it doesnt equal to 8 then we check if the queen can be palced there
        goto nc; // If it can then we found a palcement and we goto the next column
    }
    else
    {
        goto nr; // Lets say the check fails then that mean we cant place a queen in that row then we do next row to redo the test and check if we can place a queen there
    }

backtrack:
    c--;
    if (c == -1)
    {
        return 0;
    }
    goto nr;
}
