/*
    County Library System
    By Trappy
    7th feb 2022
    MIT license
    C99 Compiler
*/
#include <stdio.h>
#include <stdlib.h>

void execute_action(int action);
int menu(){
    int action;
        printf("Select An Action Below...\n");
        printf("1. Add New Patron\n");
        printf("2. View All Patrons\n");
        printf("3. Add New Resources\n");
        printf("4. View All Resources\n\n");
        printf("Your Selection: \n");
        scanf("%d", &action);
        if (action < 1 || action > 4){
            printf("Invalid Action. Try Again!\n\n");
        }
        return action;
}

void execute_action(int action) {
    switch (action) {
    case 1:
        printf("Adding New Patron\n");
        break;
    case 2:
        printf("Here is the list of Patron\n");
        break;
    case 3:
        printf("Adding New Resources\n");
        break;
    case 4:
        printf("Here Is the list of Resources\n");
        break;
    default:
        printf("Wrong Entry\n");

    }

}

int main(){
    int action;
    char title[100] = "COUNTY LIBRARY SYSTEM";
    char status[100] = "Welcome Weston";
    printf("\n\n\n\t\t\t   *********************\n\t\t\t%s\n \t\t\t    %s\n\t\t\t   ********************\n\n", title, status);
    action = menu();
    execute_action(menu());
    return 0;
}
