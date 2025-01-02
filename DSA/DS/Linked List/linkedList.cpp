#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

class LinkedList
{
    Node *first = NULL;
    Node *last = NULL;
    int length;

public:
    LinkedList()
    {
        length = 0;
    }
    LinkedList(Node *head)
    {
        first = head;
        length = this->count();
    }
    LinkedList(int a[], int n)
    {
        Node *t;
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
    Node *search(int key);
    Node *MTHsearch(int key); // Better Linear Search Using Move to head avoid transposition as we dont want to move data in a LL but nodes
    void insert(int pos, int value);
    void insertLast(int value);
    void removeDuplicates();
    void reverse();
    void concat(LinkedList l1);
    friend Node *merge(LinkedList l1, LinkedList l2);
};

void LinkedList::display()
{
    Node *p = first;
    while (p)
    {
        cout << "[" << p->data << "," << p->next << "]";
        if (p->next)
            cout << " -> ";
        p = p->next;
    }
    cout << endl;
}
int LinkedList::sum()
{
    Node *p = first;
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int LinkedList::max()
{
    Node *p = first;
    int max = p->data;
    p = p->next;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int LinkedList::count()
{
    Node *p = first;
    int count = 0;
    while (p)
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
Node *LinkedList::search(int key)
{
    Node *p = first;
    while (p)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

Node *LinkedList::MTHsearch(int key)
{
    Node *p = first;
    Node *q = NULL;
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            last = q;
            return first;
        };
        q = p;
        p = p->next;
    }
    return NULL;
}

void LinkedList::insert(int pos, int value)
{
    Node *t = new Node;
    t->data = value;
    Node *p = first;
    if (pos == 0)
    {
        t->next = first;
        first = t;
        if (!last)
            last = t;
        length++;
    }
    else if (pos > 0)
    {
        int i;
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t->next = p->next;
            p->next = t;
            if (p == last)
                last = t;
        }
        length++;
    }
    else
        cout << "Invalid Position";
}
void LinkedList::insertLast(int value)
{
    Node *t = new Node;
    t->data = value;
    t->next = NULL;
    if (first == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
    length++;
}

void LinkedList::removeDuplicates()
{
    Node *p = first;
    Node *q = first->next;

    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}
void LinkedList::reverse()
{
    Node *p = first;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void LinkedList::concat(LinkedList l)
{
    Node *p = this->first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = l.first;
    l.first = NULL;
}

Node *merge(LinkedList l1, LinkedList l2)
{
    Node *third = NULL;
    Node *last = third;
    Node *first = l1.first;
    Node *second = l2.first;
    if (first->data <= second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    while (first && second)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if (first)
    {
        last->next = first;
    }
    else
    {
        last->next = second;
    }
    return third;
}

int main()
{
    int a[4] = {2, 8, 10, 15};
    LinkedList l1(a, 4);
    int b[4] = {4, 7, 12, 14};
    LinkedList l2(b, 4);
    l1.display();
    l2.display();
    LinkedList l3(merge(l1, l2));
    l3.display();
    return 0;
}