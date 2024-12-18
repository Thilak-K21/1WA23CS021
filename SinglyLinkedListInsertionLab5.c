/* LAB PROGRAM 5
    Program to Implement Singly Linked List with the following operations:

    a) Create a linked list.
    b) Insert a node at:
       - The first position
       - Any position
       - The end of the list
    c) Display the contents of the linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* head = NULL;

void create() 
{
    int choice;
    struct node *temp, *newnode;
    printf("Enter 1 to insert, 0 to exit\n");
    do 
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) 
        {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &newnode->data);
            newnode->next = NULL;
            if (head == NULL) 
            {
                head = newnode;
            } 
            else 
            {
                temp = head;
                while (temp->next != NULL) 
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }
    } while (choice != 0);
}

void insertAtBeginning() 
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insertAtEnd() 
{
    struct node *temp, *newnode;
    temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertAtPosition() 
{
    int pos, i = 1;
    struct node *temp, *newnode;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    if (pos <= 0) 
    {
        printf("Invalid position\n");
        return;
    }
    temp = head;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if (pos == 1) 
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    while (i < pos - 1 && temp != NULL) 
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) 
    {
        printf("Position is out of bounds\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void display() 
{
    struct node *temp;
    temp = head;
    if (temp == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) 
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    int choice;
    do 
    {
        printf("\nMenu:\n");
        printf("1) Create Linked List\n");
        printf("2) Insert at Beginning\n");
        printf("3) Insert at End\n");
        printf("4) Insert at Position\n");
        printf("5) Display List\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                create();
                break;
            case 2:
                insertAtBeginning();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
