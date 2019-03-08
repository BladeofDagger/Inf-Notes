#include<iostream>
#include "konstr.h"

Film f8;
Film f9("film9", 2015, true);
Film f10;

int main() {

	
	Film film1;
	//Film("film6", 2017, false); po wywolaniu bezposrednim konstr parametr dziala destruktor
	Film film4("film4", 2018, true);
	Film film3;
	Film* wsk1 = new Film();
	Film* wsk2 = new Film("film7",2016,false);
	delete wsk1;
	delete wsk2;
	Film film2("film2", 2019, false);
	//Film("film5", 2019, true);
	system("PAUSE");
}