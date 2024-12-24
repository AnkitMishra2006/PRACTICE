#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Term
{
    int coeff;
    int exp;
};
struct Poly
{
    int n;
    struct Term* t;
};

struct Poly* create(int n)
{
    if(n == 0) return 0;
    int i;
    struct Poly p;
    p.n = n;
    p.t = (struct Term*) malloc(n * sizeof(struct Term));
    for(i = 0; i < p.n; i++)
    {
        printf("Enter the values for term %d\nCoefficient and Exponent respectively: ", i+1);
        scanf("%d %d", &p.t[i].coeff, &p.t[i].exp);
    }
    return &p;
}

float eval(struct Poly p, float x)
{
    int i;
    float res;
    for(i = 0; i < p.n; i++)
    {
        res += p.t[i].coeff * pow(x, p.t[i].exp);
    }
    return res;
}

struct poly* add(struct Poly p1, struct Poly p2)
{
    int i=0,j=0,k=0;
    struct Poly* p3 = (struct Poly*) malloc(sizeof(struct Poly));

    p3->n = p1.n + p2.n;

    p3->t = (struct Term*) malloc(p3->n*sizeof(struct Term));

    while(i < p1.n && j < p2.n)
    {
        if(p1.t[i].exp > p2.t[j].exp) p3->t[k++] = p1.t[i++];
        else if(p1.t[i].exp < p2.t[j].exp) p3->t[k++] = p2.t[j++];
        else
        {
            p3->t[k] = p1.t[i++];
            p3->t[k++].coeff += p2.t[j++].coeff;
        }
    }
    for (; i < p1.n; i++) p3->t[k++] = p1.t[i];
    for (; j < p2.n; j++) p3->t[k++] = p2.t[j];
    p3->n = k;
    return p3;
}