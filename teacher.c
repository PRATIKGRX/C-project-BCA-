#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void teacherMenu() {
    again:
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
            break;

        case 2:
            editProfile();
            break;

        case 3:
            addGrades();
            break;

        case 4:
            editGrades();
            break;

        case 5:
            handleReports();
            break;

        default:
          invalidChoice();
          goto again;
          break;
      
    }
}