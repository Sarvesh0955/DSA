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

int isempty(STACK s)
{
    if(s==NULL)
        return 0;
    return 1;
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
        int flag=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='a' && s[i]<='z')
                printf("%c",s[i]);
            else
            {
                if(s[i]=='(')
                    flag++;
                if(flag>0)
                {
                    if(s[i]==')')
                    {
                        while(s[peaklink(&sl)]!='(')
                            printf("%c",s[poplink(&sl)]);
                        int z = poplink(&sl);
                        flag--;
                    }
                    else
                        pushlink(&sl,i);
                }
                else
                {
                    if(s[i]=='*' || s[i]=='/')
                    {
                        if(isempty(sl))
                        if(s[peaklink(&sl)]=='*' || s[peaklink(&sl)]=='/')
                        printf("%c",s[poplink(&sl)]);
                        pushlink(&sl,i);
                    }
                    else
                    {
                        while(isempty(sl)!=0)
                            printf("%c",s[poplink(&sl)]);
                        if(s[i]!='\n')
                        pushlink(&sl,i);
                    }
                }
            }
        }
        while(isempty(sl)!=0)
            printf("%c",s[poplink(&sl)]);
        printf("\n");
    }
    return 0;
}