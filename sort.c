#include <stdio.h>
#include <stdlib.h>


void swap(int* arr, int idx1, int idx2)
{
    arr[idx1] = arr[idx1] ^ arr[idx2];
    arr[idx2] = arr[idx1] ^ arr[idx2];
    arr[idx1] = arr[idx1] ^ arr[idx2];
}


void bubbleSort(int n, int *arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swapping elements
                swap(arr, j, j + 1);
            }
        }
    }
}


void selectionSort(int n, int *arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            // Swapping elements
            swap(arr, min, i);
        }
    }
}


void insertionSort(int n, int *arr)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[i] > arr[j - 1])
            {
                int insertable = arr[i], temp = arr[j];
                for (int k = j; k < i; k++)
                {
                    temp = arr[k + 1] ^ temp;
                    arr[k + 1] = arr[k + 1] ^ temp;
                    temp = arr[k + 1] ^ temp;
                }
                arr[j] = insertable;
                break;
            }
        }
    }
}


int main()
{
    int n, key;
    printf("Enter the length of the array : ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size.");
        return 1;
    }
    int* arr = malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        printf("Couldn't allocate memory.");
        return 1;
    }

    printf("Input the array elemente :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int choice;
    printf("Press 1 for bubble sort, 2 for selection sort, and 3 for insertion sort...\n");
    scanf("%d", &choice);

    if (n >= 2)
    {
        switch(choice)
        {
            case 1:
                bubbleSort(n, arr);
                break;
            case 2:
                selectionSort(n, arr);
                break;
            case 3:
                insertionSort(n, arr);
                break;
            default:
                break;
        }
    }

    printf("Sorted array :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
