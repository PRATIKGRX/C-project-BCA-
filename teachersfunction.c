// teacher.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "teacher.h"
struct Teacher {
        int ID;
        char username[50];
        char password[50];
        char email[100];
        char subject[50];
        char address[100];
        char contact[40];
    };
     
//------------------------------------------------------  View Teacher Profile  -----------------------------------------------------------------
void viewTeacherProfile() {
    system("cls");

    printf("\n----------------------------------\n");
    printf("             Profile:              ");
    printf("\n----------------------------------\n\n");

    int enterid;
    char enterpassword[20];
    struct Teacher t;
    
    printf("Enter ID to view profile: ");
    scanf("%d", &enterid);
    printf("Enter Password: ");
    scanf("%s", enterpassword);

    system("cls");

  FILE *fp;
    fp = fopen("teachers.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
   
    
    while(fscanf(fp, "%d %s %s %s %s %s %s\n", &t.ID, t.username, t.password, t.email, t.subject, t.address, t.contact) == 7) {

            if (t.ID == enterid && strcmp(t.password, enterpassword) == 0) {  
                 printf("\n----------------------------------\n");
                printf("             Profile:              ");
                printf("\n----------------------------------\n\n");

                printf("|---------------|\n");
                printf("|    Profile    |\n");
                printf("|   ---------   |\n");
                printf("|     IMAGE     |\n");
                printf("|---------------|\n\n");

                printf("ID:       %d\n", t.ID);
                printf("Name:     %s\n", t.username);
                printf("Subject:  %s\n", t.subject);
                printf("Email:    %s\n", t.email);
                printf("Address:  %s\n", t.address);
                printf("Contact:  %s\n", t.contact);
                printf("----------------------------------\n");
                }
            printf("Press Enter to back...");
            fclose(fp);
            getchar();
            getchar();
            return;
    
    }
}
//-----------------------------------------------------  Edit Teacher Profile  ----------------------------------------------------------------
void editTeacherProfile() {
    printf("Editing profile...\n");
}

//-----------------------------------------------------  Add Grades  --------------------------------------------------------------------------

void addGrades() {
    printf("Adding grades...\n");
}

//-----------------------------------------------------  View Students  ----------------------------------------------------------------------

void viewStudents() {
    printf("Viewing students...\n");
}

//-----------------------------------------------------  View Grades  ------------------------------------------------------------------------
void teacherViewGrades() {
    printf("Viewing grades...\n");
}

//-----------------------------------------------------  Handle Reports  ----------------------------------------------------------------------

void handleReports() {
    printf("Handling reports...\n");
}

//-----------------------------------------------------  Change Teacher Password  -------------------------------------------------------------

void changeTeacherPassword() {
    system("cls");
    int search_id;
    struct Teacher t;
    long int size = sizeof(t);
    FILE *fp;
    
    
    fp = fopen("teachers.txt", "rb+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    printf("Enter your ID: ");
    if (scanf("%d", &search_id) != 1) {
        printf("Invalid ID input.\n");
        fclose(fp);
        return;
    }

    int found = 0;
    
    // Rewind to ensure we start from the beginning of the file
    rewind(fp); 

    while (fread(&t, sizeof(t), 1, fp) == 1) {
        if (t.ID == search_id) {
            system("cls");
            printf("Enter new password: ");
            scanf("%s", t.password);
            
           
            fseek(fp, -size, SEEK_CUR);
            
            // Write the updated struct back
            fwrite(&t, sizeof(t), 1, fp);
            
         
            fflush(fp); 
            
            printf("Password updated successfully!\n");
            found = 1;
            break;  
        }
    }
    
    if (!found) {
        printf("Teacher ID not found!\n");
    }

    fclose(fp);

    while (getchar() != '\n'); 
    
    printf("Press Enter to go back...");
    getchar();
}

//-----------------------------------------------------  Invalid Choice  ----------------------------------------------------------------------

void invalidChoice() {
    printf("Invalid Choice!\n");
    printf("Press Enter to try Again.");
    getchar();
    getchar();
}

//-----------------------------------------------------  Processing  ---------------------------------------------------------------------------

void processing() {
    printf("loading");

    for (int i = 0; i < 10; i++) {
        printf(".");
        fflush(stdout);
        Sleep(500);  
    }
    printf("\n");
}