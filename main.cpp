//
//  main.cpp
//  ex_11list_1_zlicza ilosc sasiadujacych par znakow
//
//  Created by Martyna Gruszka on 02.12.2018.
//  Copyright © 2018 Martyna Gruszka. All rights reserved.
//Napisz program, który zlicza ilość wystąpień par sąsiadujących ze sobą liter ’o’ w
//podanym przez użytkownika ciągu.

#include <iostream>
using namespace std;

char ciag_znakow[255]{};
char znak{};
void ile_razy_wystapil_znak(char *c,char z);

int main() {
    
    cout << "Wprowadz swoj ciag znakow: ";
    cin.getline(ciag_znakow,255);
    cout<<endl;
    cout<< "Wprowadz znak: ";
    cin >> znak;
    ile_razy_wystapil_znak(ciag_znakow,znak);

    
    
}
void ile_razy_wystapil_znak(char *c,char z){
    


    int i=0;
    int ilosc_par=0;
    

    while (*c != 0){
        
        
        
                if (*(c+i)==z && *(c+i+1)==z){
                    ilosc_par++;
                    i++; // sprawdzam pary
                }
                
        
        
        c++;
    }
    
    cout << " Para znaków " << "'" << z <<"'" << " wystąpił " << ilosc_par << " razy " << endl;
}

