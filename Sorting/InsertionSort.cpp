#include<iostream>
using namespace std;

/*
Insertion Sort:
1. Compares the first two elements
2. Both have to be in this form arr[0] < arr[1]
3. Go to the next position and compare elements
4. If arr[2] < arr[1], then swap arr[2] and arr[1]
5. After swapping, compare the next previous elements arr[1] and arr[0]
6. If arr[1] < arr[0], then swap arr[1] and arr[0]
7. Go to the next positions and compare elemtents and repeat

Time Complexity
Best Case - O(n)
Average Case - O(n^2)
Worst Case - O(n^2)

Space Complexity
Worst Case - O(1)
*/

void insertionSort(int arr[], int size) {
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}