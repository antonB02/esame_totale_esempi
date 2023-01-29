typedef struct
{
    char numero[11];
    char piano;
    float credito;
} Utente;

typedef struct nodo
{
    Utente dati;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Utente dati);
void stampa(Lista l);
void aggiorna(Lista *pl, char telefono[], int sec);