#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct element
{
    int i;
    int j;
    int x;
};
struct Sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};

void create(struct Sparse *s)
{
    printf("Enter the Dimensions: ");
    scanf("%d %d", &s->m, &s->n);
    printf("Total Number of non-Zero Elements: ");
    scanf("%d",&s->num);
    s->e = (struct element*)malloc(s->num*sizeof((struct element)));
    printf("Enter Non-Zero Elements:-\n ");
    for(int i = 0; i<s->num; i++)
    {
        printf("Enter row no.: ");
        scanf("%d", &(s->e[i].i));
        printf("Enter column no.: ");
        scanf("%d", &(s->e[i].j));
        printf("Enter value: ");
        scanf("%d", &(s->e[i].x));
    }
}
void display(struct Sparse s)
{
    for (int i = 0; i < s.m; i++)
    {
        for (int i = 0; i < s.n; i++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
            {
                printf("%d ", s.ele[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
        
    }
    
}