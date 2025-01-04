#include <stdio.h>
#include <stdlib.h>

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
    for (int i = st.top; i < 0; i--)
    {
        printf("\n%d", st.s[i]);
    }
    printf("\n");
}

int pop(Stack *st)
{
    int x = NULL;
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
int main()
{
    return 0;
}