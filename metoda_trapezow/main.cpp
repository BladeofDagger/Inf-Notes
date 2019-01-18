//
//  main.cpp
//  metoda_trapezow
//
//  Created by Martyna Gruszka on 18/01/2019.
//  Copyright © 2019 Martyna Gruszka. All rights reserved.
//

#include <iostream>
#include<cmath>
#include<fstream>

#define arraylen(ar) (sizeof(ar)/sizeof(ar[0])) // teraz mogę używać sobie takiej 'ala' metody
using namespace std;

float x[]={1.0,2.0,3.0,4.0,5.0,6.0};
float y[]={1.0,4.0,9.0,16.0,25.0,36.0};
float length = arraylen(x);

//f(x)=x^2
float max_x(float *x);
float min_x(float *a);

float pole_gotowa_funkcja_trapez(float x_min,float x_max);
float pole_gotowa_funkcja_prostokat(float x_min,float x_max);
float pole_tabelka(float *c, float *d);

int main() {
    
    float x_max = max_x(x);
    float x_min = min_x(x);
    
    float polet = pole_gotowa_funkcja_trapez(x_min,x_max);
    float polep = pole_gotowa_funkcja_prostokat(x_min,x_max);
    float polett = pole_tabelka(x, y);
    
    fstream plik("wyniki.txt",ios::out | ios::app);
    
    plik <<"Pole z metody trapezów: "<< polet<<endl;
    plik <<"Pole z metody prostokątów: "<<polep<<endl;
    plik <<"Pole z metody tabelkowej prostokątów: "<<polett<<endl;
    plik.close();
    
    plik.open("wyniki.txt",ios::in);
    
    char z;
    if(plik.is_open()){
        while(!plik.eof()){
            plik.get(z);
            cout << z;
        }
    }
    else{
        cout << "Mamy problem..."<<endl;
    }
    
    plik.close();
    
    
}

//metoda trapezów
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


// metoda prostokątów
float pole_gotowa_funkcja_prostokat(float x_min,float x_max){
    
    float pole = 0.0;
    int ilosc_podzialow = 1000;
    float a = x_min;
    float dx = (x_max-x_min)/ilosc_podzialow;
    
    for (int i=0; i<ilosc_podzialow; i++){
        
        pole = pole + dx*pow(a,2); //metoda: pow(baza,potęga)
        a=a+dx;
    }
    
    return pole;
    
}


// bez określenia wzoru funkcji
float pole_tabelka(float *c, float *d){
    
    float pole = 0.0;
    float a = max_x(c);
    float b = min_x(c);
    float ilosc_podzialow = length-1;
    
    float dx = (a-b)/ilosc_podzialow;
    
    for (int i=0; i<ilosc_podzialow; i++){
        
        pole = pole + (dx/2)*(*d + *(d+1)); //metoda: pow(baza,potęga)
        d++;
    }
    
    return pole;
    
}
    


//maksymalny element
float max_x(float *b){
    float max = *b;
    
    for (int i=0;i<(int)length;i++){
        if (*b>max){
            max = *b;
        }
        b++;
    }
    return max;
}


//minimalny element
float min_x(float *a){
    float min = *a;
    
    for (int i=0;i<(int)length;i++){
        if (*a < min){
            min = *a;
            
        }
        a++;
    }
   
    return min;

}

//printf("a[%d] = %d",i,licznik);
