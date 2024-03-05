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
    int t;
    scanf("%d",&t);scanf(" ");
    while(t--)
    {
        STACK sl;
        newlink(&sl);
        char s[401];
        fgets(s,400,stdin);
        
        // printf("%d",strlen(s));
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='a' && s[i]<='z')
                printf("%c",s[i]);
            else
            {
                pushlink(&sl,i);
                if(s[peaklink(&sl)]==')')
                {
                    int z = poplink(&sl);
                    while(s[peaklink(&sl)]!='(')
                    {
                        printf("%c",s[poplink(&sl)]);
                    }
                    z = poplink(&sl);
                }
            }
        }
        printf("\n");
    }
    return 0;
}