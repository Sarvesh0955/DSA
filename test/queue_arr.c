#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct que
{
    int a[MAX];
    int l;
    int r;
};

typedef struct que queue;
typedef queue* QUEUE;

QUEUE initialize()
{
    QUEUE new;
    new = (QUEUE ) malloc(sizeof(queue));
    new->l=0;new->r=0;
    return new;
}

int size(QUEUE q)
{
    return (q->r-q->l+MAX)%MAX;
}

int isempty(QUEUE q)
{
    return (q->l==q->r);
}

void enqueue(QUEUE q,int t)
{
    if(size(q)==MAX-1)
    {
        printf("Queue is full");
        return;
    }
    else
    {
        q->a[q->r]=t;
        q->r = (q->r+1)%MAX;
    }
}

void dequeue(QUEUE q)
{
    if(isempty(q))
    {
        printf("Queue Empty\n");
        return;
    }
    else
        q->r--;
}

int front(QUEUE q)
{
    if(isempty(q)==1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
        return q->a[q->l];
}

int main()
{
    QUEUE q1;
    q1 = initialize();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        enqueue(q1,t);
        printf("%d ",front(q1));
        // dequeue(q1);
    }
    return 0;
}