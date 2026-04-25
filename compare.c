#include <stdio.h>

int compare(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main(void)
{
    int a, b;
    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("n/a");
        return 0;
    }
    int max = compare(a, b);
    printf("%d", max);
    return 0;
}
