#include "ParLezaljkiSaDodatkom.h"
#include <iostream>
using namespace std;
#include "ParLezaljki.h"

ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom() :ParLezaljki(), brojDodatnih(0){}
ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(int rd, int red, int cenaLez, int vrp, int brojD):ParLezaljki(rd,red,cenaLez,vrp),brojDodatnih(brojD){}
ParLezaljkiSaDodatkom::ParLezaljkiSaDodatkom(const ParLezaljkiSaDodatkom& c) {
	rdBr = c.rdBr;
	red = c.red;
	cenaLez = c.cenaLez;
	vrPica = c.vrPica;
	brojDodatnih = c.brojDodatnih;
}
ostream& ParLezaljkiSaDodatkom::Print(ostream& os) {
	os << rdBr << " " << red << " " << cenaLez << " " << vrPica<<" "<<brojDodatnih << endl;
	return os;
}
void ParLezaljkiSaDodatkom::Prikazi() {
	cout << rdBr << " " << red << " " << cenaLez << " " << vrPica << " " << brojDodatnih << endl;
}
int ParLezaljkiSaDodatkom::vratiSvotu() {
	int suma = 0;
	suma = (cenaLez * (1 + 0.4 * brojDodatnih) + vrPica * (1 - (40 - 2 * red - 5 * brojDodatnih) / 100.0));
	return suma;
}