#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct que
{
    int a;
    struct que* next;
};

typedef struct que queue;
typedef queue* QUEUE;

void initialize(QUEUE *q)
{
    *q = NULL;
}

int size(QUEUE q)
{
    int ct=0;
    QUEUE tail=q;
    while(tail!=NULL)
    {
        ct++;
        tail=tail->next;
    }
    return ct;
}

int isempty(QUEUE q)
{
    return (size(q)==0);
}

void enqueue(QUEUE *q,int t)
{
    QUEUE new;
    new = (QUEUE ) malloc(sizeof(queue));
    if(new==NULL)
    {
        printf("Queue is full.\n");
        return ;
    }
    else
    {
        new->a=t;
        new->next=NULL;
        if(*q==NULL)
            *q=new;
        else{
        QUEUE tail=*q;
        while(tail->next!=NULL)
            tail=tail->next;
        tail->next=new;
        }
    }
}

void dequeue(QUEUE *q)
{
    if(isempty(*q))
    {
        printf("Queue Empty\n");
        return;
    }
    else
    {
        QUEUE temp=*q;
        (*q) = (*q)->next;
        free(temp);
    }
}

int front(QUEUE q)
{
    if(isempty(q)==1)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
        return q->a;
}

void print(QUEUE q)
{
    QUEUE tail=q;
    do 
    {
        printf("%d\n",tail->a);
        tail=tail->next;
    }while (tail!=NULL);
}

int main()
{
    int n;
    scanf("%d",&n);
    QUEUE q1;
    initialize(&q1);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        enqueue(&q1,t);
        // printf("%d ",front(q1));
    }
    dequeue(&q1);
    print(q1);
    return 0;
}