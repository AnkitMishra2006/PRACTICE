#include<stdio.h>

double e(double x, int n)
{
    double s = 1;
    int i;
    double num = 1, den = 1;
    for(i = 1; i<=n; i++)
    {
        num*=x;
        den*=i;
        s+=(num/den);
    }
    return s;
}


int main()
{
    double x;
    printf("Enter x for e^x: ");
    scanf("%lf", &x);
    printf("%lf", e(x,10));
    return 0;
}