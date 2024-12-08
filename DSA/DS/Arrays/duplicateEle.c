#include<stdio.h>

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

int main()
{
    return 0;
}