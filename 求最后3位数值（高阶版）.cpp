#include <math.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    int a, n;
    char s[1000];
    scanf("%d%d", &a, &n);
	sprintf(s, "%.0f", pow(a, n));
    printf("The last 3 numbers is %s.\n", strlen(s) <= 3 ? s : s + strlen(s) - 3);
}
