#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct stack 
{
    int items[MAX_SIZE];
    int top;
};

void new(struct stack *s) 
{
    s->top = -1;
}

int is_empty(struct stack *s) {
    return s->top == -1;
}

int is_full(struct stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct stack *s, int item) {
    if (is_full(s)) {
        printf("stack Overflow\n");
        return;
    }
    s->top++;
    s->items[s->top] = item;
}

int pop(struct stack *s) {
    if (is_empty(s)) {
        printf("stack Underflow\n");
        return -1;
    }
    int item = s->items[s->top];
    s->top--;
    return item;
}

int peek(struct stack *s) {
    if (is_empty(s)) {
        printf("stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}

void great(struct stack *s, int val)
{
    int a[MAX_SIZE],k=0;
    while (!is_empty(s)) 
    {
        int item = pop(s);
        if (item <= val) 
        {
            a[k]=item;
            k++;
        }
    }

    for(int i=0;i<k;i++)
        push(s,a[i]);
}

void duplicate(struct stack *s) {
    struct stack temp;
    new(&temp);

    int hsh[MAX_SIZE] = {0}; 

    while (!is_empty(s)) {
        int item = pop(s);
        if (!hsh[item]) {
            push(&temp, item);
            hsh[item] = 1; 
        }
    }

    while (!is_empty(&temp)) {
        push(s, pop(&temp));
    }
}

void display(struct stack *s) {
    if (is_empty(s)) {
        printf("stack is empty\n");
    } else {
        printf("stack contents:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);
        }
    }
}

int main() {
    struct stack stack;
    struct stack stack2;
    new(&stack);
    new(&stack2);
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int item;
        scanf("%d", &item);
        push(&stack, item);
        push(&stack2, item);
    }

    scanf("%d", &val);
    great(&stack, val);
    printf("%d ", val);
    display(&stack);

    duplicate(&stack2);
    display(&stack2);

    return 0;
}