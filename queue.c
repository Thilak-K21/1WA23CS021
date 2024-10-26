#include<stdio.h>
#define MAX 100
int queue[MAX];

void insert(int *front , int *rear, int *ele)
{
    if(*rear==MAX-1)
    {
        printf("\nOverflow");
    }
    else if (*front==-1 && *rear==-1)
    {
        *front=0;
        *rear=0;
        queue[*rear]=*ele;
        *rear=*rear+1;
    }
    else
    {
        queue[*rear]=*ele;
        *rear=*rear+1;
    }
}
int delete(int *front , int *rear)
{
    if(*front==-1)
    {
        printf("\nUnderflow");
        return -1;
    }
    else if(*front==*rear)
    {
        int val=queue[*front];
        *rear=-1;
        *front=-1;
        return val;
    }
    else{
        int val=queue[*front];
        *front=*front+1;
        return val;
    }
}
void display(int *front,int *rear)
{
    for(int i=*front;i<*rear;i++)
    {
        printf("%d\t",queue[i]);
    }
}
int main()
{
    int choice,front=-1,rear=-1,ele;
    do
    {
        printf("\n MAIN MENU");
        printf("\n 1)Insert");
        printf("\n2)Delete");
        printf("\n3)Display");
        printf("\n4)Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the element to be added : ");
                scanf("%d",&ele);
                insert(&front,&rear,&ele);
                break;
            }
            case 2:
            {
                delete(&front,&rear);
                printf("\nDeletion successful");
                break;
            }
            case 3:
            {
                display(&front,&rear);
                break;
            }
            default:
            {
                printf("\nEnter valid choice ");
                break;
            }
        }
    } while (choice!=4);

}
