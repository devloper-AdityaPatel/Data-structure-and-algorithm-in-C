
# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;


node *createnode(void);
node *create_doubly_linkedlist(node *, node *);
int length(node *);
node *insert_at_begin(node *);
node *insert_at_end(node*);
void insert_at_pos(node *);
void display(node *);


int main(){
    node *head=0,*tail=0;

    int op=0;
    printf("\n1.create doubly list\n2.find length\n3.insert at begining\n4.insert at pos\n5.insert at end\n6.display\n");

    
    printf("Enter choice : ");

    scanf(" %d",&op);
    while(op!=0){
        switch (op)
        {
        case 1:
            head=create_doubly_linkedlist(head,tail);
            break;
        case 2:

            printf("Length of list : %d \n",length(head));
            break;
        
        case 3:
            head=insert_at_begin(head);
            break;
        case 4:
            insert_at_pos(head);
            break;
        case 5:
            tail=insert_at_end(tail);
            break;
        case 6:
            display(head);
            break;
        }

        
        printf("\n1.create doubly list\n2.find length\n3.insert at begining\n4.insert at pos\n5.insert at end\n6.display\n");
        printf("Enter option : ");
        scanf(" %d",&op);
    }
    return 0;
}

node *createnode(void)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->next = 0;
    newnode->prev = 0;

    printf("enter data : ");

    scanf(" %d",&newnode->data);
    return newnode;
}

node *create_doubly_linkedlist(node *head, node *tail)
{

    printf("\n1 for add node \n0 for end the list\n");
    int choice = 1;
    while (choice)
    {
        node *newnode = createnode();
        if (!(head == 0))
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
        else
        {
            head = tail = newnode;
        }


        printf("ente choice:");

        scanf(" %d",&choice);
    }
    return head;
}

int length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

node *insert_at_begin(node *head)
{
    node *newnode = createnode();
    head->prev = newnode;
    newnode->next = head;
    head = newnode;

    return head;
}

node *insert_at_end(node *tail)
{
    node *newnode = createnode();
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;

    return tail;
}

void insert_at_pos(node *head)
{
    int pos;

    printf("Enter position : ");

    scanf(" %d",&pos);

    if (pos < 1 && pos > length(head))
    {

        printf("invalid position");
    }
    else if (pos == 1)
    {
        head = insert_at_begin(head);
    }
    else
    {
        node *temp = head;
        int i = 1;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        node *newnode = createnode();
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void display(node * head){
    node * temp = head;

    printf("[ ");
    while(temp!=0){

        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("]");
}