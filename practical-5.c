#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    else
        tail = newNode;

    head = newNode;
    printf("%d inserted at beginning\n", value);
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL)
        tail->next = newNode;
    else
        head = newNode;

    tail = newNode;
    printf("%d inserted at end\n", value);
}

void deleteValue(int value)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("%d not found\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    free(temp);
    printf("%d deleted\n", value);
}

void search(int value)
{
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("%d found at position %d\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("%d not found\n", value);
}

int length(void)
{
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayForward(void)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Forward : NULL <- ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

void displayBackward(void)
{
    struct Node *temp = tail;

    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Backward: NULL <- ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->prev != NULL)
            printf(" <-> ");
        temp = temp->prev;
    }
    printf(" -> NULL\n");
}

void freeList(void)
{
    struct Node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
}

int main(void)
{
    int choice, value;

    while (1)
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a value\n");
        printf("4. Search a value\n");
        printf("5. Display forward\n");
        printf("6. Display backward\n");
        printf("7. Length\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                printf("Length of list: %d\n", length());
                break;

            case 8:
                freeList();
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
