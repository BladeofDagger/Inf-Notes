//
//  main.cpp
//  Polynominal_interpolation
//
//  Created by Martyna Gruszka on 19/01/2019.
//  Copyright © 2019 Martyna Gruszka. All rights reserved.
// np. znajdź wartość dla x = 6; powino wyjść 36 dla f(x)= x^2


#include <iostream>
#include <fstream>

using namespace std;

#define arraylen(ar) (sizeof(ar)/sizeof(ar[0]));

double x[] = {1,2,3,4,5,7};
double y[] = {1,4,9,16,25,49};
double length = arraylen(x);



double przyblizenie(double x);
double przyblizenie2(double x);


int main() {
    double x;
    cout << "x = ";
    cin >> x;
    cout << endl;
    double przyblizenie = przyblizenie2(x);
    
    
    fstream plik("wyniki2.txt",ios::out | ios::app);
    plik << "Przybliżenie "<< x << " wynosi "<< przyblizenie<< '\n';
    plik.close();
    
    plik.open("wyniki2.txt",ios::in);
    char z;
    if (plik.is_open()){
        while(!plik.eof()){
            plik.get(z);
            cout << z;
        }
        
    }
    else {
        cout << "Mamy problem..."<<endl;
    }
    
    

}


// metoda z jedną pętlą
double przyblizenie(double X){
   
    int n = length-1; // wykladnik wielomianu
    double suma =0;
    double iloczyn = 1; // element neutralny mnozenia
    double przyblizenie;
    
    for (int i =0; i<n+1; i++){
        
        iloczyn = 1;
        for (int j = 0; j<n+1;j++){
            if (i != j){
                iloczyn = iloczyn*((X-x[j])/(x[i]-x[j]));
            }
            
        }
        suma = suma + y[i]*iloczyn;
    }
    
    przyblizenie = suma;
    return przyblizenie;
}

//metoda z dwoma pętlami
double przyblizenie2(double X){
    
    int n = length-1; // wykladnik wielomianu
    double suma =0;
    double iloczyn1 = 1;
    double iloczyn2 = 1;// element neutralny mnozenia
    double przyblizenie;
    
    for (int i =0; i<n+1; i++){
        
        iloczyn1 = 1;
        iloczyn2 = 1;
        for (int j = 0; j<i;j++){
            
            iloczyn1 = iloczyn1*((X-x[j])/(x[i]-x[j]));
            
            
        }
        for (int j = i+1; j<n+1;j++){
            iloczyn2 = iloczyn2*((X-x[j])/(x[i]-x[j]));
        }
            
        suma = suma + y[i]*iloczyn1*iloczyn2;
    }
    
    przyblizenie = suma;
    return przyblizenie;
}
