/*The Math Necromancer*/

/*============ C++ GCF, LCM, and Swap Math Library ============*/
/*Contains functions for the Greatest Common Factor, Least Common Multiple,*/
/*and Swapping two values*/

#ifndef GCF_LCM_SWP
#define GCF_LCM_SWP

/*Swap the Values of Two Variables, x and y*/
void swap(int& x, int& y)
{
    /*Pretty Intuitive*/
    int r = y;
    y = x;
    x = r;
}
/*Get the Greatest Common Factor of x and y*/
int gcf(int x, int y)
{
    /*This is the Euclidean method for finding*/
    /*the Greatest Common Factor*/
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
/*Get the Least Common Multiple of x and y*/
int lcm(int x, int y)
{
    /*The Least Common Multiple is simply*/
    /*The 2 values multiplied and then*/
    /*divided by the Greatest Common Factor*/
    return (x * y) / gcf(x, y);
}

#endif /*GCF_LCM_SWP*/