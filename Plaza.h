#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "Lezaljka.h"

template<typename T>
class Plaza {
	T** matrica;
	int trbr;
	int brRedova;
	int brKol;
public:
	Plaza();
	Plaza(int brRed,int brKoll);
	Plaza(const Plaza& p);
	~Plaza();
	void Dodaj(int rd, int kl, T lez);
	void Oslobodi(int rd, int kl);
	friend ostream& operator<<(ostream& os, Plaza<T>& l) {
		l.Print(os);
		return os;
	}
	void Ispisi(ostream& os) {
		for (int i = 0; i < brRedova; i++) {
			for (int j = 0; j < brKol; j++) {
				os << matrica[i][j];
			}
			os << endl;
		}
		return os;
	}
	ostream& Print(ostream& os) {
		for (int i = 0; i < brRedova; i++) {
			for (int j = 0; j < brKol; j++) {
				os << matrica[i][j];
			}
			os << endl;
		}
		return os;
	}
	float Ukupno();
	int BrojMesta(int brlez);
	int RedSaNajvise(int& brlez);
	void Sacuvaj(const char* fajl);
	void Ucitaj(const char* fajl);
};
template <typename T>
Plaza<T>::Plaza() {
	trbr = 0;
	brRedova = 0;
	brKol = 0;
	matrica = nullptr;
}

template <typename T>
Plaza<T>::Plaza(int brRed, int brKoll) {
	trbr = 0;
	brRedova = brRed;
	brKol = brKoll;
	matrica = new T*[brRed];
	for (int i = 0; i < brRedova; i++) {
		matrica[i] = new T[brKol];
	}
	for (int i = 0; i < brRedova; i++) {
		for (int j = 0; j < brKol; j++) {
			matrica[i][j] = T();
		}
	}
}
template <typename T>
Plaza<T>::Plaza(const Plaza& p){
	trbr = p.trbr;
	brRedova = p.brRedova;
	brKol = p.brKol;
	matrica = new T * [brRedova];
	for (int i = 0; i < brRedova; i++) {
		matrica[i] = new T[brKol];
	}
	for (int i = 0; i < brRedova; i++) {
		for (int j = 0; j < brKol; j++) {
			matrica[i][j] = p.matrica[i][j];
		}
	}
}
template <typename T>
Plaza<T>::~Plaza() {
	for (int i = 0; i < brRedova; i++) {
		delete[] matrica[i];
	}
	delete[]matrica;
}
template <typename T>
void Plaza<T>::Dodaj(int rd, int kl, T lez) {
	if (rd > brRedova || kl > brKol || rd<0|| kl<0 ) {
		throw runtime_error("Uneli ste nepostojecu poziciju!");
		return;
	}
	matrica[rd-1][kl-1] = lez;
}
template <typename T>
void Plaza<T>::Oslobodi(int rd, int kl) {
	if (rd > brRedova || kl > brKol || rd < 0 || kl < 0) {
		throw runtime_error("Uneli ste nepostojecu poziciju!");
		return;
	}
	matrica[rd-1][kl-1] = T();
}

template <typename T>
float Plaza<T>::Ukupno() {
	float uk = 0;
	for (int i = 0; i < brRedova; i++) {
		for (int j = 0; j < brKol; j++) {
			uk += matrica[i][j];
		}
	}
	return uk;
}
template <>
float Plaza<Lezaljka>::Ukupno() {
	float uk = 0;
	for (int i = 0; i < brRedova; i++) {
		for (int j = 0; j < brKol; j++) {
			uk += matrica[i][j].getBrIzn();
		}
	}
	return uk;
}
template <typename T>
int Plaza<T>::BrojMesta(int brlez) {
	int uk = 0;
	for (int i = 0; i < brRedova; i++) {
		for (int j = 0; j < brKol; j++) {
			if(matrica[i][j]==brlez)
			uk++;
		}
	}
	return uk;
}
template <>
int Plaza<Lezaljka>::BrojMesta(int brlez) {
	int uk = 0;
	for (int i = 0; i < brRedova; i++) {
		for (int j = 0; j < brKol; j++) {
			if (matrica[i][j].getBrIzn() == brlez)
				uk ++;
		}
	}
	return uk;
}
template <typename T>
int Plaza<T>::RedSaNajvise(int& brlez) {
	int maxRed = 0;
	int maxRedSuma =0;
	int trRedSuma = 0;
	for (int i = 0; i < brRedova; i++) {
		for (int j = 0; j < brKol; j++) {
			trRedSuma += matrica[i][j];
		}
		if (trRedSuma > maxRedSuma) {
			maxRedSuma = trRedSuma;
			maxRed = i;
		}
		trRedSuma = 0;
	}
	for (int i = 0; i < brKol; i++) {
		brlez += matrica[maxRed][i];
	}
	return maxRed;
}
template <>
int Plaza<Lezaljka>::RedSaNajvise(int& brlez) {
	int maxRed = 0;
	int maxRedSuma = 0;
	int trRedSuma = 0;
	for (int i = 0; i < brRedova; i++) {
		for (int j = 0; j < brKol; j++) {
			trRedSuma += matrica[i][j].getBrIzn();
		}
		if (trRedSuma > maxRedSuma) {
			maxRedSuma = trRedSuma;
			maxRed = i;
		}
		trRedSuma = 0;
	}
	for (int i = 0; i < brKol; i++) {
		brlez += matrica[maxRed][i].getBrIzn();
	}
	return maxRed;
}
template <typename T>
void Plaza<T>::Sacuvaj(const char* fajl) {
	ofstream file(fajl);
	if (!file.is_open()) {
		throw runtime_error("Lose ucitan file!");
		return;
	}
	file << brRedova << endl;
	file << brKol << endl;
	for (int i = 0; i < brRedova; i++) {
		for (int j = 0; j < brKol; j++) {
			file << matrica[i][j] << " ";
		}
		file << endl;
	}
	file.close();
}

template <typename T>
void Plaza<T>::Ucitaj(const char* fajl) {
	ifstream file(fajl);
	if (!file.is_open()) {
		throw runtime_error("Lose ucitan file!");
	}

	int red = 0, kol = 0;
	file >> red >> kol;
	if (!file) {
		throw runtime_error("Greska pri citanju dimenzija iz fajla");
	}

	// Oslobodi staru matricu ako postoji
	if (matrica != nullptr) {
		for (int i = 0; i < brRedova; ++i) delete[] matrica[i];
		delete[] matrica;
		matrica = nullptr;
	}

	// Postavimo clanove klase
	brRedova = red;
	brKol = kol;
	trbr = 0; // mozemo kasnije izracunati ako zelimo

	// Alokacija nove matrice
	matrica = new T * [brRedova];
	for (int i = 0; i < brRedova; ++i) {
		matrica[i] = new T[brKol];
		for (int j = 0; j < brKol; ++j) {
			if (!(file >> matrica[i][j])) {
				// cleanup u slucaju greske
				for (int k = 0; k <= i; ++k) delete[] matrica[k];
				delete[] matrica;
				matrica = nullptr;
				throw runtime_error("Greska pri citanju sadrzaja fajla");
			}
		}
	}

	file.close();
}
