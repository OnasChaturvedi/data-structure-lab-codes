#include <stdio.h>
#include <stdlib.h>


int binarySearch(int n, int* arr, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
    }

    return -1;
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

    printf("Input the array elements in sorted order :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search for : ");
    scanf("%d", &key);

    int target_index = binarySearch(n, arr, key);
    if (target_index == -1)
    {
        printf("Key not found in array.");
    }
    else
    {
        printf("Key found at index %d", target_index);
    }

    free(arr);
    return 0;
}
