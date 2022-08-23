#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;

void creat_node()
{

    int flag = 1;
    while (flag)
    {
        struct node *newnode, *temp;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
            head->prev = NULL;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Press 1 for add more node else press 0: ");
        scanf("%d", &flag);
    }
}

void insert_beg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->next = head;
    head = newnode;
}

void insert_last()
{
    struct node *newnode, *temp;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void insert_random()
{
    int count = 1;
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (pos == 1)
    {
        insert_beg();
    }
    else
    {
        temp = head;

        newnode->next = NULL;
        newnode->prev = NULL;

        while (temp->next != NULL && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            printf("Position out of bound!!!!,you have only %d node(s)", count);
        }

        else
        {
            printf("Enter the data: ");

            scanf("%d", &newnode->data);
            newnode->next = temp->next;

            temp->next = newnode;

            newnode->prev = temp;
            newnode->next->prev = newnode;
        }
    }
}

void delete_beg()
{
    struct node *temp;
    temp = head->next;

    free(head);

    head = temp;
    head->prev = NULL;
}

void delet_random()
{
    struct node *temp, *ttm;
    int count = 1;
    int pos = 5;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        delete_beg();
    }
    else
    {
        temp = head;
        ttm = temp->next;
        while (temp->next != NULL && count < pos - 1)
        {

            ttm = temp->next->next;
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            printf("Position out of bound!!!!,you have only %d node(s)", count);
        }
        else if (count == (pos - 1))
        {
            temp->next = ttm->next;

            free(ttm);
        }

        else
        {
            temp->next = ttm->next;
            ttm->next->prev = temp;
            free(ttm);
        }
    }
}

void delet_last()
{
    struct node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    creat_node();
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
            insert_beg();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_random();
            break;
        case 4:
            delete_beg();
            break;
        case 5:
            delet_last();
            break;
        case 6:
            delet_random();
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