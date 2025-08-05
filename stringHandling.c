#include <stdio.h>
#include <stdlib.h>

int stringLength(char* str);
void stringConcat(char* destination, char* source);
int stringCompare(char* str1, char* str2);
void insertSubstring(char* destination, char* source, int index);
void deleteSubstring(char* destination, char* source);

int main()
{
    char str1[100];
    char str2[100];

    printf("Enter the first string : ");
    scanf(" %[^\n]", str1);
    printf("Enter the second string : ");
    scanf(" %[^\n]", str2);

    printf("Length of string 1 = %d\n", stringLength(str1));
    printf("Length of string 2 = %d\n", stringLength(str2));

    printf("Comparing strings...\n");
    if (!stringCompare(str1, str2))
    {
        printf("Both strings are equal.\n");
    }
    else
    {
        printf("Both strings are different.\n");
    }

    stringConcat(str1, str2);
    printf("Concatenated string is %s\n", str1);

    char subStr1[50];
    char subStr2[50];
    int insertIndex;
    printf("Enter the substring to insert to concatenated string : ");
    scanf(" %[^\n]", subStr1);
    printf("Enter the index to insert at: ");
    scanf("%d", &insertIndex);

    insertSubstring(str1, subStr1, insertIndex);
    printf("String after insertion : %s\n", str1);

    printf("Enter the substring to delete from concatenated string : ");
    scanf(" %[^\n]", subStr2);

    deleteSubstring(str1, subStr2);
    printf("String after deletion : %s\n", str1);

    return 0;
}

int stringLength(char* str)
{
    int len;
    for (len = 0; str[len] != '\0'; len++);
    return len;
}

void stringConcat(char* destination, char* source)
{
    int i, destLen = stringLength(destination);
    for (i = destLen; source[i - destLen] != '\0'; i++)
    {
        destination[i] = source[i - destLen];
    }
    destination[i] = '\0';
}

int stringCompare(char* str1, char* str2)
{
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }

    if (str1[i] == '\0' && str2[i] == '\0')
    {
        return 0;
    }
    else if (str1[i] == '\0')
    {
        return -2;
    }
    else
    {
        return 2;
    }
}

void insertSubstring(char* destination, char* source, int index)
{
    int srcLen = stringLength(source);
    int destLen = stringLength(destination);

    for (int i = destLen - 1; i >= index; i--)
    {
        destination[i + srcLen] = destination[i];
    }

    for (int j = index; j < index + srcLen; j++)
    {
        destination[j] = source[j - index];
    }

    destination[destLen + srcLen] = '\0';
}

void deleteSubstring(char* destination, char* source)
{
    int srcLen = stringLength(source);
    int destLen = stringLength(destination);

    for (int i = 0; destination[i] != '\0'; i++)
    {
        if (destination[i] == source[0])
        {
            int compare = stringCompare(destination + i, source);
            if(compare == 2 || compare == 0)
            {
                if (compare != 0)
                {
                    for(int j = i; destination[j + srcLen] != '\0'; j++)
                    {
                        destination[j] = destination[j + srcLen];
                    }
                }
                destination[destLen - srcLen] = '\0';
                destLen -= srcLen;
            }
        }
    }
}
