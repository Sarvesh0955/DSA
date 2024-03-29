#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int z=1e8+7;

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
    R[j] = a[m + 1 + j];

    i = 0, 
    j = 0; 
    k = l;

    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[],int l,int r)
{
	if(l>=r)
		return;
		int mid=l+(r-l)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	return;
}

int main()
{
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  mergesort(a,0,n-1);
  for(int i=0;i<n;i++)
    printf("%d ",a[i]);
  return 0;
}
