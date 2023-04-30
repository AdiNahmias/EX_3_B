#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>



namespace ariel {
class Fraction{

    private: 
        int numerator;
        int denominator;

    public:

    void chekOverflow(long numerator , long denominator)const;

    Fraction(int numerator, int denominator);
    Fraction();
    Fraction(float num);

    int getNumerator();
    int getDenominator();
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    Fraction operator+(const Fraction& other) const;
    friend Fraction operator+(const Fraction& fraction , float num);
    friend Fraction operator+(float num, const Fraction &frac);

    Fraction operator-(const Fraction& other)const;
    friend Fraction operator-(const Fraction &frac, float num);
    friend Fraction operator-(float num, const Fraction &frac);
    
    Fraction operator*(const Fraction& other)const;
    friend Fraction operator*(const Fraction &frac, float num);
    friend Fraction operator*(double num, const Fraction &frac);
    
    Fraction operator/(const Fraction& other) const;
    friend Fraction operator/(const Fraction &frac, float num);
    friend Fraction operator/(float num, const Fraction &frac);
    
    bool operator==(const Fraction& other) const;
    bool operator==(float num) const;

    bool operator<(const Fraction& other) const;
    friend bool operator<(const Fraction& fraction , float num);
    friend bool operator<(const float &num, const Fraction &frac);
    

    bool operator>(const Fraction& other) const;
    friend bool operator>(float num, const Fraction& frac);
    friend bool operator> (const Fraction& fraction , float num);

    bool operator<=(const Fraction& other) const;
    friend bool operator<=(float num, const Fraction& frac);
    friend bool operator<=(const Fraction& fraction , float num);

    bool operator>=(const Fraction& other) const;
    friend bool operator>=(float num, const Fraction& frac);
    friend bool operator>=(const Fraction& fraction , float num);

    Fraction& operator++();
    Fraction& operator--();

    Fraction operator++(int);
    Fraction operator--(int);

    friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& inpt, Fraction& frc);

};

    
};

#endif