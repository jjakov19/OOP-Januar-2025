#pragma once
#include "ParLezaljki.h"
#include <iostream>
using namespace std;
class KaficSaPlazom
{
private:
	ParLezaljki** niz;
	int trbr;
	int maxbr;
	int naplacenaSvota;
public:
	KaficSaPlazom();
	KaficSaPlazom(int mxbr);
	KaficSaPlazom(const KaficSaPlazom& k);
	~KaficSaPlazom();
	friend ostream& operator<<(ostream& os, KaficSaPlazom&k);
	void Prikazi();
	ostream& Print(ostream& os);
	void Dodaj(ParLezaljki* p1);
	void Oslobodi(int oz);
	int UkupnoLezaljki();
	int UkupnaSvotaNovca();
	bool PostojiGdeTrebaPlatiti(int svt);
	void VratiNajskuplje(ParLezaljki** mx, ParLezaljki** mxNap);
};

