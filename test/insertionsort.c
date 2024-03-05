#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionsort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
        if(a[i]>a[i+1])
        {
            int key=a[i+1];
            for(int j=i;j>=0;j--)
            {
                a[j+1]=a[j];
                if(a[j]<key || j==0)
                {
                    a[j]=key;
                    break;
                }
            }
        }
}

int main()
{
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  quickSort(a,0,n-1);
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
  return 0;
}
