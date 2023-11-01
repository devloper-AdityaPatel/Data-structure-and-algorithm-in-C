#include <stdio.h>
#define SIZE 50

void insert_in_minheap(int arr[], int *size, int x);
void delete_in_minheap(int arr[], int *size);
void minheapify(int arr[], int n, int i);
void make_min_heap(int arr[], int n);
void decreasekey(int arr[], int n, int decby);

void insert_in_minheap(int arr[], int *size, int x)
{

    arr[*size] = x;
    int i = *size;
    ++*size;

    while (i > 0)
    {
        int prnt = (i - 1) / 2;

        if (arr[prnt] < arr[i])
        {
            break;
        }
        else
        {
            int tmp = arr[prnt];
            arr[prnt] = arr[i];
            arr[i] = tmp;
            i = prnt;
        }
    }
}

void delete_in_minheap(int arr[], int *size)
{

    arr[0] = arr[*size - 1];
    --*size;
    int i = 0;

    while (i < *size)
    {
        int l = 2 * i + 1, r = 2 * i + 2;

        int sidx = i;

        if (l < *size && arr[sidx] > arr[l])
            sidx = l;
        if (r < *size && arr[sidx] > arr[r])
            sidx = r;

        if (sidx == i)
        {
            break;
        }
        else
        {
            int tmp = arr[i];
            arr[i] = arr[sidx];
            arr[sidx] = tmp;
            i = sidx;
        }
    }
}

void minheapify(int arr[], int n, int i)
{

    int l = 2 * i + 1, r = 2 * i + 2;
    int sidx = i; // smallest index
    if (l < n && arr[sidx] > arr[l])
        sidx = l;

    if (r < n && arr[sidx] > arr[r])
        sidx = r;

    if (sidx != i)
    {
        int temp = arr[i];
        arr[i] = arr[sidx];
        arr[sidx] = temp;

        minheapify(arr, n, sidx);
    }
}

void make_min_heap(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minheapify(arr, n, i);
    }
}

void decreasekey(int arr[], int n, int decby)
{
    int largest = n / 2;
    for (int i = n / 2; i < n; i++)
    {
        if (arr[largest] < arr[i])
            largest = i;
    }
    arr[largest] = arr[largest] - decby;

    make_min_heap(arr,n);
}
int main()
{
    int arr[SIZE];
    int size;

    printf("Enter size : ");
    scanf(" %d",&size);

    for(int i = 0 ; i < size ;i++){
        printf("a[%d] : ",i);
        scanf(" %d",&arr[i]);
    }

    int choice = 0;
    printf("0. exit \n1. insert in heap\n2. delete in minheap\n3. make min heap\n4. to decrease max value \n5. display heap");

    printf("\nenter choice : ");
    scanf(" %d",&choice);

    while(choice){

        switch (choice)
        {
        case 1:
            int data;
            printf("enter data : ");
            scanf(" %d",&data);

            insert_in_minheap(arr,&size,data);

            break;

        case 2:
            delete_in_minheap(arr,&size);
            break;

        case 3:
            make_min_heap(arr,size);
            break;

        case 4:
            int decby = 0;
            printf("enter decrement by : ");
            scanf(" %d",&decby);
            decreasekey(arr,size ,decby);
            break;

        case 5:
            for(int i = 0 ; i<size ; i++){
                printf("%d ",arr[i]);
            }
            break;
        default:

            printf("enter invalid choice\n");
            break;
        }

        printf("\nenter choice : ");
        scanf(" %d",&choice);

    }
}