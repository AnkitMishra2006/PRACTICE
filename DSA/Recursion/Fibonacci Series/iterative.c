#include<stdio.h>

int fib(int n)
{
    int i,s, t0 = 0, t1 = 1;
    if (n<=1) return n;
    for(i=2; i<=n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int main()
{
    int n;
    printf("Enter the index of the value of fibonacci series: ");
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}