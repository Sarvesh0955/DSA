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

struct deq
{
    LINK header;
    LINK footer;
};

typedef struct deq dequeue;
typedef dequeue* DEQUEUE;

void initialize(DEQUEUE *dq)
{
    DEQUEUE new;
    new = (DEQUEUE ) malloc(sizeof(dequeue));
    new->header=(LINK ) malloc(sizeof(ELEMENT));
    new->footer=(LINK ) malloc(sizeof(ELEMENT));
    new->header->next =new->footer;
    new->footer->prev =new->header;
    new->header->prev =NULL;
    new->footer->prev =NULL;
    (*dq) = new;
}

void addfront(DEQUEUE *dq,int t)
{
    LINK new;
    new = (LINK ) malloc(sizeof(ELEMENT));
    new->a = t;
    if((*dq)->header->next == (*dq)->footer)
    {
        (*dq)->header->next = new;
        new->next = (*dq)->footer;
        (*dq)->footer->prev = new;
        new->prev = (*dq)->header;
    }
    else
    {
        LINK temp = (*dq)->header->next;
        (*dq)->header->next = new;
        new->next = temp;
        temp->prev = new;
        new->prev = (*dq)->header;
    }
}

void removefront(DEQUEUE *dq)
{
    if((*dq)->header->next == (*dq)->footer)
        printf("Dequeue is empty.\n");
    else
    {
        LINK temp = (*dq)->header->next;
        (*dq)->header->next = temp->next;
        temp->next->prev = (*dq)->header;
        free(temp);
    }
}

void addback(DEQUEUE *dq,int t)
{
    LINK new;
    new = (LINK ) malloc(sizeof(ELEMENT));
    new->a = t;
    if((*dq)->footer->prev == (*dq)->header)
    {
        (*dq)->header->next = new;
        new->next = (*dq)->footer;
        (*dq)->footer->prev = new;
        new->prev = (*dq)->header;
    }
    else
    {
        LINK temp = (*dq)->footer->prev;
        new->next = (*dq)->footer;
        temp->next = new;
        (*dq)->footer->prev = new;
        new->prev = temp;
    }
}

void removeback(DEQUEUE *dq)
{
    if((*dq)->footer->prev == (*dq)->header)
        printf("Dequeue is empty.\n");
    else
    {
        LINK temp = (*dq)->footer->prev;
        (*dq)->footer->prev = temp->prev;
        temp->prev->next = (*dq)->footer;
        free(temp);
    }
}

void print(DEQUEUE dq)
{
    LINK tail=dq->header->next;
    while(tail!=dq->footer) 
    {
        printf("%d\n",tail->a);
        tail=tail->next;
    }
    return ;
}

int first(DEQUEUE dq)
{
    if(dq->header->next == dq->footer)
    {
        printf("Dequeue is empty.\n");
        return 0;
    }
    else
        return dq->header->next->a;
}

int last(DEQUEUE dq)
{
    if(dq->footer->prev == dq->header)
    {
        printf("Dequeue is empty.\n");
        return 0;
    }
    else
        return dq->footer->prev->a;
}

int main()
{
    DEQUEUE dq;
    initialize(&dq);
    addfront(&dq,1);
    addfront(&dq,2);
    addfront(&dq,3);
    addfront(&dq,5);
    addback(&dq,9);
    addback(&dq,8);
    addback(&dq,7);
    addback(&dq,6);
    print(dq);
    printf("\n");
    removefront(&dq);
    removeback(&dq);
    print(dq);
    return 0;
}