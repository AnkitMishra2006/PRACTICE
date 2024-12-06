#include<stdio.h>

double e(double x, int n)
{
    static double s;
    if(n==0) return s;
    s = 1 + (x/n)*s;
    return e(x, n-1);
}


int main()
{
    double x;
    printf("Enter the value of x for e^x: ");
    scanf("%lf", &x);
    printf("%lf", e(x,10));
    return 0;
}