/*The Math Necromancer*/

#ifndef CONSTANTS
#define CONSTANTS

typedef unsigned long long uint64_t;

/*Infinities*/
#define INFINITY (1.0 / 0.0)
#define NEGATIVE_INFINITY (-1.0 / 0.0)
#define RECIPROCAL_INFINITY 0.0

/*NaN and Undefined Values*/

union double_bits
{
    uint64_t bits;
    double value;
};

double_bits static nan_bits = {0x7FF8000000000001ull};


#define NaN (nan_bits.value)
#define undefined NaN

/*Finite Constants for Math*/

#define pi 3.141592653589793

#define tau 6.283185307179586

#define pi_2 1.5707963267948965

#define rad_to_deg 57.29577951308232

#define deg_to_rad 0.017453292519943

#define e 2.718281828459045

#endif /*CONSTANTS*/