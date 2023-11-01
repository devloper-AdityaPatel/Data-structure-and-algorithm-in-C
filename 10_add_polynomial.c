/* program to add two polynomial.
 * Created on : 22-08-2023
 * created by : Aditya Patel
 * Roll no : 2k22/co/31 */
#include <stdio.h>
#include <stdlib.h>
#define POW(p,i) p[i].pow
#define COF(p,i) p[i].cof

struct poly
{
    int pow, cof;
};

typedef struct poly poly;

poly *read_poly(int size)
{

    poly *poly_ptr = 0;
    poly_ptr = (poly *)malloc(size * sizeof(poly_ptr));

    int i = 0;
    while (i < size)
    {
        printf("\nEnter power and cofficients for %drd term", size - i);
        printf("\npower = ");
        scanf(" %d", &POW(poly_ptr,i));

        printf("cofficient = ");
        scanf(" %d", &COF(poly_ptr,i));
        i++;
    }

    return poly_ptr;
}

void display_poly(poly *poly_ptr, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("(%d)X^%d", COF(poly_ptr,i), POW(poly_ptr,i));
        i++;
        if (i != size)
        {
            printf("+");
        }
    }
}

poly *add_poly(poly *p1, poly *p2, int size_of_p1, int size_of_p2,int*ptr_size_of_p3 )
{
    /* p1 = first polynomial passed for sum
     * p2 = second polynomial passed for sum
     * size_of_p1 = no of terms in p1
     * size_of_p2 = no of terms in p2
     * ptr_size_of_p3 = no of terms in p3 (after addition of p1 and 2),and we declare this parameter to return by reference
                        ,ideally its intitial value = 0 */

    poly *p3 = 0; // p3 = resultant polynomial after sum;
    p3 = (poly *)malloc((size_of_p1 + size_of_p2) * sizeof(poly)); // allocating maximum memory to p3

    int i = 0, j = 0, k = 0;
    while (i < size_of_p1 && j < size_of_p2)
    {
        if(POW(p1,i)>POW(p2,j)){
            POW(p3,k) = POW(p1,i);
            COF(p3,k) = COF(p1,i);
            i++;
        }
        else if(POW(p1,i)<POW(p2,j)){
            POW(p3,k) = POW(p2,j);
            COF(p3,k) = COF(p2,j);
            j++;
        }
        else{
            POW(p3,k) = POW(p2,j);
            COF(p3,k) = COF(p2,j)+COF(p1,+i);
            i++ , j++;
        }
        k++;
    }
    // printf("\n i = %d ,j = %d , k = %d \n",i,j,k);
    if(i == size_of_p1){
        // printf("inside 1\n");
        while(j < size_of_p2){
            POW(p3,k) = POW(p2,j);
            COF(p3,k) = COF(p2,j);
            j++,k++;
        }
    }
    if(j == size_of_p2){
        // printf("inside 2");
        while(i<size_of_p1){
            POW(p3,k) = POW(p1,i);
            COF(p3,k) = COF(p1,i);
            i++,k++;
        }
    }


    /* below code is writtent to reallocate memory for p3 polynomial because initial we assumed sizeof
    p3 = sizeof(p2) + sizeof(p3) and after addition it would occupy less memory than allocated earlier
    */
    p3 = (poly*)realloc(p3,k*sizeof(poly));

    //below code return no of terms in third polynomial
    *ptr_size_of_p3=k;
    printf("\n k = %d \n",k);

    return p3;
}


int main()
{
    poly* p1 = 0,*p2 =0,*p3 = 0;
    int size1 = 4 , size2 = 4 ,size3 = 0;
    p1=read_poly(size1);
    p2 = read_poly(size2);
    p3 = add_poly(p1,p2,size1,size2,&size3);
    printf("p1\n");
    display_poly(p1,size1);
    printf("\np2\n");
    display_poly(p2,size2);
    printf("\nsum\n");
    display_poly(p3,size3);
    


    return 0;
}
