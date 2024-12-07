#include <stdio.h>

// find missing element in an array of natural numbers
int missingEleIS(int a[], int length)
{
    int i;
    int n = a[length-1];
    int s = n*(n+1)/2;
    int sum = 0;
    for (i = 0; i < length - 1; i++)
    {
        sum+=a[i];
    }
    return s - sum;
}

// find missing element in an array of consecutive natural numbers 
void missingEle(int a[], int length)
{
    int diff = a[0] - 0;

    for (int i = 0; i < length - 1; i++)
    {
        if (diff!=(a[i] - i))
        {
            return diff + i;
        }
        
    }
    
}

// find multiple missing element in an array of consecutive natural numbers 

void mulMissingEle(int a[], int length)
{
    int diff = a[0] - 0;

    for (int i = 0; i < length - 1; i++)
    {
        if (diff!=(a[i] - i))
        {
            while(diff < a[i] - i)
            {
                printf("Missing Element %d", diff + i);
                diff++;
            }
        }
        
    }
}
int main()
{
    return 0;
}