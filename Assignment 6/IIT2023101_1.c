#include<stdio.h>

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
    head->a=rand() % 100;
    for(int i=1;i<n;i++)
    {
        tail->next=(LINK)malloc(sizeof(ELEMENT));
        tail=tail->next;
        tail->a=rand()%100;
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

LINK addnode(LINK head,int pos)
{
    LINK tail=head;
    LINK new=(LINK)malloc(sizeof(ELEMENT));
    new->a=rand()%100;
    
    if(pos==1)
    {
        new->next=tail;
        return new;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        tail=tail->next;
        LINK temp=tail->next;
        tail->next=new;
        if(temp==NULL)
        new->next=NULL;
        else
        new->next=temp;
        return head;
    }
}

LINK delete(LINK head,int pos)
{
    LINK tail=head;
    if(pos==1)
    {
        LINK temp=tail->next;
        free(tail);
        return temp;
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        tail=tail->next;
        LINK temp=tail->next->next;
        free(tail->next);
        if(temp!=NULL)
        tail->next=temp;
        else
        tail->next=NULL;
        return head;
    }
}

void search(LINK head,int k)
{
    LINK tail=head;
    do 
    {
        if(tail->a==k)
        {
            printf("Found element\n");
            return;
        }
        tail=tail->next;
    }while (tail!=NULL);
    printf("Not found\n");
    return;
}

double average(LINK head)
{
    int sum=0,ct=0;
    LINK tail=head;
    do 
    {
        sum+=tail->a;ct++;
        tail=tail->next;
    }while (tail!=NULL);
    double avg=(sum*1.0)/ct;
    return avg;
}
int main()
{
    int n=10;
    printf("Enter number of element: ");
    scanf("%d",&n);
    LINK head=input(n);
    print(head);

    printf("\nEnter position to add element: ");
    scanf("%d",&n);
    head=addnode(head,n);
    print(head);

    printf("\nEnter position to delete element: ");
    scanf("%d",&n);
    head=delete(head,n);
    print(head);

    printf("\nEnter element to search: ");
    scanf("%d",&n);
    search(head,n);
    
    double avg=average(head);
    printf("\n Average of linked list is: %f",avg);
    return 0;
}