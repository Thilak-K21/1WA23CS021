#include<stdio.h>
#define MAX 5
int queue1[MAX],queue2[MAX];
int front1=-1, front2=-1,rear1=-1,rear2=-1;
void insert(int queue[],int *front,int *rear,int ele)
{
    if (*rear==MAX-1)
    {
        return;
    }
    else if(*front==-1)
    {
        *front=0;
        *rear=0;
        queue[*rear]=ele;
    }
    else
    {
        *rear=*rear+1;
        queue[*rear]=ele;
    }
}
int delete(int queue[],int *front,int *rear)
{
    if(*front==-1)
    {
        printf("\nQueue is empty");
        return -1;
    }
    if(*rear==*front)
    {
        int val=queue[*front];
        *rear=*front=-1;
        return val;
    }
    else
    {
            int val=queue[*front];
             *front=*front+1;
            return val;
    }
}
    int main()
    {
        int i,e;
        printf("Enter the elements of the stack : \n");
        for(i=0;i<MAX;i++)
        {
            printf("Enter element : ");
            scanf("%d",&e);
            insert(queue1,&front1,&rear1,e);
        }
         for (i = 0; i < MAX; i++) 
         {
            int x = delete(queue1, &front1, &rear1);
            if (x != -1) 
            {
                insert(queue2, &front2, &rear2, x); 
            }
         }
        printf("\n Popped : ");
        for(i=0;i<MAX;i++)
        {
            int y=delete(queue2,&front2,&rear2);
            if(y!=-1)
                printf("%d  ",y);
        }
        
    }
