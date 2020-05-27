#include <stdio.h>
int main(void)
{
    int a;
    while (scanf("%d", &a) != EOF)
    printf("%lu\n\n", a % 2 == 0 ? a / 2 * (a + 1) : (1 + a) / 2 * a);
    return 0;
}
