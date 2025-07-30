//Code snippet with comments taken straight from the exam paper
//Code might be in Norwegian to reflect the exam paper


/**
 * Oppgave 4
 *
 * "Tallet 2.6 ganget med 135 er 351. Svaret er bare at det første sifferet er flyttet bakerst.
 * Samme gjellder disse regnestykkene når faktoren som ganges med er 2.6:
 *  2.6 * 270 = 702
 *  2.6 * 135135 = 351351
 *  2.6 * 270270 = 702702
 *
 *  Skriv et program som tar inn en faktor å gange med (eks 2.6) og som for alle tall mindre enn 1 million
 *  skriver ut alle slike regnestykker som stemmer, dersom det ikke finnes noen skal dette komme med en egen melding"
 */

#include <iostream>
int findMatchingMultiples(double factor) {
    bool found = false;
    for (int i = 1; i < 1000000; ++i) {
        int product = factor * i;

        // Convert both numbers to strings
        std::string original = std::to_string(i);
        std::string result = std::to_string(product);

        // Check if the first character of result is moved to the end of original
        if (result.length() == original.length() + 1 &&
            result.substr(1) == original &&
            result[0] == original[0]) {
            std::cout << factor << " * " << i << " = " << product << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No results found." << std::endl;
    }
    return 0; // Return 0 to indicate successful execution
}


