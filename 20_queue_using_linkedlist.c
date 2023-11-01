# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node node;


node* enqueue(node** front,node* rear,int val)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next = 0;
    newnode->data = val;

    if(*front ==0 && rear ==0){
        *front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }

    return rear;
}

node* dequeue(node*front , node* rear){
    
    if(front == 0 && rear ==0){
        printf("queue is empty!\n");
        return 0;
    }
    else{
        node* del = front;
        printf("popped item : %d\n",front->data);
        front = front->next;
        // delete del;
        free(del);
    }
    return front;
}

void display(node* front){
    node* temp = front;

    if(temp == 0){
        printf("queue is empty!\n");
    }
    else{
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}


int main(){

    node* front = 0,*rear = 0;

    printf("chose option below:\n\
            1. enqueue\n\
            2. dequeue\n\
            3. display\n\
            0. exit\n");

    int choice=0;
    printf("\n\nEnter choice : ");
    scanf(" %d",&choice);

    while(choice != 0){

        switch (choice)
        {
        case 1:
            int x;
                printf("enter element to push : ");
                scanf(" %d",&x);
                rear = enqueue(&front,rear,x);
                printf("element enqued succesfully\n");
            break;
        case 2:
            front = dequeue(front ,rear);
            break;
        case 3:
            display(front);
            break;
        
        default:
            printf("enteres invalid choice..");
            break;
        }

        printf("\nenter choice : ");
        scanf(" %d",&choice);
    }

}

