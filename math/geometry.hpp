/*The Math Necromancer*/

#ifndef GEOMETRY
#define GEOMETRY

#include "constants.hpp"

class circle
{
    public:    
        double radius;

        double area = pi * radius * radius;

        double circumference = 2 * pi * radius;

        circle() : radius(0)
        {

        }
    
        circle(double _radius) : radius(_radius)
        {

        }
};

class triangle
{
    public:
        double angles[3];
        double lengths[3];

        double altitude(double area, double length)
        {
            return 2 * area / length;
        }

        double area(double altitude, double length)
        {
            return length * altitude / 2;
        }

        triangle(double _angles[], double _lengths[])
        {
            for(int i = 0; i < 3; i++)
            {
                angles[i] = _angles[i];
                lengths[i] = _lengths[i];
            }

            bool is_right_ang = (angles[0] == 90 || angles[1] == 90 || angles[2] == 90);

            bool is_right_len = (lengths[0] * lengths[0] + lengths[1] * lengths[1] == lengths[2] * lengths[2] ||
                                lengths[1] * lengths[1] + lengths[2] * lengths[2] == lengths[0] * lengths[0] ||
                                lengths[2] * lengths[2] + lengths[0] * lengths[0] == lengths[1] * lengths[1]);

            bool is_real_len = (lengths[0] + lengths[1] <= lengths[2] &&
                                lengths[0] + lengths[2] <= lengths[1] &&
                                lengths[1] + lengths[2] <= lengths[0]);

            bool is_real_ang = (angles[0] + angles[1] + angles[2] == 180);

        }

};

double arr_max_index(double arr[])
{
    double arr_len = sizeof(arr) / sizeof(arr[0]);

    double max = 0.0;

    for(int i = 0; i < arr_len; i++)
    {
        if(arr[i] > max)
            max = i;
    }

    return max;
}

double arr_max_val(double arr[])
{
    double arr_len = sizeof(arr) / sizeof(arr[0]);

    double max = 0.0;

    for(int i = 0; i < arr_len; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}

#endif /*GEOMETRY*/