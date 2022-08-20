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
        scanf("%d", &newnode->data);
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Press 1 for add more node else press 0: ");
        scanf("%d", &flag);
    }
}

int main(int argc, char const *argv[])
{
   create_node();
    return 0;
}
