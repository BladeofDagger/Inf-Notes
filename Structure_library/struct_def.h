//
//  struct_def.h
//  Structure_library
//
//  Created by Martyna Gruszka on 28/12/2018.
//  Copyright © 2018 Martyna Gruszka. All rights reserved.
//

#ifndef struct_def_h
#define struct_def_h
#include <string>
using namespace std;
// stworzyc liste autorow
struct autor {
    string imie;
    string nazwisko;
    void drukujA();
    
};


using Autor = autor*;


struct ksiazka {
    Autor autor;
    string tytul;
    //enum wydawnictwo;
    int rocznik;
    ksiazka* kolejna=nullptr;
    void drukuj();
    
    
    
};

using Ksiazka = ksiazka*;

struct ksiegozbior {
    //wskaznik do pierwszej ksiazki
    ksiazka* pierwsza;
    void dodaj(ksiazka k); ///autor *A, string tytul, int rocznik
    //podajemy nr ktory mamy usunac
    // jak podam numer to zwraca mi ksiazke
    void usun( int nr);
    void drukujListe();
    void zwroc( int nr );
    
};



#endif /* struct_def_h */
