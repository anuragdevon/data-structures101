#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node *head = NULL, *sentinel = NULL;
int flag = 0;

struct node* insert_node_last(struct node** head,struct node** sentinel,int data)
{
    int n,i = 0; /* n => node to which the new node's next will point to */
    struct node *temp,*new_node = (struct node*)malloc(sizeof (struct node));
    new_node->data = data;
    if ( *sentinel != NULL )
    {
        (*sentinel)->next = new_node;

    }
    else
    {
        *head = new_node;
    }
    *sentinel = new_node;
    while ( 1 )
    {
        temp = *head;
        printf("\nEnter the node to whom the next pointer of this node will point to (Enter -1 for NULL):\n");
        scanf("%d",&n);

        if ( n == -1 )
        {
            new_node->next = NULL;
            break;
        }
        else
        {
            while ( i < n - 1 && temp != NULL )
            {
                temp = temp->next; i++;
            }
            if ( i == n - 1 )
            {
                if ( temp != NULL )
                {
                    new_node->next = temp;
                    flag = 1;
                    break;
                }
                else
                    printf("Such a node does not exist\n");
            }
            else
                printf("Such a node does not exist\n");
        }
    }
    temp = *head; i = 1;
    while ( temp != NULL && flag != 1 )
    {
        printf("(%d,%d)-->",i,temp->data);
        temp = temp->next; i++;
    }
    return NULL;
}

struct node* inc_steps(struct node* pt,int steps)
{
    int i; struct node* temp = pt;
    for ( i = 0; i < steps ; i ++ )
    {
        temp = temp->next;
    }
    return temp;
}

int main()
{
    printf("\nEnter the nodes in the linked list\n");
    int data, nos, period, lambda = 1, mu = 1; char op = 'Y';
    while( ( op == 'Y' || op == 'y' ) && flag != 1 )
    {
        printf("\nEnter the data for the new node\n");
        scanf("%d",&data);
        insert_node_last(&head,&sentinel,data);
        if ( flag != 1 )
        {	printf("\nDo you want to insert more data ( Y or N )\n");
            scanf("%c",&op);
            scanf("%c",&op);
        }
    }

    struct node *hare, *tortoise;
    hare = ( tortoise = head ) ;
    tortoise = tortoise ->next;
    hare = hare->next->next;
    nos = 1;

    while ( hare != tortoise && hare != NULL )
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
        nos++;
    }

    if ( hare == NULL )
    {
        printf("\n :: No loop exists in the list :: \n");
        return 0;
    }

    if ( hare == tortoise )
    {
        period = nos;
    }

    tortoise = head;
    while ( tortoise != inc_steps(tortoise,period) )
    {
        tortoise = tortoise->next;
        mu++;
    }
    if ( tortoise == inc_steps(tortoise,period) )
        printf("\n :: The start node of the loop is at node no. %d :: \n",mu);
 
    hare = tortoise->next;

    while ( hare != tortoise )
    {
        hare = hare->next;
        lambda++;
    }
    if ( hare == tortoise )
    {
        printf("\n :: The length of the loop is %d :: \n ",lambda);
    }
    return 0;
}
