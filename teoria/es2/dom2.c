#include <stdio.h>

int f(int d) // d-esima cifra da sinistra
{
    int MATRICOLA = 189888; // INSERISCI TUA MATRICOLA QUI
    int res;

    if (d <= 0 || d > 6)
    {
        return 0;
    }

    while (6 - d)
    {
        MATRICOLA /= 10;
        d++;
    }

    return (MATRICOLA % 10);
}

/*int func(int d) // d-esima cifra da destra
{
    int MATRICOLA = 189888;
    int res;

    if (d <= 0 || d > 6)
    {
        return 0;
    }

    while (d)
    {
        res = MATRICOLA % 10;
        MATRICOLA /= 10;
        d--;
    }

    return res;
}*/

int main()
{
    int a = 0, i[] = {1, 1, 1};
    while (a < 2)
    {
        i[a] = f(++a);
    }

    /*for (int k = 0; k < 3; k++)
    {
        printf("!!!i[%d] = %d\n", k, i[k]);
    }*/

    for (i[0] = 2; i[0] >= 0; i[0]--)
        printf("%d ", i[i[0]]);
    printf("\n");

    return 0;
}

// 189888