#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s: %d %d %d", l->dati.cf, l->dati.cont1, l->dati.cont2, l->dati.cont3);
        if (l->dati.disabled)
        {
            printf(" DISABLED\n");
        }
        else
        {
            printf("\n");
        }
        l = l->next;
    }
}

void insTesta(Lista *pl, Utente utente)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dati = utente;
    aux->next = *pl;
    *pl = aux;
}

void aggiorna(Lista *pl, char cf[], int attivita)
{
    while (*pl)
    {
        if (strcmp((*pl)->dati.cf, cf) != 0)
        {
            pl = &(*pl)->next;
        }
        else
        {
            if ((*pl)->dati.disabled)
            {
                printf("Codice Fiscale %s, attivita `%d: Accesso negato\n", (*pl)->dati.cf, attivita);
            }

            if (attivita == 1)
            {
                if ((*pl)->dati.cont1 != 0)
                {
                    (*pl)->dati.cont1--;
                }
                else
                {
                    printf("Codice Fiscale %s, attivita `%d: Accesso negato\n", (*pl)->dati.cf, attivita);
                    (*pl)->dati.accessi_negati++;
                    if ((*pl)->dati.accessi_negati == 3)
                    {
                        (*pl)->dati.disabled = 1;
                    }
                }
            }

            else if (attivita == 2)
            {
                if ((*pl)->dati.cont2 != 0)
                {
                    (*pl)->dati.cont2--;
                }
                else
                {
                    printf("Codice Fiscale %s, attivita `%d: Accesso negato\n", (*pl)->dati.cf, attivita);
                    (*pl)->dati.accessi_negati++;
                    if ((*pl)->dati.accessi_negati == 3)
                    {
                        (*pl)->dati.disabled = 1;
                    }
                }
            }

            else if (attivita == 3)
            {
                if ((*pl)->dati.cont3 != 0)
                {
                    (*pl)->dati.cont3--;
                }
                else
                {
                    printf("Codice Fiscale %s, attivita `%d: Accesso negato\n", (*pl)->dati.cf, attivita);
                    (*pl)->dati.accessi_negati++;
                    if ((*pl)->dati.accessi_negati == 3)
                    {
                        (*pl)->dati.disabled = 1;
                    }
                }
            }

            pl = &(*pl)->next;
        }
    }
}