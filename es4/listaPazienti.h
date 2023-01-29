typedef struct
{
    char cf[17];
    int ora;
    float temperatura;
    float saturazione;
} Rilevazione;

typedef struct
{
    char cf[17];
    int n_rilevazioni;
    float somma_temp;
    float somma_sat;
} Paziente;

typedef struct nodo
{
    Paziente dati;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Paziente p);
void stampa(Lista l);
void aggiorna(Lista *pl, char cf[], int ora, float temp, float sat);