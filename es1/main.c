#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaUrl.h"

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("\nInsert prompt: %s <textFile>", argv[0]);
        exit(100);
    }

    Lista l;
    nuovaLista(&l);
    Visita v;
    FILE *f;

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("\nErrore apertura file!\n\n");
        exit(101);
    }

    while (fscanf(f, "%d%d%d%s", &v.ora, &v.minuto, &v.seconda, v.url) == 4)
    {
        aggiorna(&l, v.url);
    }
    printf("\n");

    fclose(f);

    stampa(l);
}