/*The Math Necromancer*/

/*Fast square root function*/

#ifndef SQRT
#define SQRT

/*Includes constants such as INFINITY and undefined*/
#include "../constants/constants.hpp"

double sqrt(double x)
{
    /*Negative square roots aren't defined as real numbers*/
    if(x < 0)
    {
        return undefined;
    }
    /*The square roots of all of these "numbers" are themselves*/
    else if(x == INFINITY || x == NEGATIVE_INFINITY || x == NaN || x == undefined || x == 0 || x == 1)
    {
        return x;
    }
    /*Basic Babylonian / Newt approach for square roots*/
    double approx = x / 2;
    double prev_approx = 0.0;
    while(approx != prev_approx)
    {
        prev_approx = approx;
        approx = (approx + (x / approx)) / 2;
    }
    return approx;
}

#endif /*SQRT*/