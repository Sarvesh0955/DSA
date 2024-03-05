#include<stdio.h>
#include<stdlib.h>

struct list
{
    int a;
    struct list* next;
    struct list* prev;
};

typedef struct list ELEMENT;
typedef ELEMENT* LINK;

LINK scan(int n)
{
    LINK head = (LINK) malloc(sizeof(ELEMENT));
    LINK tail = head;
    LINK pr = head;
    scanf("%d",&head->a);
    for(int i=1;i<n;i++)
    {
        pr = tail;
        tail->next=(LINK)malloc(sizeof(ELEMENT)*n);
        tail=tail->next;
        tail->prev=pr;
        scanf("%d",&tail->a);
    }
    tail->next = head;
    head->prev = tail;
    return head;
}

void print(LINK head)
{
    LINK tail=head;
    do 
    {
        printf("%d\n",tail->a);
        tail=tail->next;
    }while (tail!=head);
}

LINK addnode(LINK head,int pos)
{
    LINK tail = head;
    LINK new=(LINK)malloc(sizeof(ELEMENT));
    if(pos==1)
    {
        int t;
        scanf("%d",&t);
        new->a = head->a;
        head->a = t;
        LINK temp = head->next;
        head->next = new;
        new->next = temp;
        temp->prev = new;
        new->prev = head;
        return head;
    }
    else
    {
        scanf("%d",&new->a);
        for(int i=1;i<pos-1;i++)
        tail = tail->next;
        LINK temp = tail->next;
        tail->next = new;
        new->prev = tail;
        if(temp==NULL)
        new->next=NULL;
        else
        {
            new->next = temp;
            temp->prev = new;
        }
        return head;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    LINK head = scan(n);
    print(head);
    printf("\n");

    int m;
    scanf("%d",&m);
    head = addnode(head,m);
    print(head);
    printf("\n");

    return 0;
}