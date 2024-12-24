#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int data) 
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct node **head, int data) 
{
    struct node *newNode = createNode(data);
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct node *head) 
{
    struct node *temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

void sort(struct node *head) 
{
    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) 
    {
        for (j = i->next; j != NULL; j = j->next) 
        {
            if (i->data > j->data) 
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() 
{
    struct node *head = NULL;

    append(&head, 5);
    append(&head, 3);
    append(&head, 8);
    append(&head, 1);

    printf("Original list:\n");
    display(head);

    sort(head);

    printf("Sorted list:\n");
    display(head);

    return 0;
}
