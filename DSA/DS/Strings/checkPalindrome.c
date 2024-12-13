#include<stdio.h>
// reverse and then compare 
// or just Compare using 2 pointers
int palindrome( char s[])
{
    int i = 0,j = 0;
    while(s[j] != '\0') j++;
    j = j-1;
    for(; i<j; i++,j--)
    {
        if(s[i] != s[j]) return 0;
    }
    return 1;
}

int main()
{
    char s[] = "naman";
    printf("%d", palindrome(s));

    return 0;
}