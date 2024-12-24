#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void concatenate(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = head2;
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    concatenate(head1, head2);

    return 0;
}
