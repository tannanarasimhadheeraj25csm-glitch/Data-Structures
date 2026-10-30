#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int x;

    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter element: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted element = %d\n", stack[top--]);
}

void peek()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element = %d\n", stack[top]);
}

void display()
{
    int i;

    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are:\n");

        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
