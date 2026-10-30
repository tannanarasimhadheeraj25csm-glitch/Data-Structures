#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void insertFront()
{
    int x;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &x);

    if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = MAX - 1;
    else
        front--;

    deque[front] = x;
}

void insertRear()
{
    int x;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &x);

    if (front == -1)
        front = rear = 0;
    else if (rear == MAX - 1)
        rear = 0;
    else
        rear++;

    deque[rear] = x;
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element = %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front++;
}

void deleteRear()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element = %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
        rear = MAX - 1;
    else
        rear--;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");

    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- DEQUE Operations ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete at Front\n");
        printf("4. Delete at Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
