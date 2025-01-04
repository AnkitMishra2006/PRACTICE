#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Stack
{
    int size;
    int top;
    int *s;
} Stack;

void create(Stack *st)
{
    printf("Enter the size of Stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}
void display(Stack st)
{
    int i;
    for (int i = 0; i <= st.top; i++)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

int pop(Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->s[st->top--];
    }
    return x;
}
void push(Stack *st, int value)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = value;
    }
}
int peek(Stack st, int pos)
{
    int x = -1;
    if ((st.top - pos + 1) < 0)
        printf("Invalid index\n");
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}
bool isEmpty(Stack st)
{
    if (st.top == -1)
        return true;
    return false;
}
bool isFull(Stack st)
{
    if (st.top == st.size - 1)
        return true;
    return false;
}
int stackTop(Stack st)
{
    if (!isEmpty(st))
        return st.s[st.top];
    return false;
}
int main()
{
    Stack st;
    create(&st);
    push(&st, 5);
    push(&st, 6);
    push(&st, 1);
    push(&st, 9);
    push(&st, 8);
    display(st);
    printf("Element at pos 1: %d", peek(st, 1));
    printf("\nPopped Item: %d\n", pop(&st));
    display(st);
    printf("Element at pos 1: %d", peek(st, 1));
    return 0;
}