# Gnome-Sort

## Funktionsweise

Gnome Sort läuft wie folgt:

1. Starte am Anfang des Arrays.
2. Vergleiche das aktuelle Element mit seinem Vorgänger.
3. Wenn die Reihenfolge korrekt ist (`a[i] >= a[i-1]`), gehe einen Schritt weiter.
4. Wenn die Reihenfolge falsch ist, tausche die beiden Elemente und gehe einen Schritt zurück.
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
## Beispiel-Durchlauf (Worst Case)

Komplett verkehrt sortierte Liste: `[ 3, 2, 1 ]`

**Start:** `[ 3, 2, 1 ]`, Zeiger (`pos`) steht bei Index 1 (Wert `2`).

1. **Vergleich 2 & 3:**
   + `2` ist kleiner als `3` (falsche Ordnung).
   + Tausch: Liste ist jetzt `[ 2, 3, 1 ]`.
   + Schritt zurück: Zeiger geht auf Index 0.

2. **Sonderfall Index 0:**
   + Der Zeiger steht ganz am Anfang.
   + Schritt vor: Zeiger geht wieder auf Index 1.

3. **Vergleich 3 & 2:**
   + `3` ist größer als `2` (richtige Ordnung).
   + Schritt vor: Zeiger geht auf Index 2 (Wert `1`).

4. **Vergleich 1 & 3:**
   + `1` ist kleiner als `3` (falsche Ordnung).
   + Tausch: Liste ist jetzt `[ 2, 1, 3 ]`.
   + Schritt zurück: Zeiger geht auf Index 1 (Wert `1`).

5. **Vergleich 1 & 2:**
   + Hier greift das Prinzip des Zurücklaufens: Die `1` wird erneut gegen ihren neuen Nachbarn geprüft.
   + `1` ist kleiner als `2` (falsche Ordnung).
   + Tausch: Liste ist jetzt `[ 1, 2, 3 ]`.
   + Schritt zurück: Zeiger geht auf Index 0.

6. **Abschluss:**
   + Liste ist sortiert. Der Zeiger läuft nun ohne weitere Tausche bis zum Ende durch.

**Ergebnis:** Um die kleine Liste zu sortieren, musste der Zeiger mehrfach den Weg zurück antreten. Bei großen Listen wächst dieser Aufwand quadratisch.

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

## Vergleich mit anderen Algorithmen

+ **Gnome Sort vs. Bubble Sort:**
  - Beide nutzen Nachbartausche.
  - Gnome Sort nutzt nur eine Schleife (Zick-Zack-Bewegung).
  - Bubble Sort läuft immer stur in eine Richtung.

+ **Gnome Sort vs. Insertion Sort:**
  - Konzeptionell sehr ähnlich (Einfügen an der richtigen Stelle).
  - Insertion Sort "schiebt" das Element direkt an den Platz.
  - Gnome Sort "tauscht" sich mühsam Schritt für Schritt dorthin.

+ **Gnome Sort vs. Quick/Merge Sort:**
  - Gnome Sort ist deutlich langsamer bei großen Daten (O(n²) vs. O(n log n)).
  - Vorteil Gnome Sort: Er ist stabil und benötigt keinen extra Speicher (O(1)).

**Fazit:** Gnome Sort ist der einfachste, aber oft ineffizienteste der "einfachen" Sortierer.

## Quellen

+ GeeksforGeeks: https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/
+ Rosetta Code: https://rosettacode.org/wiki/Gnome_sort