typedef struct
{
    char cf[17];
    int cont1;
    int cont2;
    int cont3;
    int accessi_negati;
    int disabled;
} Utente;

typedef struct nodo
{
    Utente dati;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void stampa(Lista l);
void insTesta(Lista *pl, Utente utente);
void aggiorna(Lista *pl, char cf[], int attivita);