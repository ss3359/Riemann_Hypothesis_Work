//
//  Petunia.hpp
//  Flowers
//
//  Created by Owner on 9/24/24.
//

#ifndef Petunia_hpp
#define Petunia_hpp

#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include <stdio.h>
using namespace std;


class Point{
private:
    double x;
    double y;
    
public:
    Point(double xcoord=0,double ycoord=0);
    double GetX();
    double GetY();
    Point CarToPol(Point car);
    double Distance(Point p,Point q);
    void PrintPoint(Point p){
        cout<<"("<<p.GetX()<<","<<p.GetY()<<")"<<endl;
    }
};


class Line:public Point{
    
private:
    double x;
    double y;
    double constant;
    
    
    
public:
    Line(double a=0,double b=0, double c=0);
    double getX();
    double getY();
    double getConstant();
    void PrintLine(Line l); 
    bool IsOnLine(Line l,Point p);
    
};
#endif /* Petunia_hpp */
