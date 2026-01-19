# Bogo-Sort

## Definition
**Bogosort** ist ein absichtlich extrem ineffizienter Sortieralgorithmus, der ein Array so lange **zufällig permutiert**, bis es zufällig sortiert ist. Er dient fast ausschließlich Lehr- und Spaßzwecken.

## Funktionsweise
- Prinzip: Generate & Test
- Wiederhole:
  - Array zufällig mischen
  - Prüfen, ob es sortiert ist
- Abbruch, sobald sortiert

## Pseudocode

#### Funktion ist_sortiert(liste)
FUNKTION ist_sortiert(liste)
    FÜR i von 0 bis länge(liste) - 2
    WENN liste[i] > liste[i + 1] DANN
      GIB false zurück
  GIB true zurück

#### Funktion mischen(liste)
FUNKTION mische(liste)
  Liste zufällig neu anordnen
  GIB liste zurück

#### Funktion bogosort(liste)
FUNKTION bogosort(liste)
  SOLANGE ist_sortiert(liste) = false
    liste = mische(liste)
  GIB liste zurück


## Varianten
- **Randomisiert**: Zufälliges Mischen
- **Deterministisch**: Systematisches Durchprobieren aller Permutationen
- Verwandt: **Bozosort**, **Bogobogosort**

## Komplexität
- **Best Case:** O(n)
- **Average Case:** Θ(n · n!)
- **Worst Case:** O(∞)
- **Speicher:** O(1)

## Vor- & Nachteile
**Vorteile**
- Sehr einfach
- Lehrreich (Big-O, Fakultät, Zufall)

**Nachteile**
- Extrem ineffizient
- Keine Terminierung garantiert
- Praktisch unbrauchbar

## Anwendungsfälle
- Keine praktische Nutzung

## Fazit
Bogosort ist ein abschreckendes Beispiel für schlechtes Algorithmusdesign und verdeutlicht, warum effiziente Algorithmen notwendig sind.

## Quellen
- Wikipedia – [Bogosort](<https://en.wikipedia.org/wiki/Bogosort)%5B2>)  
- GeeksforGeeks – [Bogosort](<https://www.geeksforgeeks.org/dsa/bogosort-permutation-sort/)%5B4>)  
- InterviewKickstart – [Bogosort](<https://interviewkickstart.com/blogs/learn/bogo-sort-algorithm)%5B5>)  
- DEV Community – [Bogosort](<https://dev.to/adolfont/bogosort-the-stupid-sorting-algorithm-168f)%5B8>)  
