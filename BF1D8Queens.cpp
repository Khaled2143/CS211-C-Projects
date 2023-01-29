#include <iostream>
using namespace std;

bool okay(int q[], int c){
    for ( int i = 0; i < c; i++){
        if(q[i] == q[c] || abs(q[i] - q[c]) == (c - i)){ //Same check as all the other variations of the 1D
        return false;
        }
    }
    return true;
}

void print(int q[]){
    static int Solutions;
    cout << "Solution #" << ++Solutions << ":" << endl;
    for(int i = 0; i < 8; i++){
        cout << q[i] << " ";
    }
    cout << endl;
    

    for (int i = 0; i < 8; i++){ //Just a 2D representation. You dont need this
        for(int j = 0; j < 8; j++){//You can end the print function after the cout << endl;
            if (q[j] == i)          //I just like seeing the 2D
                cout << "Q";
            else
            {
                cout << "_ ";
            }

        }
        cout << endl;
    }
}
int main () {
    int q[8] = {}; //q is the array with 8 values like this |_|_|_|_|_|_|_|_|
    int c = 0; //C is the column
    int solutions = 0;

   
    for (int i0 = 0; i0 < 8; i0++){ //Incrementing each column
        for(int i1 = 0; i1 < 8; i1++){
            for(int i2 = 0; i2 < 8; i2++){
                for(int i3 = 0; i3 < 8; i3++){
                    for(int i4 = 0; i4 < 8; i4++){
                        for(int i5 = 0; i5 < 8; i5++){
                            for(int i6 = 0; i6 < 8; i6++){
                                for(int i7 = 0; i7 < 8; i7++){
                                    q[0] = i0;
                                    q[1] = i1;
                                    q[2] = i2;
                                    q[3] = i3;
                                    q[4] = i4;//Setting each column equal to their rightful placement in the forloops
                                    q[5] = i5;
                                    q[6] = i6;
                                    q[7] = i7;
                                    for (c = 0; c < 8; ++c) { //If column is less than 8 then increment c
                                        if (okay(q, c)) { //If the current placements of the q array is good and passes conditions
                                            if (c == 7) { //If column has reached the end column and basically wentr through every placement of a queen
                                                print(q); //Then take the q array throught the print statement
                                                solutions++; //After every print increment the solution counter
                                            }
                                        } else {
                                            break; //break out of the innermost for loop when the placement of the queens is not a valid solution
                                        }           //The innermost for loop is for i7, so when a "break" statement is encountered in that loop, it immediately exits that loop and goes to the next iteration of the next outer loop (i6 in this case)
                                        if (solutions == 92) {
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
