## SK
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

## EN

# Conversion of BMP file to monochromatic 

# Instructions for using this program

1. Launch the program.
2. Put the path of your BMP file, which you want to convert to monochromatic picture.
3. Consequently write a path to output BMP file, which will be monochromatic press key ENTER and wait few seconds.
4. If you see a sentence "Obrázok sa úspešne prekonvertoval!" on screen, your new BMP file is converted to monochromatic and you can close the window of executable file.

## Fuctions of BMP convertor
## Program has been written in slovak language with diacritics, which is included with these commands:
### SetConsoleCP(1250);
### SetConsoleOutputCP(1250);

## 1. Main program functionalities
Program can parse BMP file with color depth 24 or 32 bis and convert its colours to monochromatic scheme. Program is using a NTSC coding with mathematical formula: 0.299 * r + 0.587 * g + 0.114 * b to monochromatic conversion. All the colours is included in BMP file header. 
