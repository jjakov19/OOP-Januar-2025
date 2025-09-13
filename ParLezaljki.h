#pragma once
#include<iostream>
using namespace std;
class ParLezaljki
{
protected:
	int rdBr;
	int red;
	int cenaLez;
	int vrPica;
public:
	ParLezaljki();
	ParLezaljki(int rd, int red, int cenaLez, int vrp);
	ParLezaljki(const ParLezaljki& c);
	~ParLezaljki(){}
	friend ostream& operator<<(ostream& os, ParLezaljki& o);
	virtual ostream& Print(ostream& os);
	virtual void Prikazi();
	virtual int vratiRdBr() { return rdBr;}
	virtual int vratiRed() { return red; }
	virtual int vratiCenuLez() { return cenaLez; }
	virtual int vratiVrPica() { return vrPica; }
	virtual int vratiSvotu();
	virtual int vratiBrLez() { return 1; }
};

