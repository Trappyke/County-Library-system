/*
    County Library System
    By WESTON WANJOHI
    7th feb 2022
    MIT license
    C99 Compiler
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Patron {
    char name[100];
    char password[30];
    char email[50];
    int is_staff;
};

struct Book{
    char title[100];
    char subject[100];
    char author[100];
    char edition[30];
    int is_book;
};

int save_patron(struct Patron patron);
void add_patron();
void add_book();
int menu();
void execute_action(int action);
void view_patrons();
void view_book();


int main()
{
    while(1){
    	printf("\t\t\t###########################################################################");
    	printf("\n\t\t\t############                                                   ############");
    	printf("\n\t\t\t############      COUNTY LIBRARY MANAGEMENT SYSTEM             ############");
    	printf("\n\t\t\t############                                                   ############");
   		printf("\n\t\t\t###########################################################################\n");
    	execute_action(menu());
    	printf("\n\n\n\t\t\t Enter any key to continue");
        getch();
        system("cls");
    }
    return 0;
}

int save_patron(struct Patron patron){
    FILE *fp;
    fp = fopen("patrons","ab");
    fwrite(&patron,sizeof(struct Patron),1,fp);
    fclose(fp);
    return 1;
}

int save_book(struct Book book){
    FILE *fp;
    fp = fopen("book","cb");
    fwrite(&book,sizeof(struct Book),1,fp);
    fclose(fp);
    return 1;
}

void add_patron() {
    struct Patron patron;
    system("cls");
    printf("\t\t\tAdding New Patron");
    printf("\n\t\t\t\t\tEnter Name: ");
    getchar();
    gets(patron.name);
    printf("\t\t\t\t\tEnter Your Email: ");
    gets(patron.email);
    printf("\t\t\t\t\tEnter Initial Password: ");
    gets(patron.password);
    printf("\t\t\t\t\tEnter 1 If Staff 0 Otherwise: ");
    scanf("%d", &patron.is_staff);
    if(save_patron(patron))
        printf("\t\t\t\t\tPatron %s Successfully Added To The System\n", patron.name);
    else
        printf("\t\t\t\t\tUnsuccessful\n");

}

void add_book()
{
    struct Book book;
    system("cls");
    printf("\t\t\tAdding New Book");
    printf("\n\t\t\t\t\tEnter Book Title : ");
    getchar();
    gets(book.title);
    printf("\t\t\t\t\tEnter Subject : ");
    gets(book.subject);
    printf("\t\t\t\t\tEnter Book Author: ");
    gets(book.author);
    printf("\t\t\t\t\tEnter Book Edition: ");
    gets(book.edition);
    printf("\t\t\t\t\tEnter 1 If Book 0 Otherwise: ");
    scanf("%d", &book.is_book);
    if(save_book(book))
        printf("\t\t\t\t\tResources %s Successfully Added To The System\n", book.title);
    else
        printf("\t\t\t\t\tUnsuccessful\n");

}

int menu()
{
  int action;
	char name[100];
	printf("\n\t\t\tEnter Your Name:");
	gets(name);
    printf("\n\t\t\tHello %s, What would you like to do??", name);
    printf("\n\n\t\t\t                   +++++++++++++++++++++++++++++++++++++++++++");
    printf("\n\t\t\t                   ++++++++++++++++   MENU   +++++++++++++++++");
    printf("\n\t\t\t                   +++++++++++++++++++++++++++++++++++++++++++");
	printf("\n\t\t\t                   ++                                       ++");
    printf("\n\t\t\t                   ++         1. Add New Patron             ++");
    printf("\n\t\t\t                   ++         2. View All Patrons           ++");
    printf("\n\t\t\t                   ++         3. Add New Book               ++");
    printf("\n\t\t\t                   ++         4. View All Resources         ++");
    printf("\n\t\t\t                   ++         5. Log Out                    ++");
    printf("\n\t\t\t                   ++                                       ++");
    printf("\n\t\t\t                   +++++++++++++++++++++++++++++++++++++++++++");
    printf("\n\t\t\t                   +++++++++++++++++++++++++++++++++++++++++++");
        
    printf("\n\t\t\tYour Selection: \n");
  	scanf("%d",&action);
  	if(action < 1 || action > 4) {
    	printf("\t\t\tInvalid action. Try again\n");
  }
  return action;
}

void execute_action(int action) {
    switch(action) {
    case 1:
        add_patron();
        break;
    case 2:
        view_patrons();
        break;
    case 3:
        add_book();
        break;
    case 4:
        view_book();
        break;
    default:
        printf("\t\t\tWrong Entry.\n");
    }
}

void view_patrons() {
    FILE *fp;
    struct Patron patron;
    if((fp = fopen("patrons","rb")) == NULL) {
        printf("\t\t\tUnable to open file.\n");
        return;
    }
    printf("\t\t\t%-20s%-30s%-10s\n","NAME","EMAIL","IS STAFF");
    while(!feof(fp)){
       fread(&patron,sizeof(struct Patron),1,fp);
       printf("\t\t\t%-20s",patron.name);
       printf("\t\t\t%-30s",patron.email);
       printf("\t\t\t%-10d\n",patron.is_staff);
    }

    fclose(fp);
}

void view_book() {
    FILE *fp;
    struct Book book;
    if((fp = fopen("books","cb")) == NULL) {
        printf("\t\t\tUnable to open file.\n");
        return;
    }
    printf("\t\t\t%-20s%-30s%-20s%-20s%-10s\n","TITLE","SUBJECT","AUTHOR","EDITION","IS BOOK");
    while(!feof(fp)){
       fread(&book,sizeof(struct Book),1,fp);
       printf("\t\t\t%-20s",book.title);
       printf("\t\t\t%-30s",book.subject);
       printf("\t\t\t%-20s",book.author);
       printf("\t\t\t%-20s",book.edition);
       printf("\t\t\t%-10d\n",book.is_book);
    }

    fclose(fp);
}
