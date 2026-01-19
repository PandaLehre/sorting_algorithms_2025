
Bubblesort Funktionsweise: 

    Einfacher Sortieralgorithmus 
    Sortiert eine Liste durch Vergleich benachbarter Elemente 
    Zwei Elemente werden vertauscht, wenn das Vordere größer als das Hintere ist
    Größtes Element „wandert“ pro Durchlauf ans Ende der Liste 
    Mehrere Durchläufe nötig, bis die Liste vollständig sortiert ist 
 
https://www.youtube.com/watch?v=Iv3vgjM8Pv4


Pseudocode:
      bubbleSort(Array A)
    for (n = A.size; n > 1; n = n - 1)      // äußere Schleife
     {                                            
      for (i = 0; i < n - 1; i = i + 1)     // innere Schleife
      {                                            
        if (A[i] > A[i + 1]) 
        {
          A.swap(i, i + 1)
        }
      } 
    }

Zeitliche/Speicher Komplexität:
    Laufzeit: O(n²)

    Platzkomplexität: O(1)                      // wird kein extra Speicher benötigt

Vor und Nachteile:
Vor: 
    Sehr einfache Implementation
    Kein Zusatsspeicher benötigt
    Bei schon sortierten Listen nahezu keine Laufzeit O(n)
Nachteile:
    Sehr langsam bei großen Datenmengen
    Viel Schreib und Tauschvorgänge
    Ineffizienter als moderne Methoden

Typische Anwendungsfälle: 
    Visiualisierung: Die "Aufblasen Mechanik"
    Verständnis von Algorithmen

Quellen:
    https://de.wikipedia.org/wiki/Bubblesort 

    https://www.happycoders.eu/de/algorithmen/bubble-sort/

    https://www.klinger.nrw/wp-content/uploads/2021/01/211_Bubblesort.pdf
    
    https://www.studysmarter.de/schule/informatik/theoretische-informatik/platzkomplexitaet/