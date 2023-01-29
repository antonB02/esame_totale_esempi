#include <stdio.h>

int fun(int d) // d-esima cifra da sinistra
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
    int i = 8;
    while (!fun(--i))
        ;
    do
    {
        printf("%c", '0' + fun(i--));
    } while (fun(i));
    printf("\n");

    return 0;
}

// 189888