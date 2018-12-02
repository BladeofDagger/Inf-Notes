//
//  main.cpp
//  c++pointers_ex6list2
//
//  Created by Martyna Gruszka on 26.11.2018.
//  Copyright © 2018 Martyna Gruszka. All rights reserved.
//

#include <iostream>
using namespace std;

void convert(char *a, char *b);
char *a = nullptr;
char *b = nullptr;
char text[1024]="Pogoda";
char convertedText[1024]{};

int main() {
    
    convert(text,convertedText);
    cout << text << endl;
    cout << convertedText << endl;
    
    system("PAUSE");
    
}

void convert(char *a, char *b){
    int i = 0;
    while (*a != 0){
        i++;
        a++;
        
    }
    for (int j=0; j<i; j++){
        *b++=*(--a);
        *b = 0;
    }
    
}
