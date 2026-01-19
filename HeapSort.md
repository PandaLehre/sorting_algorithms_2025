# Heapsort

Heapsort ist ein **vergleichsbasiertes Sortierverfahren**, das einen **Heap** (meist: *Max-Heap*) nutzt, um ein Array **in-place** zu sortieren. Die Grundidee:  
1) Baue aus dem unsortierten Array einen Heap.  
2) Wiederhole: Tausche das größte Element (Wurzel) ans Ende und stelle die Heap-Eigenschaft im verkleinerten Heap wieder her.

---

## Funktionsweise

### 1) Heap-Grundlagen (Max-Heap)
Ein **Max-Heap** ist ein binärer Baum (oft als Array gespeichert), bei dem gilt:
- Jeder Knoten ist **größer oder gleich** seinen Kindern.
- Das **Maximum** steht immer an der **Wurzel**.

### 2) Array-Repräsentation des Heaps
Für ein Array `A` mit **0-basiertem Index**:
- `left(i)  = 2*i + 1`
- `right(i) = 2*i + 2`
- `parent(i)= (i - 1) // 2`

So kann man ohne Pointer einen vollständigen Binärbaum im Array abbilden.

### 3) Heapsort-Ablauf (Max-Heap → aufsteigend sortiert)
- **Heap bauen**: Stelle sicher, dass das gesamte Array eine Max-Heap-Struktur erfüllt.
- **Sortierphase**:
  - Tausche `A[0]` (Maximum) mit `A[end]`.
  - Reduziere die Heap-Größe um 1 (`end--`).
  - Stelle mit **sift-down / heapify** die Max-Heap-Eigenschaft an der Wurzel wieder her.

Am Ende ist das Array **aufsteigend** sortiert.

---

## Pseudocode

### Hilfsfunktion: `siftDown` (Heapify nach unten)
`A` ist das Array, `i` der Startindex, `heapSize` die aktuelle Heap-Größe (exklusive).

```text
procedure siftDown(A, i, heapSize):
    while true:
        left  = 2*i + 1
        right = 2*i + 2
        largest = i

        if left < heapSize and A[left] > A[largest]:
            largest = left
        if right < heapSize and A[right] > A[largest]:
            largest = right

        if largest == i:
            break

        swap A[i], A[largest]
```

### Heap aufbauen: `buildMaxHeap`
```text
procedure buildMaxHeap(A):
    n = length(A)
    for i = (n//2 - 1) down to 0:
        siftDown(A, i, n)
```

**Warum startet man bei `n//2 - 1`?**  
Alle Indizes `i >= n//2` sind Blätter (haben keine Kinder) und erfüllen trivially die Heap-Eigenschaft.

### Heapsort
```text
procedure heapSort(A):
    n = length(A)
    buildMaxHeap(A)

    for end = n-1 down to 1:
        swap A[0], A[end]      // Maximum ans Ende
        siftDown(A, 0, end)    // Heapgröße ist jetzt end
```

---

## Zeitliche Komplexität

### Worst-Case: **O(n log n)**
- Es gibt `n` Extraktionen (Swap Wurzel ↔ Ende).
- Jede Wiederherstellung (`siftDown`) kostet **O(log n)**.
- → `n * log n`

### Average-Case: **O(n log n)**
Heapsort hängt (wie viele vergleichsbasierte Sorts) nicht stark von der Eingabeordnung ab.

### Best-Case: **O(n log n)**
Auch wenn das Array “fast sortiert” ist, läuft die Extraktionsphase weiter mit `n` Heapify-Operationen.

### Heap bauen: **O(n)** (wichtig!)
Das Aufbauen des Heaps via “bottom-up heapify” kostet **O(n)**, nicht `O(n log n)`.  
Intuition: Viele Knoten sind nahe an den Blättern und benötigen nur sehr wenige `siftDown`-Schritte.

**Gesamt:** `O(n) + O(n log n) = O(n log n)`

---

## Speicherkomplexität

- **O(1) Zusatzspeicher** (in-place), wenn man iteratives `siftDown` verwendet.
- Rekursive Heapify-Varianten benötigen wegen Call-Stack typischerweise **O(log n)**.

---

## Eigenschaften (Stabilität, In-Place, etc.)

- **In-place:** ✅ ja (typisch)
- **Stabil:** ❌ nein  
  Gleiche Elemente können ihre Reihenfolge verändern, weil beim Heapify und Swappen weit entfernte Elemente vertauscht werden.
- **Vergleichsbasiert:** ✅ ja  
  Untere Schranke: Vergleichsbasiertes Sortieren ist im Worst-Case nicht besser als `Ω(n log n)`.

---

## Vorteile

- **Garantiert O(n log n)** im Worst-Case (im Gegensatz zu einfachem Quicksort ohne Schutzmaßnahmen).
- **In-place** mit konstantem Zusatzspeicher.
- Keine zusätzlichen Datenstrukturen nötig (nur Array und Indexarithmetik).
- Gute Wahl, wenn **Speicher knapp** ist und Worst-Case wichtig ist.

---

## Nachteile

- **Nicht stabil**, falls Stabilität gefordert ist.
- In der Praxis oft **langsamer** als gut implementierter Quicksort/Introsort, weil:
  - schlechtere Cache-Lokalität (Heap-Sprünge im Array),
  - mehr Vergleiche/Swaps als optimierte Sortierverfahren in Standardbibliotheken.
- Best-Case nicht besser als `O(n log n)`.

---

## Typische Anwendungsfälle

- **Speicherlimitierte Umgebungen**, wo `O(1)` Zusatzspeicher wichtig ist.
- Wenn du **Worst-Case-Garantien** brauchst (z. B. in bestimmten Echtzeitsystemen oder sicherheitskritischen Pfaden).
- Als Baustein/Ideengeber für **Priority Queues** (Heap als Datenstruktur ist dort zentral).
- In Lehrkontexten: sehr gutes Beispiel für “Sortieren über eine Datenstruktur”.

**Wann eher nicht?**
- Wenn du **Stabilität** brauchst → z. B. Mergesort / stabile Varianten.
- Wenn Performance auf modernen CPUs maximal sein soll → meist Introsort / Timsort (je nach Umgebung) besser.

---

## Kurzes Beispiel (Intuition)
Array: `[4, 10, 3, 5, 1]`

1) Build Max-Heap → z. B. `[10, 5, 3, 4, 1]`  
2) Swap Wurzel mit Ende → `[1, 5, 3, 4, 10]`, heapify bis Ende-1  
3) Wiederholen → Maximum wandert schrittweise nach hinten, bis alles sortiert ist.

---

## Quellen

- Wikipedia: **Heapsort** und **Binary heap** (für Übersicht, Eigenschaften und Indexformeln).
- https://www.geeksforgeeks.org/dsa/heap-sort/
