#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp; 
}
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array* arr,int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array* arr, int index, int x)
{
    int i;
    if(index>=0 && index <= arr->length)
    {
        for(i = arr->length; i>index ;i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array* arr, int index)
{
    int i;
    if(index>=0 && arr->length>index)
    {
        int x = arr->A[index];
        for(i= index; i<arr->length; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
}
int LinSearch(struct Array* arr, int key)
{
    int i; 
    for(i = 0; i<arr->length; i++)
    {
        if(key==arr->A[i]) return i;
    }
    return -1;
}
int TranLinSearch(struct Array* arr, int key)
{
    int i; 
    for(i = 0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i-1],&arr->A[i]);
            return i;
        }
    }
    return -1;
}
int MTHLinSearch(struct Array* arr, int key)
{
    int i; 
    for(i = 0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[0],&arr->A[i]);
            return i;
        }
    }
    return -1;
}
int BinSearch(struct Array arr, int key)
{
    int mid,l=0,h = arr.length - 1;
    while(l<=h)
    {
        mid = (l+h)/2;
        if (key == arr.A[mid]) return mid;
        else if (key < arr.A[mid]) h = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
int RecBinSearch(int A[], int l, int h, int key)
{
    int mid;

    if(l<=h)
    {
        mid = (l+h)/2;
        if (key == A[mid]) 
            return mid;
        else if (key < A[mid]) 
            return RecBinSearch(A,l,mid-1,key);
        else 
            return RecBinSearch(A,mid+1,h,key);
    }
    return -1;
}
int main()
{
    // int n,i;
    // struct Array arr;
    // printf("Enter the Size of Array: ");
    // scanf("%d", &arr.size);
    // arr.A = (int*) malloc(arr.size * sizeof(int));
    // arr.length = 0;

    // printf("Enter total number of values in array: ");
    // scanf("%d", &n);
    // printf("Enter all Elements:-\n");

    // for(i=0; i<n; i++)
    // {
    //     scanf("%d", &arr.A[i]);
    // }
    // arr.length = n;
    struct Array arr = {{2,3,4,5,6},20,5};
    printf("%d", RecBinSearch(arr.A,0,4,2)) ;
    // Display(arr);
    return 0;
}