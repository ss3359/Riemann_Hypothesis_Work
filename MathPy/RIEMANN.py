import math
import pandas as pd
import numpy as np
import pygame
import os
import scipy as syp
from sympy import nsolve,symbols 
from scipy.misc import derivative
import scipy.integrate 
import sympy as sym


def PrintComplexNumber(c):
        if(c.imaginary<0):
           print(f"{c.real}{c.imaginary}i")   
        else:
           print(f"{c.real}+{c.imaginary}i") 
        print()
def SIN(c):
    ReSIN=np.sin(c.real)*np.cosh(c.imaginary)
    ImSIN=np.cos(c.real)+np.sinh(c.imaginary)
    result=Complex(ReSIN,ImSIN)
    return result
def CPXEXP(n,c):
        RealExp=pow(n,c.real)*np.cos(c.imaginary)
        ImgExp=pow(n,c.real)*np.sin(c.imaginary)
        result=Complex(RealExp,ImgExp)
        return result

def RZ1COPY(n,x,y):
    c=Complex(x,y) 
    ONE=Complex(1,0)
    if(n<=1): 
        return ONE/c.CPXEXP(n)
    else: 
        return (ONE/c.CPXEXP(n))+RZ1COPY(n-1,x,y)

class Complex: 
    def __init__(self,x,y): 
        self.real=x
        self.imaginary=y 
    def __add__(self,other): 
        SumReal=self.real+other.real
        SumImg=self.imaginary+other.imaginary
        result=Complex(SumReal,SumImg)
        return result
    def __sub__(self,other): 
        SumReal=self.real-other.real
        SumImg=self.imaginary-other.imaginary
        result=Complex(SumReal,SumImg)
        return result
    def __mul__(self,other):
        MultReal=self.real*other.real-self.imaginary*other.imaginary
        MultImg=self.real*other.imaginary+self.imaginary*other.real
        result=Complex(MultReal,MultImg)
        return result 
    def __truediv__(self,other): 
        DivReal=(self.real*other.real + self.imaginary*other.imaginary)/(pow(other.real,2)+ pow(other.imaginary,2))
        DivImg= (self.imaginary*other.real-self.real*other.imaginary)/(pow(other.real,2)+ pow(other.imaginary,2))
        result=Complex(DivReal,DivImg)
        return result
    def CPXEXP(self,n):
        RealExp=pow(n,self.real)*np.cos(self.imaginary)
        ImgExp=pow(n,self.real)*np.sin(self.imaginary)

        result=Complex(RealExp,ImgExp)
        return result
    
    def RealGamma(self,t): 
        return pow(t,self.real-1)*np.exp(-t)*np.cos(self.imaginary*np.log(t))
    def ImgGamma(self,t): 
        return pow(t,self.real-1)*np.exp(-t)*np.sin(self.imaginary*np.log(t))
    def Gamma(self):
        SumReal,errorReal=scipy.integrate.quad(self.RealGamma,0.00001,10000)
        SumImg,errorImg=scipy.integrate.quad(self.ImgGamma,0.0001,10000)
        result=Complex(SumReal,SumImg)
        return result
    

class Riemann(Complex):
    def __init__(self,x,y):
        super().__init__(x,y)
    def Eta(self,n):
        ONE=Complex(1,0)
        NEGONE=Complex(-1,0)
        if(n<=1): 
            return ONE/self.CPXEXP(n)
        else: 
            return NEGONE.CPXEXP(n-1)*ONE/self.CPXEXP(n)+self.Eta(n-1)
    def RZ1(self,n):
        ONE=Complex(1,0)
        if(n<=1):
            return ONE/self.CPXEXP(n)
        else: 
            return (ONE/self.CPXEXP(n))+self.RZ1(n-1)
    def RZ2(self,n): 
        ONE=Complex(1,0)
        EXPTWO=self.CPXEXP(ONE-self,2)
        return (ONE/ONE-EXPTWO)*self.Eta(n)
    def RZ3(self,n):
        PI=Complex(np.pi,0)
        ONE=Complex(1,0)
        TWO=Complex(2,0)
        G=self.Gamma()
        Z=RZ1COPY(n,self.real,self.imaginary)
        self+=ONE
        return CPXEXP(2,self)*CPXEXP(np.pi,self-ONE)*SIN((PI*self)/TWO)
        

        pass
      
    

def main(): 
  


    v=Complex(1/2,2)
    r3=Riemann(v.real,v.imaginary)
    n=950 #number of terms
  
    print(f"Riemann Zeta Function for n={n} of "); 
    PrintComplexNumber(v)

    if(v.real<0):
        PrintComplexNumber(r3.RZ3(n))
    elif(v.real>1):
        PrintComplexNumber(RZ1COPY(n,v.real,v.imaginary))
    elif(v.real>0 and v.real<1):
        PrintComplexNumber(r3.RZ2(n))
    elif(v==1):
        print(f"This complex number will diverge")
    else:
        print("Enter Another Number!")




main()
