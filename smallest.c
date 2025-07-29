#include <stdio.h>
#include <stdlib.h>

int findSmallest(int n, int* arr);

int main()
{
    int n;
    printf("Enter the length of the array : ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size.");
        return 1;
    }
    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        printf("Couldn't allocate memory.");
        return 2;
    }

    printf("\nInput the array elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    printf("\nSmallest element in array is %d.\n", findSmallest(n, arr));
    free(arr);
    return 0;
}

int findSmallest(int n, int* arr)
{
    int min = *arr;
    for (int* ptr = arr + 1; ptr < arr + n; ptr++)
    {
        if (*ptr < min)
        {
            min = *ptr;
        }
    }
    return min;
}
