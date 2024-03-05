//IIT2023101 Sarvesh Kumar
#include<stdio.h>

void minima(int n,int a[n][n],int rl,int rr,int cl,int cr)
{
    if(rl>rr || cl>cr)
        return;
    int mr=rl+(rr-rl)/2;
    int mc=cl+(cr-cl)/2;
    int f1=0,f2=0,f3=0,f4=0;
    // printf("%d %d\n",mr,mc);
    
    if(mr==n-1)
        f1=1;
    else if(a[mr][mc]<a[mr+1][mc])
    	f1=1;

    if(mc==n-1)
    	f2=1;
    else if(a[mr][mc]<a[mr][mc+1])
    	f2=1;

    if(mr==0)
    	f3=1;
    else if(a[mr][mc]<a[mr-1][mc])
        f3=1;

    if(mc==0)
    	f4=1;
    else if(a[mr][mc]<a[mr][mc-1])
    		f4=1;
 
    if(f1==1 && f2==1 && f3==1 && f4==1)
    	{printf("ans: %d %d\n",mr,mc);return;}
    else if(a[mr][mc]>a[mr+1][mc] && mr+1<n)
        minima(n,a,mr+1,rr,cl,cr);
    else if(a[mr][mc]>a[mr-1][mc])
        minima(n,a,rl,mr,cl,cr);
    else if(a[mr][mc]>a[mr][mc+1] && mc+1<n)
        minima(n,a,rl,rr,mc+1,cr);
    else if(a[mr][mc]>a[mr][mc-1])
        minima(n,a,rl,rr,cl,mc);
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    
    minima(n,a,0,n-1,0,n-1);        
    return 0;
}
