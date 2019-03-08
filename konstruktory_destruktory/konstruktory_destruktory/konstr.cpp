#include "konstr.h"
using namespace std;

Film::Film() {

	nazwa = "film0";
	czy_obejrzany = false;
	rocznik = 2019;
	cout << "Dziala konstruktor domyslny " << nazwa << endl;
}

Film::Film(string nazwa, bool czy_obejrzany, int rocznik) :
	
	nazwa(nazwa),
	rocznik(rocznik),
	czy_obejrzany(czy_obejrzany){
	cout << "Dziala konstruktor parametryczny "<< (nazwa) << endl;
}


Film::~Film(){

	cout << "Dziala destruktor " <<nazwa<< endl;
}