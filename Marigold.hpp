//
//  Marigold.hpp
//  Flowers
//
//  Created by Owner on 9/24/24.
//

#ifndef Marigold_hpp
#define Marigold_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include <complex>


#include "Rose.hpp"
#include "Petunia.hpp"
using namespace std;

const double PI= 3.14159265359;


class Complex{
private:
    long double x;
    long double y;
public:
    Complex(long double a=0,long double b=0){
        x=a;
        y=b;
    }
    long double GetReal(){
        return x;
    }
    long double GetImaginary(){
        return y;
    }
};

Complex operator+(Complex u,Complex v);
Complex operator-(Complex u, Complex v);
Complex operator*(Complex u, Complex v);
Complex operator/(Complex u, Complex v);
Complex CpEcp(double n, Complex p);

Complex sin(Complex z);
Complex cos(Complex z); 

void PrintComplex(Complex c);
Complex Gamma(Complex x);
Complex RiemannZeta(int n, Complex p);
Complex RiemannZetaTwo(Complex s);





#endif /* Marigold_hpp */
