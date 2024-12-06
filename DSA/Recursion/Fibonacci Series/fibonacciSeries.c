#include<stdio.h>

int fib(int n)
{
    if (n<=1) return n;
    return fib(n-2) + fib(n-1);
}

int main()
{
    int n;
    printf("Enter the index of the value of fibonacci series: ");
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}