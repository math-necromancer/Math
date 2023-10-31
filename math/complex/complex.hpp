/*The Math Necromancer*/

/*============ C++ Complex Numbers ============*/

/*Only define COMPLEX if there is no definition*/
/*This stops #include from including it multiple times*/
#ifndef COMPLEX
#define COMPLEX

#include "../constants/constants.hpp"
#include "../logarithms_exponents/fast_sqrt.hpp"
#include "../misc/abs.hpp"
#include "../trig/cordic.hpp"

/*Complex numbers: 2-dimensional - includes a*/
/*real component and a multiple of i*/
class complex
{
    public:
        double r, i;
        bool error_state = false;

        /*Get the Conjugate of a Complex Number*/
        complex conjugate()
        {
            return complex(r, -i);
        }
        /*Default constructor if no values are assigned*/
        /*at creation*/
        complex(): r(0.0), i(0.0)
        {}
        /*Lets you initialize values immediately after creation*/
        /*e.g. 'complex z(3.0, 7.0)'*/
        complex(double _r, double _i)
            : r(_r), i(_i)
        {}
        /*Similar to last constructor, but lets you set an error state*/
        complex(double _r, double _i, bool _err)
            : r(_r), i(_i), error_state(_err)
        {}
};

bool complexError(const complex& x)
{
    return x.error_state;
}
void clearError(complex& x)
{
    x.error_state = false;
}

/*Add one complex number with another*/
complex operator +(const complex& x, const complex& y)
{  
    /*To add complex numbers, simply add both the real and*/
    /*imaginary parts with that of the other number*/
    return complex(x.r + y.r, x.i + y.i);
}
/*Subtract one complex number from another*/
complex operator -(const complex& x, const complex& y)
{
    /*Same principle as addition, just flipped*/
    return complex(x.r - y.r, x.i - y.i);
}
/*Mltiply one complex number by another*/
complex operator *(const complex& x, const complex& y)
{
    /*FOIL simulation - there is subtraction because i*i = -1*/
    return complex(x.r * y.r - x.i * y.i, x.r * y.i + x.i * y.r);
}
/*Divide one complex number by another*/
complex operator /(const complex& x, const complex& y)
{
    if(y.r == 0.0 && y.i == 0.0)
    {
        return complex(undefined, undefined, true);
    }
    /*(a + bi) / (c + di)/*
    /*= ((ac + bd) / (c^2 + d^2)) / ((bc - ad) / (c^2 + d^2))*/
    /*This is because of magic*/
    double z = y.r * y.r + y.i * y.i;
    return complex((x.r * y.r + x.i * y.i) / z,
        (x.i * y.r - x.r * y.i) / z);
}

/*Get the real component of a complex number*/
double get_real(const complex& x)
{
    return x.r;
}
/*Get the multiple of i of a complex number*/
double get_imaginary(const complex& x)
{
    return x.i;
}

/*Get the Square Root of a Complex Number*/
complex sqrt(const complex& x)
{
    if(x.i == 0.0)
    {
        return x.r > 0.0? complex(sqrt(x.r), 0.0): complex(0.0, sqrt(abs(x.r)));
    }
    /*This next part is Magic*/
    /*It's actually very Complicated*/
    double mag_x = sqrt(x.r * x.r + x.i * x.i);
    return complex(sqrt((mag_x + x.r) / 2), x.i / abs(x.i) * sqrt((mag_x - x.r) / 2));
}

/*Get the Length of the Vector Created by a Complex Number x*/
double complex_magnitude(const complex& x)
{
    return sqrt(x.r * x.r + x.i * x.i);
}
/*Get the Phase Angle of a Complex Number*/
double complex_phase_angle(const complex& x)
{
    return cordic::cordic_arctan2(x.i, x.r);
}
#endif /*COMPLEX*/