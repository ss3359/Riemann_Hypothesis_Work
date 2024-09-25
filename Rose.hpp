//
//  Rose.hpp
//  Flowers
//
//  Created by Owner on 8/28/24.
//

#ifndef Rose_hpp
#define Rose_hpp

#include <stdio.h>
#include <cmath>
#include <thread>
#include <iostream>
using namespace std;


class Polynomial{
    
public:
   
    int degree;
    vector<int> coefficients;
    Polynomial(int d,vector<int> c){
        degree=d;
        for (int number:c){
            coefficients.push_back(number);
        }
        
       }

};

void SieveOfEratosthenes(int n);

vector<int> RemoveElementFromArray(int element,int primes[]); 

#endif /* Rose_hpp */
