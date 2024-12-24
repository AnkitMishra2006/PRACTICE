#include<stdio.h>
#include<stdlib.h>

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
    s->e = (struct element*)malloc((s->num) * sizeof(struct element));
    printf("Enter Non-Zero Elements:-\n ");
    for(int k = 0; k<s->num; k++)
    {
        printf("Enter row no.: ");
        scanf("%d", &(s->e[k].i));
        printf("Enter column no.: ");
        scanf("%d", &(s->e[k].j));
        printf("Enter value: ");
        scanf("%d", &(s->e[k].x));
    }
}
void display(struct Sparse s)
{
    int i, j, k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if(i==s.e[k].i && j==s.e[k].j)
            {
                printf("%d ", s.e[k++].x);
            }
            else{
                printf("0 ");
            } 
        }
        printf("\n");
        
    }
    
}