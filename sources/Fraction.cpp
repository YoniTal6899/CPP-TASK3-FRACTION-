#include "Fraction.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace ariel;

void Fraction::reduce()
{
    int common_gcd=__gcd(this->numerator, this->down);
    this->numerator= this->numerator/common_gcd;
    this->down= this->down/common_gcd;
    if (this->down<0)
    {
        this->numerator*=-1;
        this->down*=-1;
    }
}

