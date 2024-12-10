#include<stdio.h>

char* toLower(char* s, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        if(s[i] >= 65 && s[i] <= 90) s[i]+=32;
    }
    return s;
}
char* toUpper(char* s, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        if(s[i] >= 97 && s[i] <= 122) s[i]-=32;
    }
    return s;
}

char* changeCase(char* s, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        if(s[i] >= 97 && s[i] <= 122) s[i]-=32;
        else if(s[i] >= 65 && s[i] <= 90) s[i]+=32;
    }
    return s;
}
int main()
{
    char s[] = "AnKit";
    char *a = changeCase(s, 5);
    printf("%s\n", a);
    return 0;
}