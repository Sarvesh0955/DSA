#include <stdio.h>
#include <stdlib.h>

// constant amount at which stack is increased
#define BOUND 4

// top of the stack
int top = -1;

// length of stack
int length = 0;

// function to create new stack
int* create_new(int* a)
{
    // allocate memory for new stack
    int* new_a = (int*)malloc((length + BOUND) * sizeof(int));

    // copying the content of old stack
    for (int i = 0; i < length; i++)
        new_a[i] = a[i];

    // re-sizing the length
    length += BOUND;
    return new_a;
}

// function to push new element
int* push(int* a, int element)
{
    // if stack is full, create new one
    if (top == length - 1)
        a = create_new(a);

    // insert element at top of the stack
    a[++top] = element;
    return a;
}

// function to pop an element
void pop(int* a)
{
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    top--;
}

// function to display
void display(int* a)
{
    // if top is less than 0, that means stack is empty
    if (top < 0)
        printf("Stack is Empty\n");
    else {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
}

int main()
{
    int* a = create_new(a);

    // pushing element to top of stack
    a = push(a, 1);
    a = push(a, 2);
    a = push(a, 3);
    a = push(a, 4);
    display(a);

    // pushing more element when stack is full
    a = push(a, 5);
    a = push(a, 6);
    display(a);

    a = push(a, 7);
    a = push(a, 8);
    display(a);

    // pushing more element so that stack can grow
    a = push(a, 9);
    display(a);

    // free memory allocated for stack
    free(a);

    return 0;
}
