#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct node
{
    char name[60];
    char id[30];
    char contact[30];
    struct node *next;
};
struct node *head;

void display()
{
    getchar();
    struct node* temp = head;
    printf("\n########### Students ###########\n");
    while(temp!=NULL)
    {
        printf("Name: %s\n",temp->name);
        printf("Id: %s\n",temp->id);
        printf("Contact: %s\n",temp->contact);
        printf("--------------------------------\n");
        temp = temp->next;
    }
    printf("\npress any key for back\n");
    getchar();
    system("cls");
    return;
}

void update()
{
    printf("\n########## Update ###########\n");
    char id[30];
    int found = 1;
    printf("Enter Id: ");
    getchar();
    gets(id);
    struct node *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->id, id)==0)
        {
            found = 1;
            break;
        }
        temp = temp->next;
        found = 0;
    }
    if(found)
    {
        printf("Old Name : %s\n",temp->name);
        printf("Old Contact: %s\n",temp->contact);
        printf("New data:\n");
        printf("Name :");
        gets(temp->name);
        printf("Contact :");
        gets(temp->contact);
        printf("Data Updated\npress any key for back\n");
    }
    else
    {
        printf("Data not found!\npress any key for back\n");
    }
    getchar();
    system("cls");
    return;
}

void insert()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("\nInsert Student Data:\n");
    printf("Name: ");
    getchar();
    gets(temp->name);
    printf("Id: ");
    gets(temp->id);
    printf("Contact: ");
    gets(temp->contact);

    temp->next = head;
    head = temp;
    system("cls");
    return;

}

void deleteData()
{
    printf("\n########## Delete ###########\n");
    char id[30];
    int found = 0;
    printf("Enter Id: ");
    getchar();
    gets(id);
    struct node *temp = head;
    struct node *pretemp = temp;
    if(strcmp(temp->id, id)==0)
    {
        printf("Name: %s\n",temp->name);
        printf("is deleted");
        printf("\npress any key for back\n");
        getchar();
        system("cls");
        head = temp->next;
        free(temp);
        return;
    }
    else
    {
        while(temp != NULL)
        {
            if(strcmp(temp->id, id)==0)
            {
                found = 1;
                break;
            }
            pretemp = temp;
            temp = temp->next;
        }
        if(found)
        {
            printf("Name: %s\n",temp->name);
            printf("is deleted\n");
            printf("press any key for back\n");
            getchar();
            system("cls");
            pretemp->next = temp->next;
            free(temp);
        }
        else
        {
            printf("Data not found!\n");
            printf("press any key for back\n");
            getchar();
            system("cls");
        }
        return;
    }
}

int main()
{
    int n;
    while(1)
    {
        printf("############ Main Menu ############\n");
        printf("###################################\n");
        printf("###### 1. Add student data    #####\n");
        printf("###### 2. Remove a student    #####\n");
        printf("###### 3. Update student data #####\n");
        printf("###### 4. Show all data       #####\n");
        printf("###### 5. exit                #####\n");
        printf("Reply: ");
        scanf("%d", &n);
        switch(n)
        {
        case 1:
            system("cls");
            insert();
            break;
        case 2:
            system("cls");
            deleteData();
            break;
        case 3:
            system("cls");
            update();
            break;
        case 4:
            system("cls");
            display();
            break;
        case 5:
            return 0;
            break;
        default:
            printf("invalid input\nReply: ");
            break;
        }
    }
    return 0;
}
