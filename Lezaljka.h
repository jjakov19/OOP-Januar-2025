#pragma once
#include <iostream>
using namespace std;
class Lezaljka
{
	int brIznajmljenih;
	int cenaPica;
public:
	Lezaljka():brIznajmljenih(0),cenaPica(0){}
	Lezaljka(int brIz, int cena) :brIznajmljenih(brIz), cenaPica(cena) {}
	Lezaljka(const Lezaljka& l) :brIznajmljenih(l.brIznajmljenih), cenaPica(l.cenaPica) {}
	~Lezaljka(){}
	int getBrIzn()const { return brIznajmljenih; }
	int getCenaPica()const { return cenaPica; }
	friend ostream& operator <<(ostream& os, Lezaljka& l) {
		os << l.brIznajmljenih << " " << l.cenaPica<< " ";
		return os;
	}
	friend istream& operator>>(istream& is, Lezaljka& l) {
		is >> l.brIznajmljenih >> l.cenaPica;
		return is;
	}
};