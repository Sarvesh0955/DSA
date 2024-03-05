//IIT2023101 Sarvesh Kumar
#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int ent[n],ext[n];
    for(int i=0;i<n;i++)
        scanf("%d %d",&ent[i],&ext[i]);
    int ct=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i!=j)
            {
                if(ent[i]>=ent[j] && ent[i]<=ext[j]) 
                ct++;
                else if(ext[i]>=ent[j] && ext[i]<=ext[j])
                ct++;
                else if(ent[i]<=ent[j] && ext[i]>=ext[j])
                ct++;
            }
        }
    }
    printf("%d",ct);
    return 0;
}