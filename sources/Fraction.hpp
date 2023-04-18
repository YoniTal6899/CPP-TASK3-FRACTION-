#pragma once
#include <iostream>
using namespace std;

namespace ariel
{
    class Fraction
    {
        private:
            int up;
            int down;
            void reduce(); // Reduce the fraction

        public:
          Fraction(int a, int b)
          {
               if(b==0){__throw_invalid_argument("Divided by zero!");}
               this->up=a;
               this->down=b;
               this->reduce(); // Reduce the fraction
          }
          Fraction() // Default constauctor
          {
               this->up=1;
               this->down=1;
          }

          Fraction(float num) // Build Fraction object from float
          {
               this->up=num*1000;
               this->down=1000;
               this->reduce();
          }

          friend Fraction operator+(const Fraction& self, const Fraction& other)
          {
               int new_up= (self.up*other.down) + (self.down*other.up);
               int new_down= self.down*other.down;
               Fraction ans(new_up,new_down);
               return ans;
          }
          friend Fraction operator-(const Fraction& self, const Fraction& other)
          {
               int new_up= (self.up*other.down) - (self.down*other.up);
               int new_down= self.down*other.down;
               Fraction ans(new_up,new_down);
               return ans;
          }
          friend Fraction operator*(const Fraction& self, const Fraction& other)
          {
               int new_up= self.up*other.up;
               int new_down= self.down*other.down;
               Fraction ans(new_up,new_down);
               return ans;
          }
          friend Fraction operator/(const Fraction& self, const Fraction& other)
          {
               if(other.up==0){__throw_invalid_argument("Divided by zero");}
               Fraction oppsite(other.down,other.up);
               return self*oppsite; 
          }
          friend bool operator==(const Fraction& self, const Fraction& other)
          {
               if((self.up==other.up) && (self.down==other.down)){return true;}
               return false;
          }
          friend bool operator<(const Fraction& self, const Fraction& other)
          {
               int common= self.down*other.down;
               if((self.up*common/self.down)<(other.up*common*other.down)){return true;}
               return false; 
          }
          friend bool operator>(const Fraction& self, const Fraction& other)
          {
               //cout << "self: " + to_string(self.up) +" / " +to_string(self.down) <<endl;
               //cout << "other: " + to_string(other.up) +" / " +to_string(other.down) <<endl;
               int common= self.down*other.down;
               if((self.up*common/self.down)>(other.up*common*other.down)){return true;}
               return false; 
          }
          friend bool operator>=(const Fraction& self, const Fraction& other)
          {
               //cout << "self: " + to_string(self.up) +" / " +to_string(self.down) <<endl;
               //cout << "other: " + to_string(other.up) +" / " +to_string(other.down) <<endl;
               int common= self.down*other.down;
               if((self.up*common/self.down)<(other.up*common*other.down)){return false;}
               return true; 
          }
          friend bool operator<=(const Fraction& self, const Fraction& other)
          {
               int common= self.down*other.down;
               if((self.up*common/self.down)>(other.up*common*other.down)){return false;}
               return true; 
          }
          Fraction operator++()
          {
              this->up+=this->down;
              this->reduce();
              return *this;
          }
          Fraction operator--()
          {
              this->up-=this->down;
              this->reduce();
              return *this;
          }

          Fraction operator++(int)
          {
             Fraction curr(*this);
              this->operator--();
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

        friend ostream& operator<<(ostream& os, const Fraction& frac)
          {
               os << frac.up << "/" << frac.down;
               return os;
          }

        friend istream& operator>>(istream& is, Fraction& frac)
          {
               int a, b;
               char c;
               is >> a >> c >> b;
               frac = Fraction(a, b);
               return is;
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
               if(tmp==self){return true;}
               return false;
          }
          friend bool operator<(const Fraction& self, float num)
          {
               Fraction tmp(num);
               if(tmp<self){return true;}
               return false; 
          }
          friend bool operator>(const Fraction& self, float num)
          {
               Fraction tmp(num);
               if(tmp>self){return true;}
               return false;
          }
          friend bool operator>=(const Fraction& self, float num)
          {
               Fraction tmp(num);
               if(tmp>=self){return true;}
               return false; 
          }
          friend bool operator<=(const Fraction& self, float num)
          {
               Fraction tmp(num);
               if(tmp<=self){return true;}
               return false;
          }

    };
}