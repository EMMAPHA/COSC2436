#include <iostream>

void resizeArr(int* & arr, int &curSize){
    curSize *= 2;
    int* temp = new int[curSize];

    delete [] arr;
    arr =temp;
}


void print(int* arr, int size){
    for(int i=0;i<size;i++)
        std::cout<<arr[i]<<' ';
    std::cout<<'\n';
}

int main(){
    int size=5;
    int* arr = new int[5];
    
    print(arr, size);
    resizeArr(arr, size);
    print(arr, size);    
    
    delete[] arr;
    return 0;
}