#include <stdio.h>
#include <stdlib.h>
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
     

int main() {
     while (1) {
        teacherslogin(); 
    }  
    return 0;
}