#include <stdio.h>
#include <string.h>
// #include <stdlib.h>
#include <windows.h>
#include "teacher.h"

struct Teacher
{
    int ID;
    char username[50];
    char password[50];
    char email[100];
    char subject[50];
    char address[100];
    char contact[40];
};

void main() // teacher's menu
{
    while (1)
    {
        system("cls");
        int choice;
        printf("\n-----------------------------------\n");
        printf("           Teacher's Menu:            ");    // teacher's role
        printf("\n-----------------------------------\n\n");

        printf("1. View Profile\n");
        printf("2. Edit Profile\n");
        printf("3. View Students\n");
        printf("4. View Grades\n");
        printf("5. Handle Reports\n");
        printf("6. Change Password\n");
        printf("7. Logout\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nView profile selected\n");
            processing();
            viewTeacherProfile();
            break;

        case 2:
            printf("\nEdit profile selected\n");
            processing();
            editTeacherProfile();
            break;

        case 3:
            printf("\nView students selected\n");
            processing();
            viewStudents();
            break;

        case 4:
            printf("\nView grades selected\n");
            processing();
            teacherViewGrades();

            break;

        case 5:
            printf("\nHandle reports selected\n");
            processing();
            handleReports();

            break;

        case 6:
            printf("\nChange password selected\n");
            processing();
            changeTeacherPassword();
            break;

        case 7:
            printf("\nLogging out...\n");
            processing();
            return;

        default:
            invalidChoice();
            break;
        }
    }
}

//------------------------------------------------------  View Teacher Profile  -----------------------------------------------------------------
void viewTeacherProfile()
{
    while (1)
    {

        system("cls");

        printf("\n----------------------------------\n");
        printf("             Profile              ");
        printf("\n----------------------------------\n\n");

        int enterid;
        char enterpassword[20];
        struct Teacher t;

        int found = 0;

        printf("Enter ID to view profile: ");
        scanf("%d", &enterid);

        printf("Enter Password: ");
        scanf("%s", enterpassword);

        FILE *fp = fopen("teachers.txt", "r");

        if (fp == NULL)
        {
            printf("Error opening file!\n");
            return;
        }

        while (fscanf(fp, "%d %s %s %s %s %s %s",
                      &t.ID, t.username, t.password,
                      t.email, t.subject, t.address,
                      t.contact) == 7)
        {

            if (t.ID == enterid && strcmp(t.password, enterpassword) == 0)
            {

                found = 1;

                system("cls");

                printf("\n----------------------------------\n");
                printf("             Profile              ");
                printf("\n----------------------------------\n\n");

                printf("|-------------|\n");
                printf("|   Profile   |\n");
                printf("|  ---------  |\n");
                printf("|    IMAGE    |\n");
                printf("|-------------|\n\n");

                printf("ID:       %d\n", t.ID);
                printf("Name:     %s\n", t.username);
                printf("Subject:  %s\n", t.subject);
                printf("Email:    %s\n", t.email);
                printf("Address:  %s\n", t.address);
                printf("Contact:  %s\n", t.contact);

                break;
            }
        }

        fclose(fp);

        if (!found)
        {
            processing();
            printf("\nInvalid ID or password!\n");
            printf("Press Enter to try again..");
            getchar();
            getchar();
        }
        else
        {
            break;
        }
    }

    printf("\nPress Enter to go back...");
    getchar();
    getchar();
}
//-----------------------------------------------------  Edit Teacher Profile  ----------------------------------------------------------------
void editTeacherProfile()
{
    system("cls");

    int search_id;
    char search_pass[50];
    int found = 0;
    struct Teacher t;
    FILE *fp, *temp;

    fp = fopen("teachers.txt", "r");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    printf("\n----------------------------------\n");
    printf("         Edit Profile:             ");
    printf("\n----------------------------------\n\n");

    printf("Enter your ID: ");
    scanf("%d", &search_id);
    printf("Enter Password:");
    scanf("%s", search_pass);
    processing();

    while (fscanf(fp, "%d %s %s %s %s %s %s",
                  &t.ID,
                  t.username,
                  t.password,
                  t.email,
                  t.subject,
                  t.address,
                  t.contact) == 7)
    {

        if (search_id == t.ID && strcmp(search_pass, t.password) == 0)
        {

            int option;
            printf("\n");
            printf("1. Email\n");
            printf("2. Address\n");
            printf("3. Contact\n");
            printf("4. Exit\n\n");

            printf("Enter option to edit: ");
            scanf("%d", &option);
            processing();
            printf("\n");
            switch (option)
            {
            case 1:
                printf("\nEnter new email: ");
                scanf("%s", t.email);
                break;

            case 2:
                printf("\nEnter new address: ");
                scanf("%s", t.address);
                break;
            case 3:
                printf("\nEnter new contact: ");
                scanf("%s", t.contact);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                invalidChoice();
                break;
            }

            found = 1;
        }

        fprintf(temp, "%d %s %s %s %s %s %s\n",
                t.ID,
                t.username,
                t.password,
                t.email,
                t.subject,
                t.address,
                t.contact);
    }

    fclose(fp);
    fclose(temp);

    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");

    if (found)
    {
        processing();
        printf("Profile updated successfully!\n");
    }
    else
    {
        
        printf("Incorrect ID and password!\n");
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();
}

//-----------------------------------------------------  Add Grades  --------------------------------------------------------------------------

void addGrades()
{
    printf("Adding grades...\n");
}

//-----------------------------------------------------  View Students  ----------------------------------------------------------------------

void viewStudents()
{
    printf("Viewing students...\n");
}

//-----------------------------------------------------  View Grades  ------------------------------------------------------------------------
void teacherViewGrades()
{
    printf("Viewing grades...\n");
}

//-----------------------------------------------------  Handle Reports  ----------------------------------------------------------------------

void handleReports()
{
    printf("Handling reports...\n");
}

//-----------------------------------------------------  Change Teacher Password  -------------------------------------------------------------

void changeTeacherPassword()
{
    while (1)
    {

        system("cls");

        int search_id;
        char prev_password[50];
        int found = 0;
        struct Teacher t;
        FILE *fp, *temp;

        fp = fopen("teachers.txt", "r");

        if (fp == NULL)
        {
            printf("File not found!\n");
            return;
        }

        temp = fopen("temp.txt", "w");
        printf("\n----------------------------------\n");
        printf("         Change Password:             ");
        printf("\n----------------------------------\n\n");

        printf("Enter your ID: ");
        scanf("%d", &search_id);

        printf("Enter previous Password: ");
        scanf("%s", &prev_password);
        processing();

        while (fscanf(fp, "%d %s %s %s %s %s %s",
                      &t.ID,
                      t.username,
                      t.password,
                      t.email,
                      t.subject,
                      t.address,
                      t.contact) == 7)
        {

            if (search_id == t.ID && strcmp(prev_password, t.password) == 0)
            {

                printf("\nEnter new password: ");
                scanf("%s", t.password);

                found = 1;
            }

            fprintf(temp, "%d %s %s %s %s %s %s\n",
                    t.ID,
                    t.username,
                    t.password,
                    t.email,
                    t.subject,
                    t.address,
                    t.contact);
        }

        fclose(fp);
        fclose(temp);

        remove("teachers.txt");
        rename("temp.txt", "teachers.txt");

        if (found)
        {
            processing();
            printf("\nPassword updated successfully!\n");
            break;
        }
        else
        {
            printf("Invalid ID or password!\n");
            printf("Press Enter to continue...");
            getchar();
            getchar();
        }
    }

    printf("Press Enter to continue...");
    getchar();
    getchar();
}
//-----------------------------------------------------  Invalid Choice  ----------------------------------------------------------------------

void invalidChoice()
{
    printf("Invalid Choice!\n");
    printf("Press Enter to try Again.");
    getchar();
    getchar();
}

//-----------------------------------------------------  Processing  ---------------------------------------------------------------------------

void processing()
{
    printf("loading");

    for (int i = 0; i < 10; i++)
    {
        printf(".");
        fflush(stdout);
        Sleep(500);
    }
    printf("\n");
}