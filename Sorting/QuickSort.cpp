#include<iostream>
using namespace std;

/*
Quick Sort:
Divide and conquer algorthim

Time Complexity
Best Case - O(nlog(n))
Average Case - O(nlog(n))
Worst Case - O(n^2)

Space Complexity
Worst Case - O(log(n))
*/

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int mid = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < mid)  
        {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
void quickSort(int arr[], int low, int high) {
    if (low < high)  
    {  
        int mid = partition(arr, low, high);  

        quickSort(arr, low, mid - 1);  
        quickSort(arr, mid + 1, high);  
    }  
}  