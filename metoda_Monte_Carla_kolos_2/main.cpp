//
//  main.cpp
//  metoda_Monte_Carla_kolos_2
//
//  Created by Martyna Gruszka on 14/01/2019.
//  Copyright © 2019 Martyna Gruszka. All rights reserved.
//

#include <iostream>
#include<cmath>
#include<ctime>
#include<fstream>

using namespace std;

int y[]={1,2,3,4,5,6,7};
int x[]={0,5,6,7,9,11,12};



int main() {
    srand(time(NULL));
    unsigned long long int suma_punktow_total = 10000000; // nasza dokładność
    unsigned long long int suma_punktow_pod_krzywa = 0;
    float integral ;
    
    int y_max = 144;
    int y_min = 0;
    int x_max = 12;
    int x_min = 0;
    
    
   
    
    for (int i=0;i<suma_punktow_total;i++){
     
        float ax = (x_min+(rand()%x_max)+(rand()%101)/100.0);
        float by = (y_min+(rand()%y_max)+(rand()%101)/100.0);
        
        if ( ax*ax>by ){
            
            suma_punktow_pod_krzywa++;
            //cout<< "x: "<<ax<<'\t'<<"y: "<< by <<endl;
        }
        
    }
    // funkcja f(x)=x^2; integral = 1/3*x^3 x$(0,12) => 576
    
    integral = (x_max-x_min)*(y_max-y_min)*(float)suma_punktow_pod_krzywa/(float)suma_punktow_total;
    
    fstream plik("wynik.txt",ios::out | ios::app); // każda kolejna próba zapisuje się pod spodem
    plik << "Integral = " << integral<<endl;
    plik.close();
    
    char t;
    plik.open("wynik.txt",ios::in);
    if(plik.is_open()){
        while(!plik.eof()){
            plik.get(t);
            cout<<t;
        }
        
    }
    else{
        cout <<"Problem";
    }
    
    
    
    
    
    //cout << "Integral = " << integral<< endl;
    //cout << "ilosc punktow pod krzywa " << suma_punktow_pod_krzywa << endl;
    
}



