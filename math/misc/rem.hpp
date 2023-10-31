/*The Math Necromancer*/

#ifndef REM
#define REM

#include "abs.hpp"
#include "../constants/constants.hpp"

double rem(double x, double y)
{
    if(y == 0)
    {
        return undefined;
    }
    double rem = x;
    while(abs(rem) - abs(y) >= 0.0)
    {
        rem -= y;
    }
    return rem;
}

#endif /*REM*/