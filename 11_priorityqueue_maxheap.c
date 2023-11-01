/* all function of heapify is written here */
# include <stdio.h>
# include <math.h>

# define SIZE 50


void insert_in_heap(int arr[],int* psize , int x);
void delete_max(int arr[], int* psize/* size */);
void maxheapify(int arr[],int n , int i);
void heapsort(int arr[],int n);
void make_heap(int arr[], int n);
void increasekey(int arr[],int n,int incby);

void increasekey(int arr[],int n,int incby){
    int smallest = n/2;

    for(int i = n/2;i<n;i++){
        if(arr[i]<arr[smallest]){
            smallest = i;
        }
    }

    arr[smallest] = incby + arr[smallest];
    make_heap(arr,n);
}
void insert_in_heap(int arr[],int* psize , int x){
    int n  = *psize;
    arr[n] = x;
    n = n + 1;
    *psize = n;
    int i = n-1;

    while (i>0)
    {   
        
        int p  =  floor((i-1)/2);

        if(arr[p]>arr[i]){
            break;
        }
        else{
            int temp = arr[i];
            arr[i] =arr[p];
            arr[p] = temp;
            i = p;
        }
    }
    
}

void delete_max(int arr[], int* psize/* size */){
    int n = *psize;
    int x = arr[0];
    arr[0] = arr[n-1];

    n = n-1;
    *psize = n;
    
    int i = 0;

    while(i<n){
        int l = 2 * i + 1 , r = 2*i + 2;

        int lindex = i;

        if(l < n && arr[l]>arr[lindex]){
            lindex = l;
        }
        if(r < n && arr[r]> arr[lindex]){
            lindex = r;
        }

        if(lindex != i){
            int temp = arr[i];
            arr[i] =arr[lindex];
            arr[lindex] = temp;
            i = lindex;
        }
        else{
            break;
        }
    }
}


void maxheapify(int arr[],int n , int i){

    int l = 2*i + 1 , r = 2 * i + 2;

    int lindex = i; //largest index

    if(l<n && arr[l]>arr[lindex]) lindex = l;
    if(r<n && arr[r]>arr[lindex]) lindex = r;

    if(lindex !=i){
        int temp = arr[i];
        arr[i] = arr[lindex];
        arr[lindex] = temp;

        maxheapify(arr,n,lindex);
    }

}


void heapsort(int arr[],int n){
    make_heap(arr,n);


    for(int i = n ; i > 0 ; i--){
        int temp = arr[0];
        arr[0] = arr[i-1];
        arr[i-1] = temp;
        
        maxheapify(arr,i-1,0);
    }

}

void make_heap(int arr[], int n){

    for(int i = n/2 -1 ; i>=0 ; i--){
        maxheapify(arr,n,i);
    }
}


int main(){

    int arr[SIZE];
    int size;

    printf("Enter size : ");
    scanf(" %d",&size);

    for(int i = 0 ; i < size ;i++){
        printf("a[%d] : ",i);
        scanf(" %d",&arr[i]);
    }

    int choice = 0;
    printf("0. exit \n1. insert in heap\n2. delete in maxheap\n3. make max heap\n4. to increase min value \n5. display heap\n6. heapsort");

    printf("\nenter choice : ");
    scanf(" %d",&choice);

    while(choice){

        switch (choice)
        {
        case 1:
            int data;
            printf("enter data : ");
            scanf(" %d",&data);

            insert_in_heap(arr,&size,data);

            break;

        case 2:
            delete_max(arr,&size);
            break;

        case 3:
            make_heap(arr,size);
            break;

        case 4:
            int decby = 0;
            printf("enter increment by : ");
            scanf(" %d",&decby);
            increasekey(arr,size ,decby);
            break;

        case 5:
            for(int i = 0 ; i<size ; i++){
                printf("%d ",arr[i]);
            }
            break;
        
        case 6:
            heapsort(arr,size);
            break;
        default:

            printf("entered invalid choice\n");
            break;
        }

        printf("\nenter choice : ");
        scanf(" %d",&choice);

    }

}