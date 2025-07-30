//Code snippet with comments taken straight from the exam paper
//Code might be in Norwegian to reflect the exam paper

//Vi har et binært tre (ikke nødvendigvis søketre) bestående av:
struct Node {
    int ID; // Nodens ID/key/nøkkel/navn (et tall).
    Node *left, *right; // Referanse til begge subtrærne (evt. 'nullptr/NULL').
    Node(int id) { ID = id; left = right = nullptr; }
};

//Vi har kun den globale variabelen:
Node* gRoot = nullptr; // Rot-peker (har altså ikke at head->right er rota).


/**
 * Oppgave 3a - Lag den rekursive funksjonen "bool erSosken(const Node* t, const Node* s1, const Node* s2)"
 * som skriver ut node
*/

bool erSosken(const Node* t, const Node* s1, const Node* s2){
if(t != nullptr){
    // Sjekk om begge søsken er barn av den nåværende noden
    if ((t->left == s1 && t->right == s2) || (t->left == s2 && t->right == s1)) {
        return true; // De er søsken
    }

    // Sjekk i venstre subtre
    if (erSosken(t->left, s1, s2)) {
        return true;
    }

    // Sjekk i høyre subtre
    return erSosken(t->right, s1, s2);
}
else {
    return false; // t er nullptr

}

/**
 * Oppgave 3b - Lag den rekursive funksjonen "void kappTreNedentil(const Node* t, const int verdi)"
 * Funksjonen skal kutte forbindelsen fra t til alle barn som har en ID større eller lik verdi.
 * Det vil si sette aktuelle pekere i t til nullptr/null
 */

 void kappTreNedentil(const Node* t, const int verdi) {
    if (t == nullptr) return; // Hvis noden er tom, gjør ingenting

    // Sjekk venstre subtre
    if (t->left != nullptr && t->left->ID >= verdi) {
        t->left = nullptr; // Kutt forbindelsen til venstre subtre
    } else {
        kappTreNedentil(t->left, verdi); // Fortsett nedover i venstre subtre
    }

    // Sjekk høyre subtre
    if (t->right != nullptr && t->right->ID >= verdi) {
        t->right = nullptr; // Kutt forbindelsen til høyre subtre
    } else {
        kappTreNedentil(t->right, verdi); // Fortsett nedover i høyre subtre
    }