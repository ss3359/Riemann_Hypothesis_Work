//
//  Marigold.cpp
//  Flowers
//
//  Created by Owner on 9/24/24.
//

#include "Marigold.hpp"
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include <iomanip>
#include <complex>

#include "Rose.hpp"
#include "Petunia.hpp"
using namespace std;



Complex operator+(Complex u,Complex v){
    
    long double SumReal=u.GetReal()+v.GetReal();
    long double  SumImg=u.GetImaginary()+v.GetImaginary();
    
    Complex result(SumReal,SumImg);
    
    return result;
}

Complex operator-(Complex u,Complex v){
    
    long double SumReal=u.GetReal()-v.GetReal();
    long double  SumImg=u.GetImaginary()-v.GetImaginary();
    
    Complex result(SumReal,SumImg);
    
    return result;
}

Complex operator*(Complex u, Complex v){
    
    long double  ProdReal=u.GetReal()*v.GetReal()-u.GetImaginary()*v.GetImaginary();
    long double  ProdImg=u.GetReal()*v.GetImaginary()+u.GetImaginary()*v.GetReal();
    
    Complex result(ProdReal,ProdImg);
    
    return result;
}

Complex operator/(Complex u, Complex v){
    
    
    long double  DivReal=(u.GetReal()*v.GetReal() +u.GetImaginary()*v.GetImaginary())/(pow(v.GetReal(),2)+pow(v.GetImaginary(),2));;
    long double  DivImg=(u.GetImaginary()*v.GetReal() -u.GetReal()*v.GetImaginary())/(pow(v.GetReal(),2)+pow(v.GetImaginary(),2));
    
    Complex result(DivReal,DivImg);
    
    return result;
    
    
}

Complex CpExp(double n, Complex p){
    
    long double  ExpReal=pow(n,p.GetReal())*cos(log(abs(p.GetImaginary())));
    long double ExpImg;
    
    if(p.GetImaginary()<0)
        ExpImg=-pow(n,p.GetReal())*sin(log(abs(p.GetImaginary())));
    else ExpImg=pow(n,p.GetReal())*sin(log(abs(p.GetImaginary())));
    
    Complex result(ExpReal,ExpImg);
    
    return result;
}

void PrintComplex(Complex c){
    if(c.GetImaginary()<0){
        cout<<setprecision(20)<<c.GetReal()<<setprecision(20)<<c.GetImaginary()<<"i"<<endl;
    }
    else{
        
        cout<<setprecision(20)<<c.GetReal()<<"+"<<setprecision(20)<<c.GetImaginary()<<"i"<<endl;
    }
}

Complex Gamma(Complex x){
// We Will Use Simpsons Rule To Calculate the Numerical Integral.
    long double a =0.000000001,b=1000,n=50000,dt= (b-a)/n;
    long double t=a,ReSum=0,ImSum=0;
    
    while(t<=b){
        if(t==a || t==b){
            ReSum+=(dt/3)*exp(-t)*exp((x.GetReal()-1)*log(t))*cos(x.GetImaginary()*log(t));
            ImSum+=(dt/3)*exp(-t)*exp((x.GetReal()-1)*log(t))*sin(x.GetImaginary()*log(t));
        }
        else if(int(t)%2==0){
            ReSum+=(2*dt/3)*exp(-t)*exp((x.GetReal()-1)*log(t))*cos(x.GetImaginary()*log(t));
            ImSum+=(2*dt/3)*exp(-t)*exp((x.GetReal()-1)*log(t))*sin(x.GetImaginary()*log(t));
        }
        else{
            ReSum+=(4*dt/3)*exp(-t)*exp((x.GetReal()-1)*log(t))*cos(x.GetImaginary()*log(t));
            ImSum+=(4*dt/3)*exp(-t)*exp((x.GetReal()-1)*log(t))*sin(x.GetImaginary()*log(t));
        }
        t+=dt;
    }
    Complex result(ReSum,ImSum);
    
    return result;
}

Complex RiemannZeta(int n, Complex p){
    
    if(n<=1)
        return 1/CpExp(n,p);
    else
        return (1/CpExp(n,p))+RiemannZeta(n-1, p);
    
}

Complex cos(Complex z){
    long double RealCos=cos(z.GetReal())*cosh(z.GetImaginary());
     long double ImgCos=-sin(z.GetReal())*sinh(z.GetImaginary());
    
    Complex result(RealCos,ImgCos);
    
    return result;
}

Complex sin(Complex z){
    long double RealSin=sin(z.GetReal())*cosh(z.GetImaginary());
     long double ImgSin=cos(z.GetReal())*sinh(z.GetImaginary());
    
    Complex result(RealSin,ImgSin);
    
    return result;
}


Complex RiemannZetaTwo(int n,Complex s){
    Complex NumPi(PI,0);
    Complex One(1,0);
    
    return CpEcp(2,s)*CpEcp(PI,s)*sin(NumPi*s/2)*Gamma(One-s)*RiemannZeta(n, 1-s);
}
