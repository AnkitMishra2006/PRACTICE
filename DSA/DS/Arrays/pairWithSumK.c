#include<stdio.h>

// Find pair with sum k
void pair(int a[], int length, int k)
{
    int i,j;
    for(i = 0; i < length - 1; i++)
    {
        for ( j = i+1; j < length; j++)
        {
            if(a[i] + a[j] == k)
            {
                printf("%d + %d = %d\n", a[i],a[j],k);
            }
        }
    }
}
// Using Hashing
void pairH(int a[], int length,int low, int high, int k)
{
    int i;
    int H[high];
    for(i = low; i <= high; i++)
    {
        H[i] = 0;
    }
    for(i = 0; i < length; i++)
    {
        if(H[k - a[i]] != 0)
        {
            printf("%d + %d = %d\n", a[i], k - a[i], k);
        }
        H[a[i]]++;
    }
}
int main()
{
    int a[10] = {1,2,3,4,4,3,2,1,5,0};
    pairH(a,10,0,5,5);
    return 0;
}
