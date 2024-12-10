#include<stdio.h>
// Find length of a string

int length(char* s)
{
    int i;
    while(s[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    char *s = "Ankit";
    printf("%d", length(s));
    return 0;
}