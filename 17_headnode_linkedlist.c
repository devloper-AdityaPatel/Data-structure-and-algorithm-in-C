# include <stdio.h>
# include <stdlib.h>
/* ----node type user defined datatype---- */
struct node{
    int data;
    struct node* next;
};
typedef struct node node;
/* ----node type user defined datatype---- */

/*----head type user defined datatype----*/
struct head{
    node *start,*end;
    float avg;
    int count;
};
typedef struct head head;
/*----head type user defined datatype----*/

/* ----create a newnode function---- */
node* CreateNode(void){
    node * newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;

    return newnode;
}
/* ----create a newnode function end here---- */



/* ----inserting into linked list function start here---- */
void InsertNode(head* head,int x/* x is data to be insert in node */){

    node* newnode = CreateNode();
    newnode->data = x;

    if(head->start ==NULL){
        head->start = newnode;
        head->end = newnode;
    }
    else if(x < head->start->data){
        newnode->next = head->start;
        head->start = newnode;
    }
    else{
        node *temp = head->start;

        while(temp->next != NULL && x > temp->next->data){
            
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
        if(newnode->next == NULL)
            head->end = newnode;

    }

    ++head->count;
    head->avg= ((head->avg * (head->count-1)) + x)/head->count;
}
/* ----inserting into linked list function end here---- */


void display(head* head){
    node* iter = head->start;

    while(iter!=NULL){
        printf("%d ",iter->data);
        iter = iter->next;
    }
}

int main(){

    head head;
    head.count = 0;
    head.avg = 0.0;
    head.start =NULL;
    head.end = NULL;

    for(int i  = 0 ; i< 5 ; i++){
        printf("enter data: ");
        int x;
        scanf(" %d",&x);
        InsertNode(&head,x);
    }
    display(&head);
    printf("\navg : %.2f",head.avg);
}

