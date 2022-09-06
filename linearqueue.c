#include <stdio.h>
#include <stdlib.h>

int *queue;
int size;
void enqueue();
void dequeue();
void show();
int front = -1, rear = -1;

void enqueue()
{
    int ele;
    if (rear == size - 1)
    {
        printf("Queue overflowed,you can not enter element anymore!!!!");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        printf("Enter the element: ");
        scanf("%d", &ele);
        queue[rear] = ele;
    }
}
void dequeue()
{
    if (front == -1 )

    {
        printf("Queue underflowed");
    }
    else if( front > rear){
         printf("Queue is empty,nothing tob be dequeued!!!!!");
    }
    else
    {
        front = front + 1;
    }
}
void show()
{
    if (front == -1 || front > rear)
        printf("Queue is empty");
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter the max size of your queue: ");
    scanf("%d", &size);
   
    queue = (int *)malloc(sizeof(int));
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