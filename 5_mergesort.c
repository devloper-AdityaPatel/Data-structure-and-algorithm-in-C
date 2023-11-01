/* program to sort an array using merge sort */
# include <stdio.h>
# include <stdlib.h>

# define NEWLINE printf("\n");

// function to create array
void create_array(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("element [%d] = ", i + 1);
        scanf(" %d", (a + i));
    }
}

// Function to display array
void display(int *a, int size)
{
    NEWLINE
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("]");
    NEWLINE
}

void merge(int*a,int lb,int mid,int ub){
    int i = lb;
    int j = mid+1;
    int k = lb;

    int * ptr;
    int size =ub+1; // I don't the logic behind this line to allocate memory
    ptr=(int*)malloc((size)*sizeof(int));
    // int ptr[lb+ub+1];
    
    printf("inside merge\n");
    while(i<=mid && j<=ub){
        if(a[i]<a[j]){
            ptr[k]=a[i];
            i++;
        }
        else{
            ptr[k]=a[j];
            j++;
        }
        k++;
    }

    if(i>mid){
        while(j<=ub){
            ptr[k++]=a[j++];
        }
    }
    else{
        while(i<=mid){

        ptr[k++]=a[i++];
        }
    }

    for(int i = lb ;i<=ub;i++){
        a[i]=ptr[i];
    }
    free(ptr);

}
void mergesort(int*a,int lb,int ub){
    if(lb<ub){
        int mid;
        mid = (lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

int main(){
    int a[10];
    int size = 10;

    create_array(a,size);
    mergesort(a,0,9);
    display(a,size);
    return 0;
}