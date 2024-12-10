#include<stdio.h>

void VCcount(char s[], int length)
{
    int i, vcount = 0, ccount = 0;
    for(i = 0; i < length; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            vcount++;
        }
        else if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            ccount++;
        }
    }
    printf("Vowels Count: %d\nConsonants Count: %d", vcount, ccount);
}

int main()
{
    char s[] = "How Are You";
    VCcount(s, 11);
    return 0;
}