#pragma once
#include <iostream>
using namespace std;
#include "ParLezaljki.h"
class ParLezaljkiSaDodatkom:public ParLezaljki
{
private:
	int brojDodatnih;
public:
	ParLezaljkiSaDodatkom();
	ParLezaljkiSaDodatkom(int rd, int red, int cenaLez, int vrp, int brojD);
	ParLezaljkiSaDodatkom(const ParLezaljkiSaDodatkom& c);
	~ParLezaljkiSaDodatkom() {}
	ostream& Print(ostream& os)override;
	void Prikazi()override;
	int vratiSvotu()override;
	int vratiBrLez()override { return brojDodatnih+1; }
};

