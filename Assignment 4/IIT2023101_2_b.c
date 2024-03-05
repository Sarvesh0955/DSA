//IIT2023101 Sarvesh Kumar
#include<stdio.h>

void merge(int a[],int b[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    int L2[n1], R2[n2];

    for (int i = 0; i < n1; i++)
    {L[i] = a[l + i];L2[i] = b[l + i];}
    for (int j = 0; j < n2; j++)
    {R[j] = a[m + 1 + j];R2[j] = b[m + 1 + j];}

    i = 0, 
    j = 0; 
    k = l;

    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            b[k] = L2[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            b[k] = R2[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k] = L[i];
        b[k] = L2[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        a[k] = R[j];
        b[k] = R2[j];
        j++;
        k++;
    }
}

void mergesort(int a[],int b[],int l,int r)
{
	if(l>=r)
		return;

		int mid=l+(r-l)/2;
		mergesort(a,b,l,mid);
		mergesort(a,b,mid+1,r);
		merge(a,b,l,mid,r);
	return;
}

int main(){
    int n;
    scanf("%d",&n);
    int ent[n],ext[n];
    for(int i=0;i<n;i++)
        scanf("%d %d",&ent[i],&ext[i]);

    mergesort(ent,ext,0,n-1);
    //for(int i=0;i<n;i++)
        //printf("%d %d\n",ent[i],ext[i]);
    int ct=0;
    for(int i=0;i<n;i++)
    {
        int key=ext[i];
        int l=i+1,r=n-1,m;
        while(r-l>1)
        {
            m=l+(r-l)/2;
            if(ent[m]>key)
                r=m-1;
            else
                l=m;
        }
        if(ent[r]<=key)
        ct+=(r-i);
        else if(ent[l]<=key)
        ct+=(l-i);
    }
    printf("%d",ct);
    return 0;
}
