
#include<stdio.h>
struct Student
{
    int Roll_no;
    char Name[20];
    char Branch[20];
    int Batch_no;
};
struct Student s1;
void main()
{
    struct Student *ptr = &s1;
    printf("Enter the Roll_no : ");
    scanf("%d",&ptr->Roll_no);
    printf("Enter the Name : ");
    scanf("%s",ptr->Name);
    printf("Enter the Branch : ");
    scanf("%s",ptr->Branch);
    printf("Enter the Batch_no : ");
    scanf("%d",&ptr->Batch_no);
    
    printf("\nRoll_no : %d",ptr->Roll_no);
    printf("\nName : %s",ptr->Name);
    printf("\nBranch : %s",ptr->Branch);
    printf("\nBatch_no : %d",ptr->Batch_no);
}