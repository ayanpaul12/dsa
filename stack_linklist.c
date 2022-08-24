#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *head=NULL;
   int count = -1;
   int size;

void push()
{
    if (count == size-1)
    {
        printf("Stack overflow,you can not push data!!!!!!");
    }
    else
    {
        struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    newnode->next = NULL;
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
        printf("Pushed sucessfully........");
    }
    count++;
}
void pop()
{
    if (head==NULL)
    {
        printf("Stack underflow,nothing to be popped!!!!!!!");
    }

    else
    {

    struct node *temp;
    temp = head->next;
    free(head);
    head = temp;


       
         printf("Element is popped sucessfully.......");
    }
    count--;
}

void peek()
{
    
     if (head==NULL)
    {
        printf("Stack is empty!!!!!!");
    }
    else
    {
        printf("The top element is: %d ",head->data);
    }
}



int main(int argc, char const *argv[])
{
     printf("Enter the max size of your stack: ");
      scanf("%d",&size);
    // create_node();
    int choice = 0;
    while (choice != 8)
    {
        printf("\n\n****Main Menu****\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.push at top\n2.peek at top\n3.pop at top\n4.exit");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            peek();
            break;
        case 3:
            pop();
            break;
        case 4:

            break;

        default:
            printf("Please enter valid choice..");
        }
    }

    return 0;
}
