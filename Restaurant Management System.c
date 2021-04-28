#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>

void insertfirst(int data, char foodname[25], int quantity, float price);
void insertmid(int pos, int data, char foodname[25], int quantity, float price);
void insertend(int data, char foodname[25], int quantity, float price);
void updatefood(int udata, int uquantity);
void foodlist();
void order_view(int order, int quantity, int or_no);
void main_menu();
void deletefood(int serial);
int countitem();
void cls();
void echo(char print[]);
void br(int line);
void pre(int tab);
void span(int space);
void ccolor(int clr);
void pwellcome();
void loadingbar();
void middle1(void);
void middtab1(void);
void backuploader(void);
void start();
void admin();
void buyFood();
void storeFoods();

typedef struct Node
{
    char foodname[50];
    int quantity;
    float price;
    int data;
    struct Node *next;
} node;

node *head=NULL, *list;

int c=0;
int any;
int cardno[100];
float cardmoney[100];
float totalmoney = 0;
int total_order[100];
int order_quantity[100];
int order=0;
int uquantity;
int citem;

int main()
{
    int choice;
    system("title Restaurant Management");
    system("mode con: cols=60 lines=20");
    start("Starting...");
    storeFoods();
    while(1)
    {
        br(1);
        main_menu();
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            foodlist();
            buyFood();
            break;
        case 2:
            admin();
            break;
        case 3:
            loadingbar("Refreshing...");
            break;
        case 4:
            cls();
            br(2);
            pre(2);
            printf("Thank You For Using Our System.\n");
            pre(2);
            printf("Have a Good Day, Bye Bye.\n");
            Sleep(300);
            exit(1);
            break;
        default:
            br(2);
            pre(2);
            printf("Please Enter Correct Choice");
            Sleep(300);
            break;
        }
    }
    return 0;
}

void storeFoods()
{
    insertfirst(5,"Burger   ",23,120.23);
    insertend(6,"Pizza    ",13,100.67);
    insertend(1,"Hot Cake ",8,720.83);
    insertend(2,"Coffee   ",46,70.23);
    insertend(3,"Ice-Cream",46,70.23);
    insertend(4,"Sandwich ",34,60.23);
    insertend(7,"Grill    ",7,520.29);
    insertend(8,"Nun-Bread",121,35.13);
    insertend(9,"Cold Drinks",73,20.13);
}

void start(char st[])
{
    loadingbar(st);
    cls();
    pwellcome();
    Sleep(300);
    cls();
}

void adminPannel()
{
    cls();
    br(2);
    pre(2);
    echo("You are on Admin Pannel\n\n");
    pre(2);
    printf("1. Total Cash Today \n");
    pre(2);
    printf("2. View Card Pay \n");
    pre(2);
    printf("3. Add Food \n");
    pre(2);
    printf("4. Delete Food \n");
    pre(2);
    printf("5. Instant Food List \n");
    pre(2);
    printf("6. Item Counter \n");
    pre(2);
    printf("7. Backup System\n");
    pre(2);
    printf("8. Instant Order Preview\n");
    pre(2);
    printf("0. Main Menu\n");
    pre(2);
    printf("Reply: ");
}

void admin()
{
    int admin_panel_choice, choice;
    char date[35]=__DATE__;
    cls();
    middle1() ;
    pre(2);
    printf("0. Main Menu [pass:1]\n\n");
    pre(2);
    printf("Password: ");
    fflush(stdin);
    scanf("%d",&choice);

    if(choice==1)
    {
        node *temp;
        temp = list;
        int adminchoise;
        while(1)
        {
            adminPannel();
            fflush(stdin);
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                cls();
                middle1();
                pre(2);
                printf("Todays Total Cash : %0.2f  \n",totalmoney);
                pre(2);
                printf("Press Enter");
                getchar();
                break;

            case 2:
                if(c!=0)
                {
                    cls();
                    br(2);
                    pre(2);
                    printf(" ____________________________\n");
                    pre(2);
                    printf("|   Card NO.   |   Money $   |\n");
                    pre(2);
                    printf("------------------------------\n");
                    pre(2);
                    for(int z=1; z<=c; z++)
                    {
                        printf("|   %8d   |   %7.2f   |\n",cardno[z],cardmoney[z]);
                        pre(2);
                        printf("------------------------------\n");
                        pre(2);
                        Sleep(150);
                    }
                    pre(2);
                    printf("Press Enter");
                    getchar();
                }
                if(c==0)
                {
                    cls();
                    middle1();
                    pre(2);
                    printf("No Card History\n");
                }
                pre(2);
                printf("Press Enter");
                getchar();
                break;
            case 3:
                cls();
                char ffoodname[25];
                int fquantity;
                int fdata;
                float fprice;
                int fposi;
                br(2);
                pre(2);
                printf("0. <-- back  \n");
                pre(2);
                printf(" Enter Food Name :  ");
                fflush(stdin);
                scanf("%[^\n]s",ffoodname);
                if(!strcmp(ffoodname,"0"))
                    break;
                fflush(stdin);
                br(2);
                pre(2);
                printf(" Enter Food Quantity :  ");
                scanf("%d",&fquantity);
                fflush(stdin);
                br(2);
                pre(2);
                printf(" Enter Food Serial :  ");
                scanf("%d",&fdata);
                node *exist;
                exist = list;
                while(exist->data!=fdata)
                {
                    if(exist->next==NULL)
                    {
                        break;
                    }
                    exist=exist->next;
                }
                if(exist->data==fdata)
                {
                    cls();
                    br(2);
                    pre(2);
                    printf(" Food Serial Already Exist, Please Re-Enter  ");
                    Sleep(2000);
                }
                fflush(stdin);
                br(2);
                pre(2);
                printf(" Enter Food Price :  ");
                fflush(stdin);
                scanf("%f",&fprice);
                br(2);
                pre(2);
                printf("Submiting your data");
                for(int cs=0; cs<4; cs++)
                {
                    printf(" .");
                    Sleep(500);
                }
                insertend(fdata,ffoodname,fquantity,fprice);
                br(2);
                pre(2);
                printf("Adding Food  Successfull....\n");
                Sleep(2000);
                break;

            case 4:
                cls();
                middle1();
                pre(2);
                printf("Enter Serial No of the Food To Delete : ");
                int fdelete;
                fflush(stdin);
                scanf("%d",&fdelete);
                node *temp;
                temp=list;
                while(temp->data != fdelete)
                {
                    temp = temp->next;
                }
                if(temp->data==fdelete)
                {
                    deletefood(fdelete);
                }
                else
                {
                    br(2);
                    pre(2);
                    printf("Please Enter Correct Number :  ");
                    Sleep(500);
                }
                break;

            case 5:
                cls();
                foodlist();
                Sleep(1000);
                br(2);
                fflush(stdin);
                pre(2);
                printf("Press Enter");
                getchar();
                break;

            case 6:
                citem = countitem();
                cls();
                for(int cs=1; cs<=citem; cs++)
                {
                    middle1();
                    pre(2);
                    printf("Item Counting ");
                    printf(" %d ",cs);
                    Sleep(150);
                    cls();
                }
                cls();
                middle1();
                pre(2);
                printf("Total Food Item is --> %d  \n",citem);
                pre(2);
                printf("Press Enter");
                getchar();
                break;

            case 7:
                strcat(date,".txt");
                FILE *fptr;
                fptr=fopen(date,"w");
                loadingbar("Backing UP DATA...");
                if(fptr==NULL)
                {
                    br(2);
                    pre(2);
                    printf("Error!");
                    Sleep(500);
                }
                fprintf(fptr,"Total Cash Today : %0.2f\n\n\n",totalmoney);
                fprintf(fptr,"Card No ------- Money \n\n");
                for(int l=1; l<=c; l++)
                {
                    fprintf(fptr,"%d ------- %0.2f \n",cardno[l],cardmoney[l]);
                }
                br(2);
                pre(2);
                printf("Backup Successfull...");
                Sleep(1500);
                fclose(fptr);
                break;

            case 8:
                cls();
                br(2);
                pre(2);
                ccolor(26);
                printf("\n");
                ccolor(240);
                printf("______________________________________________________ ");
                ccolor(26);
                printf("\n");
                ccolor(240);
                printf("|  Order No.  |  FooD Name  |  Quantity  |  In Stock  |");
                ccolor(26);
                printf("\n");
                ccolor(240);
                printf("-------------------------------------------------------");
                ccolor(26);
                for(int o=1; o<=order; o++)
                {
                    order_view(total_order[o],order_quantity[o],o);
                }
                br(2);
                fflush(stdin);
                pre(2);
                printf("Press Enter");
                getchar();
                break;

            case 0:
                return;
                break;

            default:
                br(2);
                pre(2);
                printf("Please Select From List :  ");
                Sleep(500);
                break;
            }
        }
    }
    else if(choice==0)
    {
        main_menu();
    }
    else
    {
        br(2);
        pre(2);
        printf("Password is Incorrect!\n");
        Sleep(1000);
        admin();
    }
}

void cls()
{
    system("cls");
}

void br(int line)
{
    for(int i=0; i<line; i++)
    {
        printf("\n");
    }
}

void pre(int tab)
{
    for(int i=0; i<tab; i++)
    {
        printf("\t");
    }
}

void span(int space)
{
    for(int i=0; i<space; i++)
    {
        printf(" ");
    }
}

void echo(char st[])
{
    printf("%s",st);
    return;
}

void main_menu()
{
    cls();
    system("mode con: cols=60 lines=20");
    ccolor(6);
    echo("                                                            \n");
    echo("          ");

    ccolor(120);
    echo("                                        ");

    ccolor(6);
    echo("          \n");
    echo("          ");

    ccolor(120);
    echo("            1. Food List                ");

    ccolor(6);
    echo("          \n");

    echo("          ");

    ccolor(120);
    echo("            2. Admin Page               ");

    ccolor(6);
    echo("          \n");
    echo("          ");

    ccolor(120);
    echo("            3. Refresh Page             ");

    ccolor(6);
    echo("          \n");
    echo("          ");

    ccolor(120);
    echo("            4. Exit                     ");

    ccolor(6);
    echo("          \n");
    echo("          ");

    ccolor(120);
    echo("                                        ");

    ccolor(6);
    echo("          \n          ");
    ccolor(70);
    echo("            Reply: ");
    ccolor(6);
}

void insertend(int data, char foodname[], int quantity, float price)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data = data;
    temp->price = price;
    temp-> quantity = quantity;
    strcpy(temp->foodname,foodname);
    temp->next = NULL;
    if(head==NULL)
    {
        head = temp;
        list = head;
    }
    else
    {
        while(head->next != NULL)
        {
            head = head->next;
        }
        head->next = temp;
    }
}

void insertfirst(int data, char foodname[], int quantity, float price)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data = data ;
    temp->price = price;
    strcpy(temp->foodname,foodname);
    temp-> quantity = quantity;
    temp->next = head;
    head = temp;
    list = head ;
}

void insertmid(int pos, int data, char foodname[], int quantity, float price)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data = data;
    temp->price = price;
    temp-> quantity = quantity;
    strcpy(temp->foodname,foodname);
    while(head->next->data != pos )
    {
        head = head->next ;
    }
    temp->next = head->next;
    head->next = temp ;
}

void deletefood(int serial)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp = list;
    if(temp->data != serial)
    {
        while(temp->next->data != serial)
        {
            temp = temp->next;
        }
        if(temp->next->data == serial)
        {
            temp->next = temp->next->next;
            cls();
            printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);
            for(int cs=0; cs<4; cs++)
            {
                printf(" .");
                Sleep(400);
            }
            printf("\n\n\n\n\t\t\tDeleted Successfylly \n");
            Sleep(500);
        }
        else
        {
            printf("\n\n\n\n\t\t\tFood Item Not Found\n");
            Sleep(500);
        }
        head = temp ;
    }
    else
    {
        temp = temp->next;
        cls();
        printf("\n\n\n\n\t\t\tDeleting Item %d ",serial);
        for(int cs=0; cs<4; cs++)
        {
            printf(" .");
            Sleep(400);
        }
        printf("\n\n\n\n\t\t\tDeleted Successfylly \n");
        Sleep(500);
        head = temp ;
        list=head;
    }
}

void updatefood(int udata, int uquantity)
{
    node *temp;
    temp = list;
    while(temp->data!=udata)
    {
        temp = temp->next;
    }
    if(temp->data == udata)
    {
        temp->quantity = uquantity;
    }
}

int countitem()
{
    node *temp;
    temp = list;
    int countitem=0;
    if(temp==NULL)
    {
        countitem = 0;
    }
    else
    {
        countitem = 1;
        while(temp->next != NULL)
        {
            countitem++;
            temp = temp->next;
        }
    }

    return countitem;
}

void foodlist()
{
    system("mode con: cols=60 lines=30");
    ccolor(6);
    printf("\n");
    ccolor(240);
    printf("____________________________________________________________\n");
    ccolor(240);
    printf("|   Food No.  |   FooD Name   |   Price   |    In Stock    |\n");
    ccolor(240);
    printf("------------------------------------------------------------\n");
    ccolor(6);
    node *temp;
    temp = list;
    while(temp != NULL)
    {
        ccolor(62);
        printf("|     %4d     |   %12s  |   %6.2f   |    %4d    |\n",temp->data,temp->foodname, temp->price, temp->quantity);
        ccolor(62);
        printf("------------------------------------------------------------\n");
        temp = temp->next ;
        Sleep(100);
    }
    ccolor(6);
}

void buyFood()
{
    int get_food_choice;
    pre(2);
    fflush(stdin);
    printf("Place Your Order: ") ;
    scanf("%d",&get_food_choice);
    node *temp;
    temp = list ;
    while(temp->data != get_food_choice)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            br(2);
            pre(4);
            echo("Please Chose From List");
            br(2);
            Sleep(1000);

        }
    }
    if(get_food_choice == temp->data)
    {
fcquantity:
        pre(2);
        printf("Enter Food Quantity : ");
        int fcquantity;
        fflush(stdin);
        scanf("%d",&fcquantity);
        cls();
        if(fcquantity==0)
        {
            cls();
            middle1();
            pre(2);
            printf("Quantity Can not be Zero ");
            Sleep(2000);
            cls();

        }
        else if(fcquantity>temp->quantity)
        {
            cls();
            middle1();
            pre(2);
            printf("Out of Stock ! \n");
            Sleep(2000);
            foodlist();
            buyFood();

        }
        middle1();
        pre(2);
        printf("Choosed food %s\n",temp->foodname);
        pre(2);
        printf("price: %0.2f \n\n",temp->price*fcquantity);
        pre(2);
        printf("1. Confirm Purchase\n");
        pre(2);
        printf("2. Back\n\n");
        pre(2);
        printf("Reply: ");
        int confirm;
confirm:
        fflush(stdin);
        scanf("%d",&confirm);
        if(confirm == 1 )
        {
            br(2);
            pre(2);
            printf("1. Cash\n");
            pre(2);
            printf("2. Credit\n");
            pre(2);
            printf("Reply: ");
            int payment;
payment:
            fflush(stdin);
            scanf("%d",&payment);
            if(payment==1)
            {
                totalmoney += temp->price*fcquantity;
                order++;
                total_order[order]=get_food_choice;
                order_quantity[order]=fcquantity;
                uquantity = temp->quantity - fcquantity;
                updatefood(get_food_choice,uquantity);
                cls();
                middle1();
                pre(2);
                printf("===>THANK YOU<===");
                br(2);
                pre(2);
                printf("Food Ordered Successfully ...");
                br(2);
                pre(2);
                printf("1. Wanna Buy Another Delicious ?\n");
                pre(2);
                printf("2. Main Menu\n");
                pre(2);
                printf("Reply: ");
                int ps_menu;
psmenu:
                fflush(stdin);
                scanf("%d",&ps_menu);
                if(ps_menu==1)
                {
                    foodlist();
                    buyFood();
                }
                else if(ps_menu==2)
                {

                }
                else
                {
                    br(2);
                    pre(4);
                    printf("Please Choice from list : ");
                    goto psmenu;
                }
            }
            else if(payment==2)
            {
                int card_number[100];
                c++;
                cls();
                middle1();
                pre(2);
                printf("Enter Your Card No: ");
                fflush(stdin);
                scanf("%d",&card_number[c]);
                cardno[c] = card_number[c];
                int pin;
                pre(2);
                printf("Enter Your Card Pin: ");
                fflush(stdin);
                scanf("%d",&pin);
                cardmoney[c] = temp->price*fcquantity;
                totalmoney += temp->price*fcquantity;
                order++;
                total_order[order]=get_food_choice;
                order_quantity[order]=fcquantity;
                uquantity = temp->quantity - fcquantity;
                updatefood(get_food_choice,uquantity);
                br(1);
                pre(2);
                printf("Payment Success...");
                br(1);
                pre(2);
                printf("1. Wanna Buy Another Delicious.\n");
                pre(2);
                printf("2. Main Menu\n");
                pre(2);
                printf("Reply:");
                int ps_menu2;
psmenu2:
                scanf("%d",&ps_menu2);
                if(ps_menu2==1)
                {
                    foodlist();
                    buyFood();
                }
                else if(ps_menu2==2)
                {

                }
                else
                {
                    br(2);
                    pre(2);
                    printf("Please Chose from list : ");
                    goto psmenu2;
                }
            }
            else
            {
                br(2);
                pre(4);
                printf("Enter Chose from List : ");
                goto payment;
            }
        }
        else if(confirm == 2)
        {

        }
        else
        {
            br(2);
            pre(2);
            printf("Enter Chose from List : ");
            goto confirm;
        }
    }
    else
    {
        br(2);
        pre(2);
        echo("Please Chose From List ");
        br(2);
        Sleep(300);

    }
}

void order_view(int order, int quantity, int or_no)
{
    ccolor(6);
    node *temp;
    temp = list;
    while(temp->data != order)
    {
        temp = temp->next;
    }
    if(temp->data == order)
    {
        ccolor(26);
        printf("\n");
        ccolor(62);
        printf("|     %4d     |   %12s  |   %6.2f   |    %4d    |\n",or_no,temp->foodname,quantity,temp->quantity);
        ccolor(26);
        ccolor(62);
        printf("------------------------------------------------------------\n");
        Sleep(100);
    }
    ccolor(6);
}

void ccolor(int clr)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, clr);
}

void pwellcome()
{
    ccolor(6);
    char welcome1[122]="                                                            \n                          WELCOME                           ";
    char welcome2[200]="                                                            \n                             TO                             \n                                                            ";
    char welcome3[122]="                FOOD ORDER MANAGEMENT SYSTEM                \n                                                            ";
    printf("\n\n\n");
    for(int i=0; i<strlen(welcome1); i++)
    {
        ccolor(120);
        printf("%c",welcome1[i]);
        if((welcome1[i] >= 'A') && (welcome1[i] <= 'Z'))
            Sleep(80);
    }
    ccolor(6);
    for(int i=0; i<strlen(welcome2) ; i++)
    {
        ccolor(200);
        printf("%c",welcome2[i]);
        if((welcome2[i] >= 'A') && (welcome2[i] <= 'Z'))
            Sleep(80);
    }
    ccolor(6);
    for(int i=0; i<strlen(welcome3) ; i++)
    {
        ccolor(100);
        printf("%c",welcome3[i]);
        if((welcome3[i] >= 'A') && (welcome3[i] <= 'Z'))
            Sleep(80);
    }
    ccolor(6);
    Sleep(100);
}

void loadingbar(char message[])
{
    for (int i=1; i<=100; i+=1)
    {
        cls();
        ccolor(6);
        printf("\n\n\n\n\n\n\n\n\t\t\t");
        ccolor((i%10)+5);
        printf("%d %% ",i);
        ccolor(6);
        printf("%s\n\n\n\n\n\n\n\n    ",message);
        for (int j=0; j<i; j+=2)
        {
            ccolor(120+j);
            printf(" ");
            ccolor(6);
        }
        Sleep(10);
    }
}

void middle1()
{
    printf("\n\n\n\n\n\n\n");
}

void middtab1()
{
    printf("\t\t\t\t\t");
}
