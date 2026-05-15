#include<stdio.h>
#include<string.h>
#include "teacher.h"

void teachersmenu() {
    while (1) 
    {
        int choice;
        printf("\n===== TEACHER MENU =====\n");
        printf("1. View Profile\n");
        printf("2. Edit Profile\n");
        printf("3. Edit Grades\n");
        printf("4. Handle Reports\n");
        printf("5. Change Password\n");
        printf("6. Logout\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                viewProfile();
                    printf("Viewing profile...\n");
                break;

            case 2:
                editProfile();
                    printf("Editing profile...\n");
                break;

            case 3:
                 addGrades();
                    printf("Adding grades...\n");
                break;

            case 4:
                 editGrades();
                    printf("Editing grades...\n");
                break;

            case 5:
                 handleReports();
                    printf("Handling reports...\n");
                break;

            default:
            invalidChoice();
            printf("Invalid Choice!\n");
            getchar();
            break;
      
    }
  }
}