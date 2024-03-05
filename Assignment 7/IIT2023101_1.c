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

void new(stack *s)
{
    s->t = -1;
}

void push(stack *s,int n)
{
    s->t++;
    if(s->t==MAXSIZE)
    {
        printf("Stack Overflow.\n");
        return;
    }
    s->st[s->t]=n;
}

int pop(stack *s)
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

void peak(stack *s)
{
    printf("%d\n",s->st[s->t]);
}

struct lifolink
{
    int value;
    struct lifolink *next;
};

typedef struct lifolink stacklink;

void newlink(stacklink **s)
{
    *s=NULL;
}

void pushlink(stacklink **s,int n)
{
    stacklink *new;
    new=(stacklink *) malloc(sizeof(stacklink));
    if(new==NULL)
    {
        printf("Stack Overflow.\n");
         return ;
    }

    new->value=n;
    new->next= *s;
    *s=new;
}

int poplink(stacklink **s)
{
    int t; 
    stacklink *p;
    if(*s==NULL)
    {
        printf("Stack Underflow.\n");
         return -1;
    }
    else
    {
        t=(*s)->value;
        p=*s;
        *s=(*s)->next;
        free(p);
        return t;
    }
}

void peaklink(stacklink **s)
{
    if(*s==NULL)
    {
        printf("Stack Underflow.\n");
         return ;
    }
    else
        printf("%d\n",(*s)->value);
}

int main()
{
    stack s;
    new(&s);
    stacklink *sl;
    newlink(&sl);
    push(&s,1);push(&s,2);
    pushlink(&sl,1);pushlink(&sl,2);
    pop(&s);
    poplink(&sl);
    peak(&s);
    peaklink(&sl);
    return 0;
}