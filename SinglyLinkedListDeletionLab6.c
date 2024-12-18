/*
    Program to Implement Singly Linked List with the following operations:

    a) Create a linked list.
    b) Deletion of:
       - The first element
       - A specified element
       - The last element
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

void deleteAtFirst() 
{
    struct node *temp;
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("First element deleted successfully!\n");
}

void deleteAtPosition() 
{
    int ele;
    struct node *temp = head, *prev = NULL;
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    printf("Enter the element to delete: ");
    scanf("%d", &ele);

    while (temp != NULL && temp->data != ele) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Element not found!\n");
        return;
    }

    if (temp == head) 
    {
        head = temp->next;
    } 
    else 
    {
        prev->next = temp->next;
    }

    free(temp);
    printf("Element %d deleted successfully!\n", ele);
}

void deleteAtLast() 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head, *prev = NULL;
    while (temp->next != NULL) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head) 
    {
        head = NULL;
    } 
    else 
    {
        prev->next = NULL;
    }
    free(temp);
    printf("Last element deleted successfully!\n");
}

void display() 
{
    struct node *temp = head;
    if (temp == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    printf("List elements: ");
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
        printf("2) Delete First Element\n");
        printf("3) Delete Specified Element\n");
        printf("4) Delete Last Element\n");
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
                deleteAtFirst();
                break;
            case 3:
                deleteAtPosition();
                break;
            case 4:
                deleteAtLast();
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
