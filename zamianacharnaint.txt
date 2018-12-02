//
//  main.cpp
//  ex_13list_1
//
//  Created by Martyna Gruszka on 02.12.2018.
//  Copyright © 2018 Martyna Gruszka. All rights reserved.
//Napisz program, który oblicza sumę cyfr liczby naturalnej podanej przez użytkownika.

#include <iostream>
using namespace std;
char liczba[1024]{};
void suma_cyfr(char *l);


int main() {
    
    cout << "Podaj swoją liczbę: ";
    cin >> liczba;
        
    
    suma_cyfr(liczba);
}

void suma_cyfr(char *l){
    
    
    int suma=0;
    
    while (*l != 0){
        
        suma+=(*l-'0'); // zamiana char na int
        l++;
        
    }
//
    cout << "Suma cyfr podanej liczby wynosi: " << suma << endl;
}

//W tabeli ASCII wartość znaku 0 jest równa 48. Następne znaki cyfr do 9 mają wartości po kolei 49, 50, ..., 57. Więc gdy odejmiemy od nich wartość znaku 0 (48) to zostanie nam odpowiednia cyfra.
