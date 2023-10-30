/*The Math Necromancer*/

#ifndef _LOG
#define _LOG

#include "cordic.hpp"

#define LN_2 0.69314718056
#define LN_6 1.79175946923
#define LN_12 (LN_2 + LN_6)

/*Raise a number to the power of an integer*/
double pow_int(double x, int y)
{
    double result = 1.0;
    bool neg;
    
    if(x == 0)
    {
        if(y == 0)
            return undefined;
        
        return 0;
    }
    else if(x == 1)
    {
        return 1;
    }

    if(y < 0)
    {
        y *= -1;
        neg = true;
    }
    
    while(y > 0)
    {
        if(y % 2 == 1)
        {
            result *= x;
        }
        x *= x;
        y /= 2;
    }

    return neg? 1.0/result : result;
}

/*Get the Natural Logarithm of x*/
double log_e(double x)
{
    if(x <= 0)
    {
        /*ln(x) is undefined for neutral*/
        /*and negative values of x*/
        return undefined;
    } 
    if(x == 1)
    {
        return 0;
    }
    else if(x == 2.0)
    {
        return LN_2;
    }
    else if(x == e)
    {
        return 1;
    }
    double log_sub_lnx;
    if(x < 6)
    {
        log_sub_lnx = cordic_log_e(x / 2);
        return log_sub_lnx + LN_2;
    }
    else if(x >= 6 && x < 12)
    {
        log_sub_lnx = cordic_log_e(x / 6);
        return log_sub_lnx + LN_6;
    }
    log_sub_lnx = cordic_log_e(x / 12);
    return log_sub_lnx + LN_12;
}
#endif /*_LOG*/