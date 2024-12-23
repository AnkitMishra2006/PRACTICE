#include<stdio.h>
int isAnagram(char *a, char *b)
{
 
    int i = 0, h[26] = {0};
    for(i = 0; a[i] != '\0'; i++)
    {
        h[a[i] - 'a'] += 1;
    }
    for(i = 0; b[i] != '\0'; i++)
    {
        h[b[i] - 'a'] -= 1;
    }
    for(i = 0; i < 26; i++)
    {
        if(h[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char a[] = "medical";
    char b[] = "djhmoil";
    printf("%d", isAnagram(a, b));
    return 0;
}