#include<stdio.h>

double e(double x, int n)
{
    if(n==0) return 1;
    
    static double p=1, f=1;
    double r;
    r = e(x,n-1);
    p = p*x;
    f = f*n;
    return (r+(p/f));
    
}

int main()
{   
    double x;
    printf("Enter the x for e^x: ");
    scanf("%lf" ,&x);
    printf("%lf \n", e(x,10));
    return 0;
}