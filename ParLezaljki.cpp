#include "ParLezaljki.h"
#include <iostream>
using namespace std;

ParLezaljki::ParLezaljki() {
	 rdBr=0;
	 red=0;
	 cenaLez=0;
	 vrPica = 0;
}
ParLezaljki::ParLezaljki(int rd, int red, int cenaLez, int vrp) {
	 rdBr = rd;
	 this->red = red;
	 this->cenaLez = cenaLez;
	 vrPica = vrp;
}
ParLezaljki::ParLezaljki(const ParLezaljki& c) {
	 rdBr = c.rdBr;
	red = c.red;
	 cenaLez = c.cenaLez;
	 vrPica = c.vrPica;
}
ostream& operator<<(ostream& os, ParLezaljki& o) {
	o.Print(os);
	return os;
}
ostream& ParLezaljki::Print(ostream& os) {
	os << rdBr << " " << red << " " << cenaLez << " " << vrPica << endl;
	return os;
}
void ParLezaljki::Prikazi() {
	cout << rdBr << " " << red << " " << cenaLez << " " << vrPica << endl;
}
int ParLezaljki::vratiSvotu() {
	int svota = 0;
	svota = (cenaLez + vrPica * (1 - (40 - 2 * red) / 100.0));
	return svota;
}
