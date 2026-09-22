#include<stdio.h>
void main(){
    char n ;
    printf("Enter the char : ");
    scanf("%c",&n);
    if(n=='A' || n=='E' || n=='I' || n=='O' || n=='U')
    {
        printf("Number is vowel : ");
    }
    else
    {
        printf("Number is consonant : ");
    }
}