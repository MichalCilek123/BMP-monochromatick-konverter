# Konverzia BMP na monochromatické 

# Návod na použitie:

1. Spustite program.
2. Napíšte presnú cestu k vstupnému BMP súboru, ktorý chcete prekonvertovať na monochormatický obraz.
3. Následne vpíšte cestu k výstupnému súboru BMP, ktorý už bude monochromatický stlačte klávesu ENTER a čakajte.
4. Ak sa Vám zobrazí veta: "Obrázok sa úspešne prekonvertoval!", tak program môžete zatvoriť a obrázok budete mať čiernobiely.

## Funkcie BMP konvertora
## Program je napísaný v slovenskom jazyku s diakritikou, ktorú zabezpečujú príkazy:
### SetConsoleCP(1250);
### SetConsoleOutputCP(1250);

## 1. Základný princíp programu
Program sparsuje BMP súbor s farebnou hĺbkou 24 alebo 32 bitov a prehodí jeho farby na monochromatické. Na monochromatickú konverziu používa NTSC kódovanie so vzorcom: **0,299 * r + 0,587 * g + 0,114 * b.** Farby berie z rgb schémy v hlavičke bitmapy. 

## 2. Celý proces zabezpečujú 3 funckie, ktoré sa volajú: 
### nacitaj_subor_BMP
### skonvertuj_BMP_na_monochromaticky_obraz
### vytvor_BMP

## 3. nacitaj_subor_BMP()
  Funkcia načita BMP súbor aj s hlavičkou. Zistí či súbor existuje, ak súbor neexistuje, alebo otvorenie zlyhalo, tak ukončí program.

## 4. skonvertuj_BMP_na_monochromaticky_obraz()
  V tejto funckii sa načíta veľkosť obrázka z BMP súboru pomocou for cyklov a prefarbí ho na monochromatickú farebnú schému. 

## 5. vytvor_BMP()
  Funkcia vytvor_BMP vytvorí nový BMP súbor, do ktorého sa budú zapisovať zmenené farby pixelov, ktoré predchádzajúca funkcia prekonvertovala. Prepíše hlavičku zo štruktúry BMP. 
