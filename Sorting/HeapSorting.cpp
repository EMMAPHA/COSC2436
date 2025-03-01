#include<iostream>
using namespace std;
/*
Maximum/Minimum Heap Sorting:

Time Complexity
Best Case - O(n log(n)), where n is the size of the array
Average Case - O(n log(n))
Worst Case - O(n log(n))

Space Complexity
Worst Case - O(1)
*/

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Maximum Heap Sorting
void heapify(int arr[], int size, int i) {
    int largest = i;
    int L = 2 * i + 1;
    int R = 2 * i + 2;

    if(L < size && arr[L] > arr[largest]) // switch sign to < to find the minimum
    {
        largest = L;
    }
    if(R < size && arr[R] > arr[largest]) // switch sign to < to find the minimum
    {
        largest = R;
    }
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}

void buildHeap(int arr[], int size) {
    //Buidling a maximum heap
    int start = (size - 2) / 2;
    for(int i = start; i >= 0; i--)
    {
        heapify(arr, size, i);  //heapify from the top
    }
}

void heapSort(int arr[], int size) {
    buildHeap(arr, size);

    for(int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}