#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAXSIZE 100

struct lifo
{
    int st[MAXSIZE];
    int t;
};

typedef struct lifo stack;
typedef stack* STACK;

STACK new()
{
    STACK new=(STACK ) malloc(sizeof(stack));
    new->t = -1;
    return new;
}

void push(STACK s,int n)
{
    s->t++;
    if(s->t==MAXSIZE)
    {
        printf("Stack Overflow.\n");
        return;
    }
    s->st[s->t]=n;
}

int pop(STACK s)
{
    if(s->t==-1)
    {
        printf("Stack Underflow.\n");
        return -1;
    }
    int a=s->st[s->t];
    s->t--;
    return a;
}

int peak(STACK s)
{
    return s->st[s->t];
}


int main()
{
    STACK s;
    s = new();
    push(s,1);push(s,2);
    printf("%d\n",pop(s));
    printf("%d\n",peak(s));
    return 0;
}