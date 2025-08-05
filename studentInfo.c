#include <stdio.h>
#include <stdlib.h>

typedef struct studentInfo{
    char name[50];
    int rollNum;
    char grade;
}studentInfo;

void readStudentInfo(int n, studentInfo* arr);
void sortStudentInfo(int n, studentInfo* arr);
void displayStudentInfo(int n, studentInfo* arr);

int main()
{
    int n;
    printf("Enter the number of the students : ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }
    studentInfo* arr = malloc(sizeof(studentInfo) * n);
    if (arr == NULL)
    {
        printf("Couldn't allocate memory.\n");
        return 1;
    }

    printf("\nInput the students' information :\n");
    readStudentInfo(n, arr);

    sortStudentInfo(n, arr);
    printf("\nStudent information sorted by Roll Number :\n");
    displayStudentInfo(n, arr);

    return 0;
}

void readStudentInfo(int n, studentInfo* arr)
{
    for (int i = 0; i < n; i++)
    {
        printf("--Student %d--\nName : ", i + 1);
        scanf(" %[^\n]", arr[i].name);
        printf("Roll Number : ");
        scanf("%d", &arr[i].rollNum);
        printf("Grade : ");
        scanf("\n%c", &arr[i].grade);
    }
}

void sortStudentInfo(int n, studentInfo* arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].rollNum > arr[j + 1].rollNum)
            {
                // Swapping elements
                studentInfo temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayStudentInfo(int n, studentInfo* arr)
{
    for (int i = 0; i < n; i++)
    {
        printf("--Student %d--\nRoll Number : %d\n", i + 1, arr[i].rollNum);
        printf("Name : %s\n", arr[i].name);
        printf("Grade : %c\n", arr[i].grade);
    }
}
