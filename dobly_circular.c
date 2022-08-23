#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create_node()
{
    int flag = 1;
    while (flag)
    {
        struct node *temp;
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {

            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = head;
            head->prev = newnode;
            temp = temp->next;
        }

        printf("press 1 for more node else press 0");
        scanf("%d", &flag);
    }
}

void insert_at_beg()
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    newnode->next = head;
    newnode->prev = head->prev;
    head->prev->next = newnode;
    head->prev = newnode;
    head = newnode;
}

void insert_at_end()
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    newnode->next = head;
    newnode->prev = head->prev;
    head->prev->next = newnode;
    head->prev = newnode;
}

void insert_at_random()
{
    int pos;
    int count = 1;
    printf("Enter the position");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insert_at_beg();
    }
    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node)), *temp = head;
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        while (temp->next != head && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void delete_beg()
{

    struct node *temp = head;
    head->prev->next = head->next;
    
    head->next->prev = head->prev;

    head=head->next;
    free(temp);

}
void delete_random(){
     int pos;
    int count = 1;
    printf("Enter the position");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insert_at_beg();
    }
    else
    {
        struct node  *temp = head;
        
        while (temp->next != head && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        struct node*ttm=temp->next;
        temp->next=ttm->next;
        ttm->next->prev=temp;
        free(ttm);
        
}
}
 void delete_at_last(){
    struct node *temp;

    temp=head->prev;
    
  head->prev->prev->next=head;

head->prev=head->prev->prev ;
free(temp);

 }

void display()
{
    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main(int argc, char const *argv[])
{ create_node();
    int choice = 0;
    while (choice != 8)
    {
        printf("\n\n****Main Menu****\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n  5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_beg();
            break;
        case 2:
            insert_at_end();
            break;
        case 3:
            insert_at_random();
            break;
        case 4:
            delete_beg();
            break;
        case 5:
           delete_at_last() ;
            break;
        case 6:
            delete_random();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
    return 0;
}
