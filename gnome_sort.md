
# Gnome-Sort

## Funktionsweise

Gnome Sort läuft wie folgt:

1. Starte am Anfang des Arrays.
2. Vergleiche das aktuelle Element mit seinem Vorgänger.
3. Wenn die Reihenfolge korrekt ist (`a[i] >= a[i-1]`), gehe einen Schritt weiter.
4. Wenn die Reihenfolge falsch ist, **tausche** die beiden Elemente und gehe **einen Schritt zurück**.
5. Wiederhole dies, bis der Zeiger das Ende des Arrays erreicht.

Das Verhalten ähnelt einem „Gnom“, der durch den Garten läuft und jedes falsch platzierte Blümchen (Element) zurücksetzt, bis alles an der richtigen Stelle steht.

## Pseudocode

```text
prozedur gnomeSort(A[]):
    pos := 0
    während pos < länge(A):
        wenn (pos == 0 oder A[pos] >= A[pos-1]):
            pos := pos + 1
        sonst:
            tausche A[pos] und A[pos-1]
            pos := pos - 1
```

## Zeitliche & Speicher-Komplexität

+ Durchschnitt: O(n²)
+ Schlechtester Fall: O(n²)
+ Bester Fall: O(n) (wenn die Liste bereits nahezu sortiert ist)

+ Zusätzlicher Speicher: O(1) – arbeitet vollständig in-place.
+ Stabilität: Gnome Sort ist stabil, da Elemente nur mit ihren direkten Vorgängern getauscht werden.

## Vorteile

+ Sehr einfache Implementierung
+ Stabiler Sortieralgorithmus
+ Gut lesbar und verständlich
+ In-place (benötigt keinen Zusatzspeicher)


## Nachteile

+ Sehr langsam für große oder unsortierte Listen (O(n²))
+ Praktisch nie die beste Wahl im Vergleich zu Quick Sort, Merge Sort oder 
Timsort
+ Viele lokale Vergleiche und Rückwärtsbewegungen → ineffizient


## Typische Anwendungsfälle

+ Lehrzwecke (Einführung in einfache Sortieralgorithmen)
+ Kleine Datenmengen
+ Sonst eigentlich nutzlos

## Quellen

+ Wikipedia: https://en.wikipedia.org/wiki/Gnome_sort
+ GeeksforGeeks: https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/
+ Rosetta Code: https://rosettacode.org/wiki/Gnome_sort