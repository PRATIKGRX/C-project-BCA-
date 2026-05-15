#include <stdio.h>
#include "teacher.h"

int main() {
    int choice;
    while (1) {
        printf("===== SCHOOL MANAGEMENT SYSTEM =====\n\n");
        printf("========== Teacher's Login:=========\n");
        printf("1. Login\n");
        printf("2. Create New Account\n");
        printf("3. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Login selected\n\n");
             teachersmenu();
              break;
        }
        else if (choice == 2) {
            printf("Create New Account selected\n\n");
        }
        else if (choice == 3) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice!!\n\n");
             break;
        }
    }
    return 0;

}
