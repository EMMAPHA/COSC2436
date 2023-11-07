//extra 10_2_3
//choose 1 to apply merge sort on 100 random elements
//choose 2 to apply shell sort on 100 random elements
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int begin, int end);

void shellSort(int arr[], int n);


int main() {
  int table[100];


  for (int i=0;i< 100; i++){
    table[i]=rand()%100;
  }

  int choice;
  cout << "Choose a sorting method: " << endl;
  cout << "1. Merge Sort" << endl;
  cout << "2. Shell Sort" << endl;

  cin >> choice;

  clock_t beg, end;
  switch (choice) {
    case 1:
          beg = clock();
          mergeSort(table, 0,99);
          end = clock();
          cout << "Merge Sort took " << double(end-beg) / CLOCKS_PER_SEC << " seconds" << endl;
          break;
    case 2:
          beg = clock();
          shellSort(table, 100);
          end = clock();
          cout << "Shell Sort took " << double(end-beg) / CLOCKS_PER_SEC << " seconds" << endl;
          break;
    default:
          cout << "choose only 1-2" << endl;
          break;
  }

  return 0;

}

void mergeSort(int arr[], int begin, int end) {

  if(begin < end){

    int midpoint = begin + (end - begin) / 2;

    mergeSort(arr, begin, midpoint);
    mergeSort(arr, midpoint + 1, end);

    merge(arr, begin, midpoint, end);
  }
}
void merge(int arr[], int left, int mid, int right){

  int leftSubArray = mid - left + 1;
  int rightSubArray = right - mid;

  int leftArray[leftSubArray], rightArray[rightSubArray];

  for(int i = 0; i < leftSubArray; i++)
    leftArray[i] = arr[left + i];

  for(int j = 0; j < rightSubArray; j++)
    rightArray[j] = arr[mid + 1 + j];

  int indexOfLeftSubArray = 0;
  int indexOfRightSubArray = 0;
  int indexOfMergedArray = left;

  while(indexOfLeftSubArray < leftSubArray && indexOfRightSubArray < rightSubArray)
    {
      if(leftArray[indexOfLeftSubArray] <= rightArray[indexOfRightSubArray])
      {
        arr[indexOfMergedArray] = leftArray[indexOfLeftSubArray];
        indexOfLeftSubArray++;
      }

      else{
        arr[indexOfMergedArray] = rightArray[indexOfRightSubArray];
        indexOfRightSubArray++;
      }
     indexOfMergedArray++; 
    }

  while(indexOfLeftSubArray < leftSubArray)
    {
      arr[indexOfMergedArray] = leftArray[indexOfLeftSubArray];
      indexOfLeftSubArray++;
      indexOfMergedArray++;
    }

  while(indexOfRightSubArray < rightSubArray)
    {
      arr[indexOfMergedArray] = rightArray[indexOfRightSubArray];
      indexOfRightSubArray++;
      indexOfMergedArray++;
    }
 }

void shellSort(int arr[], int n) {

  for(int gap = n / 2; gap > 0; gap /= 2)
    {
      //insertion sort for these subarrays with gaps
      for(int i = gap; i < n; i++)
      {

        int temp = arr[i];
        int j;

        for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
          {
            arr[j] = arr[j - gap];
          }

          arr[j] = temp;
      }
    }
}