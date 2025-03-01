#include<iostream>
using namespace std;

/*
Shell Sort:
Shell sort is a variation of insertion sort.
It is more optimized and quicker than insertion sort.

Time Complexity
Best Case - O(n log(n))
Average Case - O(n (log(n))^2)
Worst Case - O(n (log(n))^2)

Space Complexity
Worst Case - O(1)
*/

void shellSort(int arr[], int size)
{
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}