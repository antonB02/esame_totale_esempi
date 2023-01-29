#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPazienti.h"

int main(int argc, char *argv[])
{
    Rilevazione r;
    Paziente p;
    Lista l;
    nuovaLista(&l);
    FILE *fb;

    if (argc != 2)
    {
        printf("\nUso: %s <fileBinario>\n\n", argv[0]);
        exit(100);
    }

    fb = fopen(argv[1], "rb");
    while (fread(&r, sizeof(Rilevazione), 1, fb) == 1)
    {
        // printf("!!! temp = %lf; sat = %lf\n", r.temperatura, r.saturazione);
        aggiorna(&l, r.cf, r.ora, r.temperatura, r.saturazione);
    }

    fclose(fb);

    stampa(l);
}