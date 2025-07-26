//Code snippit with comments taken straight from the exam paper
//Code is in Norwegian to reflect the exam paper
//Globale variabler, parametere, struct medlemmer eller hjelpe-strukturer skal IKKE brukes
//
//Treet som er oppgitt er satt opp i inorde rekke,
//dvs at den noden til venstre for en node har mindre ID enn noden selv, mens den til høyre har større ID.
//               4
//             /   \
//            2     6
//           / \   / \
//          1   3 5   7

struct Node {
int  ID;                               //  Nodens ID/key/nøkkel/navn (et tall).
Node *left;                       //   Referanse til høyre subtre
Node *right;                     //   Referanse til venstre subtre, eller nullptr/null (om tomt) og Referanse til høyre subtre, eller:  se forklaring nedenfor.
bool  harHoyreBarn;  //   Se forklaring nedenfor.

Node (int id, Node* l, Node* r, bool hHB)
{ ID = id;  left = l;  right = r;  harHoyreBarn = hHB;  }

  };


/**
* Oppgave 3a - IKKE rekursiv funksjon "Node* forste(Node* node)"
* Denne funksjonen skal returner en peker til den sekvensielt første noden (med minst ID)
* I subtreet under en node. Dersom treet er tomt skal den returnere nullptr/null
* Merk at her så betyr ikke "minste noden" det samme som neste i inorder rekkefølge
*/


Node* forste(Node* node){
 if(node == nullptr) {return nullptr} //Dersom tom, altså ingen node. Return nullptr

 Node* current = node;
 while (current -> left){
 current = current->left;
 }
 return current

}


/**
* Oppgave 3b - Lag den ikke rekursive funksjonen "bool finn(int id)"
* Returnerer true/false til om id finnes i treet tilpeket av "gRoot"
*/

bool finn(int id) {
    Node* current = gRoot;
    while (current !=nullptr){
        if(current->ID == id){
        return true;
        }
        else if(current->ID > id) { //ID of current is lower than the searching ID
        current = current->left; //Moves left
        }
        else { //ID of current is higher than the searching ID
        current = current->right; //Moves right
        }
    }
    return false;
}

/**
* Oppgave 3c - Lag den ikke rekursive funksjonen "void traverser(Node* node)"
* Starter i node og skriver ut alle id'ene i hele resten av treet
* Kan bruke funksjoner fra oppgave 3a og 3b
*/

void travarser(Node* node) {
    if (node == nullptr) return;

    Node* current node;
    while (current != nullptr) {
        std::cout << current->ID
        if (current -> left) {
            current = current ->left;
        } else if (current->harHoyreBarn) {
        current = current -> right; }
    else {
        break; }
    }
}


/**
* Oppgave 3d - Lag den ikke rekursive funksjonen "void legginn(int id)"
* Denne funksjonen skal legge inn en ny node med ID i treet.
Husk å håndtere tilfellet der treet er helt tomt, og at vi har constructoren, som gjør at man
kan opprette nye noder vha.  new  og passende parametre. Hint:  En ny node legges alltid
inn nederst, pluss noen andre prinsipper som alltid vil gjelde (men de må du finne ut av selv).
*/


void legginn(int id) {
    Node* newNode = new Node(id, nullptr, nullptr, false); // Create a new node, fill inn parameters

    if (gRoot == nullptr) { // If the tree is empty
        gRoot = newNode; // Set the new node as the root
        return;
    }

    Node* current = gRoot;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current; // Keep track of the parent node
        if (id < current->ID) {
            current = current->left; // Move to the left subtree
        } else {
            current = current->right; // Move to the right subtree
        }
    }

    // Insert the new node as a child of the parent node
    if (id < parent->ID) {
        parent->left = newNode; // Insert as left child
    } else {
        parent->right = newNode; // Insert as right child
        parent->harHoyreBarn = true; // Mark that this parent has a right child
    }
}


