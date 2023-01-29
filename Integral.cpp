#include <iostream>
using namespace std;

typedef double (*FUNC)(double); // We name a function called FUNC and put a pointer so it points to the double function. The *FUNC will not taken in doubles and return doubles as well

double integrate(FUNC f, double a, double b)
{                   // This take 3 arguments. F is a variable that stores the memory address of a function sos that we can call later in the integration function
    double sum = 0; // Then calculates the deffinite integral of the function f between the values a and b

    for (double i = a; i < b; i += 0.0001)
    {
        sum += f(i) * 0.0001;
    }
    return sum;
}

double line(double x)
{ // We are essentailly calling the FUNC by saying double x.
    return x;
}

double square(double x)
{
    return x * x;
}
double cube(double x)
{
    return x * x * x;
}

int main()
{
    cout << "The integral of f(x)= x between 3 and 9 is: " << integrate(line, 3, 9) << endl;
    cout << "The integral of f(x)= x^2 between 3 and 9 is: " << integrate(square, 3, 9) << endl;
    cout << "The integral of f(x)= x^3 between 3 and 9 is: " << integrate(cube, 3, 9) << endl;

    return 0;
}