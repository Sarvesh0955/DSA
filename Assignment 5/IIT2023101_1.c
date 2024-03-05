#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int z=1e8+7;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int l,int h)
{
   
  int pivot=a[h];
  int i=(l-1);
   
  for(int j=l;j<=h;j++)
  {
    if(a[j]<pivot)
    {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[h]);
  return (i+1);
}
 
            
void quickSort(int a[],int l,int h)
{
  if(l<h)
  {
     
    int pi=partition(a,l,h);
    quickSort(a,l,pi-1);
    quickSort(a,pi+1,h);
  }
}

int partitionrand(int a[],int l,int h)
{
   int p=rand() % (h - l + 1) + l; 
   swap(&a[p],&a[h]);
  int pivot=a[h];
  int i=(l-1);
   
  for(int j=l;j<=h;j++)
  {
    if(a[j]<pivot)
    {
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[h]);
  return (i+1);
}
 
            
void quickSortrand(int a[],int l,int h)
{
  if(l<h)
  {
     
    int pi=partitionrand(a,l,h);
    quickSortrand(a,l,pi-1);
    quickSortrand(a,pi+1,h);
  }
}

int main()
{
    int n;
    scanf("%d",&n);
    double total1=0;
    double total2=0;
    for(int k=0;k<1000;k++)
    {
        clock_t start1, end1;
        clock_t start2, end2;
        int a[n],b[n];
        for(int j=0;j<n;j++)
	    {
            a[j]=rand() % (z+1);
	        b[j]=a[j];
	    }
      
        start1=clock();
        quickSort(a,0,n-1);
        end1=clock();
        double time1= (double)(end1 - start1) / (double)(CLOCKS_PER_SEC);
	total1+=time1;

	start2=clock();
	quickSortrand(b,0,n-1);
	end2=clock();
	double time2= (double)(end2 - start2) / (double)(CLOCKS_PER_SEC);
	total2+=time2;
	//printf("\n %f \n",time);
    }
    double avg1=total1/1000.0;
    double avg2=total2/1000.0;
    printf("avg quick sort time for %d size array: %f\n",n, avg1);
    printf("avg quick random sort time for %d size array: %f\n",n, avg2);
}

