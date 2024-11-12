#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void display(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ", p->data);
        display(p->next);
    }
}