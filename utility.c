#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void clearScreen()
{
    system("cls");
}
void pauseScreen()
{
    printf("Press Enter to continue./n");
    getchar();
}
void printLine()
{
    printf("\n-----------------------------------------------------------\n");
}
void loadingAnimation()
{
    printf("loading...");
    Sleep(1500);
}
void invalidChoice(){
    printf("Invalid Choice!\n");
    printf("Press Enter to try Again.");
    getchar();
    getchar();
}