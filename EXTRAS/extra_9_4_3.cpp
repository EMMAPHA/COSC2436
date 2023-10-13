#include <iostream>
using namespace std;

void swap(int& i, int& j) {
  int temp = i;
  i = j;
  j = temp;
}

void bubbleSortV1(int arr[], int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}

void bubbleSortV2(int arr[], int n) {
  bool sorted;
  for (int i = 0; i < n-1; i++) {
    sorted = true;
    for (int j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        sorted = false;
      }
    }
    if (sorted) {
      break;
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}

void SelectionSort(int arr[], int n) {
  int min_indx;
  for (int i = 0; i < n-1; i++) {
    min_indx = i;
    for(int j = i+1; j < n; j++) {
      if (arr[j] < arr[min_indx]) {
        min_indx = j;
      }
    }
    int temp = arr[i];
        arr[i] = arr[min_indx];
        arr[min_indx] = temp;
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}

void InsertionSort(int arr[], int n) {
  int key;
  for (int i = 1; i<n; i++) {
    key = arr[i];
    // cout << key << " = key\n";
    int j = i - 1;
    while ( j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      // cout << arr[j+1] << " " << arr[j] << endl;
      j = j - 1;
      // cout << j << " is j\n";
    }
    arr[j+1] = key;
    for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
    cout << endl;
  }
  
  
}

int main() {
  int arr1[6] = {5, 4, 2, 9, 1, 0};
  int arr2[8] = {8, 30, 11, 16, 1, 14, 6, 5};
  int arr3[6] = {7, 3, 1, 2, 6, 5};
  int arr4[6] = {10, 3, 17, 7, 24, 2};

  cout << "Bubble Sort (V1): " << endl;
   bubbleSortV1(arr1, 6); 
   cout << endl;
    cout << "Bubble Sort (V2): " << endl;
   bubbleSortV2(arr4, 6);
  cout << endl;
    cout << "Selection Sort: " << endl;
SelectionSort(arr2, 8);
   cout << endl; 
    cout << "Insertion Sort: " << endl;  
/*    InsertionSort(ar1, 6);
   cout << endl; */

  //int ar[6] = {10, 3, 9, 7, 24, 2};
   InsertionSort(arr3, 6);
  

  // for (int i = 0; i < 6; i++) {
  //   cout << arr[i] << " ";
  // }
}


 //if alr sorted, you still have to compare (you dont have to swap since its alr //sorted)