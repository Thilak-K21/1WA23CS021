#include<stdio.h>
void push(int arr[], int ele , int *top, int *MAX)
{
    if(*top<*MAX-1)
    {
        *top=*top+1;
        arr[*top]=ele;
        printf("\n Successfully pushed\n");
    }
    else
    {
        printf("\nStack full");
    }
}
int pop(int arr[], int *top)        
{
    if(*top==-1)
    {
        printf("\n Stack is empty\n");
    }
    else
    {
        int x=arr[*top];
        *top=*top-1;
        return x;
    }
}
void display(int arr[], int *top)
{
    int i;
    printf("\n The stack is :\t");
    for(i=0;i<=*top;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void main()
{
    int choice,n,ele,e;
    int m=100;
    int a[100]={0};
    int t=-1;
    do
    {
          printf(" 1)Push \n 2)Pop \n 3)Display \n 4)Exit \n Enter your choice : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&ele);
        push(a,ele,&t,&m);
    }
    else if(choice==2)
    {
        e=pop(a,&t);
        printf("\n Pop successful\n The element %d was popped\n\n",e);
    }
    else if (choice==3)
    {
        display(a,&t);
    }
    else
    {
        printf("\n Enter a valid  choice\n");
    }  
    }while(choice!=4);

}