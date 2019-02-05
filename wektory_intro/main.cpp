//
//  main.cpp
//  wektory_intro
//
//  Created by Martyna Gruszka on 18/01/2019.
//  Copyright © 2019 Martyna Gruszka. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include<cmath>
#define arraylen(ar) (sizeof(ar)/sizeof(ar[0]))
using namespace std;

int ilosc_cyfr =10;

void readfile(int *ilosc_cyfr,int *x,int *y);



float max_x(int *x);
float min_x(int *a);
float pole_gotowa_funkcja_trapez(float x_min,float x_max);



int main() {
    
    int x[10];
    int y[10];
    readfile(&ilosc_cyfr, x,y );
    
    for (int i=0;i<ilosc_cyfr;i++){
        cout<<x[i]<<endl;
    }
    
    
    float x_max = max_x(x);
    float x_min = min_x(x);
    
    float polet = pole_gotowa_funkcja_trapez(x_min,x_max);
    
    cout << polet;
}


float pole_gotowa_funkcja_trapez(float x_min,float x_max){
    
    float pole = 0.0;
    int ilosc_podzialow = 1000;
    float a = x_min;
    float dx = (x_max-x_min)/ilosc_podzialow;
    
    for (int i=0; i<ilosc_podzialow; i++){
        
        pole = pole + (dx/2)*(pow(a,2)+pow(a+dx,2)); //metoda: pow(baza,potęga)
        a=a+dx;
    }
    
    return pole;
    
}

//maksymalny element
float max_x(int *b){
    int max = (float)*b;
    
    for (int i=0;i<(int)ilosc_cyfr;i++){
        if (*b>max){
            max = *b;
        }
        b++;
    }
    return (float)max;
}


//minimalny element
float min_x(int *a){
    int min = (float) *a;
    
    for (int i=0;i<(int)ilosc_cyfr;i++){
        if (*a < min){
            min = *a;
            
        }
        a++;
    }
    
    return (float)min;
    
}

void readfile(int *ilosc_cyfr,int *x,int *y){
    char z;
    
    int lokalny_licznik = 0;
    ifstream plik("data.txt");
    
    if (plik.is_open()){
        while (!plik.eof()) {
            //*ilosc_cyfr=*ilosc_cyfr+1;
            plik.get(z);
            if (lokalny_licznik%2 == 0){
                *x=z-'0';
                x++;
            }
            else {
                *y=z-'0';
                y++;
            }
            
            lokalny_licznik++;
        }
    }
    plik.close();
    
}


