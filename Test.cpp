#include "doctest.h"

#include <iostream>
#include <string>
using namespace std;

#include "sources/Fraction.hpp"
using namespace ariel;

TEST_CASE("FRACTION_FRACTION")
{
    Fraction a(3,6);
    Fraction b(0.4);
    Fraction add(9,10);
    Fraction sub(1,10);
    Fraction mul(2,10);
    Fraction div(10,8);
    Fraction sub2(-1,10);
    Fraction div2(8,10);
    CHECK_EQ(a+b,add);
    CHECK_EQ(a-b,sub);
    CHECK_EQ(a*b,mul);
    CHECK_EQ(a/b,div);
    CHECK_EQ(b+a,add);
    CHECK_EQ(b-a,sub2);
    CHECK_EQ(b*a,mul);
    CHECK_EQ(b/a,div2);
    CHECK_EQ(a>b,false);
    CHECK_EQ(a>=b,false);
    CHECK_EQ(b<a,true);
    CHECK_EQ(b<=a,true);
    CHECK_EQ(a==b,false);    
}

TEST_CASE("FRACTION_FLOAT")
{
    Fraction a(3,6);
    float b=0.4;
    Fraction add(9,10);
    Fraction sub(1,10);
    Fraction mul(2,10);
    Fraction div(10,8);
    Fraction sub2(-1,10);
    Fraction div2(8,10);
    CHECK_EQ(a+b,add);
    CHECK_EQ(a-b,sub);
    CHECK_EQ(a*b,mul);
    CHECK_EQ(a/b,div);
    CHECK_EQ(b+a,add);
    CHECK_EQ(b-a,sub2);
    CHECK_EQ(b*a,mul);
    CHECK_EQ(b/a,div2);
    CHECK_EQ(a>b,false);
    CHECK_EQ(a>=b,false);
    CHECK_EQ(b<a,true);
    CHECK_EQ(b<=a,true);
    CHECK_EQ(a==b,false);    
}