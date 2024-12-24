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
struct Sparse* add(struct Sparse *s1, struct Sparse *s2)
{
    int p = 0, q = 0, k = 0;
    if((s1->m!=s2->m) || (s1->n!=s2->n)) return 0;

    struct Sparse *sum = (struct Sparse *) malloc(sizeof(struct Sparse));
    sum->m = s1->m; sum->n = s1->n; 
    sum->e = (struct element *) malloc((s1->num + s2->num)*sizeof(struct element));

    while(p < s1->num && q < s2->num)
    {
        if(s1->e[p].i < s2->e[p].i) sum->e[k++] = s1->e[p++];
        else if(s1->e[p].i > s2->e[p].i) sum->e[k++] = s2->e[q++];
        else
        {
            if(s1->e[p].j < s2->e[p].j) sum->e[k++] = s1->e[p++];
            else if(s1->e[p].j > s2->e[p].j) sum->e[k++] = s2->e[q++];
            else
            { 
                sum->e[k] = s1->e[p++];
                sum->e[k++].x += s2->e[q++].x;
            }
        }
    }
    for(; p < s1->num; p++) sum->e[k++] = s1->e[p];
    for(; q < s1->num; q++) sum->e[k++] = s2->e[q];
    sum->num = k;
    return sum;
}