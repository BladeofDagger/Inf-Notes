//
//  main.cpp
//  ex_10list1
//
//  Created by Martyna Gruszka on 01.12.2018.
//  Copyright © 2018 Martyna Gruszka. All rights reserved.
//Napisz program, który zamienia w podanym przez użytkownika zdaniu słowo
//kotek na piesek. Np. dla podanego zdania: Ten kotek jest ładny. program wypisze:
//Ten piesek jest ładny.

#include <iostream>
using namespace std;
void zamianaslowa(char *z, char *s1, char *s2, char *m);
char zdanie[] = "jest kotek kotek kotek kotek ladny.";
char slowo1[]="kotek";
char slowo2[]="pi";
char zdanie_zmodyfikowane[]{};

int main() {
//    cout.width(3);
//    cout << right << "1"<<endl;
//    cout << left << "1"<<endl; do wyrownywania
    zamianaslowa(zdanie,slowo1,slowo2,zdanie_zmodyfikowane);
}


void zamianaslowa(char *z, char *s1, char *s2, char *m){
    
    bool czy_zmieniono= false;
    bool czy_zmienione2 = false;
    
    int dlugosc=0;
    int dlugosc2=0;
    char *s12 = s1;
    char *s22 = s2;
    int ilosc_powtorzonych_liter = 0;
    
    int licznik=0;
    
    
    // sprawdzamy ile liter ma słowo1
    while ( *s1 != 0){
        dlugosc++;
        s1++;
    }
    // ile liter ma slowo2
    while ( *s2 != 0){
        dlugosc2++;
        s2++;
    }
    
    s1=s12;
    s2=s22;
    
    cout << "Podane zdanie: " <<'\n'<< zdanie <<endl;
    
    while (*z != 0){
        
        
        czy_zmieniono=false; // bedziemy sprawdzac wszystkie litery
        czy_zmienione2=false;
        
        //        to jest równoważne :
        //        if (*(z+i)==*(s1)&&**(z+i+1)==*(s1+1)&&(z+i+2)==*(s1+2)&& ... itd.)
        for (int n=0; n<dlugosc; n++){
            if (*(z+n)==*(s1+n)){
                
                
                // sprawdzam po kolei czy litery sie zgadzaja i ile zgodnosci bylo w jednym przebiegu petli
                ilosc_powtorzonych_liter++;
                
            }
        
        }
        
        
        
        if (ilosc_powtorzonych_liter==dlugosc){
            licznik++;
            
            if (dlugosc==dlugosc2){
                for (int n=0; n<dlugosc2; n++ ){
                    
                    // dla konkretnej pozycji *z zastepuje litery ze zdania odpowiednikami ze slowo2
                    *(z+n)=*(s2+n);
                    }
            }
            // problem: nowo dodane litery ze slowa2 zwiekszaja ilosc liter w zdaniu i wychodza poza zakres
            else if (dlugosc2 > dlugosc){
                for (int n=0; n<dlugosc2; n++ ){
                    
                    //dopoki jest mniejsze od dlugosci slowa1
                    if ( n<dlugosc){
                        
                        *(z+n)=*(s2+n);
                        *m++=*(s2+n);
                        
                        
                    } else {
                        
                        czy_zmieniono=true;
                        *m++=*(s2+n);
                        // przypisujemy wartosc i przesuwamy sie do przodu w zmodyfikowanym zdaniu
                        
                        
                        
                        
                    }
                  
                }
                
                *m++=' '; // dodajemy spacje na koncu slowa2 i przesuwamy sie do przodu w zmodyfikowanym zdaniu
                
                
            }
            
            else {
                for (int n=0; n<dlugosc; n++ ){
                    
                    // jesli "skoncza mi sie litery ze slowa2 (bo jest krotsze)to pozostale litery zamieniam w spacje"
                    if ( n < dlugosc2 ){
                        *(z+n)=*(s2+n);
                        *m++=*(s2+n);
                        
                    } else {
                        czy_zmienione2=true;
                        
                    }
                    
                    
                    
                }
                *m++=' ';
            }
            
            
            
        }
        
        // zerujemy zeby za kazdym razem sprawdzac od poczatku ile liter sie powtorzylo
        
        ilosc_powtorzonych_liter = 0;
        
        
        
        if (czy_zmieniono || czy_zmienione2){
            z = z+dlugosc;
            
                    }
    
        else {
            *m=*z;// chcemy przypisac *m wartosc *z tylko gdy sami nie zmodyfikowalismy wartosci
            m++;
            
        }

        
        
        z++;
        
        
        
        
        
    }
    
    
    cout << "Słowo " <<"'"<< slowo1 << "'" << " powtórzyło się "  << licznik;
    if (licznik == 1){
         cout << " raz." << endl;
    } else {
        cout << " razy." << endl;
    }
    
    cout << "Zmodyfikowane zdanie: "<<'\n'<< zdanie_zmodyfikowane<< endl;
    
    
}


