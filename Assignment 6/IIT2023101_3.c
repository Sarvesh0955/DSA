#include<stdio.h>
#include<stdlib.h>

struct list
{
    int a;
    struct list* next;
};
typedef struct list ELEMENT;
typedef ELEMENT* LINK;

LINK input(int n)
{
    LINK head=(LINK)malloc(sizeof(ELEMENT));
    LINK tail=head;
    scanf("%d",&tail->a);
    for(int i=1;i<n;i++)
    {
        tail->next=(LINK)malloc(sizeof(ELEMENT));
        tail=tail->next;
        scanf("%d",&tail->a);
    }
    tail->next = NULL;
    return head;
}

void print(LINK head)
{
    LINK tail=head;
    do 
    {
        printf("%d\n",tail->a);
        tail=tail->next;
    }while (tail!=NULL);
}

LINK func(LINK head1,LINK head2)
{
    LINK tail1=head1;

    LINK new=(LINK)malloc(sizeof(ELEMENT));
    LINK tail=new,prev;
    do
    {
        LINK tail2=head2;
        int ct=0;
        do
        {
            if(tail1->a==tail2->a)
            {
                ct++;
                break;
            }
            tail2=tail2->next;
        }while(tail2!=NULL);
        if(ct==0)
        {
            tail->a=tail1->a;
            tail->next=(LINK)malloc(sizeof(ELEMENT));
            prev=tail;
            tail=tail->next;
        }    
        tail1=tail1->next;
    }while(tail1!=NULL);

    LINK tail2=head2;
    do
    {
        LINK tail1=head1;
        int ct=0;
        do
        {
            if(tail1->a==tail2->a)
            {
                ct++;
                break;
            }
            tail1=tail1->next;
        }while(tail1!=NULL);
        if(ct==0)
        {
            tail->a=tail2->a;
            tail->next=(LINK)malloc(sizeof(ELEMENT));
            prev=tail;
            tail=tail->next;
        }    
        tail2=tail2->next;
    }while(tail2!=NULL);
    free(prev->next);
    prev->next=NULL;
    return new;
}

int main()
{
    int n;
    printf("Enter number of element in list 1: ");
    scanf("%d",&n);
    printf("Enter list 1 elements: \n");
    LINK head1=input(n);
    print(head1);

    printf("Enter number of element in list 2: ");
    scanf("%d",&n);
    printf("Enter list 2 elements: \n");
    LINK head2=input(n);
    print(head2);

    LINK uncomm= func(head1,head2);
    printf("Linked list with uncommon elements is: \n");
    print(uncomm);
}