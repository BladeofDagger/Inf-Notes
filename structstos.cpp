#include<iostream>
#include<cstring>
using namespace std;
//struktura listy jednokierunkowej
// wskaznik do ksiazki
//deklaracje w pliku naglowkowym 
// cpp funkcjonalnosci dodaj /usun
// projekt do oddania;
//


// stworzyc liste autorow
struct autor {
	string imie;
	string nazwisko;
};


using Autor = autor*;

struct ksiazka {
	Autor autor;
	string tytul;
	//enum wydawnictwo;
	int rocznik;
	ksiazka *Kolejna;
	
};


struct ksiegozbior {
	//wskaznik do pierwszej ksiazki
	Ksiazka pierwsza{}; // Ksiazka biezoca = pierwsza
	// if (biezaca-> kolejna != nullptr){biezoca = biezoca -> kolejna;} // 
	void dodaj(ksiazka k); ///autor *A, string tytul, int rocznik
	//podajemy nr ktory mamy usunac
	// jak podam numer to zwraca mi ksiazke 
	void usun(ksiazka k);
};


using Ksiazka = ksiazka*;


autor au1{ "mart","gru" };
autor au2{ "d","b" };
autor au3{ "f","h" };


int main() {

	ksiegozbior Mojksiegozbior;
	//Mojksiegozbior.dodaj();
	//Mojksiegozbior.usun(int nr);
	//Mojksiegozbior.zwroc(int nr);
	//Mojksiegozbior.drukuj(); // drukuje mi cala liste
	//wyszukiwanie, funkcja


	
	//autor imie nazwisko //string

	//ksiazka autor tytul //string wydawnictwo//enum rocznik int //enum //kolejna(*) //koniec listy to nullptr


	//ksiegoszbior pierwsz wskaznik do ksiazki
	//dodaj() z obiektów//czy nie nullptr
	//usun()

	system("PAUSE");

}
//autor *A,string tytul, int rocznik
void dodaj(ksiazka k) {

	Ksiazka Nowa = new ksiazka;

	Nowa->autor =k.autor;
	Nowa->tytul =k.tytul;
	//Nowa->wydawnictwo =k.wydawnictwo;
	Nowa->rocznik=k.rocznik;



}