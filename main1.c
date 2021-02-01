//
// Created by Tokoza Thawethe on 01/02/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int New_book();
int Word_search();
int Filter_search();
int Author_filter();
int Year_filter();
int Page_count_filter();
int ISBN_filter();
int Show_books();
int Delete_book();

typedef struct Book{

    char Title[100];
    char Author[100];
    int Year;
    int Pagecnt;
    int ISBN;
    struct next = book[count +1];

}Book;

typedef struct Node{
    Book date ;
    struct Node*next;
}Node;

struct Book * book;
int count ;
char save = 'n';
int size;

FILE * library;
char filename[100] = "Book Management System.txt";

int main() {

    int action;
    int searchchoice;
    char proceed = {'h'};

    printf("\nWelcome to the Legenty Book Management System!!!\n\n ");

    //Create Book Array Dynamic using size input by User
    book = malloc(sizeof(Book) * size);

    printf("Before you begin, Please answer a short question(s):\n\n");

    do {
        if(save != 'y' && save != 'n'){
            printf("Invalid Entry...\n\n");
        }

        printf("1. Would you like to save the changes you will make in a file ?\n'y' if yes\n'n' if no: ");
        gets(&save);
    }while(save !='y' && save !='n');

    printf("\nThank You!\n You may Begin.\n");

    do {

        if(proceed != 'h'){
            printf("Invalid entry...\nPlease try again!\n\n");
        }

        printf("\nWhat would you like to do:\n\n 1. New Book \n 2. Search\n 3. Show Books\n 4. Delete Book\n 5. Exit\n\n");
        scanf("%d", &action);

        fflush(stdin);

        switch (action) {
            case 1:
                New_book();
                break;

            case 2:
                printf("Would you like to perform a 1.Word search or 2.Filter:\t");
                scanf("%d", &searchchoice);

                if(searchchoice == 1){
                    Word_search();
                } else if(searchchoice == 2){
                    Filter_search();
                } else{ printf("Invalid Entry...");}
                break;

            case 3:
                Show_books();
                break;

            case 4:
                Delete_book();
                break;
            case 5:
                break;

            default:
                printf("Invalid Entry...\n\n");
        }

        if(action != 5) {
            printf("\nEnter 'h' to proceed to home page\n Enter 'f' to finish\n\n :");
            proceed = getch();
        }

    }while( proceed != 'f' && action != 5);



    if(save == 'y') {
    }
    printf("Thank you for your time :)");

    return 0;
}

int New_book(){

    count++;

    printf("Add book to Library:\n\n");
    printf("Please enter the following info:\n");

    printf("NOTE: Please enter an underscore '_' in place of any spaces\n\n");

    printf("Title:");
    scanf("%s", book[count].Title);

    printf("\nAuthor:");
    scanf("%s", book[count].Author);

    printf("\nYear:");
    scanf("%d", &book[count].Year);

    printf("\nPage count: ");
    scanf("%d", &book[count].Pagecnt);

    printf("\nISBN:");
    scanf("%d", &book[count].ISBN);

    printf( "\n\n[Book No. %d]", count);
    printf( "\nTitle : %s\n",book[count].Title);
    printf( "Author : %s\n",book[count].Author);
    printf( "Year : %d\n",book[count].Year);
    printf( "Page Count : %d\n", book[count].Pagecnt);
    printf( "ISBN : %d\n\n", book[count].ISBN);

    if(save == 'y') {

        library = fopen(filename,"w+");
        if(count > 1){
            library = fopen(filename,"a");
        }

        if (library != NULL) {

            fprintf(library, "[Book No. %d]\n", count);
            fprintf(library, "Title : %s\n", book[count].Title);
            fprintf(library, "Author : %s\n", book[count].Author);
            fprintf(library, "Year : %d\n", book[count].Year);
            fprintf(library, "Page Count : %d\n", book[count].Pagecnt);
            fprintf(library, "ISBN : %d\n\n", book[count].ISBN);
            fclose(library);

        }else{
            printf("\nError while accessing File: Library");
        }}

    return count;
}

int Word_search(){

    char s_title[20];
    int i;

    printf("\n\nEnter a title to search:");
    scanf("%s", s_title);


    for (i = 1; i != (count + 1); i++) {

        if (strcmp(book[i].Title, s_title) == 0) {

            printf("\n\n[Book No.: %d]\n", i);
            printf("Title:%s\n", book[i].Title);
            printf("Author: %s\n", book[i].Author);
            printf("Year: %d\n", book[i].Year);
            printf("Page count: %d\n", book[i].Pagecnt);
            printf("ISBN: %d\n\n", book[i].ISBN);
        }}
    if(save == 'y') {
        library = fopen(filename, "a+");
        if(library != NULL) {

            fread(book,sizeof(struct Book),count, library);

            for (i = 1; i != (count + 1); i++) {

                if (strcmp(book[i].Title, s_title) == 0) {

                    fprintf(library, "\n\nSearch Results:\n\n");
                    fprintf(library, "[Book No.: %d]\n", i);
                    fprintf(library, "Title:%s\n", book[i].Title);
                    fprintf(library, "Author: %s\n", book[i].Author);
                    fprintf(library, "Year: %d\n", book[i].Year);
                    fprintf(library, "Page count: %d\n", book[i].Pagecnt);
                    fprintf(library, "ISBN: %d\n\n", book[i].ISBN);


                }}}}

    printf("Search is Complete.\n\n");

    return count;
}

int Filter_search(){

    int fchoice;

    printf( "\nFilter by :\n\n1.Title \n2.Author \n3.Year of Publication \n4.No. of Pages \n5.ISBN No.\n\n :");
    scanf("%d", &fchoice);

    switch(fchoice){
        case 1:
            Word_search();
            break;
        case 2:
            Author_filter();
            break;
        case 3:
            Year_filter();
            break;
        case 4:
            Page_count_filter();
            break;
        case 5:
            ISBN_filter();
            break;
        default:
            printf("Invalid Entry...");
            return 0;
    }

    printf("Filter Complete!\n\n");

    return 0;
}

int Author_filter() {

    char s_author[20];
    int i;

    printf("\n\nEnter the author name to search: ");
    scanf("%s", s_author);

    for (i = 1; i != (count + 1); i++) {

        if (strcmp(book[i].Author, s_author) == 0) {

            printf("\n\n[Book No.: %d]\n", i);
            printf("Title:%s\n", book[i].Title);
            printf("Author: %s\n", book[i].Author);
            printf("Year: %d\n", book[i].Year);
            printf("Page count: %d\n", book[i].Pagecnt);
            printf("ISBN: %d\n\n", book[i].ISBN);
        }}

    if (save == 'y') {
        library = fopen(filename, "a+");
        if (library != NULL) {

            fread(book,sizeof(struct Book),count, library);

            for (i = 1; i != (count + 1); i++) {

                if (strcmp(book[i].Author, s_author) == 0) {

                    fprintf(library, "Search Results:\n\n");
                    fprintf(library, "[Book No.: %d]\n", i);
                    fprintf(library, "Title:%s\n", book[i].Title);
                    fprintf(library, "Author: %s\n", book[i].Author);
                    fprintf(library, "Year: %d\n", book[i].Year);
                    fprintf(library, "Page count: %d\n", book[i].Pagecnt);
                    fprintf(library, "ISBN: %d\n\n", book[i].ISBN);
                }}}

        return count;
    }
    return 0;
}

int Year_filter() {

    int s_year;
    int i;

    printf("\n\nEnter a year: ");
    scanf("%d", &s_year);

    for (i = 1; i != (count + 1); i++) {

        if (book[i].Year == s_year) {

            printf("\n\n[Book No.: %d]\n", i);
            printf("Title:%s\n", book[i].Title);
            printf("Author: %s\n", book[i].Author);
            printf("Year: %d\n", book[i].Year);
            printf("Page count: %d\n", book[i].Pagecnt);
            printf("ISBN: %d\n\n", book[i].ISBN);
        }}

    if (save == 'y') {
        library = fopen(filename, "a+");
        if (library != NULL) {

            fread(book,sizeof(struct Book),count, library);

            for (i = 1; i != (count + 1); i++) {

                if (book[i].Year == s_year) {

                    fprintf(library, "Search Results:\n\n");
                    fprintf(library, "[Book No.: %d]\n", i);
                    fprintf(library, "Title:%s\n", book[i].Title);
                    fprintf(library, "Author: %s\n", book[i].Author);
                    fprintf(library, "Year: %d\n", book[i].Year);
                    fprintf(library, "Page count: %d\n", book[i].Pagecnt);
                    fprintf(library, "ISBN: %d\n\n", book[i].ISBN);
                }}}}

    return count;
}

int Page_count_filter(){

    int s_pgcnt;
    int i;

    printf("\n\nEnter a Page count: ");
    scanf("%d", &s_pgcnt);

    for (i = 1; i != (count + 1); i++) {

        if (book[i].Pagecnt == s_pgcnt) {

            printf("\n\n[Book No.: %d]\n", i);
            printf("Title:%s\n", book[i].Title);
            printf("Author: %s\n", book[i].Author);
            printf("Year: %d\n", book[i].Year);
            printf("Page count: %d\n", book[i].Pagecnt);
            printf("ISBN: %d\n\n", book[i].ISBN);

        }
    }

    if(save == 'y') {
        library = fopen(filename, "a+");
        if (library != NULL) {

            fread(book,sizeof(struct Book),count, library);

            for (i = 1; i != (count + 1); i++) {

                if (book[i].Pagecnt == s_pgcnt) {

                    fprintf(library, "Search Results:\n\n");
                    fprintf(library, "[Book No.: %d]\n", i);
                    fprintf(library, "Title:%s\n", book[i].Title);
                    fprintf(library, "Author: %s\n", book[i].Author);
                    fprintf(library, "Year: %d\n", book[i].Year);
                    fprintf(library, "Page count: %d\n", book[i].Pagecnt);
                    fprintf(library, "ISBN: %d\n\n", book[i].ISBN);
                }}}}

    return count;
}

int ISBN_filter() {

    int s_isbn;
    int i;

    printf("\n\nEnter a ISBN: ");
    scanf("%d", &s_isbn);

    for (i = 1; i != (count + 1); i++) {

        if (book[i].ISBN == s_isbn) {

            printf("\n\n[Book No.: %d]\n", i);
            printf("Title:%s\n", book[i].Title);
            printf("Author: %s\n", book[i].Author);
            printf("Year: %d\n", book[i].Year);
            printf("Page count: %d\n", book[i].Pagecnt);
            printf("ISBN: %d\n\n", book[i].ISBN);
        }
    }
    if (save == 'y') {
        library = fopen(filename, "a+");
        if (library != NULL) {

            fread(book,sizeof(struct Book),count, library);

            for (i = 1; i != (count + 1); i++) {

                if (book[i].ISBN == s_isbn) {

                    fprintf(library, "Search Results:\n\n");
                    fprintf(library, "[Book No.: %d]\n", i);
                    fprintf(library, "Title:%s\n", book[i].Title);
                    fprintf(library, "Author: %s\n", book[i].Author);
                    fprintf(library, "Year: %d\n", book[i].Year);
                    fprintf(library, "Page count: %d\n", book[i].Pagecnt);
                    fprintf(library, "ISBN: %d\n\n", book[i].ISBN);

                }}}}

    return count;
}

int Show_books(){

    int i;

    for(i = 1;i < count+1;i++) {

        printf("\nBook Number: %d", i);
        printf("\nTitle : %s\n", book[i].Title);
        printf("Author : %s\n", book[i].Author);
        printf("Year : %d\n", book[i].Year);
        printf("Page Count : %d\n", book[i].Pagecnt);
        printf("ISBN : %d\n", book[i].ISBN);
    }

    if(save == 'y') {

        library = fopen(filename, "a+");
        if(library != NULL) {

            fread(book,sizeof(struct Book),count, library);

            for (i = 0; i < 5; i++) {

                fprintf(library,"\nBook Number: %d", i);
                fprintf(library,"\nTitle : %s\n", book[i].Title);
                fprintf(library,"Author : %s\n", book[i].Author);
                fprintf(library,"Year : %d\n", book[i].Year);
                fprintf(library,"Page Count : %d\n", book[i].Pagecnt);
                fprintf(library,"ISBN : %d\n\n", book[i].ISBN);
                fclose(library);

            }} else{
            printf("Error accessing file: Library...");
        }
        printf("\nThere are %d book(s) in total currently in the library\n\n", count);
        puts("Library read successfully\n\n");
    }
    return count;
}

int Delete_book() {

    int book_num = 0;
    int i;

    for(i = 1;i != count+1;i++) {

        printf("\nBook Number: %d", i);
        printf("\nTitle : %s\n", book[i].Title);
        printf("Author : %s\n", book[i].Author);
        printf("Year : %d\n", book[i].Year);
        printf("Page Count : %d\n", book[i].Pagecnt);
        printf("ISBN : %d\n", book[i].ISBN);
    }

    printf("\n\nEnter number of Book to be deleted: ");
    scanf("%d", &book_num);

    if(book_num > count){
        printf("Invalid Book number...\n\n");
        return 0;
    }
    if(save == 'n'){
        for(i = count - 1;i < count + 1; i++){

            book[book_num] = book[book_num + 1];

        }
        count-=1;

        for(i = 1;i != count+1;i++) {

            printf("\nBook Number: %d", i);
            printf("\nTitle : %s\n", book[i].Title);
            printf("Author : %s\n", book[i].Author);
            printf("Year : %d\n", book[i].Year);
            printf("Page Count : %d\n", book[i].Pagecnt);
            printf("ISBN : %d\n", book[i].ISBN);
        }}

    if(save == 'y') {

        library = fopen(filename, "a+");
        if (library != NULL){
        fread(book, sizeof(struct Book), 1, library);

        for (i = 1; i != count; i++) {

            if (book[i].Title == book[book_num].Title) {

                free(book[i].Title);
                free(book[i].Author);
                free(&book[i].Year);
                free(&book[i].Pagecnt);
                free(&book[i].ISBN);
            }}

    book[book_num] = book[book_num+1];

    for(i = count - 1;i < count + 1; i++){

        book[book_num] = book[book_num + 1];

    }
    count--;

    for(i = 1;i != count+1;i++) {

        printf("\nBook Number: %d", i);
        printf("\nTitle : %s\n", book[i].Title);
        printf("Author : %s\n", book[i].Author);
        printf("Year : %d\n", book[i].Year);
        printf("Page Count : %d\n", book[i].Pagecnt);
        printf("ISBN : %d\n", book[i].ISBN);
    }

    for(i = 1;i != count+1;i++) {

        fprintf(library, "[Book No. %d]\n", count);
        fprintf(library, "Title : %s\n", book[count].Title);
        fprintf(library, "Author : %s\n", book[count].Author);
        fprintf(library, "Year : %d\n", book[count].Year);
        fprintf(library, "Page Count : %d\n", book[count].Pagecnt);
        fprintf(library, "ISBN : %d\n\n", book[count].ISBN);
    }
        fclose(library);
        }else{printf("Error whilst accessing file\n\n")}}

    printf("Book Deletion Complete\n\nThere are %d books remaining.\n\n",count+1);

    return count;
}



