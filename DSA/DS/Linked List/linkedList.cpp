#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

class LinkedList
{
    Node* first = NULL;
    Node* last = NULL;
    int length;
    
public:

    LinkedList()
    {
        length = 0;
    }
    LinkedList(int a[], int n)
    {
        Node* t;
        first = new Node;
        first->data = a[0];
        first->next = NULL;
        last = first;
        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = a[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
        length = n;
    }

    void display();
};

void LinkedList::display()
{
    Node *p = first;
    while(p)
    {
        cout<< p->data;
        p = p->next;
    }
}