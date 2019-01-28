//
//  main.cpp
//  Projekt_cyfermistrz
//
//  Created by Martyna Gruszka on 14/12/2018.
//  Copyright © 2018 Martyna Gruszka. All rights reserved.
//

#include <iostream>
#include <ctime>
#include<string>
#include <iomanip>
#include<array>




using namespace std;

const unsigned int ilosc_cyfr=4;


struct cyfry{
    char wartosc;
    int pozycja;
    bool czy_trafione;
    
};



void space();
void losowanie();
int sprawdzanie_cyfr(char Moja_liczba[ilosc_cyfr], cyfry Wylosowana_liczba[ilosc_cyfr], bool flag);


int main() {
    // pseudolosowość
    //srand(time(NULL));
    int runda = 1;
    int ilosc_trafien_poz,ilosc_trafien;
    
   
    
    
    char Liczba[ilosc_cyfr];
    
    bool wygrana = false;
    
    
   
    
    
    
    
    
    
    /*char a = (rand()%10)+'0';
    char b = (rand()%10)+'0';
    char c = (rand()%10)+'0';
    char d = (rand()%10)+'0';*/
    char a = 1 +'0';
    char b = 1 + '0';
    char c = 1 + '0';
    char d = 1 + '0';
    
    char znaki[] = {a,b,c,d};
    
    // tworzymy tablicę struktur
    cyfry cyfra[ilosc_cyfr];
    
    for (int i=0; i<ilosc_cyfr;i++){
        
        cyfra[i].wartosc=znaki[i];
        cyfra[i].pozycja=i;
        cyfra[i].czy_trafione = false;
        
    }
    
    
    
    cout << "'T+' - Ilość trafionych cyfr na dobrych miejscach"<<endl;
    cout << "'T-' - Ilość trafionych cyfr, ale na złych miejscach"<<endl;
    
    cout << endl;
    cout <<setw(18);
    for (int i=0;i<ilosc_cyfr;i++){
        cout<<cyfra[i].wartosc;
    }
    cout<<endl;
    cout<< left << setw(10)<<"Próba";
    cout << right <<setw(15)<<"Twoja liczba";
    cout <<right << setw(10)<<"T+";
    cout << right << setw(10)<<"T-";
    cout<<endl;
    cout<<endl;
    
    while (!wygrana){
        

        ilosc_trafien_poz=0;
        ilosc_trafien=0;
        
        

        // czyszczenie tablicy
        
        cout <<left<< setw(17)<<runda;
        //cin.width(5);
        char c;
        for (unsigned int i=0; i<ilosc_cyfr;i++){
            
            while ((c =getchar()) =='\n'){
                Liczba[i]=c;
            }
            
        }
       
        
        
       
        ilosc_trafien_poz = sprawdzanie_cyfr(&Liczba[ilosc_cyfr],&cyfra[ilosc_cyfr],true);
        ilosc_trafien = sprawdzanie_cyfr(&Liczba[ilosc_cyfr],&cyfra[ilosc_cyfr],false);
        
    
        /*for (unsigned int i=0; i<ilosc_cyfr;i++){
            //cin.get(y);
            //Liczba[i]=getchar();
            
            //Liczba[i]=y;
            cout << Liczba[i];
            
        }*/
        cout << Liczba[1];
    
        
        
        cout << right <<setw(33)<<ilosc_trafien_poz;
      
        cout << right << setw(10)<<ilosc_trafien;
        cout<<endl;
        
        if (ilosc_trafien_poz==ilosc_cyfr){
            cout<<endl;
            cout << setw(25)<<"WYGRANA!!!"<<endl;
            wygrana = true;
            break;
            
        }
        runda++;
    }
    

    
    
}


int sprawdzanie_cyfr(char Moja_liczba[ilosc_cyfr], cyfry Wylosowana_liczba[ilosc_cyfr], bool flag){
    
        int cyfry_trafione_plus_pozycja = 0;
        int cyfry_trafione = 0;
    
    
    
        for (unsigned int i=0; i<ilosc_cyfr;i++){
            
            
            for (unsigned int j=0;j<ilosc_cyfr;j++){
                
                if (Moja_liczba[i]==Wylosowana_liczba[j].wartosc && i == Wylosowana_liczba[j].pozycja) {
                    
                    Wylosowana_liczba[j].czy_trafione = true;
                    cyfry_trafione_plus_pozycja++;
                        
                    }
                else if (Moja_liczba[i]==Wylosowana_liczba[j].wartosc && i != Wylosowana_liczba[j].pozycja && Wylosowana_liczba[j].czy_trafione==false){
                        cyfry_trafione++;
                    
                }
            
            }
        }
    
    if (flag==true){
        return cyfry_trafione_plus_pozycja;
    }
    else {
        return cyfry_trafione;
    }
}
    

    
    
    
    
    
    
    
    
    
    
    

