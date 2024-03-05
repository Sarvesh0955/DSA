//IIT2023101 Sarvesh Kumar
#include<stdio.h>

int minima(int a[],int l,int r,int n)
{
    int m=l+(r-l)/2;
    if ((m==0 || a[m-1]>a[m]) && (m==n-1 || a[m+1]>a[m]))
        return m;
    else if (m>0 && a[m-1]<a[m])
        return minima(a,l,(m-1),n);
    return minima(a,(m+1),r,n);
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=minima(a,0,n-1,n);
    printf("%d ",ans);    
    return 0;
}