#include <stdio.h>

int fact(int n)
{
    if(n==0||n==1) return 1;
    return fact(n-1)*n;
}

int nCr(int n, int r)
{
    int num = fact(n);
    int den = fact(r)*fact(n-r);
    return num/den;
}

int main()
{
    int n,r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);
    printf("nCr: %d", nCr(n,r));
    return 0;
}