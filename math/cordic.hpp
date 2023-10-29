/*The Math Necromancer*/
#include "constants.hpp"

/*Only includes this file if it*/
/*has not been included before*/
#ifndef CORDIC
#define CORDIC 1

/*Arctangent values in radians of reciprocals of powers of 2*/
const double arctan_table[] = {0.7853981633974483, 0.4636476090008061,
0.24497866312686414, 0.12435499454676144, 0.06241880999595735,
0.031239833430268277, 0.015707317311820675, 0.007853982188588921,
0.003927007429845775, 0.0019634954084936207, 0.0009817486233105316,
0.0004908986424572795, 0.000245442012454231, 0.00012272178284733785,
0.00006135987049809571, 0.00003067993411545705, 0.000015339990535147898,
0.000007669995267573617, 0.000003834997633794508, 0.000001917498817078266
};

/*Get the amount of values in the arctangent table*/
int arctan_table_length = sizeof(arctan_table) / sizeof(arctan_table[0]);

/*CORDIC gain*/
/*Scale Factor for the Infinite Product of the Cosine of the CORDIC Rotation Matrix*/
const double cordic_K = 0.60725293500888125617;

/*Class for return values, resembles a vector*/
/*Contains x, y, and the angle*/
class cordic_result
{
    public:
        double x, y, angle;

        /*If values are not specified, default to 0*/
        cordic_result()
            : x(0.0), y(0.0), angle(0.0)
        {

        }
        /*Constructor for specific initialization of vales*/
        cordic_result(double _x, double _y, double _angle)
            : x(_x), y(_y), angle(_angle)
        {

        }
};

/*Method Used to Compare Vectors and Determine Angles*/
cordic_result cordic_vector(double x, double y, double theta)
{
    /*Declare some variables*/
    double x_new = x;
    double y_new = y;
    double exp_2 = 1.0;
    double angle = 0.0;

    for(int i = 1; i < arctan_table_length; i++)
    {
        /*Delta determines whether y is positive*/
        double delta = (y >= 0.0)? 1: -1;
        /*Multiplying y delta allows angle convergence to 0*/
        x_new += delta * (y / exp_2);
        y_new -= delta * (x / exp_2);
        /*Update the angle. As the angle converges to 0,*/
        /*It updates this variable, giving the original*/
        /*angle after the process is done*/
        angle += delta * arctan_table[i - 1];

        /*Update x & y after each iteration*/
        x = x_new;
        y = y_new;

        /*Increase the power of 2 each iteration to prepare*/
        /*for the next one*/
        exp_2 *= 2;

    }

    /*Defines the return values. The angle variable is the arctangent*/
    cordic_result return_val(x, y, angle);


    return return_val;
}

/*Method Used to Compare Angles and Determine Vectors*/
cordic_result cordic_angle(double x, double y, double theta)
{
    /*Declare some variables*/
    double x_new = x;
    double y_new = y;
    double exp_2 = 1.0;
    double angle = 0.0;

    for(int i = 0; i < arctan_table_length; i++)
    {
        /*Similar to cordic_vector's delta, except*/
        /*This one checks if the given angle is less*/
        /*than the desired angle*/
        double delta = (angle <= theta)? 1: -1;
        /*Updating x_new & y_new; after enough*/
        /*iterations, these values will be the*/
        /*Sine and Cosine of the initial angle*/
        /*multiplied by some constant cordic_K*/
        x_new -= delta * (y / exp_2);
        y_new += delta * (x / exp_2);
        angle += delta * arctan_table[i];

        /*Update x & y for the next iteration*/
        x = x_new;
        y = y_new;
        /*Update the power of 2 of each iteration*/
        /*to prepare for the next one*/
        exp_2 *= 2;
    }

    /*Defines the return values; x and y are the*/
    /*Sine and Cosine scaled by some constant*/
    cordic_result return_val(x, y, angle);

    return return_val;
}

/*Get the Arc Tangnet in Radians From a Ratio*/
double cordic_arctan2(double y, double x)
{
    /*Preform cordic_vector(); the angle variable is the arctangent*/
    cordic_result result = cordic_vector(x, y, 0);
    return result.angle;
}

/*Get the Arc Tangent of y Radians*/
double cordic_arctan(double x)
{
    /*Same concept as cordic_arctan2*/
    /*Turns x into a ratio by dividing by 1*/
    
    double y = 1;
    cordic_result result = cordic_vector(y, x, 0);
    return result.angle;
}

/*Get the Hypotinuse of a Right Triangle With Lengths x and y*/
double cordic_hypot(double x, double y)
{
    /*When calling cordic_vector, the x variable is*/
    /*The hypotinuse of an imaginary triangle with side lengths of*/
    /*the original x variable and y variable*/
    cordic_result result = cordic_vector(x, y, 0);
    /*The hypotinuse is scaled by a constant cordic_K*/
    return result.x * cordic_K;
}

/*Get the Sine of Theta Radians*/
double cordic_sin(double theta)
{
    double x = 1.0;
    double y = 0.0;

    cordic_result result = cordic_angle(x, y, theta);
    return result.y * cordic_K;
}

/*Get the Cosine of Theta Radians*/
double cordic_cos(double theta)
{
    double x = 1.0;
    double y = 0.0;

    cordic_result result = cordic_angle(x, y, theta);
    return result.x * cordic_K;
}

/*Get the Tangent of Theta Radians*/
double cordic_tan(double theta)
{
    double x = 1.0;
    double y = 0.0;

    cordic_result result = cordic_angle(x, y, theta);
    return result.y / result.x;
}

double cordic_log_e(double x)
{
    if(x <= 0)
    {
        return undefined;
    }
    else if(x == 1)
    {
        return 0;
    }
    
    double term = (x * x - 2 * x + 1) / (x * x + 2 * x + 1);
    double numerator = (x - 1) / (x + 1);
    double log_e = 0.0;

    for(int i = 1; i <= arctan_table_length; i += 2)
    {
        log_e += numerator / i;
        numerator *= term;
    }

    return 2 * log_e;
}
#endif /*CORDIC*/