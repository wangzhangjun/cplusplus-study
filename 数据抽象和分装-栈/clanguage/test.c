#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <asser.h>

typedef struct Link
{
    int data;
    struct Link *next;
} Link;

typedef struct Stack {
    Link * head;
    int size; 
}Stack;

void initStack(Stack *stack)
{
    stack->head = NULL;
    stack->size = 0;
}

void pushStack(Stack *stack, const int data)
{
    Link *node = (Link *)malloc(sizeof(Link));
    assert(node != NULL);
    node->data = data;
    node->next = stack->head;
    stack->head = node;
    stack->size++;
}

void popStack(Stack *stack, int *data)
{
    if(stack->size == 0) {
        return ;
    }
    Link *tmp = stack->head;
    *data = stack->head->data;
    stack->head = stack->head->next;
    free(tmp);
    --stack->size;
}

void cleanStack(Stack *stack)
{
    while (stack->head != NULL)
    {
        Link *tmp = stack->head;
        stack->head = stack->head->next;
        free(tmp);
    }
    stack->size = 0;
}

int main()
{
    Stack stack;
    initStack(&stack);
    for(int i = 0; i < 5; i++) {
        pushStack(&stack, i);
    }
    int tmp;
    while(stack.size > 0) {
        popStack(&stack, &tmp);
        printf("%d\n", tmp);
    }
    return 0;
}