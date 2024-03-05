#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct lifoSTACK
{
    int value;
    struct lifoSTACK *next;
};

typedef struct lifoSTACK stackSTACK;
typedef stackSTACK* STACK;

STACK newSTACK()
{
    return NULL;
}

STACK pushSTACK(STACK s,int n)
{
    STACK new;
    new=(STACK ) malloc(sizeof(stackSTACK));
    if(new==NULL)
    {
        printf("Stack Overflow.\n");
         return s;
    }
    new->value=n;
    new->next= s;
    return new;
}

STACK popSTACK(STACK s)
{ 
    STACK p;
    if(s==NULL)
    {
        printf("Stack Underflow.\n");
            return s;
    }
    else
    {
        p=s;
        s=s->next;
        free(p);
        return s;
    }
}

int peakSTACK(STACK s)
{
    if(s==NULL)
    {
        printf("Stack Underflow.\n");
         return -1;
    }
    else
        return s->value;
}

void print(STACK head)
{
    STACK tail=head;
    do 
    {
        printf("%d\n",tail->value);
        tail=tail->next;
    }while (tail!=NULL);
}

int main()
{
    STACK sl;
    sl = newSTACK();
    sl = pushSTACK(sl,1);
    sl = pushSTACK(sl,2);
    sl = pushSTACK(sl,3);
    sl = pushSTACK(sl,4);
    print(sl);
    printf("\n");
    sl = popSTACK(sl);
    printf("%d",peakSTACK(sl));
    return 0;
}