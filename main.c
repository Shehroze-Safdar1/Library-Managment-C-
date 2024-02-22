/* Author and System Information
   author_name         = Muhammad Shahroze
   program_name        = Library Managment System
   programming_laguage = C
   operating_system    = Windows_10
   ide                 = code-blocks-20.03
   start_date          = 3-June-2022
   end_date            = 12-June-2022
*/
/* Purpose Of Program
   The main purpose of this program is to make a library system in which user can add,
   delete,display,update and issue a book
*/
/* Input-Processing-Output
   •Input:
    o Name Of Book
    o Id Of Book
    o ISBN Number of Book
   •Processing:
    o Structures
    o Arrays
    o String
    o Loops
    o If-Else if
    o printf
    o scanf
   •Output:
    o Add A Book
    o Display A Book
    o Issue A Book
    o Delete A Book
    o Update A Book
*/
//Write the program
//Import Libraries
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//Declaring functions

void addbook();
void displaybook();
void deletebook();
void searchbyname();
void searchISBN();
void searchID();
void updatebook();
void issuebook();

//Declaring Structures for Library
struct book
{
    char bookname[50];
    char author[50];
    char is_reserved[50];
    int id;
    int isbn;
    int edition;
}data[5];//Intializing structure element outside main
struct student
{
    char studentname[50];
    char studentclass[50];
    char book_name[50];
    int rollno;
    int id;
}s;//Intializing structure element outside main
int i;

int main()//Start of main
{
  char choice;
      printf("<<<<<===LIBRARY MANAGMENT SYSTEM===>>>>>\n");//Menu For User
      printf("a = Add new book\n");
      printf("b = Display books\n");
      printf("s = Search books\n");
      printf("Search Books By:\n");
      printf("        A.Search By ISBN:\n");
      printf("        B.Search By Book Name\n");
      printf("        C.Search By Book Id\n");
      printf("d = Delete Books\n");
      printf("u = Update a Book\n");
      printf("i = Issue a Book\n");
      printf("q = Quit the program\n");

  while(1)//While Loop
  {
      printf("\nEnter a=add book\n b=display book\n A=search by ISBN\n B=search by name\n C=search by Id\n u=update book\n d=delete book\n i=issue book\n q=quit\n : ");
      choice=getche();

      if(choice=='a')
        addbook();
      else if(choice=='b')
        displaybook();
      else if(choice=='d')
        deletebook();
      else if(choice=='A')
        searchISBN();
      else if(choice=='B')
        searchbyname();
      else if(choice=='C')
        searchID();
      else if(choice=='u')
        updatebook();
      else if(choice=='i')
        issuebook();
      else if(choice=='q')
        exit(1);
      else
        printf("Invalid Input\n");
  }
  printf("Press any key to continue....");
}
void addbook()
{
    system("cls");//Clearing the screen
    FILE *fp;
    for(int i=0;i<5;i++)//Taking input from user.
    {
        printf("Enter Book%d data  \n",i+1);
        printf("Enter book name : ");
        fflush(stdin);
        gets(data[i].bookname);
        printf("Enter author name : ");
        fflush(stdin);
        gets(data[i].author);
        printf("Enter book id : ");
        scanf("%d",&data[i].id);
        printf("Enter book isbn : ");
        scanf("%d",&data[i].isbn);
        printf("Enter book's edition : ");
        scanf("%d",&data[i].edition);
        printf("\n\n");
        printf("Book has been added successfully!!\n");
    }
    fp=fopen("library.txt","w");//Opening file in write mode
    for(int i=0;i<5;i++){
        fwrite(&data[i], sizeof(struct book), 1,fp);//Writing records in file
    }
    fclose(fp);
}
void displaybook()
{
   system("cls");
   FILE *fp;
   printf("\n<<<<<===AVAILABLE BOOKS====>>>>\n");
//Opening file in read mode.
   fp=fopen("library.txt","r");
//Displaying the records using while loop.
   while(fread(&data[i], sizeof(data[i]), 1, fp) == 1)
   {
    printf("Book:- \nBook name : %s\nAuthor name : %s\nId : %d\nISBN : %d\nEdition : %d\n\n",&data[i].bookname,&data[i].author,data[i].id,data[i].isbn,data[i].edition);
   }
   fclose(fp);

}
//End of displaybooks

void searchISBN()
{
   FILE *fp;
    system("cls");
    int b_isbn;
    int result;
//Opening file in read mode.
    fp=fopen("library.txt","r");
    for(int i=0;i<5;i++)
    {
      fread(&data[i], sizeof(struct book), 1,fp);
    }
      fclose(fp);

    printf("Enter the ISBN of book you want : ");//Taking input from user
    scanf("%d",&b_isbn);
    for(int i=0;i<5;i++)
    {
//Comparing input with structure elements
        result=data[i].isbn;
        if(result==data[i].isbn)
        {
            break;
        }
    }
    if(result==data[i].isbn)
    {
        printf("Yes we have this book");
    }
    else
    {
        printf("Sorry! we don't have this book");
    }
}
//end of search by ISBN

void searchbyname()
{
    system("cls");
    FILE *fp;
    char bname[30];
    int result;
    fp=fopen("library.txt","r");
    for(int i=0;i<5;i++)
    {
     fread(&data[i], sizeof(struct book), 1,fp);
    }
     fclose(fp);

    printf("Which book do you want : ");
//Taking input in form of string
    gets(bname);
//Comparing two string by strcmp function
    for(int i=0;i<5;i++)
    {
        result=strcmp(bname,data[i].bookname);
        if(result==0)
        {
            break;
        }
    }
        if(result==0)
     {
        printf("Yes we have this book");
     }
     else
     {
        printf("Sorry! we don't have this book");
     }
}
//end of search by name

void searchID()
{
    FILE *fp;
    system("cls");
    int b_id;
    int result;
    fp=fopen("library.txt","r");
    for(int i=0;i<5;i++){
        fread(&data[i], sizeof(struct book), 1,fp);
    }
    fclose(fp);

    printf("Enter the Id of Book you want : ");
    scanf("%d",&b_id);
    for(int i=0;i<5;i++)
    {
        result=data[i].id;
        if(result==data[i].id)
        {
            break;
        }
    }
    if(result==data[i].id)
    {
        printf("Yes we have this book");
    }
    else
    {
        printf("Sorry! we don't have this book");
    }
}
// end of search by id

void updatebook()
{
     struct book b1[5];
  FILE *fp;
  int i;
  char new_name[10],old_name[10];
  fp=fopen("D:/library.txt","r");
  for(i=0;i<5;i++)
  {
    fscanf(fp,"%s %s %d %d %d %d\n",b1[i].bookname,b1[i].author,&b1[i].isbn,&b1[i].id,&b1[i].edition,&b1[i].is_reserved);
  }
  printf("\nEnter old name: ");
  gets(old_name);
  printf("Enter new name: ");
  gets(new_name);
  int j,result;
  for(j=0;j<5;j++)
  {
    result=strcmp(b1[j].bookname,old_name);
    if (result==0)
    {
        strcpy(b1[j].bookname,new_name);
        break;
    }
  }
  FILE *ip;
  int k;
  ip=fopen("D:/library.txt","w");
  for(k=0;k<5;k++)
  {
    fprintf(ip,"%s %s %d %d %d %d\n",b1[k].bookname,b1[k].author,b1[k].isbn,b1[k].id,b1[k].edition,b1[k].is_reserved);
  }
  printf("Your Record has been updated successfuly");

  fclose(ip);
}
//end of update book

void deletebook()
{
    system("cls");
    FILE*fp;
    int id,f=0;
    printf("<== Remove Books ==>\n\n");
    printf("Enter Book id to remove: ");
    scanf("%d",&id);
    FILE*ft;
    fp=fopen("library.txt","r");
//Creating a temperory file for saving records
    ft=fopen("temp.txt","w");
//Comparing data enter by user with structure elements(id).
    while(fread(&data[i],sizeof(struct book),1,fp) == 1)
    {
        if(id == data[i].id)
        {
            f=1;
        }
    else
        {
            fwrite(&data[i],sizeof(struct book),1,ft);
        }
    }
        if(f==1)
        {
            printf("\n\nBook successfully deleted");
        }
        else
        {
            printf("\n\nRecord not found");
        }

    fclose(fp);
    fclose(ft);

    remove("library.txt");
    rename("temp.txt", "library.txt");
}
//end of deletebook

void issuebook()
{
    system("cls");
    FILE*fp;
    int f=0;
//Taking input from student
    printf("<== Issue Books ==>\n\n");
    printf("Enter Book id to issue: ");
    scanf("%d", &s.id);
    fp=fopen("library.txt","r");
    for(i=0;i<5;i++)
    {
        fread(&data[i],sizeof(struct book),1,fp);
//Comparing student id entered with book id(structure element)
        if(data[i].id==s.id)
        {
//Using the function of strcpy to copy book entered by student in structure of book.
            strcpy(s.book_name,data[i].bookname);
            f=1;
            break;
        }
    }
    if(f==0)
    {
        printf("No book found with this id\n");
        printf("Please try again...\n\n");
        return;
    }
//Opening file to save student record
    fp=fopen("student.txt","w");
    printf("Enter Student Name: ");
    fflush(stdin);
    gets(s.studentname);

    printf("Enter Student Class: ");
    fflush(stdin);
    gets(s.studentclass);

    printf("Enter Student Roll: ");
    scanf("%d", &s.rollno);

    printf("Book Issued Successfully\n\n");
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
}




