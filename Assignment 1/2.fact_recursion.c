//IIT2023101 Sarvesh Kumar
#include<stdio.h>

int fact(int n)
{
    if(n==1 || n==0)
    {
        printf("1=");
        return 1;
    }
    else
    {
        printf("%d*",n);
        return n*fact(n-1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d!=",n);
    printf("%d",fact(n));
    return 0;
}