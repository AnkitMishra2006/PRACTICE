#include<stdio.h>

// Assuming correspondance cases will be same
void compareStrings(char s[], char a[])
{
    int i = 0;
    while(s[i] != '\0' && a[i] != '\0')
    {
        if(s[i] != a[i]) break;
        i++;
    }
    if(s[i] == a[i]) printf("Both Strings are Equal\n");
    else if(s[i] < a[i]) printf("First String is smaller and second larger in terms of character\n");
    else if(s[i] > a[i]) printf("First String is larger and second second smaller in terms of character\n");
}
int main()
{
    char s[] = "Ankit";
    char a[] = "Ankesh";
    compareStrings(s,a);
    return 0;
}