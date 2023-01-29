typedef struct
{
    int ora;
    int minuto;
    int seconda;
    char url[100];
} Visita;

typedef struct
{
    char url[100];
    int cont;
} Sito;

typedef struct nodo
{
    Sito dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void stampa(Lista l);
void insTesta(Lista *pl, Sito sito);
void aggiorna(Lista *pl, char url[]);