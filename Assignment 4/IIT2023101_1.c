//IIT2023101 Sarvesh Kumar
#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int min=a[i],index;
        for(int j=i;j<n;j++)
        {
            if(min>=a[j])
            {
                min=a[j];
                index=j;
            }
        }
        swap(&a[i],&a[index]);
    }
    for(int j=0;j<n;j++)
        printf("%d ",a[j]);
    return 0;
}