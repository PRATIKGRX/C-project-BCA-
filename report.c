#include <stdio.h>
#include <string.h>
#include "report.h"

void createReport() {
    FILE *fp = fopen("reports.txt", "a");
    if (!fp) { printf("File error!\n"); return; }
    int studentId; char studentName[50], description[100]; float grade;
    printf("\n--- Create Report ---\nEnter Student ID: ");
    scanf("%d", &studentId); getchar();
    printf("Enter Student Name: ");
    fgets(studentName, 50, stdin); studentName[strcspn(studentName, "\n")] = '\0';
    printf("Enter Grade: ");
    scanf("%f", &grade); getchar();
    printf("Enter Description: ");
    fgets(description, 100, stdin); description[strcspn(description, "\n")] = '\0';
    fprintf(fp, "StudentID:%d\nStudentName:%s\nGrade:%.2f\nDescription:%s\n---\n", studentId, studentName, grade, description);
    fclose(fp); printf("Report saved!\n");
}

void viewAllReports() {
    FILE *fp = fopen("reports.txt", "r");
    if (!fp) { printf("No reports found!\n"); return; }
    char line[150]; printf("\n--- All Reports ---\n");
    while (fgets(line, sizeof(line), fp) != NULL) { printf("%s", line); }
    fclose(fp);
}

void deleteReport() {
    FILE *fp = fopen("reports.txt", "r"); FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) { printf("File error!\n"); return; }
    int searchId, currentId, skipBlock = 0, found = 0; char line[150];
    printf("Enter Student ID to delete: "); scanf("%d", &searchId);
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "StudentID:%d", &currentId) == 1) {
            if (currentId == searchId) { skipBlock = 1; found = 1; }
        }
        if (!skipBlock) { fprintf(temp, "%s", line); }
        if (strncmp(line, "---", 3) == 0) { skipBlock = 0; }
    }
    fclose(fp); fclose(temp);
    remove("reports.txt"); rename("temp.txt", "reports.txt");
    if (found) printf("Report deleted successfully!\n");
    else printf("Student ID not found.\n");
}

void studentWriteReport() {
    FILE *fp = fopen("reports.txt", "a");
    if (!fp) { printf("File error!\n"); return; }
    int studentId; char studentName[50], description[100];
    printf("\n--- Write Your Report ---\nEnter Your Student ID: ");
    scanf("%d", &studentId); getchar();
    printf("Enter Your Name: ");
    fgets(studentName, 50, stdin); studentName[strcspn(studentName, "\n")] = '\0';
    printf("Write Report Details: ");
    fgets(description, 100, stdin); description[strcspn(description, "\n")] = '\0';
    fprintf(fp, "StudentID:%d\nStudentName:%s\nGrade:N/A\nDescription:%s\n---\n", studentId, studentName, description);
    fclose(fp); printf("Report submitted!\n");
}

void studentViewReports() {
    FILE *fp = fopen("reports.txt", "r");
    if (!fp) { printf("No reports found!\n"); return; }
    int searchId, currentId, printBlock = 0, found = 0; char line[150];
    printf("Enter your Student ID: "); scanf("%d", &searchId);
    printf("\n--- Your Personal Reports ---\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "StudentID:%d", &currentId) == 1) { printBlock = (currentId == searchId) ? 1 : 0; }
        if (printBlock) { printf("%s", line); found = 1; }
        if (strncmp(line, "---", 3) == 0) { printBlock = 0; }
    }
    fclose(fp);
    if (!found) printf("No reports found matching your ID.\n");
}