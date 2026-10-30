#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct PriorityQueue
{
    int data;
    int priority;
};

struct PriorityQueue pq[MAX];
int size = 0;

// Insert
void enqueue(int data, int priority)
{
    if (size == MAX)
    {
        printf("Queue is full\n");
        return;
    }

    pq[size].data = data;
    pq[size].priority = priority;

    size++;

    printf("Element inserted\n");
}

// Delete highest priority element
void dequeue()
{
    int i;
    int highest = 0;

    if (size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    // Find highest priority
    for (i = 1; i < size; i++)
    {
        if (pq[i].priority < pq[highest].priority)
        {
            highest = i;
        }
    }

    printf("Deleted element: %d\n", pq[highest].data);

    // Move elements to fill the deleted position
    for (i = highest; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Display
void display()
{
    int i;

    if (size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("\nData\tPriority\n");

    for (i = 0; i < size; i++)
    {
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
    }
}

int main()
{
    int choice;
    int data, priority;

    while (1)
    {
        printf("\n--- Priority Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter priority: ");
                scanf("%d", &priority);

                enqueue(data, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}