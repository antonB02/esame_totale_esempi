#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPazienti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Paziente p)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dati = p;
    aux->next = *pl;
    *pl = aux;
}

void stampa(Lista l)
{
    printf("\n");
    while (l)
    {
        printf("%s %g %g\n", l->dati.cf, l->dati.somma_temp / l->dati.n_rilevazioni, l->dati.somma_sat / l->dati.n_rilevazioni, l->dati.n_rilevazioni);
        l = l->next;
    }
    printf("\n");
}

void aggiorna(Lista *pl, char cf[], int ora, float temp, float sat)
{
    while (*pl)
    {
        if (strcmp((*pl)->dati.cf, cf) != 0)
        {
            // printf("!!!this ran(2)\n");
            pl = &(*pl)->next;
        }
        else
        {
            // printf("!!!this ran(3)\n");
            (*pl)->dati.n_rilevazioni++;
            (*pl)->dati.somma_temp += temp;
            (*pl)->dati.somma_sat += sat;
            break;
        }
    }

    if (!(*pl))
    {
        // printf("!!!this ran(1)\n");
        Paziente p;
        strcpy(p.cf, cf);
        p.n_rilevazioni = 1;
        p.somma_temp = temp;
        p.somma_sat = sat;
        insTesta(pl, p);
    }
}