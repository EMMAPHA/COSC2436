#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
Time Complexity
Best Case - O(n + k), where n is the size of the array and k is the number of buckets 
Average Case - O(n + k)
Worst Case - O(n^2)

Space Complexity
Worst Case - O(n)
*/

void insertionSort(vector<float> arr, int size) {
    for(int i = 1; i < size; i++)
    {
        float key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bucketSort(float arr[], int size) {
    vector<float> buckets[size];

    for (int i = 0; i < size; i++) {
        int bIndex = size * arr[i];
        buckets[bIndex].push_back(arr[i]);
    }

    for (int i = 0; i < size; i++)
        insertionSort(buckets[i], size);
        //sort(buckets[i].begin(), buckets[i].end());

    int index = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index] = buckets[i][j];
            index++;
        }
}
