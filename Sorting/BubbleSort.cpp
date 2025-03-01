#include<iostream>
using namespace std;

/*
Bubble Sort:
It'll take an unsorted array, then compare 2 elements and see which one is greater.

Bubble Sort V1:
Time Complexity
Best Case - O(n)
Average Case - O(n^2)
Worst Case - O(n^2)

Space Complexity
O(1)
*/

void bubbleSortV1(int arr[], int size) {
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                //swap(arr[j], arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/*
Bubble Sort V2:
Time Complexity
Best Case - O(n)
Average Case - O(n^2)
Worst Case - O(n^2)

Space Complexity
Worst Case - O(1)
*/

void bubbleSortV2(int arr[], int size) {
    int i = 0;
    bool flag = false;
    while(!false)
    {
        flag = true;
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                //swap(arr[j], arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        i++;
    }
}