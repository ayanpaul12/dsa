#include <stdio.h>
#include <stdlib.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
        return -1;
    else  
        return stack[top--];
}

int priority(char x)
{
    if (x == '(')
        return 0;

    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;
    if (x == '^')

        return 3;
}

int check_al_num(char e)
{
    if ((e > 64 && e < 91) || (e > 96 && e < 123))
    {
        return 2;
    }
    else if ((e > 47 && e < 58))
    {
        return 3;
    }

    else
    {
        return 4;
    }
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression using alphabets only  : ");
    scanf("%s", exp);
    printf("\n");
    e = exp;

    while (*e != '\0')
    {

        if (check_al_num(*e) == 2)
        {
            printf("%c ", *e);
        }
        else if (check_al_num(*e) == 3)
        {
            printf(
                "Enter alphabets only");
            break;
        }
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c ", pop());
    }
    return 0;
}