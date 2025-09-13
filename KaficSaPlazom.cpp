#include "KaficSaPlazom.h"
#include "ParLezaljki.h"
#include <iostream>
using namespace std;

KaficSaPlazom::KaficSaPlazom() {
	maxbr = 0;
	trbr = 0;
	naplacenaSvota = 0;
	niz = nullptr;
}
KaficSaPlazom::KaficSaPlazom(int mxbr) {
	maxbr = mxbr;
	trbr = 0;
	naplacenaSvota = 0;
	niz = new ParLezaljki * [maxbr];
	for (int i = 0; i < mxbr; i++) {
		niz[i] = nullptr;
	}
}
KaficSaPlazom::KaficSaPlazom(const KaficSaPlazom& k) {
	maxbr = k.maxbr;
	trbr = k.trbr;
	naplacenaSvota = k.naplacenaSvota;
	niz = new ParLezaljki * [maxbr];
	for (int i = 0; i < trbr; i++) {
		this->niz[i] = k.niz[i];
	}
}
KaficSaPlazom::~KaficSaPlazom() {
	for (int i = 0; i < trbr; i++) {
		if (niz[i] != nullptr) {
			delete niz[i];
		}
	}
	delete[]niz;
}
ostream& operator<<(ostream& os, KaficSaPlazom&k) {
	k.Print(os);
	return os;
}
ostream& KaficSaPlazom::Print(ostream& os) {
	os << "Kafic sa plazom:" << endl;
	for (int i = 0; i < trbr; i++) {
		niz[i]->Print(os);
	}
	os << endl;
	return os;
}
void KaficSaPlazom::Prikazi() {
	cout << "Kafic sa plazom:" << endl;
	for (int i = 0; i < trbr; i++) {
		cout << niz[i] << " ";
	}
	cout << endl;
}
void KaficSaPlazom::Dodaj(ParLezaljki* p1) {
	if (trbr >= maxbr) {
		cout << "Nema mesta!" << endl;
		return;
	}
	niz[trbr++] = p1;
}
void KaficSaPlazom::Oslobodi(int oz) {
	int ind=0;
	for (int i = 0; i < trbr; i++) {
		if (oz == niz[i]->vratiRdBr()) {
			ind = i;
		}
	}
	naplacenaSvota += niz[ind]->vratiSvotu();
	
		for (int i = ind; i < trbr - 1; i++) {
			niz[i] = niz[i + 1];
		}
	
	trbr--;
}
int KaficSaPlazom::UkupnoLezaljki() {
	int uk = 0;
	for (int i = 0; i < trbr; i++) {
		uk += niz[i]->vratiBrLez();
	}
	return uk;
}
int KaficSaPlazom::UkupnaSvotaNovca() {
	int uk = 0;
	for (int i = 0; i < trbr; i++) {
		uk += niz[i]->vratiSvotu();
	}
	return uk;
}
bool KaficSaPlazom::PostojiGdeTrebaPlatiti(int svt) {
	for (int i = 0; i < trbr; i++) {
		if (niz[i]->vratiSvotu() > svt) {
			return true;
		}
	}
	return false;
}
void KaficSaPlazom::VratiNajskuplje(ParLezaljki** mx, ParLezaljki** mxNap) {
	*mx = niz[0];
	*mxNap = niz[0];
	int najLez = niz[0]->vratiSvotu();
	int najPice = niz[0]->vratiVrPica();
	for (int i = 1; i < trbr; i++) {
		if (niz[i]->vratiSvotu() > najLez) {
			najLez = niz[i]->vratiSvotu();
			*mx = niz[i];
		}
		if (niz[i]->vratiVrPica() > najPice) {
			najPice = niz[i]->vratiVrPica();
			*mxNap = niz[i];
		}
	}
}