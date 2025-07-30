//Code snippet with comments taken straight from the exam paper
//Code might be in Norwegian to reflect the exam paper




/*
* Oppgave 3
* Vi har et binært tre (ikke nødvendigvis søketre) bestående av nodene:
*/

struct Node {
char ID; // Nodens ID/key/nøkkel/navn (ett tegn).

Node *left, *right;  // Referanser til begge subtrærne eller neste i preorder rekkefølge eller nullptr/NULL (se resten av oppgaveteksten).

bool nesteIPreorder; // Er false dersom høyre subtre finnes,
                     // er true dersom tomt høyre subtre og at right, da i stedet peker til neste node i preorder rekkefølge.
                     // Har noden er tomt høyre subtre, og er den aller siste i preorder rekkefølge, vil den også være true,
                     // bare at right da vil peke til nullptr/NULL.

    Node (char id, int p) { // Constructor:
    ID = id; nesteIPreorder = false; left = right = nullptr; }
};

// og de global variablene:
Node* gRoot = nullptr, // Rot-peker (har altså ikke at head->right er rota).
* gForrige = nullptr; // Den forrige noden i preorder rekkefølge (jfr. oppg.3b).

/**
* Oppgave 3a - Lag den IKKE rekursive funksjonen "Node* neste(Node* node)
* som returnerer en peker til den neste noden i preorder rekkefølge.
* Dersom noden er den siste noden i preorder rekkefølge
* eller om pekerern til noden er en nullptr så skal funksjonen returnere nullptr
*/

//Merk at denne vil ikke sjekke om det finnes en neste i preorder fra første noden i treet, bare fra og med noden som gis som parameter.
Node* neste(Node* node) {
    if (node == nullptr) return nullptr; // Hvis noden er tom, returner nullptr

    if (node->left != nullptr) {
        return node->left; // Returner venstre subtre hvis det finnes.
    } else {
        // høyre subtre finnes, gå til det
        if (node->right != nullptr) {
            return node-right;
        } else {
            return nullptr
        }
    }
}


/**
* Oppgave 3b - Lag den rekursive funksjonen "void settNeste(Node* node)"
* som går igjennom hele treet under node og setter korrekt verdi i alle nodenes right og nesteIPreorder
*/

void settNeste(Node* node){
if(node != nullptr ) { //En reell node
   if(gForrige != nullptr) { //Minst EN node tidligere i preorder rekkefølge
      if(gForrige->right == nullptr){ //Dersom forrige ikke hadde en høyre node
      gForrige->right == node //Vi setter noden til å være neste i preorder
                              //Right skal alltid peke på neste i rekken, så dersom den
                              //FORRIGE ikke peker på noe så skal den peke på "node" som er neste.

      gForrige->nesteIPreorder = true;  //Siden vi vet at gForrige ikke har noe høyre subtre
      }
    //Nå som vi har ordnet forrige nodes informasjon så kan vi sette parameter noden som neste
    gForrige = node;

    settNeste(node->left) //Rekursivt sjekker venstre barn (Preorder: seg selv -> venstre -> høyre)
                          //Dersom vi denne rekursivt fortsetter til en node som ikke eksisterer
                          //vil første if setning av funksjonen stoppe den.

    if(node->nesteIPreorder != nullptr){ settNeste(node->right) } //Dersom noden har høyre subtre
                                                                  //Å simpelt si node->right hadde vært feil
                                                                  //Siden det er det selve oppgaven skal fikse opp


    }
   }
  }
}