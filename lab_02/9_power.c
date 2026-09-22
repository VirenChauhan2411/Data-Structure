#include<stdio.h>
void main()
{
    int x,y,ans = 1;
    printf("Enter the base and power : ");
    scanf("%d %d",&x,&y);
    for(int i = 0; i<y ; i ++)
    {
        ans = ans * x;
    }
    printf("ans is : %d" ,ans);
    

}