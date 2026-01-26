# Quick Sort

## Funktionsweise
Er funktioniert, indem das Array in kleinere Teilbereiche aufgeteilt wird: Es wird ein  Pivot-Element gewählt, das als Referenz für die Aufteilung dient. Alle Elemente, die kleiner oder gleich dem Pivot sind, werden links eingeordnet, und alle größeren rechts. Die beiden Teilbereiche werden danach rekursiv wieder auf die gleiche Weise sortiert.

## Pseudocode

```
funktion Quicksort (A, links, rechts)
    if links == rechts
        gebe Element bei links zurück
    Wenn links < rechts
        i := links
        j := rechts - 1
        P := rechts

        Solange i < j
            Solange A[i] <= A[p] && i < j
                i := i + l
            Solange A[j] > A[p] && i < j
                j := j- 1
            vertausche A[i] und A[j]
        
        Wenn A[p] < A[i]
            vertausche A[p] und A[i]
            p := i
        sonst
            vertausche A[p] und A[i+1]
            p = i+1

        Quicksort (A, links, p-1)
        Quicksort (A, p+1, rechts)
```

## Zeitkomplexität

- Best Case: $O(n log n)$
- Average Case: $O(n log n)$
- Worst Case: $O(n²)$

## Speicherkomplexität

- Best Case: $O(log n)$
- Worst Case: $O(n)$

## Vorteile
- ⁠Sehr schnell im Durchschnitt
- Benötigt wenig zusätzlichen Speicher (in-place).
- Sehr gut für große Datenmengen geeignet.
- ⁠Teile-und-herrsche-Prinzip ermöglicht effiziente Rekursion.

## Nachteile

- ⁠Worst-Case Laufzeit O(n^2), wenn schlechte Pivot-Wahl (z. B. bereits sortierte Arrays).
- ⁠Nicht stabil (relative Reihenfolge gleicher Elemente bleibt nicht erhalten).
- Rekursion kann bei sehr großen Arrays zu Stack-Overflow führen, wenn nicht optimiert.

## Typische Anwendungsfälle

- Sortieren großer Datenmengen in der Praxis (z. B. in Datenbanken, Bibliotheken).
- Als Standard-Sortieralgorithmus in vielen Programmiersprachen (z. B. Varianten in C, Python vor Timsort).
- ⁠Geeignet für Situationen, in denen Speicher knapp ist (in-place).
- Gut für zufällige bzw. unsortierte Eingabedaten.

## Quellen

- https://algorithmen-lernen.de/quicksort/
- https://studyflix.de/informatik/quicksort-1322
