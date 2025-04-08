# Konverzia BMP na monochromatické 

## Funkcie BMP konvertora

## 1. Program sparsuje BMP súbor a prehodí jeho farby na monochromatické. Na farebnú konverziu používa NTSC kódovanie so vzorcom: **0,299 * r + 0,587 * g + 0,114 * b.**, Farby berie z rgb schémy v bitmape.

## 2. Celý proces zabezpečujú 3 funckie, ktoré sa volajú: 
### nacitaj_subor_BMP
### skonvertuj_BMP_na_monochromaticky_obraz
### vytvor_BMP
