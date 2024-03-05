#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct lifolink
{
    int value;
    struct lifolink *next;
};

typedef struct lifolink stacklink;
typedef stacklink* STACK;

void newlink(STACK *s)
{
    *s=NULL;
}

void pushlink(STACK *s,int n)
{
    STACK new;
    new=(STACK ) malloc(sizeof(stacklink));
    if(new==NULL)
    {
        printf("Stack Overflow.\n");
            return ;
    }

    new->value=n;
    new->next= *s;
    *s=new;
}

int poplink(STACK *s)
{
    int t; 
    STACK p;
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

int peaklink(STACK *s)
{
    if(*s==NULL)
    {
        printf("Stack Underflow.\n");
            return -1;
    }
    else
        return (*s)->value;
}

int main()
{
    STACK sl;
    newlink(&sl);
    pushlink(&sl,1);pushlink(&sl,2);
    pushlink(&sl,3);pushlink(&sl,4);
    printf("%d\n",poplink(&sl));
    printf("%d\n",peaklink(&sl));
    return 0;
}