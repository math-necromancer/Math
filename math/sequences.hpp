/*The Math Necromancer*/

#ifndef SEQ
#define SEQ

/*Get the factorial of x*/
long factorial(long x)
{
    long result = x;
    long i = x - 1;

    while (i > 1)
    {
        result *= i;
        i--;
    }
    
    return result;
}

/*Get the x'th number in the fibonacci sequence*/
int fibonacci(int x)
{
    if(x == 0)
    {
        return 0;
    }
    if(x == 1)
    {
        return 1;
    }

    int matrix[2][2] = {{1, 1}, {1, 0}};
    int a, b, c, d;

    for(int i = 2; i <= x; i++)
    {
        a = matrix[0][0] * 1 + matrix[0][1] * 1;
        b = matrix[0][0] * 1 + matrix[0][1] * 0;
        c = matrix[1][0] * 1 + matrix[1][1] * 1;
        d = matrix[1][0] * 1 + matrix[1][1] * 0;

        matrix[0][0] = a;
        matrix[0][1] = b;
        matrix[1][0] = c;
        matrix[1][1] = d;
    }

    return matrix[0][1];
}

#endif /*SEQ*/