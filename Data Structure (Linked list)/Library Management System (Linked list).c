#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct node
{
    char bookName[50];
    char bookType[50];
    char bookId[30];
    char bookAuthor[50];
    double bookPrice;
    struct node *next;
};

struct node *head;

void addBook()
{
    getchar();
    printf("\n########### Add Book Data ##########\n");
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("Book Name: ");
    gets(temp->bookName);
    printf("Book Type: ");
    gets(temp->bookType);
    printf("Book Id: ");
    gets(temp->bookId);
    printf("Book Author: ");
    gets(temp->bookAuthor);
    printf("Book Price: ");
    scanf("%lf",&temp->bookPrice);
    temp->next = head;
    head = temp;
    printf("\nBook Added\n");
    printf("Press any key to go back\n");
    getchar();
    getchar();
    system("cls");
    return;
}

void update()
{
    char bookI[50];
    int found = 0;
    struct node *temp = head;
    getchar();
    printf("\n########### Update a Book ##########\n");
    printf("Book Id: ");
    gets(bookI);
    while(temp!=NULL)
    {
        if(strcmp(temp->bookId, bookI)==0)
        {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found==1)
    {
        printf("\n----Old Data----\n");
        printf("Book Name: %s\n", temp->bookName);
        printf("Book Type: %s\n", temp->bookType);
        printf("Book Author: %s\n", temp->bookAuthor);
        printf("Book Price: %.2lf\n", temp->bookPrice);
        printf("--------------------------------\n");
        printf("----New Data----\n");
        printf("Book Name: ");
        gets(temp->bookName);
        printf("Book Type: ");
        gets(temp->bookType);
        printf("Book Author: ");
        gets(temp->bookAuthor);
        printf("Book Price: ");
        scanf("%lf",&temp->bookPrice);
        printf("\nData Updated\n");
    }
    else
        printf("No data found with id %s!!\n",bookI);

    printf("Press any key to go back\n");
    getchar();
    getchar();
    system("cls");
    return;
}

void search()
{
    getchar();
    char bookI[50];
    int found = 0;
    struct node *temp = head;
    getchar();
    printf("\n########### Search a Book ##########\n");
    printf("Book Id: ");
    gets(bookI);
    while(temp!=NULL)
    {
        if(strcmp(temp->bookId, bookI)==0)
        {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found==1)
    {
        printf("Book Name: %s\n", temp->bookName);
        printf("Book Type: %s\n", temp->bookType);
        printf("Book Id: %s\n", temp->bookId);
        printf("Book Author: %s\n", temp->bookAuthor);
        printf("Book Price: %.2lf\n", temp->bookPrice);
    }
    else
        printf("No data with id %s!!\n",bookI);

    printf("Press any key to go back\n");
    getchar();
    system("cls");
    return;
}

void display()
{
    struct node *temp = head;
    printf("\n############# All Books ############\n");
    while(temp!=NULL)
    {
        printf("Book Name: %s\n", temp->bookName);
        printf("Book Type: %s\n", temp->bookType);
        printf("Book Id: %s\n", temp->bookId);
        printf("Book Author: %s\n", temp->bookAuthor);
        printf("Book Price: %.2lf\n", temp->bookPrice);
        printf("--------------------------------\n");
        temp = temp->next;
    }
    printf("Press any key to go back\n");
    getchar();
    getchar();
    system("cls");
    return;
}

void removeData()
{
    char bookI[50];
    int found = 0;
    struct node *temp = head, *preTemp;
    getchar();
    printf("\n########### Remove a Book ##########\n");
    printf("Book Id: ");
    gets(bookI);
    if(strcmp(temp->bookId, bookI)==0){
        head = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL)
    {
        if(strcmp(temp->bookId, bookI)==0)
        {
            found = 1;
            break;
        }
        preTemp = temp;
        temp = temp->next;
    }
    if(found==1)
    {
        preTemp->next = temp->next;
        free(temp);
        printf("\nData Removed\n");
    }
    else
        printf("No data found with id %s!!\n",bookI);

    printf("Press any key to go back\n");
    getchar();
    system("cls");
    return;
}

int main()
{
    int n;
    head = NULL;
    while(1)
    {
        printf("\n############# Main Menu ############\n");
        printf("####################################\n");
        printf("##### 1. Add Books             #####\n");
        printf("##### 2. Search a book         #####\n");
        printf("##### 3. Display all books     #####\n");
        printf("##### 4. Remove a book         #####\n");
        printf("##### 5. Update a book data    #####\n");
        printf("##### 6. Exit                  #####\n");
        printf("####################################\n");
        printf("Reply: ");
        scanf("%d", &n);
        switch(n)
        {
        case 1:
            system("cls");
            addBook();
            break;
        case 2:
            system("cls");
            search();
            break;
        case 3:
            system("cls");
            display();
            break;
        case 4:
            system("cls");
            removeData();
            break;
        case 5:
            system("cls");
            update();
            break;
        case 6:
            return 0;
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    }
    return 0;
}
