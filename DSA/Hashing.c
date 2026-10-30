#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int linearTable[TABLE_SIZE];
int quadraticTable[TABLE_SIZE];

struct Node
{
    int key;
    struct Node *next;
};

struct Node *chainTable[TABLE_SIZE];

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void initLinear()
{
    int i;

    for (i = 0; i < TABLE_SIZE; i++)
        linearTable[i] = -1;
}

void insertLinear(int key)
{
    int index = hashFunction(key);
    int i, probe;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        probe = (index + i) % TABLE_SIZE;

        if (linearTable[probe] == -1)
        {
            linearTable[probe] = key;
            printf("Key %d inserted at index %d\n", key, probe);
            return;
        }
    }

    printf("Hash table is full\n");
}

void displayLinear()
{
    int i;

    printf("\nLinear Probing Table:\n");
    printf("Index\tValue\n");

    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (linearTable[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, linearTable[i]);
    }
}

void initQuadratic()
{
    int i;

    for (i = 0; i < TABLE_SIZE; i++)
        quadraticTable[i] = -1;
}

void insertQuadratic(int key)
{
    int index = hashFunction(key);
    int i, probe;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        probe = (index + i * i) % TABLE_SIZE;

        if (quadraticTable[probe] == -1)
        {
            quadraticTable[probe] = key;
            printf("Key %d inserted at index %d\n", key, probe);
            return;
        }
    }

    printf("No free slot found\n");
}

void displayQuadratic()
{
    int i;

    printf("\nQuadratic Probing Table:\n");
    printf("Index\tValue\n");

    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (quadraticTable[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, quadraticTable[i]);
    }
}

void initChaining()
{
    int i;

    for (i = 0; i < TABLE_SIZE; i++)
        chainTable[i] = NULL;
}

void insertChaining(int key)
{
    int index = hashFunction(key);

    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->key = key;
    newNode->next = NULL;

    if (chainTable[index] == NULL)
        chainTable[index] = newNode;
    else
    {
        temp = chainTable[index];

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Key %d inserted at index %d\n", key, index);
}

void displayChaining()
{
    int i;
    struct Node *temp;

    printf("\nSeparate Chaining Table:\n");
    printf("Index\tChain\n");

    for (i = 0; i < TABLE_SIZE; i++)
    {
        printf("%d\t", i);

        temp = chainTable[i];

        if (temp == NULL)
            printf("-");

        while (temp != NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }

        if (chainTable[i] != NULL)
            printf("NULL");

        printf("\n");
    }
}

int main()
{
    int choice, key;

    initLinear();
    initQuadratic();
    initChaining();

    while (1)
    {
        printf("\n--- HASHING ---\n");
        printf("1. Insert using Linear Probing\n");
        printf("2. Insert using Quadratic Probing\n");
        printf("3. Insert using Separate Chaining\n");
        printf("4. Display Linear Probing\n");
        printf("5. Display Quadratic Probing\n");
        printf("6. Display Separate Chaining\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insertLinear(key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                insertQuadratic(key);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                insertChaining(key);
                break;

            case 4:
                displayLinear();
                break;

            case 5:
                displayQuadratic();
                break;

            case 6:
                displayChaining();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
