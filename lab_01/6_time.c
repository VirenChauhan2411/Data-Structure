#include <stdio.h>

void main()
{
    int Tsec;
    int h, m, s;

    printf("Enter total s: ");
    scanf("%d", &Tsec);

    h = Tsec / 3600;           
    m = (Tsec % 3600) / 60;  
    s = Tsec % 60;           

    printf("%d:%d:%d\n", h, m, s);

}
