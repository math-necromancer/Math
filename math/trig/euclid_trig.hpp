/*The Math Necromancer*/

/*============ C++ Trigonometry Library ============*/
/*Includes the 6 basic Euclidean trigonometric functions:*/
/*sin(x), cos(x), tan(x), sec(x), csc(x), cot(x)*/
/*Also includes inverse trigonometric functions:*/
/*asin(x), acos(x), atan(x), asec(x), acsc(x), acot(x)*/
/*Also includes:*/
/*versin(x), covers(x), vercos(x), covercos(x), exsec(x), excsc(x)*/
/*As well as their inverses*/

/*This file was created by the Math Necromancer for*/
/*his own use. Please ask permission before using it*/
/*in your project*/

/*Euclid more like Bruhhh o-o*/

#ifndef EUCLID_TRIG
#define EUCLID_TRIG

#include "cordic.hpp"
#include "../misc/rem.hpp"
#include "../logarithms_exponents/fast_sqrt.hpp"

using namespace cordic;

double sin(double x)
{
    x = rem(x, tau);
    if(rem(x, pi) == 0.0)
    {
        return 0.0;
    }
    else if(rem(x, pi) == pi_2)
    {
        return 1.0;
    }
    return cordic_sin(x);
}

double cos(double x)
{
    x = rem(x, tau);
    if(rem(x, pi) == 0.0)
    {
        return 1.0;
    }
    else if(rem(x, pi) == pi_2)
    {
        return 0.0;
    }
    return cordic_cos(x);
}

double tan(double x)
{
    x = rem(x, tau);
    if(rem(x, pi) == 0.0)
    {
        return 0.0;
    }
    else if(rem(x, pi) == pi_2)
    {
        return INFINITY;
    }
    return cordic_tan(x);
}

double sec(double x)
{
    return 1.0 / cos(x);
}
double csc(double x)
{
    return 1.0 / sin(x);
}
double cot(double x)
{
    x = rem(x, tau);
    if(rem(x, pi) == 0.0)
    {
        return INFINITY;
    }
    else if(rem(x, pi) == pi_2)
    {
        return 0.0;
    }
    return cos(x) / sin(x);
}
double versin(double x)
{
    return 1.0 - cos(x);
}
double covers(double x)
{
    return 1.0 - sin(x);
}
double vercos(double x)
{
    return 1.0 + cos(x);
}
double covercos(double x)
{
    return 1.0 + sin(x);
}
double exsec(double x)
{
    return sec(x) - 1.0;
}
double excsc(double x)
{
    return csc(x) - 1.0;
}

/*Inverse Trigonometric Functions*/

double arcsin(double x)
{
    return cordic_arctan2(x, sqrt(1.0 - x * x));
}
double arccos(double x)
{
    return cordic_arctan2(sqrt(1.0 - x * x), x);
}
double arctan(double x)
{
    if(x == 0.0)
    {
        return 0.0;
    }
    if(x == INFINITY || x == NEGATIVE_INFINITY)
    {
        return pi_2;
    }
    if(x == NaN || x == undefined)
    {
        return x;
    }
    return cordic_arctan(x);
}
double arcsec(double x)
{
    if(x >= 1.0 || x <= -1.0)
    {
        return arccos(1.0 / x);
    }
    return undefined;

}
double arccsc(double x)
{
    if(x >= 1.0 || x <= -1.0)
    {
        return arcsin(1.0 / x);
    }
    return undefined;
}
double arccot(double x)
{
    if(x == 0.0)
    {
        return pi_2;
    }
    if(x == INFINITY || x == NEGATIVE_INFINITY)
    {
        return 0.0;
    }
    if(x == NaN || x == undefined)
    {
        return x;
    }
    return cordic::cordic_arctan2(1.0, x);
}
double arcversin(double x)
{
    return arccos(1.0 - x);
}
double arcvercos(double x)
{
    return arccos(x - 1.0);
}
double arccovers(double x)
{
    return arcsin(1.0 - x);
}
double arccovercos(double x)
{
    return arcsin(x - 1.0);
}
double arcexsec(double x)
{
    return arcsec(1.0 + x);
}
double arcexcsc(double x)
{
    return arccsc(1.0 + x);
}

double asin(double x)
{
    return arcsin(x);
}
double acos(double x)
{
    return acos(x);
}
double atan(double x)
{
    return arctan(x);
}
double asec(double x)
{
    return arcsec(x);
}
double acsc(double x)
{
    return arccsc(x);
}
double acot(double x)
{
    return arccot(x);
}
double aversin(double x)
{
    return arcversin(x);
}
double avercos(double x)
{
    return arcvercos(x);
}
double acovers(double x)
{
    return arccovers(x);
}
double acovevercos(double x)
{
    return arccovercos(x);
}
double aexsec(double x)
{
    return arcexsec(x);
}
double aexcsc(double x)
{
    return arcexcsc(x);
}

#endif /*EUCLID_TRIG*/