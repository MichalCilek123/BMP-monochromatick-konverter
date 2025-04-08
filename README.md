# Konverzia BMP na monochromatické 

## Funkcie BMP konvertora

## 1. Základný princíp programu
Program sparsuje BMP súbor s farebnou hĺbkou 24 alebo 32 bitov a prehodí jeho farby na monochromatické. Na monochromatickú konverziu používa NTSC kódovanie so vzorcom: **0,299 * r + 0,587 * g + 0,114 * b.**, Farby berie z rgb schémy v bitmape. 

## 2. Celý proces zabezpečujú 3 funckie, ktoré sa volajú: 
### nacitaj_subor_BMP
### skonvertuj_BMP_na_monochromaticky_obraz
### vytvor_BMP

## 3. nacitaj_subor_BMP()
  Funkcia načita BMP súbor aj s hlavičkou. Zistí či súbor existuje, ak súbor neexistuje, alebo otvorenie zlyhalo, tak sa ukončí program.

## 4. skonvertuj_BMP_na_monochromaticky_obraz()
  V tejto funckii sa načíta veľkosť obrázka z BMP súboru pomocou for cyklov a prefarbí ho na monochromatické farby. 

## 5. vytvor_BMP()
  
