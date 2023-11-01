# include <stdio.h>

# define SIZE 50

void maxheapify(int arr[], int n ,int i);
void makeheap(int arr[], int n);

void maxheapify(int arr[], int n , int i ){

    int l = 2* i + 1, r = 2*i + 2;

    int largestindex = i;

    if(l<n && arr[largestindex] < arr[l]) largestindex= l;
    if(r<n && arr[largestindex] < arr[r]) largestindex= r;

    if(largestindex != i){
        int temp = arr[i];
        arr[i] = arr[largestindex];
        arr[largestindex] = temp;

        maxheapify(arr,n,largestindex);
    }
}

void makeheap(int arr[],int n){
    for(int i = n/2 -1 ; i>= 0 ; i--){
        maxheapify(arr,n,i);
    }
}


void heapsort(int arr[],int n){
    makeheap(arr,n);
    
    for(int i = 0 ; i<n ; i++){
        int temp = arr[n-i-1];
        arr[n-i-1] = arr[0];
        arr[0] = temp;
        maxheapify(arr,n-i-1,0);
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

    heapsort(arr,size);

    for(int i = 0; i <size ; i++){
        printf("%d ",arr[i]);
    }
}