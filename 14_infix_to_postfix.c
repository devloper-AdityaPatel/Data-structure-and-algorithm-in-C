#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define STACKMAX 50

/* ----stack declaration start---- */
struct Stack
{
    char stackarray[STACKMAX];
    int top;
};

typedef struct Stack Stack;
/* ----stack declaration end---- */

/* ----stack operation definition start---- */

void push(Stack *stack, char value)
{
    if (stack->top == STACKMAX - 1)
    {
        printf("stack overflow : cannot insert data\n");
        return;
    }
    else
    {
        ++stack->top;
        stack->stackarray[stack->top] = value;
    }
}

char pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("stack underflow : stack is empty\n");
        return '\0';
    }
    else
    {
        char value = stack->stackarray[stack->top];
        stack->top--;
        return value;
    }
}

char peek(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("stack underflow : stack is empty\n");
        return '\0';
    }
    else
    {
        return stack->stackarray[stack->top];
    }
}

int isempty(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }

    return 0;
}

/* ----end of stack operation ---- */



/* ----expression input function */
void exp_input(char *exp)
{
    scanf("%s", exp);

    int i = 0;
    while(exp[i] != '\0') i++;
    exp[i+1] = '#';
    return;
}



/* ----check parathesis consistency function start here---- */
int check_paranthesis(char *exp)
{

    Stack stack;
    stack.top = -1;

    int i = 0;

    while (exp[i] != '#')
    {
        if (exp[i] == '(' && (isempty(&stack) || peek(&stack) == '('))
        {
            push(&stack, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isempty(&stack))
            {
                return 0;
            }
            else if (peek(&stack) == '(')
            {
                pop(&stack);
            }
        }
        ++i;
    }

    if (isempty(&stack))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/* ----check parathesis consistency function end here---- */

/* ----function to check is character an operand start here---- */
int isoperand(char val){
    if (val == '+') return 0; 
    else if(val == '-') return 0;
    else if(val == '*') return 0;
    else if(val == '/') return 0;
    else if(val == '(') return 0;
    else if(val == ')') return 0;
    else return 1;
}
/* ----function to check is character an operand end here---- */

/* ----priority in stack function start here---- */
int isp(char operator){
    switch (operator)
    {
    case '/':
        return 2;
        break;
    case '*':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '(':
        return 0;
        break;
    case '#':
        return -1;
        break;
    
    default:
        printf("priority is not defined!\n");
        break;
    }
}

/* ----priority in stack function end here---- */


/* ----priority of incoming operator function start here---- */
int icp(char operator){
    switch (operator)
    {
    case '/':
        return 2;
        break;
    case '*':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '(':
        return 4;
        break;
    case '#':
        return -1;
        break;
    
    default:
        printf("priority is not defined!\n");
        break;
    }
}

/* ----priority  of incoming operator stack function end here---- */


/* ----convert infix to postfix expression function start here---- */

char* infix_to_postfix(char*exp){

    Stack stack;
    stack.top = -1;
    push(&stack,'#');

    int i = 0;
    char* postfix = (char*)malloc(MAX*sizeof(char));
    int j = 0;

    while(exp[i] != '#'){
        // printf("top = %c",peek(&stack));break;
        if(isoperand(exp[i])){
            postfix[j] = exp[i];
            j++;
            // break;
        }
        else if(exp[i] == ')'){
            while(peek(&stack) != '('){
                char op = pop(&stack);
                postfix[j] = op;
                j++;

            }//end of while loop
            char rmv = pop(&stack);
        }
        else{
            while(isp(peek(&stack))>=icp(exp[i])){
                char op;
                op = pop(&stack);
                postfix[j] = op;
                j++;
            }
            push(&stack,exp[i]);
        }
        i++;
    }
    while(peek(&stack)!='#'){
        char op;
        op = pop(&stack);
        postfix[j] = op;
        j++;
    }
    postfix[j] = '#';
    return postfix;
}
/* ----convert infix to postfix expression function end here---- */

/* ----function  to evaluate postfix expression start here ---- */
void evaluate_postfix(char exp){
    
}
/* ----function  to evaluate postfix expression start here ---- */


int main()
{

    char exp[MAX];
    printf("enter infix expression : ");
    exp_input(exp);

    char*postfix;
    postfix = infix_to_postfix(exp);
    
    printf("postfix expression : ");
    for(int i = 0; postfix[i] != '#';i++){
        printf("%c",postfix[i]);
    }

}