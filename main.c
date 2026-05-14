#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
void main()
{
    int choice;
    loadingAnimation();
    again:
    system("cls");
    printLine();
    printf("School Management System: \n");
    printLine();
    printf("1. Login as Admin.\n");
    printf("2. Login as Teacher.\n");
    printf("3. Login as Student.\n");
    printf("4. Exit.\n\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        // admin login function here
        break;
    case 2:
        // Teacher login function here
        break;
    case 3:
        // Student login functio here
        break;
    case 4:
        exit(0);
        break;
    default:
        invalidChoice();
        goto again;
        break;
    }
    getchar();
}