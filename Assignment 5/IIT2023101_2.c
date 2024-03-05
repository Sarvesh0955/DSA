#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
      
void quickSort2(int a[],int l,int r)
{
  if(r-l<1) return;
  else
  {
    int pvt1=a[l];
    int pvt2=a[r];
    if(pvt1>pvt2)
    {swap(&pvt1,&pvt2);swap(&a[l],&a[r]);}

    int ind1=l+1,ind2=l+1;
    for(int i=l+1;i<=r;i++)
    {
        if(a[i]<pvt1 && a[i]<pvt2)
        {
            swap(&a[i],&a[ind2]);
            swap(&a[ind2],&a[ind1]);
            ind1++;ind2++;
        }
        else if(a[i]>pvt1 && a[i]<pvt2)
        {
            swap(&a[i],&a[ind2]);
            ind2++;
        }
    }
    swap(&a[r],&a[ind2]);
    if((ind1-1)!=0)
    swap(&a[l],&a[ind1-1]);
   
    quickSort2(a,l,ind1-2);
    quickSort2(a,ind1,ind2-1);
    quickSort2(a,ind2+1,r);
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  quickSort2(a,0,n-1);
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
  return 0;
}
