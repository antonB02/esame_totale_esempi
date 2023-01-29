#include <stdio.h>

char f(char *s)
{
    int i, *p = (int *)s;
    printf("!!! s = %d\n", s);
    char *q;
    p++;
    q = (char *)p;
    printf("!!! q = %d\n", q);
    return *q;
}

int main()
{
    printf("\n%c\n\n", f("milano"));
}