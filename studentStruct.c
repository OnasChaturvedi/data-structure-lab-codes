#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[50];
    int roll_no;
    float marks;
}Student;

void readStudentInfo(Student* student);
void displayStudentInfo(int n, Student* arr);

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
    Student* arr = malloc(sizeof(Student) * n);
    if (arr == NULL)
    {
        printf("Couldn't allocate memory.\n");
        return 1;
    }

    printf("\nInput the students' information :\n");
    for (int i = 0; i < n; i++)
    {
        readStudentInfo(&arr[i]);
    }

    printf("\nAll students' information :\n");
    displayStudentInfo(n, arr);

    int maxIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].marks > arr[maxIdx].marks)
        {
            maxIdx = i;
        }
    }
    printf("\nStudent with highest marks :\n");
    displayStudentInfo(1, arr + maxIdx);
}

void readStudentInfo(Student* student)
{
    printf("\nName : ");
    scanf(" %[^\n]", student->name);
    printf("Roll Number : ");
    scanf("%d", &student->roll_no);
    printf("Marks : ");
    scanf("\n%f", &student->marks);
}

void displayStudentInfo(int n, Student* arr)
{
    for (int i = 0; i < n; i++)
    {
        printf("--Student %d--\nName : %s", i + 1, (arr+i)->name);
        printf("Roll Number : %d", (arr+i)->roll_no);
        printf("Marks : %f", (arr+i)->marks);
    }
}
