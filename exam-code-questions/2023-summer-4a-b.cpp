//Code snippet with comments taken straight from the exam paper
//Code might be in Norwegian to reflect the exam paper

/**
* Oppgave 4a - Lag den ikke-rekursive funksjonen "char forsteSingleBokstav(const char tekst[], const int n)"
* Som finner og returnerer den første bokstaven i tekst som forekommer bare en gang.
* n er antall tegn i teksten.
*
* I oppgave 4a er det ikke lov til å bruke noen hjelpestrukturer -
* som f.eks. array, stakk, kø eller liste. Funksjonen blir derfor sikkert av O ( n^2 ).
*
* tekst inneholder kun bokstavene A-Z (kun store bokstaver, og ingen blanke/space).
* Finnes det ingen bokstav som forekommer bare en gang, returneres ‘ ‘ (blank/space).
*/

char forsteSingleBokstav(const char tekst[], const int n) {
    for (int i = 0; i < n; ++i) {
        bool finnesFlereGanger = false;
        for (int j = 0; j < n; ++j) {
            if (i != j && tekst[i] == tekst[j]) {
                finnesFlereGanger = true;
                break; // Vi har funnet en duplikat, så vi kan bryte ut av den indre løkken
            }
        }
        if (!finnesFlereGanger) {
            return tekst[i]; // Returner den første bokstaven som kun forekommer én gang
        }
    }
    return ' '; // Hvis ingen bokstav forekommer bare en gang, returner blank
}

/**
 * Oppave 4b - Gjør oppgave 4a men nå med en hjelpestruktur.
 */
char medHjelpestruktur(const char tekst[], const int n) {
    int count[26] = {0}; // Array for å telle forekomster av hver bokstav (A-Z)
    // Tell forekomster av hver bokstav
    for (int i = 0; i < n; ++i) {
        count[tekst[i] - 'A']++;
    }

    // Finn den første bokstaven som kun forekommer én gang
    for (int i = 0; i < n; ++i) {
        if (count[tekst[i] - 'A'] == 1) {
            return tekst[i]; // Returner den første bokstaven som kun forekommer én gang
        }
    }

    return ' '; // Hvis ingen bokstav forekommer bare en gang, returner blank
}

