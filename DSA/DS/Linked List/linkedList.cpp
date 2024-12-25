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
    int sum();
    int max(); 
    int count();
    int getCount();
    Node * search(int key);
};

void LinkedList::display()
{
    Node *p = first;
    while(p)
    {
        cout<< p->data<<" ";
        p = p->next;
    }
}
int LinkedList::sum()
{
    Node* p = first;
    int sum = 0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int LinkedList::max()
{
    Node* p = first;
    int max = p->data;
    p = p->next;
    while(p)
    {
        if(p->data > max) max = p->data;
        p = p->next;
    }
    return max;
}
int LinkedList::count()
{
    Node* p = first;
    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }
    length = count;
    return length;
}
int LinkedList::getCount()
{
    return length;
}
Node* LinkedList::search(int key)
{
    Node* p = first;
    while(p)
    {
        if(key == p->data) return p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    int a[5] = {9,5,7,3,1};
    LinkedList l(a, 5);
    l.display();
    cout<<endl<<l.count();
    return 0;
}