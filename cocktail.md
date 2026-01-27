
# Cocktail Sort (Bidirectional Bubble Sort)

## Funktionsweise
Cocktail Sort ist eine bidirektionale Variante von Bubble Sort. Der Algorithmus durchläuft die Liste abwechselnd von links nach rechts und anschließend von rechts nach links. Dadurch wandern große Elemente schneller nach rechts und kleine Elemente schneller nach links. Der Vorgang wiederholt sich, bis kein Tausch mehr stattgefunden hat.

## Pseudocode
```text
procedure cocktail_sort(A):
    n ← length(A)
    start ← 0
    end ← n - 1
    swapped ← true

    while swapped is true:
        swapped ← false

        # Vorwärtsdurchlauf
        for i from start to end - 1:
            if A[i] > A[i + 1]:
                swap A[i], A[i + 1]
                swapped ← true

        if swapped is false:
            break

        swapped ← false
        end ← end - 1

        # Rückwärtsdurchlauf
        for i from end - 1 down to start:
            if A[i] > A[i + 1]:
                swap A[i], A[i + 1]
                swapped ← true

        start ← start + 1
```

## Zeitliche & Speicherkomplexität
- **Best Case:** O(n)
- **Average Case:** O(n²)
- **Worst Case:** O(n²)
- **Speicherbedarf:** O(1)
- **Stabilität:** Stabil

## Vor- & Nachteile
### Vorteile
- Einfach zu implementieren.
- Adaptiv: Stoppt früh bei nahezu sortierten Listen.
- Stabil und in-place.

### Nachteile
- Quadratische Laufzeit.
- Für große Datenmengen ungeeignet.

## Typische Anwendungsfälle
- Kleine Eingabemengen.
- Lehrzwecke zur Demonstration von Sortierprinzipien.
- Nahezu sortierte Listen.

## Quellen
- Wikipedia: Cocktail shaker sort — https://en.wikipedia.org/wiki/Cocktail_shaker_sort

