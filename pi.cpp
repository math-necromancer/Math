#include <iostream>
#include "math/frac.hpp"

int main()
{
    fraction f_0(2, 3);
    fraction f_1(5, 9);

    bool result = f_0 > f_1;

    std::cout << "True: " << result << '\n';
}