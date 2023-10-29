#pragma once

#include <iostream>

//Constants

/*Infinite Constants*/
/*Symbolized with "∞"*/

/*Arbitrarily Large Number, Practically ∞*/
#define infinity 1e+76

/*Similar to ∞, but in the Other Direction*/
#define Nininity -infinity

/*~Equal to 1/∞, Approaches 0*/
#define infinitesimal 1e-76

/*Finite Constants*/

/*Pi, Symbolized with "π", is the Ratio of a Circle's Circumference to it's Diameter*/
#define pi 3.141592653589793238462643383279502884f

/*"e" is the Limit as s -> ∞ of (1 + 1/s)^s*/
/*It is Also the Base of the Natural Logarithm  */
#define e 2.718281828459045235360287471352662497f

/*Undefined: Used when No Answer Exists*/
#define undefined 0


/*Complex Numbers (r + i)*/
class complex
{
    public:
        /*r is the Real Number Axis going Horizontally, i is the Complex Axis going Vertically. i = sqrt(-1)*/
        double r, i = 0;
};

//Number Classification Functions

/*Check if a Number is Finite*/
bool isFinite(double x)
{
    return x < infinity && x > Nininity? true: false;
}

/*Check if a Number is Infinite*/
bool isInfinite(double x)
{

    return x >= infinity || x <= Nininity? true: false;
}

/*Check if a Complex Number can be Expressed as a Real Number*/
bool isReal(complex x)
{
    return x.i == 0 && isFinite(x.r)? true: false;
}

/*Check if a Complex Number can not be Expressed as a Real Number*/
bool isComplex(complex x)
{
    return x.i != 0 && isFinite(x.r)? true: false;
}

/*Check Whether or Not a Number is an Integer*/
bool isInteger(double& x)
{
    return (int)x == x? true: false;
}

/*Check if an Integer is Even or Not*/
bool isEven(int x)
{
    return (x) % 2 == 0? true: false;
}

/*Check if an Integer is Odd or Not*/
bool isOdd(int x)
{
    return (x) % 2 == 1? true: false;
}

// Simple Input -> Output Functions

/*Get the Absolute Value of a Number*/
double abs(double x)
{
    return x < 0? -x: x;
}

/*Round a Number Down, No Matter What*/
int floor(double x)
{
    return !isInteger(x)? (int) x: x;
}

/*Round a Number Up, No Matter What*/
int ceil(double x)
{
    return !isInteger(x)? (int) (x + 1): x;
}

/*Round a Number to the Nearest Integer*/
int round(double x)
{
    return (x - floor(x) < 0.5)? floor(x): ceil(x);
}

/*Extension of round(), Round to Any Number */
/*Example: roundExt(12, 17) = 17)*/
double roundExt(double x, double decimal)
{
    return decimal != 0? round(x / decimal) * decimal: 0;
}

/*Get the Factorial of Numbers 1 - 14 */
/*(15! is More than the Integer Limit can Handle!)*/
/*(1,307,674,368,000)*/
int factorial(int x)
{
    if(x < 0)
    {
        return undefined;
    }
    else if(x == 0 || x == 1)
    {
        return 1;
    }
    else
    {
        for(int i = (x - 1); i > 1; i -= 1)
        {
            x *= i;
        }

        return x;
    }
}

//Roots

/*Get a Very Rough Approximation of the Square Root of a Number*/
/*The Second Parameter Sets the Maximum Difference of the*/
/*Approximaiton to the True Square Root*/
double approx_sqrt(double x, double decimal)
{
    if(x < 0)
    {
        return undefined;
    }
    else if(x == 0)
    {
        return 0;
    }
    else
    {
            
        double y = x;

        /*Evil Method for Approximation*/
        /*BABYLON*/
        while(y - (x / y) >= decimal)
        {
            y = (y + x / y) / 2;
        }

        return y;
    }
}

/*Get the Square Root of a Number*/
double sqrt(double x)
{
    if(x < 0)
    {
        return undefined;
    }
    else if(x == 0)
    {
        return 0;
    }
    else
    {
        
    }
}

/*Get the Inverse of the Square Root of x*/
/*(1 / √x)*/
double inv_sqrt(double x)
{
    
}