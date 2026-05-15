// teacher.c
#include <stdio.h>
#include "teacher.h"

void viewProfile() {
    printf("Viewing profile...\n");
}

void editProfile() {
    printf("Editing profile...\n");
}

void addGrades() {
    printf("Adding grades...\n");
}

void editGrades() {
    printf("Editing grades...\n");
}

void handleReports() {
    printf("Handling reports...\n");
}

void invalidChoice() {
    printf("Invalid Choice!\n");
    printf("Press Enter to try Again.");
    getchar();
    getchar();
}