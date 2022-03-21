/*
    County Library System
    By Trappy
    7th feb 2022
    MIT license
    C99 Compiler
*/
#include <stdio.h>
#include <stdlib.h>


struct Patron{
    char name[100];
    char email[50];
    char password [30];
    int is_staff;
};

struct Resources{
    char title[100];
    char subject[100];
    char author[100];
    char edition[30];
    int is_book;
};

void add_patron()
{
    struct Patron patron;
    printf("Enter Name: ");
    getchar();
    gets(patron.name);
    printf("Enter Your Email: ");
    gets(patron.email);
    printf("Enter Initial Password: ");
    gets(patron.password);
    printf("Enter 1 If Staff 0 Otherwise: ");
    scanf("%d", &patron.is_staff);
    printf("Patron %s Successfully Added To The System\n", patron.name);


}

void add_resources()
{
    struct Resources resources;
    printf("Enter Book Title : ");
    getchar();
    gets(resources.title);
    printf("Enter Subject : ");
    gets(resources.subject);
    printf("Enter Book Author: ");
    gets(resources.author);
    printf("Enter Book Edition: ");
    gets(resources.edition);
    printf("Enter 1 If Book 0 Otherwise: ");
    scanf("%d", &resources.is_book);
    printf("Resources %s Successfully Added To The System\n", resources.title);

}
int menu(){
    int action;
        printf("Select An Action Below...\n\n");
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
        add_patron();
        break;
    case 2:
        printf("Here Is the List of Patrons");
        break;
    case 3:
       add_resources();
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
    char title[100] = "COUNTY LIBRARY MANAGEMENT";
    char status[100] = "Welcome Weston";
    printf("\n\n\n\t\t\t   *********************\n\t\t\t%s\n \t\t\t    %s\n\t\t\t   ********************\n\n", title, status);
    execute_action(menu());
    return 0;
}
