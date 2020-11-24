// ex- 12 c program for hrap sort
#include <stdio.h>
#include <stdlib.h>

// A heap has current size and array of elements
struct MaxHeap{
    int* array;
    int size;
};

// function for insertion in heap
void InsertHeap(int *array, int num, int location){
    array[location] = num;

}

// function for deletion in heap
void DeleteHeap(int *array, int num, int size){
    int i = 0;
    while(1){
        if(num == array[i]){
            // do the stuffs
            for(;i<size-1;++i){
                array[i] = array[i+i];
            }
            printf("\nSuccessfully deleted!\n");
            return;
        }
        printf("\nOops, No such element is present!\n");
    }
}

// function for just swapping two numbers(used below)
void swap(int* a, int* b){
    int t = *a; *a = *b;  *b = t; 
}

// function for maxHeapify
void maxHeapify(struct MaxHeap* maxHeap, int index){
    int Big = index;  
    int Left = (index << 1) + 1;  
    int Right = (index + 1) << 1; 

    // checking the greater, less or not equal of child of the root
    if (Left < maxHeap->size &&
        maxHeap->array[Left] > maxHeap->array[Big])
        Big = Left;

    if (Right < maxHeap->size &&
        maxHeap->array[Right] > maxHeap->array[Big])
        Big = Right;

    if (Big != index)
    {
        swap(&maxHeap->array[Big], &maxHeap->array[index]);
        maxHeapify(maxHeap, Big);
    }
}

// function to create maxHeap
struct MaxHeap* createAndBuildHeap(int *array, int size){
    int i;
    struct MaxHeap* maxHeap =
              (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
    maxHeap->size = size;   
    maxHeap->array = array; 

    for (i = (maxHeap->size - 2) / 2; i >= 0; --i)
        maxHeapify(maxHeap, i);
    return maxHeap;
}

// For heapsort function
void heapSort(int* array, int size)
{
    // building a heap
    struct MaxHeap* maxHeap = createAndBuildHeap(array, size);
    while (maxHeap->size > 1)
    {
        swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
        --maxHeap->size;  // Reduce heap size

        // root heapify
        maxHeapify(maxHeap, 0);
    }
}

// function to print the array
void Display(int* arr, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

// main function begins here
int main()
{
    int size = 1;
    int array[size];
    int op = 0; // for options
    int location = 0; // for tracking the location
    while(1){
        printf("Enter the options to be executed: \n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Quit\n");
        scanf("%d",&op);
        switch(op){  // using the swicth case
            case 1: printf("Enter the number to be inserted: ");
                    scanf("%d",&op);
                    InsertHeap(array, op, location);
                    heapSort(array, size);
                    location+=1;
                    size+=1;
                    printf("\nInserted Successfully!\n");
                    break;
            case 2: printf("Enter the number to be deleted: ");
                    scanf("%d",&op);
                    DeleteHeap(array, op, size);
                    heapSort(array, size);
                    location-=1;
                    size-=1;
                    break;
            case 3: printf("The array is: \n");
                    Display(array, size);
                    break;
            case 4: printf("\nExiting...\n");
                    exit(0);
            default: printf("\nWrong Option selected!\n");
        }
    }
}
