//extra_8_5_2
#include <iostream>
using namespace std;
//print from 0 to size-1
void forward(int array[], int size)//prints the array forwards
{
  if(size > 1)
    forward(array, size - 1);
  cout << array[size-1] << " ";
}

//print from size-1 to 0
void backward(int array[], int size)//prints the array backwards
{
  cout << array[size-1] << " ";
  if(size > 1)
    backward(array, size - 1);
}

int main() {
    int myArray[] = {1, 2, 3, 4, 5};

    forward(myArray, 5);
    cout << endl;
    backward(myArray, 5);

    

    return 0;
}
