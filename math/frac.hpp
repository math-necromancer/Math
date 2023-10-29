/*The Math Necromancer*/

/*============ C++ Math Fractions Library ============*/
/*Includes Arithmetic and evaluation as well as comparison operators*/

/*This file was created by the Math Necromancer for*/
/*his own use. Please ask permission before using it*/
/*in your project*/

#ifndef _FRACTION
#define _FRACTION

#include "constants.hpp"

class fraction
{
    private:
        int numerator = 0;
        int denominator = 0;
    public:
        fraction(int _n, int _d)
                : numerator(_n), denominator(_d)
        {
            if(denominator == 0)
            {
                numerator = undefined;
                denominator = undefined;
            }
            else if(denominator < 0)
            {
                numerator *= -1;
                denominator *= -1;
            }
        }
        int getNumerator()
        {
            return numerator;
        }
        int getDenominator()
        {
            return denominator;
        }
        void setNumerator(int numerator)
        {
            this->numerator = numerator;
        }
        void setDenominator(int denominator)
        {
            this->denominator = denominator;
        }
};

void swap(int& x, int& y)
{
    int r = y;
    y = x;
    x = r;
}

int gcf(int x, int y)
{
    if (x < y)
    {
        swap(x, y);
    }
    while(y != 0)
    {
        double r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int lcm(int x, int y)
{
    return (x * y) / gcf(x, y);
}

double evaluateFraction(fraction f)
{
    if(f.getDenominator() == 0)
    {
        return undefined;
    }
    return (double)f.getNumerator() / (double)f.getDenominator();
}

fraction simplifyFraction(fraction f)
{
    int _gcf = gcf(f.getNumerator(), f.getDenominator());
    return fraction(f.getNumerator() / _gcf, f.getDenominator() / _gcf);
}

fraction reciprocal(fraction f)
{
    return fraction(f.getDenominator(), f.getNumerator());
}

/*Arithmetic Operators*/
fraction operator +(fraction f0, fraction f1)
{
    if(f0.getDenominator() == f1.getDenominator())
    {
        return fraction(f0.getNumerator() + f1.getNumerator(), f0.getDenominator());
    }
    int common_denominator = lcm(f0.getDenominator(), f1.getDenominator());
    f0.setNumerator(f0.getNumerator() * (common_denominator / f0.getDenominator()));
    f1.setNumerator(f1.getNumerator() * (common_denominator / f1.getDenominator()));
    return fraction(f0.getNumerator() + f1.getNumerator(), common_denominator);
}
fraction operator -(fraction f0, fraction f1)
{
    if(f0.getDenominator() == f1.getDenominator())
    {
        return fraction(f0.getNumerator() - f1.getNumerator(), f0.getDenominator());
    }
    int common_denominator = lcm(f0.getDenominator(), f1.getDenominator());
    f0.setNumerator(f0.getNumerator() * (common_denominator / f0.getDenominator()));
    f1.setNumerator(f1.getNumerator() * (common_denominator / f1.getDenominator()));
    return fraction(f0.getNumerator() - f1.getNumerator(), common_denominator);
}
fraction operator *(fraction f0, fraction f1)
{
    return fraction(f0.getNumerator() * f1.getNumerator(), f0.getDenominator() * f1.getDenominator());
}
fraction operator /(fraction f0, fraction f1)
{
    return fraction(f0.getNumerator() * f1.getDenominator(), f0.getDenominator() * f1.getNumerator());
}

/*Boolean Operators*/
bool operator ==(fraction f0, fraction f1)
{
    f0 = simplifyFraction(f0);
    f1 = simplifyFraction(f1);
    return f0.getNumerator() == f1.getNumerator() && f0.getDenominator() == f1.getDenominator()?
        true: false;
}
bool operator !=(fraction f0, fraction f1)
{
    f0 = simplifyFraction(f0);
    f1 = simplifyFraction(f1);
    return f0.getNumerator() != f1.getNumerator() || f0.getDenominator() != f1.getDenominator()?
        true: false;
}
bool operator <(fraction f0, fraction f1)
{
    return (f0.getNumerator() * f1.getDenominator() < f1.getNumerator() * f0.getDenominator())?
        true: false;
}
bool operator >(fraction f0, fraction f1)
{
    return (f0.getNumerator() * f1.getDenominator() > f1.getNumerator() * f0.getDenominator())?
        true: false;
}
bool operator <=(fraction f0, fraction f1)
{
    return !(f0 > f1);
}
bool operator >=(fraction f0, fraction f1)
{
    return !(f0 < f1);
}


#endif /*_FRACTION*/