/* Menu driven program to perform operation on unsorted array */

#include <stdio.h>
#define NEWLINE printf("\n");

void display(int *, int);
void create_array(int *, int);
int linear_search(int *, int, int);
void insert_in_array(int *, int *, int);
void delete_element(int *, int *, int);
int val(void);

// function to take input;
int val(void){
    int value;
    printf("enter value: ");
    scanf("%d", &value);
    return value;
}

// function to delete element from array
void delete_element(int *a, int *ptr_size, int value)
{
    int pos;
    pos = linear_search(a, *ptr_size, value);
    if (pos == -1)
    {
        printf("element cannot deleted as element is not persent\n");
        NEWLINE
    }
    else
    {
        *(a + pos) = *(a + *ptr_size);
        --*ptr_size;
        printf("element deleted successfully");
    }
}

// Function to search in array and return position
int linear_search(int *a, int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (*(a + i) == value)
        {
            return i;
        }
    }

    return -1; // if element is not persent
}

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

// Function to insert in array
void insert_in_array(int *a, int *size, int value)
{
    *(a + *size) = value;
    ++*size;
}

int main()
{
    int a[100];
    int size = 0, *ptr_size = &size;

    // Menu program
    int choice = 1;
    printf("chose any following operation :\n\
        0. To exit\n\
        1. To create array(Note : Max 100 element\n\
        2. To display array\n\
        3. To insert in array\n\
        4. To linear search in array\n\
        4. To delete element in array\n\
        \n");
    while (choice != 0)
    {   
        NEWLINE
        printf("Enter Choice : ");
        scanf(" %d", &choice);
        NEWLINE

        switch (choice)
        {
        case 1:
            NEWLINE

            printf("Enter size of array : ");
            scanf(" %d", &size);

            if (size > 100)
            {
                printf("array is overflow\n");
            }
            else if (size <= 0)
            {
                printf("array is underflow\n");
            }
            else
            {
                create_array(a, size);
            }
            break;

        case 2:
            NEWLINE
            display(a, size);
            NEWLINE

            break;
        case 3:
            int insert_value;
            insert_value=val();
            insert_in_array(a, ptr_size, insert_value);

            break;
        
        case 4:
            int search_value,pos;
            search_value=val();
            pos = linear_search(a,size,search_value);
            if(pos==-1){
                printf("element is not found\n");
                NEWLINE
            }
            else{
                printf("element is found at position %d \n",pos);
                NEWLINE
            }
            break;

        case 5:
            int del_value;
            del_value=val();
            delete_element(a,ptr_size,del_value);
            break;

        default:
            if (choice != 0)
                printf("chosen invalid choice\n");
            ;
        }

        if (choice == 0)
        {
            break;
        }
    }
}

