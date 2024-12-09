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
// In sorted array Using 2 pointers
void pair2pt(int a[], int length, int k)
{
    int i = 0, j = length - 1;
    while(i<j)
    {
        if(a[i] + a[j] == k)
        {
            printf("%d + %d = %d\n", a[i], a[j], k); 
            i++; 
            j--;
        } 
        else if (a[i] + a[j] < k) i++;
        else j--;
    }
}
int main()
{
    int a[10] = {1,3,5,6,8,9,10,12,15,16};
    pair2pt(a,10,17);
    return 0;
}
