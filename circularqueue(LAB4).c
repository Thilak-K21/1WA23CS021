#include<stdio.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) 
{
    if ((rear + 1) % N == front)
        printf("\nOverflow");
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() 
{
    if (front == -1 && rear == -1)
        printf("Underflow");
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        printf("Deletion successful");
    }
    else
    {
        front = (front + 1) % N;
        printf("Deletion successful");
    }
}

void display() 
{
    if (front == -1 && rear == -1)
        printf("Queue is empty");
    else 
    {
        int i = front;
        printf("Elements are: ");
        while (i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d", queue[rear]);
    }
}

int main() 
{
    int choice, ele;
    do 
    {
        printf("\nMain Menu");
        printf("\n1) Insert");
        printf("\n2) Delete");
        printf("\n3) Display");
        printf("\n4) Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) 
        {
            printf("Enter element: ");
            scanf("%d", &ele);
            enqueue(ele);
        }
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();
    } while (choice != 4);
  return 0;
}
