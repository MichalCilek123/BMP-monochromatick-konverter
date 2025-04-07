#include <vector>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

#pragma pack(push, 1)

struct BMP_Hlavicka
{
	uint16_t typ_suboru;
	uint32_t velkost;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t offset;
};

struct Hlavicka_info_BMP
{
	uint32_t velkost;
	uint32_t sirka;
	uint32_t vyska;
	uint16_t polia;
	uint16_t bit_sucet;
	uint32_t kompresia;
	uint32_t velkost_obrazka;
	uint32_t x_pixely_na_meter;
	uint32_t y_pixely_na_meter;
	uint32_t pouzite_farby;
	uint32_t dolezite_farby;
};

struct BMP_Hlavicka_farieb
{
	uint32_t r;
	uint32_t g;
	uint32_t b;
	uint32_t alpha;
	uint32_t typy_farieb;
	uint32_t nepouzite[16];
};

#pragma pack(pop)

struct BMP
{
	BMP_Hlavicka hlavicka;
	Hlavicka_info_BMP info_hlavicka;
	BMP_Hlavicka_farieb hlavicka_farieb;
	vector<uint8_t> udaje;
};

BMP nacitaj_subor_BMP(const string& cesta)
{
	BMP bmp;
		ifstream fin(cesta, ios::binary);
	if(!fin)
	{
		cerr << "Cesta k súboru: " << cesta << " neexistuje!" << endl;
		exit(EXIT_FAILURE);
	}
	fin.read(reinterpret_cast<char*>(&bmp.hlavicka), sizeof(bmp.hlavicka));
	fin.read(reinterpret_cast<char*>(&bmp.info_hlavicka), sizeof(bmp.info_hlavicka));
	
	if(bmp.info_hlavicka.bit_sucet == 32)
	{
		fin.read(reinterpret_cast<char*>(&bmp.hlavicka_farieb), sizeof(bmp.hlavicka_farieb));
	}
	
	fin.seekg(bmp.hlavicka.offset, fin.beg);
	bmp.udaje.resize(bmp.info_hlavicka.velkost_obrazka == 0 ? bmp.hlavicka.velkost - bmp.hlavicka.offset : bmp.info_hlavicka.velkost_obrazka);
	fin.read(reinterpret_cast<char*>(bmp.udaje.data()), bmp.udaje.size());
	
	return bmp;
}

void vytvor_BMP(const BMP& bmp, const string& ulozenie)
{
	ofstream fout(ulozenie, ios::binary);

	if(!fout)
	{
			cerr << "Súbor sa nepodarilo uloži!" << endl;
			exit(EXIT_FAILURE);	
	}
	
	fout.write(reinterpret_cast<const char*>(&bmp.hlavicka), sizeof(bmp.hlavicka));
	fout.write(reinterpret_cast<const char*>(&bmp.info_hlavicka), sizeof(bmp.info_hlavicka));
	
	
	if(bmp.info_hlavicka.bit_sucet == 32 || bmp.info_hlavicka.bit_sucet == 24 )
	{
		fout.write(reinterpret_cast<const char*>(&bmp.hlavicka_farieb), sizeof(bmp.hlavicka_farieb));
	}
	fout.write(reinterpret_cast<const char*>(bmp.udaje.data()), bmp.udaje.size());
}

void skonvertuj_BMP_na_monochromaticky_obraz(BMP& bmp)
{
	int sirka = bmp.info_hlavicka.sirka, vyska = bmp.info_hlavicka.vyska, sirka_riadka = (sirka * bmp.info_hlavicka.bit_sucet / 8 + 3) & ~3;
	
	for(int i = 0; i < vyska; i++)
	{
		for(int j = 0; j < sirka; j++)
		{
			int index = i * sirka_riadka + j * (bmp.info_hlavicka.bit_sucet / 8);
			
			uint8_t cervena = bmp.udaje[index + 2];
			uint8_t zelena = bmp.udaje[index + 1];
			uint8_t modra = bmp.udaje[index];
			uint8_t seda = static_cast<uint8_t>(0.299 * cervena + 0.587 * zelena + 0.114 * modra);
			
			bmp.udaje[index] = seda;
			bmp.udaje[index + 1] = seda;
			bmp.udaje[index + 2] = seda;
			if(bmp.info_hlavicka.bit_sucet == 32 || bmp.info_hlavicka.bit_sucet == 24)
			{
				bmp.udaje[index + 3] = 255;
			}
		}
	}
}

int main()
{
	SetConsoleCP(1250);
	SetConsoleOutputCP(1250);

	cout << "Informácie:" << endl;
	cout << "Program dokáže konvertova bmp súbory, ktoré maju bitovú håbku 24 alebo 32 bitov." << endl;
	cout << "Postupujte pod¾a nižšie uvedených pokynov." << endl << endl;
	
	cout << "Napíšte sem prosím cestu k BMP súboru, ktorý chcete pretransformova na èiernobielo: ";

	
	string cesta, ulozenie;
	cin >> cesta;
	BMP bmp = nacitaj_subor_BMP(cesta);
	
	cout << "Napíšte prosím cestu kam chcete súbor uloži: ";
	cin >> ulozenie;
	skonvertuj_BMP_na_monochromaticky_obraz(bmp);
	vytvor_BMP(bmp, ulozenie);
	
		
	cout << "Obrázok sa úspešne prekonvertoval!" << endl;

	system("pause");

	return 0;
}
