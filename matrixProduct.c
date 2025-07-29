#include <stdio.h>
#include <stdlib.h>

int** allocateMatrixMemory(int m, int n);
void freeMatrixMemory(int m, int n, int** matrix);
void inputMatrix(int m, int n, int** matrix);
void outputMatrix(int m, int n, int** matrix);
int** multiplyMatrices(int m1, int n1, int** matrix1, int m2, int n2, int** matrix2);

int main()
{
    int m1, n1, m2, n2;
    printf("---Matrix A Dimensions---\n");
    printf("Enter the number of rows : ");
    scanf("%d", &m1);
    printf("Enter the number of columns : ");
    scanf("%d", &n1);
    printf("\n---Matrix B Dimensions---\n");
    printf("Enter the number of rows : ");
    scanf("%d", &m2);
    printf("Enter the number of columns : ");
    scanf("%d", &n2);

    if (n1 <= 0 || m1 <= 0 || m2 <= 0 || n2 <= 0)
    {
        printf("Invalid matrix size.\n");
        return 1;
    }
    else if (n1 != m2)
    {
        printf("Can't multiply, incompatible dimensions!\n");
        return 1;
    }

    int** A = allocateMatrixMemory(m1, n1);
    int** B = allocateMatrixMemory(m2, n2);
    if (A == NULL || B == NULL)
    {
        printf("Error in allocating memory.\n");
        return 2;
    }

    printf("\n---Input Matrix A---\n");
    inputMatrix(m1, n1, A);
    printf("\n---Input Matrix B---\n");
    inputMatrix(m2, n2, B);

    int** C = multiplyMatrices(m1, n1, A, m2, n2, B);
    if (C == NULL)
    {
        printf("Error in allocating memory.\n");
        return 2;
    }

    printf("---A---\n");
    outputMatrix(m1, n1, A);
    printf("---B---\n");
    outputMatrix(m2, n2, B);
    printf("---A x B---\n");
    outputMatrix(m1, n2, C);

    freeMatrixMemory(m1, n1, A);
    freeMatrixMemory(m2, n2, B);
    freeMatrixMemory(m1, n2, C);

    return 0;
}

// Allocates a matrix of given size and returns a pointer to it.
int** allocateMatrixMemory(int m, int n)
{
    int** matrix = (int**) malloc(sizeof(int*) * m);
    if (matrix == NULL)
    {
        printf("Couldn't allocate memory.\n");
        return NULL;
    }
    for (int i = 0; i < m; i++)
    {
        *(matrix + i) = (int*) malloc(sizeof(int) * n);
        if (*(matrix + i) == NULL)
        {
            printf("Couldn't allocate memory.\n");
            return NULL;
        }
    }

    return matrix;
}

// Frees memory occupied by a 2d matrix
void freeMatrixMemory(int m, int n, int** matrix)
{
    for (int i = 0; i < m; i++)
    {
        free(*(matrix + i));
    }

    free(matrix);
}

// Takes input of matrix elements.
void inputMatrix(int m, int n, int** matrix)
{
    for (int i = 0; i < m; i++)
    {
        printf("Row %d :\n", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", *(matrix + i) + j);
        }
        printf("\n");
    }
}

// Prints matrix elements.
void outputMatrix(int m, int n, int** matrix)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

// Multiplies two matrices together and returns a pointer to the resultant array.
int** multiplyMatrices(int m1, int n1, int** matrix1, int m2, int n2, int** matrix2)
{
    int** result = allocateMatrixMemory(m1, n2);
    if (result == NULL)
    {
        printf("Error in allocating memory.\n");
        return NULL;
    }

    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            *(*(result + i) + j) = 0;
            for (int k = 0; k < n1; k++)
            {
                *(*(result + i) + j) += (*(*(matrix1 + i) + k)) * (*(*(matrix2 + k) + j));
            }
        }
    }

    return result;
}
