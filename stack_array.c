#include <stdio.h>
#include <stdlib.h>

int size;
int *stack;
int top = -1;
void push()
{
    if (top == size - 1)
    {
        printf("Stack overflow,you can not push data!!!!!!");
    }
    else
    {
        printf("Enter the value");
        int data;
        scanf("%d", &data);
        stack[++top] = data;
        printf("Pushed sucessfully........");
    }
}
void peek()
{
    
     if (top ==  - 1)
    {
        printf("Stack is empty!!!!!!");
    }
    else
    {
        printf("The top element is: %d ",stack [top]);
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow,nothing to be popped!!!!!!!");
    }

    else
    {

        top = top - 1;
         printf("Element is popped sucessfully.......");
    }
}

int main(int argc, char const *argv[])
{
     printf("Enter the max size of your stack: ");
      scanf("%d",&size);
      stack=(int*)malloc(sizeof(int));
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
