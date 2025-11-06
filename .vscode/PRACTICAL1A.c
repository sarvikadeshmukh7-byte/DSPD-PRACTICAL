#include <stdio.h>

int main()
{
    int a[100];
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &a[i]);
    }
    
    int sume = 0, sumo = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            sume = sume + a[i];
        }
        else
        {
            sumo = sumo + a[i];
        }
    }
    
    printf("The sum of the elements at even index is %d\n", sume);
    printf("The sum of the elements at odd index is %d\n", sumo);
    
    return 0;
}