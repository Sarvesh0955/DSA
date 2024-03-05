//IIT2023101 Sarvesh Kumar
#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    scanf("%s",s);
    int n=strlen(s);
    int count=0;
    for(int i=0;i<n;i++)
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            count++;
    printf("Vowels count=%d",count);
    return 0;
}