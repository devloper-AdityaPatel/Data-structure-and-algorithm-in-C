#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *createnode()
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = 0;
    newnode->next = 0;

    return newnode;
}

node *push(node *top, int x)
{
    node *newnode = createnode();
    newnode->data = x;
    if (top == 0)
    {
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }

    return top;
}

node *pop(node *top)
{
    if (top == 0)
    {
        printf("Stack is empty!");
    }
    else
    {
        node *temp = top;
        printf("poped item : %d\n",top->data);
        top = top->next;
        // delete temp;
        free(temp);
    }
    return top;
}

void display(node *top)
{
    node *temp = top;
    while (temp != 0)
    {
        printf("%d ",temp->data);

        temp = temp->next;
    }
}

void peek(node *top)
{
    if (top == 0)
    {
        printf("stack is empty");
    }
    else
    {
        printf("Top item : %d\n",top->data);
    }
}


int main(){

    node* top = 0;

    printf("chose option below:\n\
            1. push\n\
            2. pop\n\
            3. display\n\
            4. peek\n\
            5. isempty\n\
            6. isfull\n\
            0. exit\n");

    int choice=0;
    printf("\n\nEnter choice : ");
    scanf(" %d",&choice);
    while(choice != 0){
        
        switch(choice){
            case 1 :
                int x;
                printf("enter element to push : ");
                scanf(" %d",&x);
                top = push(top,x);
                printf("element pushed succesfully");
                break;
            case 2 : 
                top=pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                peek(top);
                break;
            default:
                printf("enteres invalid choice..");
        }
        printf("\nenter choice : ");
        scanf(" %d",&choice);
    }
}