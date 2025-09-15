#include "KaficSaPlazom.h"
#include "ParLezaljki.h"
#include "ParLezaljkiSaDodatkom.h"
#include"Lezaljka.h"
#include "Plaza.h"
#include <iostream>
using namespace std;


void zadatak1() {
	// 2 poena
	int pL[] = { 12, 1, 40, 20 };
	ParLezaljki* p1 = new ParLezaljki(pL[0], pL[1], pL[2], pL[3]);
	//p1->Prikazi();
	cout << *p1 << endl;
	// 2 poena
	int pLD[] = { 21, 2, 30, 10, 1 };
	ParLezaljkiSaDodatkom* p2 = new ParLezaljkiSaDodatkom(pLD[0], pLD[1], pLD[2], pLD[3], pLD[4]);
	//p2->Prikazi();
	cout << *p2 << endl;
	int rbr[] = { 12, 15, 18, 23, 27, 31, 34, 37 };
	int red[] = { 1, 1, 1, 2, 2, 3, 3, 3 };
	int cena[] = { 40, 40, 40, 30, 30, 20, 20, 20 };
	int napici[] = { 20, 40, 30, 30, 70, 20, 30, 10 };
	int dodatno[] = { 1, 2 };
	KaficSaPlazom* pKSP = new KaficSaPlazom(10);
	// 2 poena
	for (int i = 0; i < 4; i++)
	{
		pKSP->Dodaj(new ParLezaljki(rbr[i], red[i], cena[i], napici[i]));
		pKSP->Dodaj(new ParLezaljkiSaDodatkom(rbr[i+4], red[i+4], cena[i+4], napici[i+4], dodatno[i % 2]));
	}
	// 2 poena
	//pe.print();
	cout << *pKSP << endl;
	// 2 poena
	int oznaka = 34;
	pKSP->Oslobodi(oznaka);
	//pe->print();
	cout << *pKSP << endl;
	// 2 poena
	cout << pKSP->UkupnoLezaljki() << endl;
	// 2 poena
	cout << pKSP->UkupnaSvotaNovca() << endl;
	// 2 poena
	int svota = 5000;
	if (pKSP->PostojiGdeTrebaPlatiti(svota))
		cout << "Postoje lezaljke gde treba platiti vise od " << svota << endl;
	else
		cout << "ne postoje lezaljke gde treba platiti vise od " << svota << endl;
	// 3 poena
	ParLezaljki* pLezMaxCena = nullptr, * pLezMaxNapitak = nullptr;
	pKSP->VratiNajskuplje(&pLezMaxCena, &pLezMaxNapitak);
	pLezMaxCena->Prikazi();
	pLezMaxNapitak->Prikazi();
	// 1 poena
	delete pKSP;
}
void zadatak2()
{
	int brRedova = 4, brKolona = 8;
	int brojPodataka = 7;
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	try{
		int red[] = { 1, 1, 2, 2, 3, 3, 3 };
		int kolona[] = { 2, 5, 1, 6, 3, 5, 7 };
		int lez[] = { 2, 3, 2, 2, 4, 3, 2 };
		Plaza<int> plaza(brRedova, brKolona);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			plaza.Dodaj(red[i], kolona[i], lez[i]);
		cout << plaza << endl; //plaza.Ispisi(cout);
		// 1 bod
		plaza.Oslobodi(red[3], kolona[3]);
		cout << plaza << endl; //plaza.Ispisi(cout);
		// 1 bod
		int ukupno = plaza.Ukupno();
		cout << ukupno << endl;
		// 1 bod
		int brLez = 2;
		int brojMesta = plaza.BrojMesta(brLez);
		cout << brojMesta << endl;
		// 1 bod
		int brojLez = 0;
		int redNaj = plaza.RedSaNajvise(brojLez);
		cout << redNaj << " " << brojLez << endl;
		// 1 bod
		char fajl[] = "PlazaVal.txt";
		plaza.Sacuvaj(fajl);
		// 1 boda
		Plaza<int> plazaUcitana;
		plazaUcitana.Ucitaj(fajl);
		cout << plazaUcitana << endl; //plazaUcitana.Ispisi(cout);
	}
	catch (const runtime_error& k) {
		cout << "Greska:" << k.what() << endl;
	}
	try{
		int red[] = { 1, 1, 2, 2, 3, 3, 3 };
		int kolona[] = { 2, 5, 1, 6, 3, 5, 7 };
		int lez[] = { 2, 3, 2, 2, 4, 3, 2 };
		int cena[] = { 40, 40, 30, 30, 20, 20, 20 };
		Plaza<Lezaljka> plaza(brRedova, brKolona);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			plaza.Dodaj(red[i], kolona[i], Lezaljka(lez[i], cena[i]));
		}
		// 1 bod
		cout << plaza << endl; //plaza.Ispisi(cout);
		// 1 bodova
		plaza.Oslobodi(red[3], kolona[3]);
		cout << plaza << endl; //plaza.Ispisi(cout);
		// 2 bod
		float ukupno = plaza.Ukupno();
		cout << ukupno << endl; // 2664
		// 2 bod
		int brLez = 2;
		int brojMesta = plaza.BrojMesta(brLez);
		cout << brojMesta << endl;
		// 2 bod
		int brojLez = 0;
		int redNaj = plaza.RedSaNajvise(brojLez);
		cout << redNaj << " " << brojLez << endl;
		// 0 bod
		char fajl[] = "PlazaVal1.txt";
		plaza.Sacuvaj(fajl);
		// 1 bod
		Plaza<Lezaljka> plazaUcitana;
		plazaUcitana.Ucitaj(fajl);
		cout << plazaUcitana << endl; //novValUc.Ispisi(cout);
	}
	catch (const runtime_error& b) {
		cout << "Greska:" << b.what() << endl;
	}
}

int main()
{
	//zadatak1();
	zadatak2();
	return 0;
}