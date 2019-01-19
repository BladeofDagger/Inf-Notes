//
//  main.cpp
//  Numerical_differentiation
//
//  Created by Martyna Gruszka on 19/01/2019.
//  Copyright © 2019 Martyna Gruszka. All rights reserved.
// x^2 -> 2x

#include <iostream>
#define arraylen(ar) (sizeof(ar)/sizeof(ar[0]));
using namespace std;

double x[]={1,2,3,4,5,6};
double y[]={1,4,9,16,25,36};
double length = arraylen(x);

double przyblizenie_wartosci_wielomianu(double W);
void przyblizenie_pochodnej_forward(double X,double dx);
void przyblizenie_pochodnej_backwards(double X, double dx);
void przyblizenie_pochodnej_central(double X,double dx);

int main() {
    
    przyblizenie_pochodnej_backwards(9,0.000001);
    przyblizenie_pochodnej_central(9,0.000000001);
    przyblizenie_pochodnej_forward(9,0.0000001);
}

void przyblizenie_pochodnej_backwards(double X,double dx){
    
    
    double y = przyblizenie_wartosci_wielomianu(X);
    double x_minusdx = X - dx;
    double y_minusdx = przyblizenie_wartosci_wielomianu(x_minusdx);
    
   
    double pochodna;
    
    pochodna = (y-y_minusdx)/dx;
    cout << pochodna<<endl;
    
    
}

void przyblizenie_pochodnej_forward(double X,double dx){
    
    
    double y = przyblizenie_wartosci_wielomianu(X);
    double x_plusdx = X + dx;
    double y_plusdx = przyblizenie_wartosci_wielomianu(x_plusdx);
    
    double pochodna;
    
    pochodna = (y_plusdx-y)/dx;
    cout << pochodna<<endl;
    
    
}

void przyblizenie_pochodnej_central(double X,double dx){
    
    
    double x_minusdx = X - dx;
    double x_plusdx = X + dx;
    double y_plusdx = przyblizenie_wartosci_wielomianu(x_plusdx);
    double y_minusdx = przyblizenie_wartosci_wielomianu(x_minusdx);
    
    double pochodna;
    
    pochodna = (y_plusdx-y_minusdx)/dx;
    cout << pochodna<<endl;
    
}

double przyblizenie_wartosci_wielomianu(double W){
    
    int n = length-1;
    double przyblizenie;
    double suma = 0;
    double iloczyn1 = 1;
    double iloczyn2 = 1;
    
    for (int i=0; i<n+1; i++){
        
        iloczyn1=1;
        iloczyn2=1;
        for (int j=0; j<i; j++){
            iloczyn1 = iloczyn1*((W-x[j])/(x[i]-x[j]));
        }
        for (int j=i+1; j<n+1; j++){
            iloczyn2 = iloczyn2*((W-x[j])/(x[i]-x[j]));
        }
        
        suma = suma + y[i]*iloczyn1*iloczyn2;
    }
    przyblizenie = suma;
    
    return przyblizenie;
}
