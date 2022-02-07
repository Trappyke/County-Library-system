/*
    County Library System
    By Trappy
    7th feb 2022
    MIT license
    C99 Compiler
*/
#include <stdio.h>
#include <stdlib.h>

int menu(){
    int action;
        printf("Select An Action Below...\n");
        printf("1. Add New Patron\n");
        printf("2. View All Patrons\n");
        printf("3. Add New Resources\n");
        printf("4. View All Resources\n");
        printf("Your Selection: \n");
        scanf("%d", &action);
        return action;
}
int main(){
    int action;
    printf("COUNTY LIBRARY SYSTEM\n");
    printf("Welcome Trappy!\n");
    action = menu();
    printf("Your Selection: %d\n");
    return 0;
}
