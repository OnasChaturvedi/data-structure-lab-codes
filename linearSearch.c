#include <stdio.h>
#include <stdlib.h>

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
        return 2;
    }

    printf("Input the array elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search for : ");
    scanf("%d", &key);

    int target_index = linearSearch(n, arr, key);
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

int linearSearch(int n, int* arr, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
