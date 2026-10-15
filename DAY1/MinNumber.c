#include <stdio.h>

int main()
{
    int n, c = 0;
    scanf("%d", &n);

    c += n / 100; n %= 100;
    c += n / 50;  n %= 50;
    c += n / 20;  n %= 20;
    c += n / 10;  n %= 10;
    c += n / 5;   n %= 5;
    c += n / 2;   n %= 2;
    c += n;

    printf("%d\n", c);
    return 0;
}