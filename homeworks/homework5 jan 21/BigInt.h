//
// Created by Vahe Aleksanyan on 02.02.23.
//

#ifndef HOMWORK5_JAN_21_BIGINT_H
#define HOMWORK5_JAN_21_BIGINT_H

#include "iostream"
using namespace std;
class BigInt {
    string digits;
public:
    // ------------ public constructors ------------
    BigInt(unsigned long long n = 0);
    BigInt(string &); // why we don`t put argument name?
    BigInt(const char *);
    BigInt(BigInt &);


    // ------------ helper friend functions ------------
    friend void divide_by_two(BigInt &a);
    friend bool isNull(const BigInt &);
    friend int Length(const BigInt &);
    int operator[] (const int) const; // why we put const after parentases


    // ------------ operator overloading ------------

    //Post/Pre - Incrementation
    BigInt &operator=(const BigInt &);

    BigInt &operator++();
    BigInt operator++(int temp);
    BigInt &operator--();
    BigInt operator--(int tmep);

    // addition and subtraction
    friend BigInt & operator+=(BigInt &, const BigInt &);  // why use friend function for operator overloading
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt & operator-=(BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, const BigInt &);

    // comparision operators
    friend bool operator==(const BigInt &, const BigInt &);
    friend bool operator!=(const BigInt &, const BigInt &);

    friend bool operator>(const BigInt &, const BigInt &);
    friend bool operator>=(const BigInt &, const BigInt &);
    friend bool operator<(const BigInt &, const BigInt &);
    friend bool operator<=(const BigInt &, const BigInt &);

    friend BigInt &operator*=(BigInt &, const BigInt &);
    friend BigInt operator*(const BigInt &, const BigInt &);
    friend BigInt &operator/=( BigInt &, const BigInt &);
    friend BigInt operator/(const BigInt &, const BigInt &);


    //Modulo
    friend BigInt operator%(const BigInt &, const BigInt &);
    friend BigInt &operator%=(BigInt &, const BigInt &);

    //Power Function
    friend BigInt &operator^=(BigInt &,const BigInt &);
    friend BigInt operator^(BigInt &, const BigInt &);

    //Square Root Function
    friend BigInt sqrt(BigInt &a);

    //Read and Write
    friend ostream &operator<<(ostream &,const BigInt &);
    friend istream &operator>>(istream &, BigInt &);


    //Others
    friend BigInt NthCatalan(int n);
    friend BigInt NthFibonacci(int n);
    friend BigInt Factorial(int n);
};

#endif //HOMWORK5_JAN_21_BIGINT_H
