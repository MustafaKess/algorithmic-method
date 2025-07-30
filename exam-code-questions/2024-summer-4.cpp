//Code snippet with comments taken straight from the exam paper
//Code might be in Norwegian to reflect the exam paper

/**
 * Oppgave - 4
 * Lag funksjonen "void skrivDato(const int dagNr)"
 * Funskjonen bereger og skriver ut hvilken dato dette er. (Dag og måned)
 * Vi ser bort ifra skuddår, så månedene har 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
 * Dersom dagNr feks er 96 skal den skrive ut 6/4
 *
 **/

#include <iostream>

void skrivDato(const int dagNr) {
 if (dagNr < 1 || dagNr > 365) {
  std::cout << "\n\tDagnummer må være i intervallet 1–365!\n\n";
  return;
 }

 int dagerPrMnd[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 int måned = 1;
 int resterendeDager = dagNr;

 for (int i = 0; i < 12; i++) {
  if (resterendeDager <= dagerPrMnd[i]) {
   std::cout << resterendeDager << "/" << måned << "\n";
   return;
  }
  resterendeDager -= dagerPrMnd[i];
  måned++;
 }
}
