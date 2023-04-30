#include "Fraction.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <stdexcept>

using namespace std;
namespace ariel{

void Fraction :: chekOverflow(long numerator , long denominator)const{
    if (denominator < INT_MIN || numerator < INT_MIN || numerator > INT_MAX || denominator > INT_MAX){
        throw std::overflow_error("The numerator or the denominator are too large or small");
    }
}

Fraction :: Fraction(int numerator , int denominator){
    if (denominator == 0){
        throw std :: invalid_argument ("It is not possible to divide by 0");
    }
    this -> numerator = numerator;
    this -> denominator = denominator;
    int gcd = std::__gcd(this->numerator, this->denominator);
    this -> numerator = numerator/gcd;
    this -> denominator = denominator/gcd;
}

Fraction :: Fraction(){
    this -> numerator = 1;
    this -> denominator = 1;
}

Fraction::Fraction(float num) {
    int up = this->numerator = (int)(num*1000);
    int down = this->denominator = 1000;
    int gcd = __gcd(up, down);
    this->numerator = up/gcd;
    this->denominator = down/gcd; 
}


int Fraction::getNumerator(){
    return this->numerator;
}

int Fraction::getDenominator(){
    return this->denominator;
}

void Fraction::setNumerator(int numerator){
    this->numerator = numerator;
    int gcd = __gcd(this->denominator, this->numerator);
    this->numerator = numerator/gcd;
    this->denominator = denominator/gcd;
}

void Fraction::setDenominator(int denominator){
    if (denominator == 0){
        throw std :: invalid_argument ("It is not possible to divide by 0");
    }
    this->denominator = denominator;
    int gcd = __gcd(this->denominator, this->numerator);
    this->numerator = numerator/gcd;
    this->denominator = denominator/gcd;
}


Fraction Fraction::operator+(const Fraction& other) const{ 
    long up1 = (long)(this->numerator * other.denominator) + (long)(other.numerator * this->denominator);
    long down1 = (long)this->denominator * other.denominator;
    chekOverflow(up1, down1);
    int up = (this->numerator * other.denominator) + (other.numerator * this->denominator);
    int down = this->denominator * other.denominator;
    return Fraction(up,down);
    
}

 Fraction operator+(const Fraction& fraction , float num){
    Fraction temp(num);
    return fraction + temp;  
}

Fraction operator+(const float num, const Fraction& frac){
    Fraction temp(num);
    return temp + frac; 
}

Fraction Fraction::operator-(const Fraction& other)const{
    long up1 = (long)(this->numerator * other.denominator) - (other.numerator * this->denominator);
    long down1 = (long)this->denominator * other.denominator;
    chekOverflow(up1,down1);
    int up = (this->numerator * other.denominator) - (other.numerator * this->denominator);
    int down = this->denominator * other.denominator;
    return Fraction(up,down);
    
}


Fraction operator-(const Fraction &frac, float num){
    Fraction temp(num);
    return frac-temp;
}

Fraction operator-(float num, const Fraction &frac){
    Fraction temp(num);
    return temp-frac;
}

Fraction Fraction::operator*(const Fraction& other)const{
    long up1 = (long)this->numerator * other.numerator;
    long down1 = (long)this->denominator * other.denominator;
    chekOverflow(up1,down1);
    int up = this->numerator * other.numerator;
    int down = this->denominator * other.denominator;
    return Fraction(up,down);
}

Fraction operator*(const Fraction &frac, float num){
    Fraction temp(num);
    return frac*temp;
}

Fraction operator*(double num, const Fraction &frac){
    Fraction temp(num);
    return temp * frac;
}

Fraction Fraction::operator/(const Fraction& other) const{
    if(other.numerator == 0){
        throw std :: runtime_error ("It is not possible to divide by 0");
    }
    long up1 = (long)this->numerator * (long)other.denominator;
    long down1 = (long)this->denominator * (long)other.numerator;
    chekOverflow(up1,down1);
    int up = this->numerator * other.denominator;
    int down = this->denominator * other.numerator;
    return Fraction(up,down);   
}

Fraction operator/(float num, const Fraction &frac){
    if(frac.numerator == 0){
        throw std :: runtime_error ("It is not possible to divide by 0");
    }
    Fraction temp(num); 
    return temp/frac;
}

Fraction operator/(const Fraction &frac, float num){
    if(num == 0){
        throw std :: runtime_error ("It is not possible to divide by 0");
    } 
    Fraction temp(num); 
    return frac/temp;
}

bool Fraction::operator==(const Fraction& other) const {
    float num1 = (float)this->numerator/this->denominator;
    float num2 = (float)other.numerator/other.denominator;
    return round(num1 * 1000)/1000 == round(num2 * 1000)/1000;
}
    

bool Fraction :: operator==(float num) const{
    float num1 = (float)this->numerator/this->denominator;
    return round(num1*1000)/1000 == round(num*1000)/1000;
}



bool Fraction::operator<(const Fraction& other) const {
    if(this->denominator == other.denominator){
            return this->numerator < other.numerator;
    }else if(this->numerator == other.numerator){
            return this->denominator > other.denominator;        
    }
    else if(((float)this->numerator/this->denominator) < ((float)other.numerator/other.denominator)){
        return true;
    }
    return false;
    
}

bool operator<(const Fraction& fraction , float num){
        return fraction < Fraction(num);
}


bool operator<(const float &num, const Fraction& frac) {
   return Fraction(num) < frac;
}



bool Fraction::operator>(const Fraction& other) const {
    return ((float)(this->numerator) / this->denominator) > (float)(other.numerator) / other.denominator;
}

bool operator>(float num, const Fraction& frac) {
    return Fraction(num) > frac;
    
}

bool operator>(const Fraction& fraction , float num){
        return fraction > Fraction(num);
}

bool Fraction::operator<=(const Fraction& other) const {
    if(((float)this->numerator/(float)this->denominator) > 0 && (((float)other.numerator/(float)other.denominator) < 0)){
        return false;
    }
    
    else if ((this -> numerator* other.denominator) <= (other.numerator*this -> denominator)){
        return true;
    } 
    return false;
    }


bool operator<=(float num, const Fraction& frac){
    return (Fraction(num) <= frac); 
}

bool operator<=(const Fraction& fraction , float num){
    return fraction <= Fraction(num);      
}
    
bool Fraction::operator>=(const Fraction& other) const {
    if(((float)this->numerator/(float)this->denominator) < 0 && ((float)other.numerator/(float)other.denominator) > 0){
        return false;
    }
    if ((this -> numerator* other.denominator) >= (other.numerator*this -> denominator)){
        return true;
    } 
    return false;
}

bool operator>=(float num, const Fraction& frac){
    return (Fraction(num) >= frac);  
    
}

bool operator>=(const Fraction& fraction , float num){
        return fraction >= Fraction(num);
}

//prefix: ++n
Fraction& Fraction::operator++(){
    this->numerator = this->numerator + this->denominator;
    return *this;
}

//postfix: n++
Fraction Fraction::operator++(int) { 
    Fraction temp = *this;
    *this = *this+1; 
    return temp; 
    
}

//prefix: --n
Fraction& Fraction::operator--(){
    this->numerator = this->numerator - this->denominator;
    return *this;
}

//postfix: n--
Fraction Fraction::operator--(int) { 
    Fraction temp = *this; 
    *this = *this-1; 
    return temp;
        
}



std::ostream& operator<<(std::ostream& output, const Fraction& fraction) {
    if (fraction.denominator == 0) {
        output << "Undefined";
    //up and down are negative
    } else if (fraction.denominator < 0) {
        if (fraction.numerator < 0) {
            output << (-fraction.numerator) << "/" << (-fraction.denominator);
        //down is negative
        } else {
            output << "-" << fraction.numerator << "/" << (-fraction.denominator);
        }
    //up and down are not negative
    } else {
        output << fraction.numerator << "/" << fraction.denominator;
    }
    return output;
}

std::istream& operator>>(std::istream& input, Fraction& fraction){
    int up;
    int down;
    if((input>>up>>down) && down != 0){
        fraction = Fraction(up,down);
    }else{
        throw runtime_error("Invalid input");    
    }
    return input;
}

}




