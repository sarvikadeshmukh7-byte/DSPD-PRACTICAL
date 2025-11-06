#include <stdio.h>
#include <stdbool.h>

bool search(int *a, int n, int x)
{
    if(a == NULL || n <= 0)
    {
        return false;
    }
    else
    {
        int beg = 0;
        int end = n - 1;
        int mid;
        while(beg <= end)
        {
            mid = (beg + end) / 2;
            if(a[mid] == x)
            {
                printf("low = /");
                printf("The element %d is present at index %d", a[mid], mid);
                printf("\n");
                return true;
            }
            else if(a[mid] > x)
            {
                printf("low = %d, mid = %d, High = %d, a[%d] = %d\n", beg, mid, end, mid, a[mid]);
                printf("Subarray is: ");
                for(int k = beg; k <= end; k++)
                {
                    printf("%d ", a[k]);
                }
                beg = mid + 1;
                printf("\n");
            }
            else
            {
                printf("low = %d, mid = %d, High = %d, a[%d] = %d\n", beg, mid, end, mid, a[mid]);
                printf("Subarray is: ");
                for(int k = beg; k <= end; k++)
                {
                    printf("%d ", a[k]);
                }
                beg = mid + 1;
                printf("\n");
            }
        }
        return false;
    }
}

int main()
{
    int a[100];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    int x;
    printf("\nEnter the element to search: ");
    scanf("%d", &x);
    
    bool result = search(a, x, n);
    if(result == false && n <= 0)
        printf("Element not found");
    else if(result == false && n > 0)
        printf("Please enter the elements in the array.");
    else
        printf("Hence, the element is found in the array.");
    
    return 0;
}