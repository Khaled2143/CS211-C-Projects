#include <iostream>
#include <vector>
using namespace std;


int main() {
vector<int> t[3];
int n;
cout << "Enter the amount of rings you want to enter: " << endl;
cin >> n;
cout << "Number of rings: " << n << endl;


//If n is mod 2 nd it equals 0, then close is equal to 2 else its 1
int close = (n % 2 == 0 ? 2 : 1);
// if n is mod 2 and it equals 0, far is equal to 1 else its 2
int far = (n % 2 == 0 ? 1 : 2);
int from = 0, to = close, candidate = 1, move = 0;

//Init the towers
for(int i = n+1; i>= 1; --i)
t[0].push_back(i); //This is not n+1 because we do a loop that sets n+1 to i so i represent n + 1. Smae as the other towers
t[1].push_back(n+1); //Putting a total of 4 values in each other. That way every tower
t[2].push_back(n+1);//Has a value in it constantly and it takes out another issue
                    //Of making sure weather or not it is empty. 


while(t[1].size() < n + 1){ //While the tower size of tower 1 does not consists of all the rings
cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << endl;
//So it moves from Tower is becuase the from tower is 0, so = 0 + 'A' or 65 is still A, but the to tower is to which 1 + 'A' gives you 66 which is equivalent to B

t[to].push_back(t[from].back()); //Take the last element from the from tower, and place it on top of the to tower
t[from].pop_back();//The values are stacked on to thw tower like    //1 but in an array it would be 4, 3, 2, 1
 //Also remove the last value we just took from the from tower      //2
                                                                    //3
                                                                    //4
//Determine the from tower
if (t[(to+1) % 3].back() < t[(to+2) % 3].back()) //Determining if the last value on top of to+1 or to+ 2 is less than the other
from = (to + 1) % 3;    //And if thats the case the to tower is the one to the right of the left
else    //So, if we last placed on tower 1 then the next towers we can place on are tower 2 or tower 0
from = (to + 2) % 3;
candidate = t[from].back(); //The candidate we're moving is the ring value that is on top of all the other rings

//To determine which tower is the to tower 

//From tower + close towers last value, If it is bigger than the candidate
if(t[(from+close) % 3].back() > candidate)//from+1 mod 3 
to = (from + close) % 3; //for n = 3, from + 1 since thats what close is set to above
else 
to = (from + far) % 3;



}
return 0;
}