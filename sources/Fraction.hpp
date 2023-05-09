#pragma once
#include <iostream>
#include <limits>
using namespace std;

namespace ariel
{   const int ELEF=1000;
     const int MEA=100;  
    const int MAX = numeric_limits<int>::max();
     const int MIN = numeric_limits<int>::min(); 
    class Fraction
    {
        private:
            int numerator;
            int down;
            void reduce(); // Reduce the fraction

        public:
          Fraction(const int numerator, int denominator)
          {
               if(denominator==0){__throw_invalid_argument("Divided by zero!");}
               this->numerator=numerator;
               this->down=denominator;
               this->reduce(); // Reduce the fraction
          }
          Fraction() : numerator(1), down(1) // Default constauctor
          {}

          Fraction(float num) : numerator(int(num*ELEF)), down(ELEF) // Build Fraction object from float
          {
               this->reduce();
          }

          int getNumerator() const 
          {
               return this->numerator;
          }

          int getDenominator() const 
          {
               return this->down;
          }

          friend Fraction operator+(const Fraction& self, const Fraction& other)
          {
               if ((self.numerator == MAX ^ self.down == MAX)!=0 || (self.numerator <= (MIN + MEA) && other.numerator <= (MIN + MEA))){throw overflow_error("overflow");}
               int new_top= (self.numerator*other.down) + (self.down*other.numerator);
               int new_down= self.down*other.down;
               Fraction ans(new_top,new_down);
               return ans;
          }
          friend Fraction operator-(const Fraction& self, const Fraction& other)
          {
               if ((self.numerator<= MIN + MEA && other.numerator <= MIN + MEA) || (self.numerator >= MAX - MEA && other.numerator <= MIN + MEA)){throw overflow_error("overflow");}
               int new_top= (self.numerator*other.down) - (self.down*other.numerator);
               int new_down= self.down*other.down;
               Fraction ans(new_top,new_down);
               return ans;
          }
          friend Fraction operator*(const Fraction& self, const Fraction& other)
          {
               if ((self.numerator == MAX ^ self.down == MAX)!=0 || (other.numerator == MAX && other.down != MAX)){throw overflow_error("overflow");}
               int new_top= self.numerator*other.numerator;
               int new_down= self.down*other.down;
               Fraction ans(new_top,new_down);
               return ans;
          }
          friend Fraction operator/(const Fraction& self, const Fraction& other)
          {
               if ((self.down == MAX && self.numerator < MAX - MEA) || (self.numerator == MAX && self.down != MAX)){throw overflow_error("overflow");}
               if(other.numerator==0){__throw_runtime_error("Divided by zero");}
               int new_top= self.numerator*other.down;
               int new_down= self.down*other.numerator;
               Fraction ans(new_top,new_down);
               return ans;
          }
          friend bool operator==(const Fraction& self, const Fraction& other)
          {
               return ((self.numerator==other.numerator) && (self.down==other.down));
          }
          friend bool operator<(const Fraction& self, const Fraction& other)
          {
               int common= self.down*other.down;
               return ((self.numerator*common/self.down)<(other.numerator*common/other.down));
          }
          friend bool operator>(const Fraction& self, const Fraction& other)
          {
               int common= self.down*other.down;
               return ((self.numerator*common/self.down)>(other.numerator*common/other.down));
          }
          friend bool operator>=(const Fraction& self, const Fraction& other)
          {
               int common= self.down*other.down;
               return !((self.numerator*common/self.down)<(other.numerator*common/other.down)); 
          }
          friend bool operator<=(const Fraction& self, const Fraction& other)
          {
               int common= self.down*other.down;
               return !((self.numerator*common/self.down)>(other.numerator*common/other.down));
          }
          Fraction operator++()
          {
              this->numerator+=this->down;
              this->reduce();
              return *this;
          }
          Fraction operator--()
          {
              this->numerator-=this->down;
              this->reduce();
              return *this;
          }

          Fraction operator++(int)
          {
             Fraction curr(*this);
              this->operator++();
              this->reduce();               
              return curr;
          }

         Fraction operator--(int)
          {
              Fraction curr(*this);
              this->operator--(); 
              this->reduce();              
              return curr;
          }

        friend ostream& operator<<(ostream& ost, const Fraction& frac)
          {
               ost << frac.numerator << "/" << frac.down;
               return ost;
          }

        friend istream& operator>>(istream& ist, Fraction& frac)
          {
               int numerator=0;
               int denominator =0;
               ist >> numerator >> denominator;
               if(denominator==0){__throw_runtime_error("Invalid args!");}
               frac = Fraction(numerator, denominator);
               return ist;
          }

          friend Fraction operator+(const Fraction& self, float num)
          {
               Fraction tmp(num);
               return self+tmp;
          }
          friend Fraction operator-(const Fraction& self, float num)
          {
               Fraction tmp(num);
               return self-tmp;
          }
          friend Fraction operator*(const Fraction& self, float num)
          {
               Fraction tmp(num);
               return self*tmp;
          }
          friend Fraction operator/(const Fraction& self, float num)
          {
               Fraction tmp(num);
               return self/tmp;
          }
          friend bool operator==(const Fraction& self, float num)
          {
               Fraction tmp(num);
              return self==tmp;
          }
          friend bool operator<(const Fraction& self, float num)
          {
               Fraction tmp(num);
              return self<tmp;
          }
          friend bool operator>(const Fraction& self, float num)
          {
               Fraction tmp(num);
              return self>tmp;
          }
          friend bool operator>=(const Fraction& self, float num)
          {
               Fraction tmp(num);
               return self>=tmp;
          }
          friend bool operator<=(const Fraction& self, float num)
          {
               Fraction tmp(num);
              return self<=tmp;
          }

          friend Fraction operator+(float num, const Fraction& self)
          {
               Fraction tmp(num);
               return self+tmp;
          }
          friend Fraction operator-(float num, const Fraction& self)
          {
               Fraction tmp(num);
               return tmp-self;
          }
          friend Fraction operator*(float num, const Fraction& self)
          {
               Fraction tmp(num);
               return self*tmp;
          }
          friend Fraction operator/(float num, const Fraction& self)
          {
               Fraction tmp(num);
               return tmp/self;
          }
          friend bool operator==(float num, const Fraction& self)
          {
               Fraction tmp(num);
              return tmp==self;
          }
          friend bool operator<(float num, const Fraction& self)
          {
               Fraction tmp(num);
               return tmp<self;
          }
          friend bool operator>(float num, const Fraction& self)
          {
               Fraction tmp(num);
               return tmp>self;
          }
          friend bool operator>=(float num, const Fraction& self)
          {
               Fraction tmp(num);
               return tmp>=self; 
          }
          friend bool operator<=(float num, const Fraction& self)
          {
               Fraction tmp(num);
               return tmp<=self;
          }
          

    };
}