#pragma once
using namespace std;

#include<iostream>
#include<string>

class Film
{
	string nazwa;
	bool czy_obejrzany;
	int rocznik;

public:
	
	Film();
	Film(string nazwa, bool czy_obejrzany, int rocznik);
	virtual ~Film();


};
