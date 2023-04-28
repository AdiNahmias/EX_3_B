#include "Fraction.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
namespace ariel{

Fraction :: Fraction(int numerator , int denominator){
    if (denominator == 0){
        throw std :: invalid_argument ("INVALID DEMONINATOR");
    }
    int gcd = std::__gcd(numerator, denominator);
    this -> numerator = numerator/gcd;
    this -> denominator = denominator/gcd;
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
}

void Fraction::setDenominator(int denominator){
    if (denominator == 0){
        throw std :: invalid_argument ("Invalid denominator");
    }
    this->denominator = denominator;
}


Fraction Fraction::operator+(Fraction& other){

    int up = (this->numerator * other.denominator) + (other.numerator * this->denominator);
    int down = this->denominator * other.denominator;

    int gcd = std::__gcd(up, down);
    up /= gcd;
    down /= gcd;

    return Fraction(up,down);
    
}

double Fraction::operator+(double num){
    double result = (double(this->numerator) / double(this->denominator)) + num;
    return result;
}

Fraction operator+(double num, Fraction &frac){
    int up = num*1000;
    int down = 1000; 
    
    return Fraction(up,down) + frac;
}


Fraction Fraction::operator-(Fraction& other){
    
    int up = (this->numerator * other.denominator) - (other.numerator * this->denominator);
    int down = this->denominator * other.denominator;

    int gcd = std::__gcd(up, down);
    up /= gcd;
    down /= gcd;

    return Fraction(up,down);
    
}



Fraction operator-(Fraction &frac, float num){
    
    int up = num*1000;
    int down = 1000; 
    Fraction temp(up,down);
    
    return frac-temp;
}

Fraction operator-(float num, Fraction &frac){
    
    int up = num*1000;
    int down = 1000; 
    
    return Fraction(up,down)-frac;
}

Fraction Fraction::operator*(Fraction& other) {
    
    int up = this->numerator * other.numerator;
    int down = this->denominator * other.denominator;

    int gcd = std::__gcd(up, down);
    up /= gcd;
    down /= gcd;

    return Fraction(up,down);
}

double Fraction::operator*(double num){
    
    double result = (this->numerator / this->denominator) * num;
    return result;
}


Fraction operator*(double num, Fraction &frac){
    
    int up = num*1000;
    int down = 1000; 
    
    return Fraction(up,down) * frac;
}


Fraction Fraction::operator/(Fraction& other) const{

    int up = this->numerator * other.denominator;
    int down = this->denominator * other.numerator;

    int gcd = std::__gcd(up, down);
    up /= gcd;
    down /= gcd;

    return Fraction(up,down);   
}

Fraction operator/(float num, Fraction &frac){
    
    int up = num*1000;
    int down = 1000;
    Fraction temp(up,down); 
    
    return temp/frac;
}

Fraction operator/(Fraction &frac, float num){
    
    int up = num*1000;
    int down = 1000; 
    Fraction temp(up,down); 
    
    return frac/temp;
}


bool Fraction::operator==(const Fraction& other) const {
    if ((this->numerator == other.numerator) && (this->denominator == other.denominator)){
        return true;
    }
    return false;
}


bool Fraction::operator<(const Fraction& other) const {
    if ((this->numerator/this->denominator) < (other.numerator/other.denominator)){
        return true;
    }
    return false;
    
}

bool operator<(float num, const Fraction& frac) {
    if (Fraction(num) < frac){
        return true;
    }
    return false;
    
}

bool Fraction::operator>(const Fraction& other) const {
    double thisValue = static_cast<double>(this->numerator) / this->denominator;
    double otherValue = static_cast<double>(other.numerator) / other.denominator;
    return thisValue > otherValue;
}

bool operator>(float num, const Fraction& frac) {
    if (Fraction(num) > frac){
        return true;
    }
    return false;
    
}

bool Fraction::operator<=(const Fraction& other) const {
    if ((this->numerator/this->denominator) <= (other.numerator/other.denominator)){
        return true;
    } 
    return false;
}

bool operator<=(float num, const Fraction& frac){
    if (Fraction(num) <= frac){
        return true;
    }
    return false;
    
}
    
bool Fraction::operator>=(const Fraction& other) const {
    double thisValue = static_cast<double>(this->numerator) / this->denominator;
    double otherValue = static_cast<double>(other.numerator) / other.denominator;
    return thisValue >= otherValue;
}

bool operator>=(float num, const Fraction& frac){
    if (Fraction(num) >= frac){
        return true;
    }
    return false;
    
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


std::ostream& operator<<(std::ostream& output, const Fraction& fraction){
    output << fraction.numerator<< "/" <<fraction.denominator;
    return output;
}

std::istream& operator>>(std::istream& input, Fraction& fraction){

    int up;
    int down;
    char temp;

    input>>up;
    input>>temp;
    input>>down;

    if(temp == '/' && down != 0){

        fraction.setDenominator(up);
        fraction.setNumerator(down);  

    }else{

        throw invalid_argument("Invalid input");    
    }
    

    return input;
}

}




