//
//  Petunia.cpp
//  Flowers
//
//  Created by Owner on 9/24/24.
//


#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include "Petunia.hpp"
using namespace std;

const double PI= 3.14159265359;

//Functions of the Point Class
Point::Point(double xcoord, double ycoord){
    
    x=xcoord;
    y=ycoord;
}
double Point::GetX(){
    return x;
}
double Point::GetY(){
    return y;
}
Point Point:: CarToPol(Point car){


        double x=car.GetX(),y=car.GetY(), r=sqrt(x*x+y*y),theta=atan(y/x);
  
    if(x<=0&&y>0)
        theta=PI-theta;
    else if (x<0&& y<=0)
        theta=PI+theta;
    else if(x>0&&y<0)
        theta=2*PI-theta;
    else if(y==0){
        if(x>0){
            theta=0;
            Point car(r,theta);
            return car;

        }
        else{
            theta=PI;
            Point car(r,theta);
            return car;
        }
    }  else if(x==0){
        if(y>0){
            theta=PI/2;
            Point car(r,theta);
            return car;

        }
        else{
            theta=3*PI/2;
            Point car(r,theta);
            return car;
        }
    }
       
    Point pol(r,theta);
    
    return pol;
        
        
}

double Point::Distance(Point p, Point q){
    
    double d_squared=pow((q.GetX()-p.GetX()),2)+pow((q.GetY()-p.GetY()),2);
    
    return sqrt(d_squared); 
}






//Functions of the Line Class
Line::Line(double a, double b, double c){
    x=a;
    y=b;
    constant=c;
}
double Line:: getX(){return x;}
double Line:: getY(){return y;}
double Line:: getConstant(){return constant;}

void Line::PrintLine(Line l){
    
    cout<<"Line: "<<l.getX()<<"x + "<<l.getY()<<"y = "<<l.getConstant()<<endl;
}

bool Line::IsOnLine(Line l,Point p){
    
    double result=l.getX()*p.GetX()+l.getY()*p.GetY();
    
    if(result==l.getConstant())
        return true;
    return false;
}
