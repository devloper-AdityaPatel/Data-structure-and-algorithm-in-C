# include <stdio.h>
# define SIZE 20

struct stack{
    int stack_array[SIZE];
    int top;
};


typedef struct stack stack;
void push(stack* stack_ptr , int data){

    if(stack_ptr->top == SIZE-1){
        printf("stack : overflow\n");
        return;
    }

    stack_ptr->top++;
    stack_ptr->stack_array[stack_ptr->top] = data;

    return;
}

void pop(stack* stack_ptr){

    if(stack_ptr->top == -1){
        printf("stack : underflow");
        return;
    }

    int data = stack_ptr->stack_array[stack_ptr->top];
    stack_ptr->top--;
    printf("poped item : %d",data);
    return;
}


void main(){

    stack stack;
    stack.top = -1;

    printf("0 To exit \n1 Push \n2 pop\n\n");

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

            push(&stack,data);
            
            break;
        
        case 2:
            pop(&stack);
            break;
        
        default:
            printf("enter invalid choice\n");
            break;
        }

        printf("\nenter choice : ");
        scanf(" %d",&choice);
        
    }
}