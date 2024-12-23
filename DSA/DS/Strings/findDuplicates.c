#include<stdio.h>

// 1. Compare a char with other chars 
// 2. using hashtable
// 3. using bits

void hashDuplicates(char* a)
{
    int H[26], i;
    for(i = 0; i < 26; i++)
    {
        H[i] = 0;
    }
    for(i = 0; a[i] != '\0'; i++)
    {
        H[a[i] - 97] += 1;
    }
    for(i = 0; i < 26; i++)
    {
        if(H[i] > 1)
        {
            printf("Character: %c \nCount: %d\n", i + 97, H[i]);
        }
    }
}

void bitsDuplicates(char *a)
{
    long int i,h = 0, x = 0;
    for(i = 0; a[i] != '\0'; i++)
    {
        x = 1;
        x = x<<(a[i] - 97);
        if((x&h) > 0)
        {
            printf("%c is a duplicate\n", a[i]);
        }
        else{
            h = h|x;
        }
    }
}
int main()
{   
    char a[] = "naman";
    bitsDuplicates(a);
    return 0;
}