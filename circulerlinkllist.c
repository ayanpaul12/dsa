#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void create_node()
{
    int flag = 1;
    while (flag)
    {
        struct node *newnode, *temp;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        newnode->next = NULL;
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;

            newnode->next = head;

            temp = newnode;
        }
        printf("Press 1 for add more node else press 0: ");
        scanf("%d", &flag);
    }
}

void display()
{
    struct node *temp;
    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void delete_begin()
{
    struct node *temp = head, *last;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    last = temp;
    temp = head->next;
    last->next = temp;
    free(head);
    head = temp;
}

void last_del()
{
    struct node *last, *temp;
    last = temp = head;
    while (temp->next->next != head)
    {
        last = temp->next->next;
        temp = temp->next;
    }
    temp->next = head;
    ;
    free(last);
}

void random_delete()
{
    struct node *temp, *last;

    int count = 1;
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        delete_begin();
    }
    else
    {
        temp = head;
        last = head->next;
        while (temp->next != head && count < pos - 1)
        {

            last = temp->next->next;
            temp = temp->next;

            count++;
        }
        if (temp->next == NULL)
        {
            printf("Position out of bound!!!!,you have only %d nodes", count);
        }
        else
        {
            temp->next = last->next;
            free(last);
        }
    }
}

void begin_insert()
{
    struct node *newnode, *last, *temp;
    ;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    last = temp = head;
    while (temp->next->next != head)
    {
        last = temp->next->next;
        temp = temp->next;
    }

    temp = head;
    last->next = newnode;

    newnode->next = head;
    head = newnode;
}

void last_insert()
{

    struct node *newnode, *temp;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    newnode->next = NULL;
    scanf("%d", &newnode->data);

    while (temp->next != head)
    {

        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}

void random_insert()
{
    int count = 1;
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (pos == 1)
    {
        begin_insert();
    }
    else
    {
        temp = head;
        printf("Enter the data: ");

        scanf("%d", &newnode->data);
        newnode->next = NULL;

        while (temp->next != head && count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int main(int argc, char const *argv[]) {

{

    create_node();
    int choice = 0;
    while (choice != 8)
    {
        printf("\n\n****Main Menu****\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            begin_insert();
            break;
        case 2:
            last_insert();
            break;
        case 3:
            random_insert();
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            last_del();
            break;
        case 6:
            random_delete();
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
}
