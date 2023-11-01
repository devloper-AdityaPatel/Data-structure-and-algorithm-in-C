# include <stdio.h>
# include <limits.h>
# define MAX 5

/* ----queue data type defined here---- */
typedef struct{
    int arr[MAX],front,rear;
}queue;
/* ---- end of queue data type  definition */


/* ----queue initialization function ----*/
queue init_queue(){
    queue init_var;
    init_var.front = -1;
    init_var.rear = 0;

    return init_var;
}
/* ----queue initialization function definition end---- */

/* ----enqueue function definition---- */
void enqueue(queue* q,int item){
    
    if(q->rear!=q->front){
        q->arr[q->rear] = item;
        q->rear = (q->rear+1)% MAX;

        if(q->front == -1){
            q->front = 0;
        }
    }
    else{
        printf("queue is overflow:NO more elements can add\n");
    }
}
/* ----enqueue function definition end here ---- */

/* ----dequeue function definition start here---- */
int dequeue(queue* q){
    if(q->front !=-1){
        int item = q->arr[q->front];
        q->front = (q->front+1)%MAX;

        if(q->rear==q->front){
            q->rear=0;
            q->front=-1;
        }

        return item;
    }
    else{
        printf("queue is underflow\n");
        return INT_MIN;
    }
}
/* ----dequeue function definition end here---- */

int main(){
    queue qu;
    qu = init_queue();

    printf("0 To exit \n1 enqueue \n2 dequeue\n\n");

    int choice = 0;

    printf("\nenter choice : ");
    scanf(" %d",&choice);

    while(choice){

        switch (choice)
        {
        case 1:
            int data;
            printf("enter data : ");
            scanf(" %d",&data);

            enqueue(&qu,data);
            
            break;
        
        case 2:
            int item;
            item = dequeue(&qu);
            if (item != INT_MIN) printf("\ndequeue item : %d\n",item);
            break;
        
        default:
            printf("enter invalid choice\n");
            break;
        }

        printf("\nenter choice : ");
        scanf(" %d",&choice);
        
    }
    return 0;
}
