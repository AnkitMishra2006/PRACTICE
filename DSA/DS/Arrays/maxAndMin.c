#include<stdio.h>

// Find min and max element in an array in a single scan

void maxAndMin(int a[], int length)
{
    int i;
    int min = a[0];
    int max = a[0];
    for(i = 1; i < length; i++)
    {
        if(a[i] > max) max = a[i];
        else if(a[i] < min) min = a[i];
    }
    printf("Min: %d\nMax: %d", min, max);
}
int main()
{
    int a[10] = {2,3,9,13,14,27,58,4,0,4};
    maxAndMin(a, 10);
    return 0; 
}