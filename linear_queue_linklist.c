#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL,*temp;
int count = -1;
int size;

void enqueue();
void dequeue();
void show();

void enqueue()
{
    struct node  *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (count == size - 1)
    {
        printf("Stack overflow,you can not push data!!!!!!");
    }
    else if (head == NULL)
    {
        printf("Enter the element:");
        scanf("%d", &newnode->data);
        head = temp = newnode;
        count++;
    }
    else
    {
        printf("Enter the element:");
        scanf("%d", &newnode->data);
        temp->next = newnode;
        temp = newnode;
        count++;
    }
    
}

void dequeue()
{
    if (head == NULL)
    {
        printf("Stack underflow,nothing to be popped!!!!!!!");
    }

    else
    {
        struct node *temp1;
        temp1 = head->next;
        free(head);
        head = temp1;
        printf("Element is popped sucessfully.......");
        count--;
    }
}
void show()
{
    struct node *temp3;
    temp3 = head;
    if (head == NULL)
    {
        printf("Stack is empty!!!!!!");
    }
    else
    {
        
        while (temp3 != NULL)
        {
            printf("%d ", temp3->data);
            temp3 = temp3->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter the max size of your queue: ");
    scanf("%d", &size);

    int choice = 0;
    while (choice != 8)
    {
        printf("\n\n****Main Menu****\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Enqueue\n2.Show\n3.Dequeue\n4.exit");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            show();
            break;
        case 3:
            dequeue();
            break;
        case 4:

            return 0;

        default:
            printf("Please enter valid choice..");
        }
    }

    return 0;
}