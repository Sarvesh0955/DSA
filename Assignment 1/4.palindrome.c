//IIT2023101 Sarvesh Kumar
#include<stdio.h>
#include<string.h>

int pal(char s[],int l,int r)
{
    if(l>=r)
        return 1;
    if(s[l]==s[r])
        pal(s,l+1,r-1);
    else
        return -1;
}

int main()
{
    char s[100];
    scanf("%s",&s);
    int n=strlen(s);
    if(pal(s,0,n-1)==1)
        printf("Pallindrome");
    else
        printf("Not Pallindrome");
    return 0;
}