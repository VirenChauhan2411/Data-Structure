#include<stdio.h>
void main()
{
    char s[100];
    printf("Enter the string in lowercase : ");
    scanf("%s",s);
    printf("The string in uppercase is : ");
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            s[i] = s[i]-32;
        }
    }
    printf("%s",s);
}