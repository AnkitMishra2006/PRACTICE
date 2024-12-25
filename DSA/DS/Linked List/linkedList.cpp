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
    Node* MTHsearch(int key); //Better Linear Search Using Move to head avoid transposition as we dont want to move data in a LL but nodes
    void insert(int pos, int value);
};

void LinkedList::display()
{
    Node *p = first;
    while(p)
    {
        cout<<"["<<p->data<<","<<p->next<<"]";
        if(p->next) cout<<" -> ";
        p = p->next;
    }
    cout<<endl;
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

Node* LinkedList::MTHsearch(int key)
{
    Node* p = first;
    Node* q = NULL;
    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return first;
        };
        q = p;
        p = p->next;
    }
    return NULL;
}

void LinkedList::insert(int pos, int value)
{
    Node* t = new Node;
    t->data = value;
    Node* p = first;
    if(pos == 0)
    {
        t->next = first;
        first = t;
        length++;
    }
    else if(pos > 0)
    {
        int i;
        for(i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        if(p)
        {
            t->next = p->next;
            p->next = t;
        }
        length++;
    }
    else cout<<"Invalid Position";
}
int main()
{
    // int a[5] = {9,5,7,3,1};
    // LinkedList l(a, 5);
    LinkedList l;
    l.display();
    cout<<l.getCount()<<endl;
    l.insert(0,4);
    l.insert(1,2);
    l.insert(2,5);
    l.display();
    cout<<l.getCount();
    return 0;
}