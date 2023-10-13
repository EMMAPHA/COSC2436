//extra_9_4_1
#include <iostream>
using namespace std;


int main()
{
    int num;
    char* name;

    cout << "Please enter the amount of characters in the name!" << endl;
    cin >> num; 

    //TODO1: allocate memory for the name
    //! Hint: Use the new keyword
    // * Write Code Here *
    name = new char[num]; //allocate memory for an array of num char

    cout << "Please enter the name!" << endl;

    //TODO2: store the name in the allocated memory
    //* Write Code Here *
    
    //cin >> name;
    for(int i = 0; i < num; i++)
    {
        cin >> name[i];
    }
    

    cout << "The name is: " << endl;

    for(int i = 0; i < num; i++)
    {
        cout << name[i];
    }

    //TODO3: deallocate memory for the name
    //! Hint: Use the delete keyword
    //* Write Code Here *
    delete [] name; //deallocate memory for a char (name)

    return 0;
}