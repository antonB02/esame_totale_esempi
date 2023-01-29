#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "listaUrl.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void stampa(Lista l)
{
    while (l)
    {
        if (l->dato.cont >= 3)
        {
            printf("%s %d\n", l->dato.url, l->dato.cont);
        }
        l = l->next;
    }
    printf("\n");
}

void insTesta(Lista *pl, Sito sito)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dato = sito;
    aux->next = *pl;
    *pl = aux;
}

void aggiorna(Lista *pl, char url[])
{
    while (*pl && strcmp((*pl)->dato.url, url) != 0)
    {
        pl = &(*pl)->next;
    }
    if (*pl)
    {
        (*pl)->dato.cont++;
    }
    else
    {
        Sito sito;
        strcpy(sito.url, url);
        sito.cont = 1;
        insTesta(pl, sito);
    }
}