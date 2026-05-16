#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <windows.h>
#include "teacher.h"

void teachersmenu() {
    while (1) 
    {
        system("cls");
        int choice;
        printf("\n-----------------------------------\n");
        printf("           Teacher's Menu:           ");    //teacher's role
        printf("\n-----------------------------------\n\n");
    
        printf("1. View Profile\n");
        printf("2. Edit Profile\n");
        printf("3. View Students\n");
        printf("4. View Grades\n");
        printf("5. Handle Reports\n");
        printf("6. Change Password\n");
        printf("7. Logout\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                viewTeacherProfile();
                    printf("Viewing profile...\n");
                break;

            case 2:
                editTeacherProfile();
                    printf("Editing profile...\n");
                break;

            case 3:
                 viewStudents();
                    printf("Viewing students...\n");
                break;

            case 4:
                 teacherViewGrades();
                    printf("Viewing grades...\n");
                break;

            case 5:
                 handleReports();
                    printf("Handling reports...\n");
                break;
            
            case 6:
                changeTeacherPassword();
                printf("Changing password...\n");
                break;

            case 7:
                printf("Logging out...\n");
                processing();
                return;

            default:
            invalidChoice();
            getchar();
            break;
      
    }
  }
}