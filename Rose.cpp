//
//  Rose.cpp
//  Flowers
//
//  Created by Owner on 8/28/24.
//

#include<stdio.h>
#include<cmath>
#include<thread>
#include <iostream>
#include <vector>
#include <array>
#include "Rose.hpp"

using namespace std;

void SieveOfEratosthenes(int n){
    
    int i=0;
    int primes[n];
    while(i<n){
        primes[i]=i+1;
        i++;
    }
    
    for(int p:primes){
        cout<<p<<endl;
        if(p!=1){
            for(int q: primes){
                for(int j=2; j<=sqrt(n);j++)
                    if(q==p*j)
                        cout<<""<<endl;
            }
            
        }
        
    }
        
}


    

       


 
