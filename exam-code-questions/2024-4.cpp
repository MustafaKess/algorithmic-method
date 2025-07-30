//Text, code and comments might be in norwegian due to being taken from the exam paper
/*
Oppgave 4
Vi har en lang tekst som inneholder  N  tegn (alle slags tegn på tastaturet, ikke bare bokstaver og sifre).
Disse ligger i:  char txt[N]. Det er maksimum tre stykk av samme tegn i arrayen.

Skriv et komplett program som skriver ut tegnene det er eksakt tre like av og hvor mange det dreier seg om.
F.eks. for teksten:   hgfhnk!mBSgmiGtytAr4n8765!TASn68m5BrsseBgrT!GybbGtb798uyu76
ville den ha kunnet skrevet ut noe slikt som:            ! 6 7 8 B G b g m n r t y

Antall tegn det er tre like av: 13

Er det aktuelt å bruke noen kodesnutter fra pensum, så er det bare å henvise til dette.
NB:  Det er ikke meningen at du her trenger å innføre noen hjelpe-array eller andre datastrukturer.
*/
#include <cstring>
#include <iostream>   // For cout
using namespace std;

const int N = 100;     // Define N with a fixed size
char txt[N];           // Character array
int n = N;             // Length of the array (or number of valid elements in txt)

// Main function (spelled correctly)
int main() {
  // Example input to test
  strcpy(txt, "aabacada");  // You can modify this as needed
  n = strlen(txt);          // Update n to reflect the actual content length

  for (int i = 0; i < n; i++) {
    int antallForekomster = 1;  // Start at 1 because current i is one occurrence

    for (int j = 0; j < n; j++) {
      if (i != j && txt[i] == txt[j]) {
        antallForekomster++;  // Count other matching characters
      }
    }

    if (antallForekomster == 3) {
      cout << "Index: " << i << " | Symbol: " << txt[i] << endl;
      txt[i] = '\0';  // Mark the character so it won't be counted/printed again
    }
  }

  return 0;
}