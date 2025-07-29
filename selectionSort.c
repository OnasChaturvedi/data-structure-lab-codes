#include <stdio.h>
#include <stdlib.h>

void selectionSort(int n, int *arr);

int main()
{
    int n;
    printf("Enter the length of the array : ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }
    int* arr = malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        printf("Couldn't allocate memory.\n");
        return 1;
    }

    printf("\nInput the array elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    selectionSort(n, arr);

    printf("\nSorted array :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);
    return 0;
}


void selectionSort(int n, int *arr)
{
    if (n <= 1)
    {
        return;
    }

    int* min = arr;
    for (int* ptr = arr + 1; ptr < arr + n; ptr++)
    {
        if (*ptr < *min)
        {
            min = ptr;
        }
    }

    int temp = *min;
    *min = *arr;
    *arr = temp;

    selectionSort(n - 1, arr + 1);
}
