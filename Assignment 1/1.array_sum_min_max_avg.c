//IIT2023101 Sarvesh Kumar
#include<stdio.h>

int sum(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    return sum;
}

int max(int a[],int n)
{
    int m=a[0];
    for(int i=1;i<n;i++)
        if(m<=a[i])
            m=a[i];
    return m;
}

int min(int a[],int n)
{
    int m=a[0];
    for(int i=1;i<n;i++)
        if(m>=a[i])
            m=a[i];
    return m;
}

float avg(int a[],int n)
{
    float sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    float av=sum/n;
    return av;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Sum=%d\n",sum(a,n));
    printf("Min=%d,",min(a,n));
    printf("Max=%d\n",max(a,n));
    printf("Avg=%f\n",avg(a,n));
    return 0;
}