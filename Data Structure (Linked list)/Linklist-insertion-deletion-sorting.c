#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} ll;
ll *head;

void sortList()
{
    ll *current = head, *index;
    int swap;
    if(head == NULL)
    {
        return;
    }
    else
    {
        while(current != NULL)
        {
            index = current->next;
            while(index != NULL)
            {
                if(current->num > index->num)
                {
                    swap = current->num;
                    current->num = index->num;
                    index->num = swap;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void insert(int number)
{
    ll *temp = head;
    ll *addNew = (ll*)malloc(sizeof(ll));
    addNew->num = number;
    addNew->next = NULL;
    if(temp==NULL)
        head = addNew;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=addNew;
    }
}

void display()
{
    ll *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->num);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void removeNumber(int n)
{
    ll *temp = head, *preNode;
    if(temp==NULL)
    {
        printf("Empty Link List\n");
        exit(1);
    }
    else if(temp->num==n)
    {
        head = temp->next;
        free(temp);
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->num==n)
                break;
            preNode = temp;
            temp = temp->next;
        }
        if(temp==NULL)
            printf("Number Not found\n");
        else
        {
            preNode->next = temp->next;
            free(temp);
            printf("Number removed\n");
        }
    }
}

int main()
{
    int n;

    printf("Inserting Number until ZERO is given:\n");
    while(scanf("%d",&n) && n)
    {
        insert(n);
    }
    sortList();
    display();
    printf("Deleting Number until ZERO is given:\n");
    while(scanf("%d",&n) && n)
    {
        removeNumber(n);
        display();
    }
    return 0;
}
