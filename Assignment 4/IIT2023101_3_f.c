//IIT2023101 Sarvesh Kumar
#include<stdio.h>

int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}

int arrmin(int a[],int n)
{
    if(n==1)
        return a[0];
    int m=n/2;
    int a1[m],a2[n-m];
    for(int i=0;i<m;i++)
        a1[i]=a[i];
    for(int i=0;i<n-m;i++)
        a2[i]=a[m+i];
    return min(arrmin(a1,m),arrmin(a2,n-m));
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int min=arrmin(a,n);
    printf("%d",min);
    return 0;
}