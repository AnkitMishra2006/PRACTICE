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
int Get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}
void Set(struct Array* arr, int index, int x)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index] = x;
    }
}
int Max(struct Array arr)
{
    int i;
    int max = arr.A[0];
    for(i = 1 ; i<arr.length ; i++)
    {
        if(arr.A[i]>max) max = arr.A[i];
    }
    return max;
}
int Min(struct Array arr)
{
    int i;
    int min = arr.A[0];
    for(i = 1 ; i<arr.length ; i++)
    {
        if(arr.A[i]<min) min = arr.A[i];
    }
    return min;
}
int Sum(struct Array arr)
{
    int i;
    int sum = 0;
    for(i = 0 ; i<arr.length ; i++)
    {
        sum+=arr.A[i];
    }
    return sum;

}
int RSum(struct Array arr, int n)  //Call RSum(arr, arr.length - 1)
{
    if(n<0) return 0;
    else return RSum(arr,n-1) + arr.A[n];

}
int Avg(struct Array arr)
{
    int i;
    int sum = 0;
    for(i = 0 ; i<arr.length ; i++)
    {
        sum+=arr.A[i];
    }
    return sum/arr.length;
    // return Sum(arr)/arr.length;
}
void Reverse(struct Array* arr)
{
    // Using Two Pointers Approach
    int i = 0, j = arr->length - 1;
    while(i<j)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }

    // Brute Force
    // int i,j,B[arr->length];
    // for(i = arr->length , j = 0 ; i >= 0 ; i--,j++ )
    // {
    //     B[j] = arr->A[i];
    // }
    // for ( i = 0; i < arr->length; i++)
    // {
    //     arr->A[i] = B[i];
    // }
    
}
void InsertIS(struct Array* arr, int x)
{
    if(arr->length == arr->size) return;
    int i = arr->length - 1;
    while(i>= 0 && x < arr->A[i]){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}
int IsSorted(int arr[], int n)
{
    // Call IsSorted(arr, arr.length)
    int i;
    for ( i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]) return 0;
    }
    return 1;

}
void Rearrange(struct Array* arr)
{
    int i,j;
    i = 0;
    j = arr->length - 1;

    while(i<j)
    {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>0) j++;

        if(i<j) swap(&arr->A[i], &arr->A[j]);
    }
}
struct Array*  Merge(struct Array* arr1, struct Array* arr2)
{
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;
    struct Array* arr3 = (struct Array*) malloc(sizeof(struct Array));
    while(i < m && j < n)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for(; i < m ; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(; j < n ; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = arr1->size + arr2->size;
    return arr3;
}
struct Array*  Union(struct Array* arr1, struct Array* arr2)
{
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;
    struct Array* arr3 = (struct Array*) malloc(sizeof(struct Array));
    while(i < m && j < n)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else
        {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for(; i < m ; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for(; j < n ; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    arr3->size = arr1->size + arr2->size;
    return arr3;
}
struct Array*  Intersection(struct Array* arr1, struct Array* arr2)
{
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;
    struct Array* arr3 = (struct Array*) malloc(sizeof(struct Array));
    while(i < m && j < n)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            i++;
        }
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
        else
        {
            j++;
        }
    }
    arr3->length = k;
    arr3->size = arr1->size + arr2->size;
    return arr3;
}
struct Array*  Difference(struct Array* arr1, struct Array* arr2)
{
    int i = 0, j = 0, k = 0;
    int m = arr1->length;
    int n = arr2->length;
    struct Array* arr3 = (struct Array*) malloc(sizeof(struct Array));
    while(i < m && j < n)
    {
        if(arr1->A[i] < arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            i++;
        }
        else if(arr1->A[i] > arr2->A[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for(; i < m ; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;
    arr3->size = arr1->size + arr2->size;
    return arr3;
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