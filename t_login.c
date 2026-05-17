// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <windows.h>
// // #include "teacher.h"

// struct Teacher {
//         int ID;
//         char username[50];
//         char password[50];
//         char email[100];
//         char subject[50];
//         char address[100];
//         char contact[40];
//     };
     

// void teacherslogin() {
   
//     while (1) {
//         system("cls");
//         int choice;
//         printf("\n===================================\n");
//         printf("       SCHOOL MANAGEMENT SYSTEM       ");
//         printf("\n===================================\n");

//         printf("----------------------------------\n");
//         printf("           Teacher's Login:          ");
//         printf("\n----------------------------------\n\n");

//         printf("1. Login\n");
//         printf("2. Create New Account\n");
//         printf("3. Exit\n\n");
//         printf("Enter choice: ");
//         scanf("%d", &choice);

//         if (choice == 1) {
//             printf("Login selected\n\n");
//             processing();  
//             login();
//               break;
//         }
//         else if (choice == 2) {
//             printf("Create New Account selected\n\n");
//             processing();  
//             teachersaccount();
//             break;
//         }
//         else if (choice == 3) {
//             printf("Exiting...\n");
//             processing();  
            
//         }
//         else {
//             invalidChoice();
//         }
//     }

// }


// //--------------------------------------------------------  LOGIN  ---------------------------------------------------------------------

// void login(){
//   system("cls");
//   printf("\n----------------------------------\n");
//   printf("                Login:               ");
//   printf("\n----------------------------------\n\n");

//   struct Teacher t;
//   int enterid; 
//   char enterpassword[20];

//   printf("Enter ID: ");
//   scanf("%d", &enterid);

//   printf("Enter Password: ");
//   scanf("%s", enterpassword);

//   FILE *fp;
//     fp = fopen("teachers.txt", "r");

//     if (fp == NULL) {
//         printf("File cannot open!\n");
//         return;
//     }
    
//     while (fscanf(fp, "%d %s %s %s %s %s %s", 
//                     &t.ID, 
//                     t.username, 
//                     t.password, 
//                     t.subject, t
//                     .email, 
//                     t.address, 
//                     t.contact) == 7)  {

//                 if (enterid == t.ID && strcmp(enterpassword, t.password) == 0) {
//                     printf("Login successful!\n");
//                     fclose(fp);
//                     processing();  
//                     teachersmenu();
//                     return;
                    
//                 }
//     }
//      fclose(fp);
//     printf("Invalid ID or password!\n");
//     invalidChoice();

// }


// //--------------------------------------------------------  CREATE TEACHER'S ACCOUNT ---------------------------------------------------------

   
// void teachersaccount() {
//     while (1) {
//         system("cls");

//         printf("\n----------------------------------\n");
//         printf("          Create New Account:         ");
//         printf("\n----------------------------------\n\n");
 
//     struct Teacher t;
//     FILE *fp;
//     fp = fopen("teachers.txt", "a");

//     if (fp == NULL) {
//         printf("File cannot open!\n");
//         return;
//     }

//     printf("Enter Teacher ID: ");
//     scanf("%d", &t.ID);

//     printf("Enter Username: ");
//     scanf("%s", t.username);

//     printf("Enter Password: ");
//     scanf("%s", t.password);

//     printf("Enter Email: ");
//     scanf("%s", t.email);

//     printf("Enter Subject: ");
//     scanf("%s", t.subject);

//     printf("Enter Address: ");
//     scanf("%s", t.address);

//     printf("Enter Contact: ");
//     scanf("%s", t.contact);

//     fprintf(fp, "%d %s %s %s %s %s %s\n",
//             t.ID,
//             t.username,
//             t.password,
//             t.email,
//             t.subject,
//             t.address,
//             t.contact);

//     fclose(fp);

//     printf("Account created successfully!\n");

//     printf("Press Enter to continue...");
//     getchar();
//     getchar();
//     return;
// }
// }

// //---------------------------------------------------------- EXIT -----------------------------------------------------------------------
