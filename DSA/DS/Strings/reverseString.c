#include<stdio.h>
#include<stdlib.h>

char* reverse(char s[])
{
    int i,j;
    for(i = 0; s[i] != '\0'; i++){}
    char* t = (char *) malloc((i+1)*sizeof(char));
    i = i-1;
    for(j = 0; i >= 0; j++,i--)
    {
        t[j] = s[i];
    }
    t[j] = '\0';
    return t;
}

int main()
{
    char s[] = "Python";
    char* t = reverse(s);
    printf("%s", t);
    return 0;
}