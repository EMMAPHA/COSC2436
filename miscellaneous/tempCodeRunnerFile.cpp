//extra_8_5_3
//pointers and deallocating memories
#include <iostream>
using namespace std;

int main(){
    int n, m;

    cin >> n >> m;

    int** myArr = new int*[n]; //create an array of pointers

    for(int i = 0; i < n; i++)
    {
        myArr[i] = new int[m];
    }

    //input to 2d matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) 
        {
            cin >> myArr[i][j];
        }

        cout << endl;
    }

    //Output 2D Matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) 
        {
            cout << myArr[i][j] << " ";
        }

        cout << endl;
    }

    //deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] myArr[i];//delete inner arrays
    }
    delete[] myArr;

    return 0;
}