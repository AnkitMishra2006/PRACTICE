#include <stdio.h>


int nCr(int n, int r)
{
    if (r==0||n==r) return 1;
    else return nCr(n-1,r-1)+nCr(n-1,r);
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