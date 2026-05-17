#include<stdio.h>
#include<string.h>
#include<ctype.h>
int verifyOldPassword(char oldPassword[],char savedPassword[])
{
    char oldPassword[50];
    printf("Enter old password: ");
    scanf("%s", oldPassword);
    if(strcmp(oldPassword, savedPassword) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validatePasswordStrength(char password[])
{
    int i,upper = 0,lower = 0,digit = 0,special = 0;
    if(strlen(password)<8)
    {
        return 0;
    }
    for(i = 0; password[i]!= '\0'; i++)
    {
        if(isupper(password[i]))
            upper = 1;
        else if(islower(password[i]))
            lower = 1;
        else if(isdigit(password[i]))
            digit = 1;
        else
            special = 1;
    }
    if(upper&&lower&&digit&&special)
    {
        return 1;
    }
    return 0;
}
void changePassword()
{
    char newPassword[50];
    char oldPassword[50];
    char confirmPassword[50];
    char savedPassword[30] = "Admin@123";
    printf("Enter old password: ");
    scanf("%s", oldPassword);
    if(!verifyOldPassword(oldPassword,savedPassword))
    {
        printf("Incorrect old password\n");
        return;
    }
    printf("Enter new password: ");
    scanf("%s", newPassword);
    if(!validatePasswordStrength(newPassword))
    {
        printf("Weak password\n");
        printf("Password must contain:\n");
        printf("- At least 8 characters\n");
        printf("- Uppercase letter\n");
        printf("- Lowercase letter\n");
        printf("- Number\n");
        printf("- Special character\n");
        return;
    }
   printf("Confirm new password: ");
    scanf("%s", confirmPassword);

    if(strcmp(newPassword, confirmPassword) != 0)
    {
        printf("Password does not match\n");
        return;
    }
    strcpy(savedPassword, newPassword);
    printf("Password changed successfully\n");
}