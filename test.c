#include <stdio.h>

int main()
{
    int i = 0;
    while (i < 9)
    {
        printf("%d", i-(i%3));
        i++;
    }
}