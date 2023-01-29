#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Utente dati)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dati = dati;
    aux->next = *pl;
    *pl = aux;
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %c %g\n", l->dati.numero, l->dati.piano, l->dati.credito);
        l = l->next;
    }
}

void aggiorna(Lista *pl, char telefono[], int sec)
{
    while (*pl)
    {
        if (strcmp((*pl)->dati.numero, telefono) != 0)
        {
            pl = &(*pl)->next;
        }
        else
        {
            if ((*pl)->dati.piano == 'A')
            {
                float chiamata = 0.15;
                while (sec > 0)
                {
                    chiamata += 0.08;
                    sec -= 60;
                }
                chiamata = floor(100 * chiamata) / 100;
                (*pl)->dati.credito -= chiamata;
                pl = &(*pl)->next;
            }
            else
            {
                float chiamata = 0.12 / (float)60 * sec;
                chiamata = floor(100 * chiamata) / 100;
                (*pl)->dati.credito -= chiamata;
                pl = &(*pl)->next;
            }
        }
    }
}