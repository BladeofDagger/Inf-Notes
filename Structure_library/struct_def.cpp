//
//  struct_def.cpp
//  Structure_library
//
//  Created by Martyna Gruszka on 28/12/2018.
//  Copyright © 2018 Martyna Gruszka. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "struct_def.h"
using namespace std;

void ksiegozbior::dodaj( ksiazka k) {
    
    Ksiazka Nowa = new ksiazka;
    
    Nowa->autor = k.autor;
    Nowa->tytul =k.tytul;
    Nowa->rocznik=k.rocznik;
    
    if (pierwsza == nullptr){
        pierwsza = Nowa;
    } else {
        
        Ksiazka biezaca = pierwsza;

        
        while(biezaca->kolejna!=nullptr){
            biezaca=biezaca->kolejna;
            
        }
        
        
        biezaca->kolejna=Nowa;
    }
    
    
}

void autor::drukujA(){
    cout << imie << " "<<nazwisko << endl;
}

void ksiazka::drukuj(){
    
    cout << tytul << " "<< rocznik <<endl;
    
}

void ksiegozbior::usun( int nr ){
    
    Ksiazka poprzednia, biezaca;
    int index = 0;
    if (pierwsza == nullptr){
        return ;
    }
    if (nr == 0){
        biezaca = pierwsza->kolejna;
        delete pierwsza;
        pierwsza = biezaca;
    }
    else {
        biezaca = pierwsza;
        poprzednia = pierwsza;
        while (biezaca->kolejna!=nullptr && index < nr){
            poprzednia = biezaca;
            biezaca=biezaca->kolejna;
            index++;
        }
        if (biezaca != nullptr){
            poprzednia->kolejna=biezaca->kolejna;
            delete biezaca;
        }
    }
}

void ksiegozbior::drukujListe(){
    
    
    cout<<"Moja biblioteka: "<<endl;
    cout<<endl;
    Ksiazka biezaca=pierwsza;
    
        
    while ( biezaca != nullptr ) {
        
        biezaca->autor->drukujA();
        biezaca->drukuj();
        cout<<endl;
        
        biezaca=biezaca->kolejna;
        
    }
}

void ksiegozbior::zwroc(int nr ){
    Ksiazka biezaca;
    
    
    int index = 0;
    if (pierwsza == nullptr){
        return ;
    }
    else {
        
        biezaca = pierwsza;
        
        while (biezaca->kolejna!=nullptr && index < nr){
            biezaca=biezaca->kolejna;
            index++;
        }
        if (biezaca != nullptr){
            
            biezaca->autor->drukujA();
            biezaca->drukuj();
            cout<<endl;
        }
    }
}





