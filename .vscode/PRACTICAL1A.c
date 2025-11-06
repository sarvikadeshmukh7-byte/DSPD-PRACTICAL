#include <stdio.h>

int main()
{
    int a[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int i;
    for(i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    int sume = 0, sumo = 0;
    for(i = 0; i < n; i++)
    {
        if(i % 2 == 0)
            sume = sume + a[i];
        else
            sumo = sumo + a[i];
    }
    
    printf("\nThe sum of the elements at even index is %d", sume);
    printf("\nThe sum of the elements at odd index position is %d", sumo);
    
    return 0;
}