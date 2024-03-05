//IIT2023101 Sarvesh Kumar
#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int min=__INT_MAX__;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(min>=a[i])
            min=a[i];
    }
    printf("%d",min);
    return 0;
}