#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
      
void quickSort(int a[],int l,int r)
{
  if(l>=r) return;
  else
  {
    int pvt=a[r];
    int ind1=l;
    for(int ind2=l;ind2<r;ind2++)
    {
      if(a[ind2]<pvt)
      {
        swap(&a[ind2],&a[ind1]);
        ind1++;
      }
    }
    swap(&a[r],&a[ind1]);
    quickSort(a,l,ind1-1);
    quickSort(a,ind1+1,r);
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
