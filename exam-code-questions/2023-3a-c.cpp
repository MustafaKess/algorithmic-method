//Code snippet with comments taken straight from the exam paper
//Code might be in Norwegian to reflect the exam paper

// Vi har et binært tre (ikke nødvendigvis søketre) bestående av noder:

struct Node {
char ID; // Nodens ID/key/nøkkel/navn (ett tegn).
int pos; // Posisjon i treet.
Node *left, *right; // Referanser til begge subtrærne, evt. nullptr/NULL
Node (char id, int p) // Constructor:
{ ID = id; pos = p; left = right = nullptr; }
};

//og en global variabel

Node *gRoot = nullptr; // Global root pointer

//I oppgave 3 skal det ikke innføres globale data eller flere struct medlemmer enn angitt ovenfor.
//Det skal heller ikke brukes andre strukturer (array, stack, queue eller liste)
//Men i oppgave 3c kan det være aktuelt å innføre en kortere array

/**
* Oppgave 3a - Lag de to rekursive funksjonene "void speilvend(Node* node)" og "void settPosisjoner(Node* node, int p)"
*/

/**
* Speilvend noden n og alle dens subtrær/barn. Dvs bytte om på sine venstre og høuyre barn, og dette skjer
* rekursivt for alle noder i treet.
*/

void speilvend(Node* node) {
    if (node == nullptr) return;
    // Swap left and right children
    Node* temp = node->left; // Temp for å lagre left child når right bytter om
    node->left = node->right;
    node->right = temp;
    // Recursively call for left and right children
    speilvend(node->left);
    speilvend(node->right);
}

/**
* Setter rekursivt ny posisjon for alle noder i treet.
*/
void settPosisjoner(Node* node, int p) {
    if (node == nullptr) return;

    node->pos = p; // Set the position of the current node

    // Recursively set positions for children
    settPosisjoner(node->left, 2 * p + 1); // Left child position
    settPosisjoner(node->right, 2 * p + 2); // Right child position
}


/**
* Oppgave 3b - Lag den rekursive funksjonen "void ultraSpeilvend(Node* n, int p)"
* Denne funksjonen skal kombinere begge de forrige funksjonene i en.
*/
void ultraSpeilvend(Node* n, int p) {
    if (n == nullptr) return;

    // Set the position of the current node
    n->pos = p;

    // Recursively call for left and right children with updated positions
    ultraSpeilvend(n->left, 2 * p + 1);
    ultraSpeilvend(n->right, 2 * p + 2);

    // Swap left and right children
    Node* temp = n->left;
    n->left = n->right;
    n->right = temp;
}

/**
* Oppgave 3c - Lag den IKKE rekursive funksjonen "Node* finnNode(int p)"
* Denne funksjonen skal returnere en peker til noden med posisjon p, eller nullptr/null dersom den ikke finnes.
*/
Node*  finnNode(int p)  {
  Node* n = gRoot;                       //  Initierer søkepeker.
  if (n)  {                              //  Treet er ikke tomt:
     char intBinar[32];                  //  Array for bit-mønster (baklengs).
     int slutt = -1;                     //  Initieres til før arrayens start.
	                                     //  Bygger binærmønsteret for 'p':
     while (p)   {                       //  Så lenge bit igjen: Fyller med
       intBinar[++slutt] = (p %  2) ? '1' : '0';  //  bakerste bitet (1/0).
       p /= 2;                           //  Tar vekk det bakerste bitet(!).
     }
     slutt--;           //  Ignorerer første bit (rota), starter på 'slutt-1'.
     for (int i = slutt;  n && i >= 0;  i--)   //  Gjennomgår baklengs-bitene.
	 n = (intBinar[i] == '0') ? n->left : n->right;    //  0-venstre, 1-høyre:
  }
  return n;                          //  Returnerer noden der 'n' har stanset
