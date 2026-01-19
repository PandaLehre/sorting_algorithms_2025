# Selection Sort

## Funktionsweise

Die Liste wird durchgegangen und in jedem Durchlauf das kleinste Element im Teil rechts des jetzigen Elements gesucht. Dieses Element wird dann mit dem jetzigen Element getauscht.

## Pseudocode

```
SELECTIONSORT(A, n)
  FOR i FROM 0 TO n - 2 DO
    minIndex = i
    
    // suche das kleinste Element rechts von i
    FOR j FROM i + 1 TO n - 1 DO
      IF A[j] < A[minIndex] THEN
        minIndex = j
      END IF
    END FOR
    
    // tausche das kleinste Element mit i, falls verschieden
    IF minIndex != i THEN
      SWAP(A[i], A[minIndex])
    END IF
    
  END FOR
END SELECTIONSORT
```

## Zeitkomplexität

- $O(n^2)$ bei $n$ Elementen
- jedes Element wird durchgegangen -> n Durchläufe
- bei jedem Durchlauf werden max. $n$ Elemente durchgegange, um das kleinste zu suchen

## Speicherkomplexität

- $O(1)$ - konstant
- es wird je nach Implementierung maximal eine extra Variable zum Tauschen der Elemente benötigt

## Vorteile

- sehr einfach
- in-place, d.h. es wird kein zusätzliches Array benötigt

## Nachteile

- langsam: $O(n^2)$
- instabil, d.h. gleichwertige Elemente können ihre relative Reihenfolge verlieren

## Typische Anwendungsfälle

- Schule
- sehr kleine Datenmengen
- wenn wenig Speicherung zur Verfügung steht oder unnötige Schreibvorgänge vermieden werden sollen

## Quellen

- https://youcademy.org/selection-sort-pros-cons/
- https://studyflix.de/informatik/selectionsort-1323
- https://en.wikipedia.org/wiki/Selection_sort