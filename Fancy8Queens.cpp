//Khaled Ahmed and Farita 


#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int c){

    for (int i = 0; i < c; i++)
    if (q[i] == q[c] || abs(q[i] - q[c]) == c - i) //This is essentially the function that checks where we can place a queen
    return false;                                  //You can think of it as like the 1D 8queens without goto. q[i] is the row and q[c] is the column
    return true;
}


void print (int q[]){
    static int solution = 0;
    int i, j, k, l;
    typedef char box[5][7]; //Box will be a data type now, typedef allows us to use box as a name multiple times whilst having differnet actions. FOr example box now reprents white board, black board, and a pointer board
    box bb, wb, *board[8][8]; //bb and wb are both 5 by 7. Because we connected the 8 by 8 array to the char 5 by 7, it now points to the 5 by 7 array


    //Fill in blackbox and white box to represent a square of a chess board 5 by 7

    char black = ' ';

    char white = char(219); //White ascii character

    for  (i = 0; i < 5; i++)
    {
        for (j = 0; j < 7; j++){
            bb[i][j] = black;      //This 5 by 7 represents 1 square in the 8 by 8 
            wb[i][j] = white;      //We are using the for loop to print the characters for i and j which represents the rwow and column for the 5 by 7
        }
    }
    //Now we create 2 more boxes to reprsent a queen on white background and aqueen and a black backgorund 

    static box bq = 
    
   {{white, white, white, white, white, white, white},

    {white, black, white, black, white, black, white},

    {white, black, black, black, black, black, white},

    {white, black, black, black, black ,black, white},

    {white, white, white, white, white, white, white}};

static box wq =

{{black, black, black, black, black, black, black},

 {black, white, black, white, black, white, black},

 {black, white, white, white, white, white, black},

 {black, white, white, white, white, white, black},

 {black, black, black, black, black, black, black}};


//Now we will use the board with pointers to BB and WB in alternating positions like a chess board

for (i = 0; i < 8; i++) //Will be going through the entirety of the 8 by 8 chessboard and filling up each square with its appropriate color
for (j = 0; j < 8; j++)
if ((i + j)% 2 == 0) //If adding row and column is divisble by 2 with a remainder of 0 then, it adds with numbers starting from 1-8. so 1+1 = 2 % 2 = 0, so white board will be printed in 1,1 coords
board[i][j] = &wb; //Fill that square with the white else fill it with black 
else 
board[i][j] = &bb;


//Now we set up current solution on chess board
//Putting white queen on black background and black queen on white background

for (i = 0; i < 8; i++)
if ((i+q[i])%2 == 0)
board[q[i]][i] = &bq; // row queen is placed plus the column position mod by 2, if that equals 0 reaminder then place black queen other then that place white queen
else 
board[q[i]][i] = &wq;

cout << "Solution #" << ++solution << endl;
for (i = 0; i < 8; i++)    //This prints out the solutions above the printed fancy chessboard
cout << q[i] << " ";       //It prints it like a 1d array |7|3|0|2|5|1|6|4|
           
           cout << endl;       //You read it column 1 row 7 or column 2 row 3

//UpperBorder
cout << " ";
for ( i = 0; i < 7*8; i++)
cout << char(219);
cout << endl;

//Print the Board 
for ( i = 0; i < 8; i++) //Well be looping for all rows 
for (k = 0; k < 5; k++){ //This fills up the row from the bb or the wb
cout << char(219); //left border
for (j = 0; j < 8; j++) //Will be looping for all columns c vghbh
for (l = 0; l < 7; l++) //Fills up the column from the bb or wb 
// board[i][j] = Address of wb (or bb, wq, bq)
// *board[i][j] = Dereference to get that wb.
// (*board[i][j])[k][l] is the kth row, lth column of the box.

cout << (*board[i][j])[k][l]; //This outputs all board components, the black queen, white queen, white bkacground, and black bakground 
cout << char(219) << endl; // right border
}


//LowerBorder
cout << " ";
for ( i = 0; i < 7*8; i++) //7*8 just covers the entirety of the lower botrder
cout << char(219);//Aesthetics
cout << endl<< endl;
}



int main() {

int q[8] = {}, c = 0; //Basically set row and column to 0,0 

q[0] = 0;


while (c >= 0) { // NEXT COL:

c++; // Move to the next column, we have this because we're thinking of it as the 1D 8queens, 

if (c>7) { // If you have passed the last column, a solution is found

print (q); // Call the print function and backtrack

c--;

}

else q[c] = -1; // set to -1 so in inner loop you can start q[c] from 0

while (c >= 0) { // NEXT ROW:

q[c]++; // Move to the next row 

if (q[c] > 7) c--; // If you have passed the last row, backtrack since that means we havent found a solution within the column

else // Otherwise, call the ok function.

if(ok(q, c)) break; // If ok (returns true), a queen is filled in the row | Also checks the diagnols and row checks 

}

}

return 0;

}