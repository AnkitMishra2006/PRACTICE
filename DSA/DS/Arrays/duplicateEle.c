#include<stdio.h>

// Find duplicates in sorted array
void duplicateEle(int a[], int length)
{
    int i;
    int lastDuplicate = 0;
    for ( i = 0; i < length; i++)
    {
        if(a[i] == a[i+1] && lastDuplicate != a[i])
        {
            lastDuplicate = a[i];
            printf("%d\n", a[i]);
        }
    }
    
}

// Find duplicates in sorted array with their counts

void duplicateEleCounts(int a[], int length)
{
    int i,j;
    for(i = 0; i < length - 1; i++)
    {
        if(a[i] == a[i+1])
        {
            j = i + 1;
            while(a[i] == a[j]) j++;
            printf("%d is appearing %d times\n", a[i], j - i);
            i = j - 1;
        }
    }
}

// Using Hashing
void duplicates(int a[], int low, int high, int length)
{
    int i;
    int h[high];
    for(i = low; i <= high; i++)
    {
        h[i] = 0;
    }
    for(i = 0; i < length; i++)
    {
        h[a[i]]++;
    }
    for(i = low; i <= high; i++)
    {
        if(h[i] != 0)
        {
            printf("%d is appearing %d times\n", i, h[i]);
        }
    }
}

int main()
{
    int a[10] = {9,9,3,5,4,3,5,4,1,1};
    duplicates(a, 1, 9, 10);
    return 0;
}