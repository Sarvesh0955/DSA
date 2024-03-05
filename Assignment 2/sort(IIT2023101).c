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
    double total1=0;
    double total2=0;
    FILE *ptr=fopen("output.txt","w+");
    if(ptr==NULL)
	    exit(0);
    
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
        insertionsort(a,n);
        for(int j=0;j<n;j++)
       		fprintf(ptr,"%d ",a[j]);
	fprintf(ptr,"\n");
        end1=clock();
        double time1= (double)(end1 - start1) / (double)(CLOCKS_PER_SEC);
	total1+=time1;

	start2=clock();
	mergesort(b,0,n-1);
	for(int j=0;j<n;j++)
                fprintf(ptr,"%d ",b[j]);
        fprintf(ptr,"\n");
	end2=clock();
	double time2= (double)(end2 - start2) / (double)(CLOCKS_PER_SEC);
	total2+=time2;
	//printf("\n %f \n",time);
    }
    double avg1=total1/1000.0;
    double avg2=total2/1000.0;
    printf("avg insertion sort time for %d size array: %f\n",n, avg1);
    printf("avg merge sort time for %d size array: %f\n",n, avg2);
}
