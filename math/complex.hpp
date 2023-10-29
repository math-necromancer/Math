/*The Math Necromancer*/

/*Only define COMPLEX if there is no definition*/
/*This stops #include from including it multiple times*/
#ifndef COMPLEX
#define COMPLEX

/*Complex numbers: 2-dimensional - includes a*/
/*real counterpart and a multiple of i*/
class complex
{
    public:
        double r, i;

        /*Default constructor if no values are assigned*/
        /*at creation*/
        complex(): r(0.0), i(0.0)
        {}
        /*Lets you initialize values immediately after creation*/
        /*e.g. 'complex z(3.0, 7.0)'*/
        complex(double _r, double _i): r(_r), i(_i)
        {}
};

/*Add one complex number with another*/
complex complex_add(const complex& x, const complex& y)
{  
    /*To add complex numbers, simply add both the real and*/
    /*imaginary parts with that of the other number*/
    return complex(x.r + y.r, x.i + y.i);
}

/*Subtract one complex number from another*/
complex complex_sub(const complex& x, const complex& y)
{
    return complex(x.r - y.r, x.i - y.i);
    /*Same principle as addition, just flipped*/
}

/*Mltiply one complex number by another*/
complex complex_multiply(const complex& x, const complex& y)
{
    /*FOIL simulation - there is subtraction because i*i = -1*/
    return complex(x.r * y.r - x.i * y.i, x.r * y.i + x.i * y.r);
}

/*Get the conjugate of a complex number*/
complex complex_conj(const complex& x)
{
    return complex(x.r, -x.i);
}

/*Divide one complex number by another*/
complex complex_div(const complex& x, const complex& y)
{
    /*(a + bi) / (c + di)/*
    /*= ((ac + bd) / (c^2 + d^2)) / ((bc - ad) / (c^2 + d^2))*/

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

#endif /*COMPLEX*/