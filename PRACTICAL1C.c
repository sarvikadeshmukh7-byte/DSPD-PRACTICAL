#include <stdio.h>

struct student
{
    char name[50];
    int regno;
    char branch[50];
    float avgmarks;
};

int main()
{
    int n;
    printf("Enter the no. of students: ");
    scanf("%d", &n);
    
    struct student s[n];
    
    int i, j;
    for(i=0; i<n; i++)
    {
        printf("Enter the details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Registration number: ");
        scanf("%d", &s[i].regno);
        printf("Branch: ");
        scanf("%s", s[i].branch);
        printf("Average marks: ");
        scanf("%f", &s[i].avgmarks);
    }
    
    struct student temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(s[j].avgmarks > s[j+1].avgmarks)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    
    printf("\nThe sorted list is:\n");
    for(i=0; i<n; i++)
    {
        printf("\nName: %s\n", s[i].name);
        printf("Registration number: %d\n", s[i].regno);
        printf("Branch: %s\n", s[i].branch);
        printf("Average marks: %f\n", s[i].avgmarks);
    }
    
    return 0;
}
