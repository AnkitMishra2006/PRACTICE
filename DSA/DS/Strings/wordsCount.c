#include<stdio.h>

void wCount(char s[], int length)
{
    int i, wcount = 1;
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == ' ' && s[i-1] != ' ') wcount++;
    }
    printf("Words Count: %d\n", wcount);
}

int main()
{
    char s[] = "How Are You";
    wCount(s, 11);
    return 0;
}