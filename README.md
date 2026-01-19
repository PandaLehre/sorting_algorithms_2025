# Sorting Algorithm Project

Aufgabenstellung auf deutsch. Ihre Dokumentation wahlweise auf deutsch oder englisch verfassen. Kommentare im Code bitte immer auf englisch schreiben.

## Projektbeschreibung

Diese Projektaufgabe ist als Gruppenarbeit angelegt und gliedert sich in drei Phasen: Recherche & Theorie, gemeinsames Design (Schnittstelle & Testkatalog) und Implementierung.

1. Teamaufteilung:
   - Pro Sortieralgorithmus wird ein Team gebildet (z. B. Bubble, Quick, Merge, Insertion, Heap, ...).
   - Gruppengröße: 2–4 Personen.

2. Phase A — Recherche & Theorie (je Team):
   - Erstellt eine Dokumentation `<algorithm>.md` mit: Funktionsweise, Pseudocode, zeitliche/speicherkomplexität, Vor-/Nachteile, typische Anwendungsfälle und **Quellen**.
   - Bereitet eine kurze Präsentation vor, in der das Team die wichtigsten Erkenntnisse vorträgt

3. Phase B — Gemeinsame Schnittstelle & Testkatalog (alle Teams):
   - Nach den Präsentationen entwerfen alle gemeinsam die Testfälle und den Projektaufbau.
   - Haltet das Ergebnis in `test_catalog.md` fest (Eingabeformat, Optionen, erwartete Ausgabe, Randfälle, Benchmarkspezifikationen).
   - Beispiel für eine einfache CLI-Konvention, die alle Implementierungen unterstützen sollten:

      - `./main <algorithm> -i <inputfile> -n <count> -o <asc|desc>`
      - Alternativ: `./main --algo bubble --input data.txt --order asc`

4. Phase C — Testimplementierung & Algorithmus-Implementierung:
   - Implementiert die Tests in z. B. `tests/input_small.txt`, `tests/input_medium.txt`, `tests/input_large.txt` oder automatisierte C-Testprogramme.
   - Jedes Team implementiert den Algorithmus gemäß gemeinsamer Schnittstelle (Dateinamen-Vorschlag: `sort_<name>.c`).
   - Führt die Tests aus, messt Laufzeit und Speicherverbrauch und dokumentiert die Ergebnisse.

   **Ziel: Gemeinsamer, reproduzierbarer Testkatalog und vergleichbare Implementierungen, die Korrektheit, Laufzeit und Speicherverhalten offenlegen.**

## Möglicher Aufbau des Projektverzeichnisses

Bitte legen Sie sich einen eigenen Workspace (Projektordner) an und öffnen Sie diesen in VS Code.

Der folgende Verzeichnisbaum zeigt einen möglichen Aufbau des Projekts:

```graph
project-root/
|
├── .vscode/           # VS Code configuration files
|
├── build/             # Compiled files and temporary files (C/C++ Runner)
│   ├── Debug/
│   └── Release/
|
├── tests/             # Test cases
│   ├── small_input.txt
│   ├── large_input.txt
│   └── ...
|
├── .gitignore         # Files and directories to be ignored by git
├── main.c             # Main source file
├── README.md          # Project overview and general information
├── sort1_bubble.c     # Bubble Sort implementation
├── sort2_quick.c      # Quick Sort implementation
├── sort3_merge.c      # Merge Sort implementation
├── ...
├── sorting.h          # Sorting algorithm declaration header file
├──  utils.c           # Utility functions
├──  utils.h           # Utility function declarations
└──
```
