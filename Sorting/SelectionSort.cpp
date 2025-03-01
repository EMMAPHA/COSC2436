#include<iostream>
using namespace std;

/*
Selection Sort:
1. Start at arr[0] and scan the list to find the minimum
2. Swap with arr[0] and minimum
3. Move to the next position arr[1] and scan the list again for minimum
4. Swap with arr[1] and minimum
AND SO ON...

Time Complexity
Best Case - O(n^2)
Average Case - O(n^2)
Worst Case - O(n^2)

Space Complexity
Worst Case - O(1)
*/

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++)
    {
        int minimum = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[minimum])
            {
                minimum = j;
            }
        }
        if(minimum != i)
        {
            //swap(arr[i], arr[minimum])
            int temp = arr[i];
            arr[i] = arr[minimum];
            arr[minimum] = temp;
        }
    }
}