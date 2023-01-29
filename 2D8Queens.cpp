#include <iostream>
using namespace std;

int main()
{

    int board[8][8] = {0}; // Init all vlaues to 0

    int row = 0;
    int column = 0;
    board[row][column] = 0;

nextColumn:

    column++;
    if (column == 8)
        goto print; // If all columns have been searched then that means we all solutions have been found

    row = -1; // Sets row to -1

nextRow:

    ++row;

    if (row == 8)
        goto backtrack; // We've searched the entirety of a column so that means no solutions has not been found yet. goto backtrack to try different options

    // Row Test

    for (int i = 0; i < column; i++)
    {                           // Incrementing column allows us to move across the board in a horizontal line
        if (board[row][i] == 1) // Column is replaced with i since column is being incremented
            goto nextRow;       // Theres a queen in the row so that means we go to the nextrow and find a new soltuion
    }

    // Up Diagnol test

    for (int i = 1; row - i >= 0 && column - i >= 0; i++)
    {
        if (board[row - i][column - i] == 1)
            goto nextRow;
    }

    // Down diagnol

    for (int i = 1; row + i < 8 && column - i >= 0; i++)
        if (board[row + i][column - i] == 1)
            goto nextRow;

    board[row][column] = 1;
    goto nextColumn;

backtrack:

    --column;

    for (row = 0; board[row][column] != 1; ++row)
        board[row][column] = 0;
    goto nextRow;

print:
    int numSolutions = 0;
    cout << "Solution # " << ++numSolutions << endl;
    for (int r = 0; r < 8; ++r)
    { // Creating the 8 by 8 board
        for (int c = 0; c < 8; ++c)
            cout << board[r][c];
        cout << "\n";
    }
    goto backtrack;
}
