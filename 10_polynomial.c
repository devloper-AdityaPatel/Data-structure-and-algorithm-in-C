
# include <stdio.h>
# include <stdlib.h>
# define POW(i) poly_ptr[i].pow
# define COF(i) poly_ptr[i].cof

struct poly{
    int pow , cof;
};

typedef struct poly poly;


poly* read_poly(int size){

    poly* poly_ptr=0;
    poly_ptr = (poly*)malloc(size*sizeof(poly_ptr));

    int i = 0;
    while(i<size){
        printf("\nEnter power and cofficients for %drd term",size-i);
        printf("\npower = ");
        scanf(" %d",&POW(i));

        printf("cofficient = ");
        scanf(" %d",&COF(i));
        i++;
    }

    return poly_ptr;
}

void display_poly(poly* poly_ptr,int size){
    int i = 0;
    while(i < size){
        printf("(%d)X^%d",COF(i),POW(i));
        i++;
        if(i!=size){
            printf("+");
        }
    }
}

int main(){
    poly * poly_ptr = 0;
    int size = 3;
    poly_ptr = read_poly(size);
    display_poly(poly_ptr,size);

    return 0;
}
