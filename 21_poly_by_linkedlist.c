# include <stdio.h>
# include <stdlib.h>
/* ----user defined data type---- */
struct  node
{
    int cof,pow;
    struct node*next;
};

typedef struct node node;

struct poly
{
    node* head,*tail;
};
typedef struct poly poly;

/* ----function---- */

void poly_init(poly * polyptr){
    polyptr->head = 0;
    polyptr->tail = 0;
}

node* createnode(void){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->next = 0;
    newnode->cof = 0;
    newnode->pow = 0;

    return newnode;
}
void read_polynomial(poly * polyptr,int coff,int pow){
    node* newnode = createnode();
    newnode->cof = coff;
    newnode->pow = pow;
    if(polyptr->head == 0 && polyptr->tail == 0){
        polyptr->head = polyptr->tail = newnode;
        return;
    }
    else{
        newnode->next = polyptr->head;
        polyptr->head = newnode;
        return;
    }
}

void display_polynomial(poly* polyptr){
    node* temp1 = polyptr->head;
    node* temp2 = polyptr->tail;

    while (temp1 != 0)
    {
        printf("(%d)x^%d+",temp1->cof,temp1->pow);
        temp1 = temp1->next;
    }
    printf("\b\n");
}

poly addpolynomial(poly p1,poly p2){

    node* temp1 = p1.head;
    node* temp2 = p2.head;

    poly p3;
    poly_init(&p3);
    
    while (temp1 != 0 && temp2 != 0)
    {
        if(temp1->pow == temp2->pow){
            read_polynomial(&p3,(temp1->cof+temp2->cof),temp1->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->pow > temp2->pow){
            read_polynomial(&p3,temp1->cof,temp1->pow);
            temp1 = temp1->next;
        }
        else{
            read_polynomial(&p3,temp2->cof,temp1->pow);
            temp2 = temp2->next;
        }
    }

    if(temp1 == 0){
        while(temp2 != 0){
            read_polynomial(&p3,temp2->cof,temp1->pow);
            temp2 = temp2->next;
        }
    }
    if(temp2 == 0){
        while(temp1 != 0){
            read_polynomial(&p3,temp1->cof,temp1->pow);
            temp1 = temp1->next;
        }
    }

    return p3;
}

int main(){
    
    poly p1,p2,p3;
    poly_init(&p1); // initializing polynomial
    poly_init(&p2); // initializing polynomial
    poly_init(&p3); // initializing polynomial

    printf("reading polynomial 1\n");
    while (1){
        int coff ,pow;
        printf("Enter power(-1 to exit) : ");
        scanf(" %d",&pow);
        if(pow == -1){
            break;
        }
        printf("Enter cofficient of power %d : ",pow);
        scanf(" %d",&coff);
        read_polynomial(&p1,coff,pow);
    }
    printf("reading polynomial 2\n");
    while (1){
        int coff ,pow;
        printf("Enter power(-1 to exit) : ");
        scanf(" %d",&pow);
        if(pow == -1){
            break;
        }
        printf("Enter cofficient of power %d : ",pow);
        scanf(" %d",&coff);
        read_polynomial(&p2,coff,pow);
    }
    printf("polynomial 1\n");
    display_polynomial(&p1);
    printf("polynomial 2\n");
    display_polynomial(&p2);
    p3 = addpolynomial(p1,p2);
    printf("polynomial 3\n");
    display_polynomial(&p3);



}