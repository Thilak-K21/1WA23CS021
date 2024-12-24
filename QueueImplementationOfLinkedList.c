#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *head = NULL;
struct node *front = NULL;
struct node *rear = NULL;
struct node *temp = NULL;
struct node *newnode = NULL;

void create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("Enter data: ");
    scanf("%d", &newnode->data);
}

void push(int data)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void pop()
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    temp = head;
    if (temp->next == NULL)
    {
        int ele = temp->data;
        head = NULL;
        free(temp);
        printf("Popped: %d\n", ele);
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    int ele = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    printf("Popped: %d\n", ele);
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void createQueue()
{
    create();
    front = rear = newnode;
}

void enqueue()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Underflow\n");
        return;
    }
    temp = front;
    int ele = temp->data;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
    printf("Dequeued: %d\n", ele);
}

void displayQueue()
{
    temp = front;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Create Queue\n");
        printf("5. Enqueue\n");
        printf("6. Dequeue\n");
        printf("7. Display Queue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            createQueue();
            break;
        case 5:
            enqueue();
            break;
        case 6:
            dequeue();
            break;
        case 7:
            displayQueue();
            break;
        case 8:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
