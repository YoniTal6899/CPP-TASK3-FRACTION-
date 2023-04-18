#include "Fraction.hpp"
#include <cmath>
#include <iostream>
using namespace ariel;

void Fraction::reduce()
{
    int common_gcd=1;
    int high_val=1;
    if(abs(this->down) > abs(this->up)){high_val=abs(this->down);}
    else{high_val=abs(this->up);}
    for(int i= common_gcd; i<high_val;i++)
    {
        if(abs(this->down)%i==0 && abs(this->up)%i==0){common_gcd=i;}
    }
    this->up= this->up/common_gcd;
    this->down= this->down/common_gcd;
}

