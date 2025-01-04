#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int top;
    int *s;
} Stack;

void create(Stack * st)
{
    printf("Enter the size of Stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int*) malloc(st->size * sizeof(int));

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

int main()
{

    return 0;
}