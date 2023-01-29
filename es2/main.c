#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    FILE *fb;
    FILE *ft;
    char cf[17];
    int attivita;
    Utente utente;
    Lista l;
    nuovaLista(&l);

    if (argc != 3)
    {
        printf("\nUso: %s <fileBinario> <fileTestuale>\n", argv[0]);
        exit(100);
    }

    fb = fopen(argv[1], "rb");
    if (fb == NULL)
    {
        printf("\nErrore apertura file binario.\n\n");
        exit(101);
    }

    while (fread(cf, sizeof(cf), 1, fb) == 1)
    {
        strcpy(utente.cf, cf);
        utente.cont1 = 4;
        utente.cont2 = 4;
        utente.cont3 = 4;
        utente.accessi_negati = 0;
        utente.disabled = 0;
        insTesta(&l, utente);
    }

    fclose(fb);

    ft = fopen(argv[2], "r");
    if (fb == NULL)
    {
        printf("\nErrore apertura file di testo.\n\n");
        exit(102);
    }

    while (fscanf(ft, "%s%d", cf, &attivita) == 2)
    {
        // printf("Codice Fiscale: %s, attivita: %d\n", cf, attivita);
        aggiorna(&l, cf, attivita);
    }

    fclose(ft);

    stampa(l);
}