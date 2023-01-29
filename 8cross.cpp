#include <iostream>
using namespace std;

bool okay(int q[], int c){
    static int matrix[8][5] = {
        {-1},           //0
        {0, -1},        //1
        {0, -1},        //2
        {0, 2, 1, -1},  //3
        {0, 1, 3, -1},  //4
        {1, 4, -1},     //5
        {2, 3, 4, -1},  //6
        {3, 4, 5, 6, -1}//7
    };

    for(int i = 0; i < c; ++i)
        if (q[i] == q[c]) //If a number has already been used then it returns false 
            return false;
    

    for (int i = 0; matrix[c][i] != -1; ++i)//Matrix is the helper array and the column is beign incremented becuase it can be iamgined like this |_|_|_|_|_|_|_|
        if(abs(q[c] - q[matrix[c][i]]) == 1) //If current placement subtracted from returned value of the helper array is 1 then we know it is consecutive
            return false;  
        return true;

    
}

void print(int q[]){

    static int numSolutions = 1;

    cout << "Solution #" << numSolutions << ": " << endl;
    cout << "   " << " | " << q[0] << " | " << q[1] << " | " << endl;
    cout << " | " << q[2] << " | " << q[3] << " | " << q[4] << " | " << q[5] << " | " << endl;
    cout << "   " << " | " << q[6] << " | " << q[7] << " | " << endl;
    cout << endl;
    ++numSolutions;
}

void next(int q[], int c){

if (c == 8)

print(q);
else
    for(q[c] = 1; q[c] <= 8; q[c]++)
    if (okay(q,c))
    next(q, c+1);

}


int main() {
int q[8];
next (q,0); //Placed the first number at index 0 then proceeds to go to the next box by doing c+1
return 0;
}

