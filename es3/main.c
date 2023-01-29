#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUtenti.h"

int main(int argc, char *argv[])
{

    Lista l;
    nuovaLista(&l);
    Utente utente;
    FILE *fb;
    FILE *ft;
    char telefono[11];
    int sec;

    if (argc != 3)
    {
        printf("\nUso: %s <fileBinario> <fileTestuale>\n\n");
        exit(100);
    }

    fb = fopen(argv[1], "rb");
    if (fb == NULL)
    {
        printf("\nErrore apertura file binario.\n\n");
        exit(101);
    }

    while (fread(&utente, sizeof(Utente), 1, fb) == 1)
    {
        insTesta(&l, utente);
    }

    fclose(fb);

    // stampa(l);

    ft = fopen(argv[2], "r");
    if (ft == NULL)
    {
        printf("\nErrore apertura file di testo.\n\n");
        exit(102);
    }

    while (fscanf(ft, "%s%d", telefono, &sec) == 2)
    {
        aggiorna(&l, telefono, sec);
    }

    fclose(ft);

    stampa(l);
}