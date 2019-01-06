//
//  main.cpp
//  Structure_library
//
//  Created by Martyna Gruszka on 28/12/2018.
//  Copyright © 2018 Martyna Gruszka. All rights reserved.
//

//#include<iostream>
//#include<string>
#include "struct_def.h"

//to nie jest potrzebne
//#include "struct_def.cpp"
//using namespace std;
//struktura listy jednokierunkowej
// wskaznik do ksiazki
//deklaracje w pliku naglowkowym
// cpp funkcjonalnosci dodaj /usun
// projekt do oddania;
//




autor au1{"Adam","Mickiewicz"};
autor au2{"Henryk","Sienkiewicz"};
autor au3{"Boleslaw","Prus"};
autor au4{"Stanislaw","Lem"};
autor au5{"Jan","Kochanowski"};
autor au6{"Juliusz","Slowacki"};

autor listA[] = {au1,au2,au3,au4,au5,au6};
//autor *A =listA;
int n=6;



int main() {
    
    ksiegozbior Mojksiegozbior;
    Mojksiegozbior.pierwsza = nullptr;
    
    
    Mojksiegozbior.dodaj(ksiazka{&listA[0],"Dziady",1975});
    Mojksiegozbior.dodaj(ksiazka{&listA[1],"Potop",1980});
    Mojksiegozbior.dodaj(ksiazka{&listA[2],"Lalka",1970});
    Mojksiegozbior.dodaj(ksiazka{&listA[3],"Solaris",1977});
    Mojksiegozbior.dodaj(ksiazka{&listA[3],"Bajki Robotow",1987});
    Mojksiegozbior.dodaj(ksiazka{&listA[1],"Krzyzacy",1970});
    Mojksiegozbior.dodaj(ksiazka{&listA[4],"Treny",1965});
    Mojksiegozbior.dodaj(ksiazka{&listA[5],"Kordian",1990});
    


    Mojksiegozbior.drukujListe();
    //Mojksiegozbior.zwroc(0);
    //Mojksiegozbior.zwroc(5);
    
    
    
    
    //Mojksiegozbior.usun(0);
    //Mojksiegozbior.drukujListe();
    //Mojksiegozbior.zwroc(int nr);
    //Mojksiegozbior.drukuj(); // drukuje mi cala liste
    //wyszukiwanie, funkcja
    
    
    
    
    
   //wydawnictwo//enum //koniec listy to nullptr

    
    //system("PAUSE");
    
}







