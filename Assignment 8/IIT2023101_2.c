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
    tail->prev=NULL;
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

void printrev(LINK head)
{
    LINK tail=head;
    while(tail->next!=NULL)
        tail=tail->next;
    do 
    {
        printf("%d\n",tail->a);
        tail=tail->prev;
    }while (tail!=NULL);
}

LINK addnode(LINK head,int pos)
{
    LINK tail=head;
    LINK new=(LINK)malloc(sizeof(ELEMENT));
    scanf("%d",&new->a);
    
    if(pos==1)
    {
        new->next=tail;
        new->prev = NULL;
        head->prev = new;
        return new;
    }
    else
    {
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

LINK delete(LINK head,int pos)
{
    LINK tail=head;
    if(pos==1)
    {
        head = head->next;
        head->prev = NULL;
        free(tail);
        return head;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        tail=tail->next;
        LINK temp=tail->next->next;
        if(temp!=NULL)
        {
            temp->prev = tail;
            tail->next=temp;
        }
        else
        free(tail->next);
        return head;
    }
}

int search(LINK head,int k)
{
    LINK tail = head;
    int ct=1;
    while (tail!=NULL)
    {
        if(tail->a == k)
            break;
        else
            ct++;
        tail=tail->next;
    }
    return ct;
}

int dist(LINK head,int a,int b)
{
    int p1=search(head,a);
    int p2=search(head,b);

    int d = p2 - p1 + 1;
    if(d<0) d*=-1;
    return d;
}

int main()
{
    int n;
    scanf("%d",&n);
    LINK head = scan(n);
    print(head);
    printf("\n");

    int pos;
    scanf("%d",&pos);
    head = addnode(head,pos);
    print(head);
    printf("\n");
    printrev(head);
    printf("\n");

    scanf("%d",&pos);
    head = delete(head,pos);
    print(head);
    printf("\n");
    printrev(head);
    printf("\n");

    int a,b;
    scanf("%d %d",&a,&b);
    printf("dist btw a,b: %d",dist(head,a,b)-2);

    return 0;
}