#include <iostream>
using namespace std;

bool okay(int q[], int c){

    int mp[3][3] = {0, 2, 1,
                    0, 2, 1,
                    1, 2, 0};

    int wp[3][3] = {2, 1, 0,
                    0, 1, 2,
                    2, 0, 1};

    for (int i = 0; i < c; i++)
    if (q[i] == q[c]) //Row check to see if we used the same number already
    return false;   //The row check is essentially the same for all the 8Queens variations of the program
                    //Return false since of course we dont want ot return true if a value has already been used 

    for(int i = 0; i < c; i++){
        //Mp current Girl Score > Score of women i
        if((mp[c][q[c]] > mp[c][q[i]]) && (wp[q[c]][c] > wp[q[c]][i]))
                                           //Score for current man > Score for man i 
        return false;
        return true;

                                    //and   Wp pref for previous man < current wwomen and current man 
        if((mp[i][q[c]] < mp[i][q[i]]) && (wp[q[c]][i] < wp[q[c]][c]))
        //Previous MP scores for a for a current women < previous man prefrence for previous women i 
        return false;
    }
    return true;

}

void print(int q[])
{
static int numSolutions = 0;
cout << "Solutions #" << ++numSolutions<< ":" << endl;
for (int i = 0; i < 3; i++)
cout << i << "\t" << q[i] << endl;
cout << endl;
}

int main() 
{
    int q[3] = {}; //3 elements all init to 0
    int c = 0; // men
    while (c >= 0){ //Condiiton to make sure we stay at 0,1,2
        if(c == 2){ //If it equals 2 then all 3 mens have been amtched
            print(q);
            --c; //Like going back a column in 8 queens, backtrack to find another solution 

        }
    
    else 

    q[++c] = -1; //Row = -1
    while(c >= 0){ //while men is staying above 0 or ewqual to 0- to be in range of 0,1,2
    ++q[c]; //Keep incrementing row or women 
    if (q[c] == 3) //if we reached the end of the row which is 2 not 3 that means we didnt find a solution
    --c; //So we do c-- so backtrack and find a new solution
    else if (okay(q,c)) //We check this new solution by using the okay function to check if we can place this 
    break;
    }

}
return 0;

}

