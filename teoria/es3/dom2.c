#include <stdio.h>

int f(int d)
{
    int MATRICOLA = 189888; // INSERISCI TUA MATRICOLA QUI
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
}

int main()
{
    char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 1;
    while (i < 7)
    {
        printf("%c", *((char *)((int *)s + i)));
        i += f(i) ? f(i) : 1;
    }
    printf("\n");
}