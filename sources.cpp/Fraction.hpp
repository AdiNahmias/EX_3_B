#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <algorithm>

namespace ariel {
class Fraction{

    private: 
        int numerator;
        int denominator;

    public:
    Fraction(int numerator, int denominator);
    Fraction(double num);
    int getNumerator();
    int getDenominator();
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    Fraction operator+(Fraction& other);
    double operator+(double num);
    friend Fraction operator+(double num, Fraction &frac);
    Fraction operator-(Fraction& other);
    double operator-(double num);
    friend Fraction operator-(double num, Fraction &frac);
    Fraction operator*(Fraction& other);
    double operator*(double num);
    friend Fraction operator*(double num, Fraction &frac);
    Fraction operator/( Fraction& other);
    friend Fraction operator/(double num, Fraction &frac);
    bool operator==(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    Fraction& operator++();
    Fraction& operator--();
    Fraction operator++(int);
    Fraction operator--(int);
    friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& input, Fraction& fraction);

};

    
};

#endif