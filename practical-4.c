#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last;

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        last = head;
        while (last->next != head)
            last = last->next;

        last->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("%d inserted at beginning\n", value);
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last;

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        last = head;
        while (last->next != head)
            last = last->next;

        last->next = newNode;
        newNode->next = head;
    }
    printf("%d inserted at end\n", value);
}

void deleteValue(int value)
{
    struct Node *temp;
    struct Node *prev;
    struct Node *last;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        if (head->data == value)
        {
            free(head);
            head = NULL;
            printf("%d deleted\n", value);
        }
        else
        {
            printf("%d not found\n", value);
        }
        return;
    }

    if (head->data == value)
    {
        last = head;
        while (last->next != head)
            last = last->next;

        temp = head;
        last->next = head->next;
        head = head->next;
        free(temp);
        printf("%d deleted\n", value);
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != head && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        printf("%d not found\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("%d deleted\n", value);
}

void search(int value)
{
    struct Node *temp;
    int position = 1;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    do
    {
        if (temp->data == value)
        {
            printf("%d found at position %d\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    printf("%d not found\n", value);
}

int length(void)
{
    struct Node *temp;
    int count = 0;

    if (head == NULL)
        return 0;

    temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

void display(void)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to %d)\n", head->data);
}

void freeList(void)
{
    struct Node *temp;
    struct Node *nextNode;

    if (head == NULL)
        return;

    temp = head;
    do
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);

    head = NULL;
}

int main(void)
{
    int choice, value;

    while (1)
    {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a value\n");
        printf("4. Search a value\n");
        printf("5. Display\n");
        printf("6. Length\n");
        printf("7. Exit\n");
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
                display();
                break;

            case 6:
                printf("Length of list: %d\n", length());
                break;

            case 7:
                freeList();
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
