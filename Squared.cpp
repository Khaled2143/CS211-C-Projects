#include <iostream>
using namespace std;



int main(){

//last digit of the square of any natural number only 
//depends on the number's last digit - any other digits 
//represent powers of 10 and do not make any difference to the last digit of the square.


for (int i = 1; i < 99; i++){ //We dont need to go this high, but we stay below 0 since the last two digits only matter
    int squared = i * i;
    

       
        cout << squared << endl; //Prints out every square from 1-99
        cout <<"Divided by 10 gives you: " << squared / 10 << endl;
        cout << "Divide 10 and Mod 2 gives you: " << (squared / 10) % 2 << endl<< endl; //Gives a remainder 

        if (squared % 2 != 0 && (squared / 10) % 2 != 0) {
         cout << "The squared produt with the last two digits being odd: " << squared;
        
        }
         cout << "THERE ARE NO SQUARE PRODUCTS WHERE THE LAST TWO ARE ODD" << endl; // This prints every single time from 1 - 1000 because there are no numbers that fit the criteria 
         
         
    /*
Square numbers end with 0, 1, 4, 5, 6 or 9 at the unit’s place
If a number ends with 1 or 9, then its square will always end with 1
If a number ends with 4 or 6, then its square will always end with 6
Unit digit of square of any number will be the unit digit of square of its last digit
The square root of perfect square is always a natural number
The perfect squares will end with even numbers of zeros
Square of even numbers are always even
Square of odd numbers are always odd

    */
}
}



