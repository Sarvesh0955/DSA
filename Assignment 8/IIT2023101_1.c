#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct list
{
    int data;
    struct list *next;
};

struct queue
{
    struct list *next;
    struct list *prev;
};

struct list *createl(int val)
{
    struct list *list = (struct list *)malloc(sizeof(struct list));
    list->data = val;
    list->next = NULL;
    return list;
}

struct queue *createq()
{
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    queue->next = NULL;
    queue->prev = NULL;
    return queue;
}

void enqueue(struct queue *q, int val)
{
    struct list *temp = createl(val);
    if (q->prev == NULL)
    {
        q->prev = q->next = temp;
        return;
    }

    q->prev->next = temp;
    q->prev = temp;
}

void dequeue(struct queue *q)
{
    if (q->next == NULL)
        return;
    struct list *temp = q->next;
    q->next = q->next->next;
    if (q->next == NULL)
    {
        q->prev = NULL;
    }
    free(temp);
}

int size(struct queue *queue)
{
    if (queue->next == NULL)
        return 0;
    int i = 1;
    struct list *temp = queue->next;
    while (temp != queue->prev)
    {
        i++;
        temp = temp->next;
    }

    return i;
}

void display(struct queue *queue)
{
    if (queue->next == NULL)
        return;
    int i = 1;
    struct list *temp = queue->next;
    while (1)
    {
        printf("%d:Flight number: %d\n", i, temp->data);
        i++;
        temp = temp->next;
        if (temp == queue->prev)
            break;
        if (i > size(queue))
            break;
    }
}

void search(struct queue *queue, int pos)
{
    int i = 1;
    struct list *temp = queue->next;
    while (temp != NULL && temp->data != pos)
    {
        temp = temp->next;
        i++;
    }
    if (temp != NULL && temp->data == pos)
        printf("%d\n", i);
    else
        printf("Not present.\n");
}

int main()
{
    int test;
    scanf("%d", &test);
    while (test--)
    {
        int n;
        scanf("%d", &n);
        struct queue *queue = createq();

        for (int i = 0; i < n; i++)
        {
            int k;
            scanf("%d", &k);
            if (k == 1)
            {
                int val;
                scanf("%d", &val);
                enqueue(queue, val);
            }
            else if (k == 2)
            {
                dequeue(queue);
            }
            else if (k == 3)
            {
                display(queue);
            }
            else if (k == 4)
            {
                printf("Length: %d\n", size(queue));
            }
            else if (k == 5)
            {
                int pos;
                scanf("%d", &pos);
                search(queue, pos);
            }
            else
                break;
        }
    }
    return 0;
}