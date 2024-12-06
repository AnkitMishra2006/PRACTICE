#include<stdio.h>

double e(double x, int n)
{
    double s = 1;
    for(;n>0;n--)
    {
        s = 1+( (x/n) * s);
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