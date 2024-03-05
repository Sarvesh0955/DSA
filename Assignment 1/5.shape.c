//IIT2023101 Sarvesh Kumar
#include<stdio.h>

struct coo{
    int a;
    int b;
}c[4];

int abs(int n)
{
    if(n<0)
        return -1*n;
    else
        return n;
}

int main()
{
    printf("Enter 4 cordintes in cyclic order start form bottom left corner:\n");
    scanf("%d %d",&c[0].a,&c[0].b);
    scanf("%d %d",&c[1].a,&c[1].b);
    scanf("%d %d",&c[2].a,&c[2].b);
    scanf("%d %d",&c[3].a,&c[3].b);
    int l1,l2,l3,l4;
        l1=abs(c[0].a-c[1].a);
        l2=abs(c[1].b-c[2].b);
        l3=abs(c[2].a-c[3].a);
        l4=abs(c[3].b-c[0].b);
    // printf("%d %d %d %d\n",l1,l2,l3,l4);
    if(l1==l2 && l2==l3 && l3==l4 && l4==l1)
        printf("Square");
    else if(l1==l3 && l2==l4)
        printf("Rectangle");
    else
        printf("Other shape");
}