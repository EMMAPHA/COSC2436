#include <iostream>
#include <stdexcept> //handle exceptional conditions in c++

class MiniStack {
private:
    int* data;        // Array to store elements
    int* minData;     // Array to store minimum values
    int capacity;     // Capacity of the stack
    int topIndex;     // Index of the top element

public:
    // Constructor to initialize the stack
    MiniStack(int size) {
        capacity = size;
        data = new int[size];    // allocates memory for the data stack
        minData = new int[size]; // allocates memory for the minimum values stack
        topIndex = -1;           // initializes the top index as -1 (empty stack)
    }


    // Destructor to free the memory
    ~MiniStack() {
        delete[] data;     // deallocates memory for the data stack
        delete[] minData;  // deallocates memory for the minimum values stack
    }
    

    // Function to push an element onto the stack
    void push(int val) {
        if (topIndex == capacity - 1) {
            throw std::overflow_error("FULL"); // checks for stack overflow
        }

        topIndex++;   // increments the top index
        data[topIndex] = val; // pushes the value onto the data stack

        // Updates the minData with the minimum value(edge case?)
        if (topIndex == 0 || val <= minData[topIndex - 1]) {
            minData[topIndex] = val; // if it is the first element or smaller than the previous minimum, we update minData
        } else {
            minData[topIndex] = minData[topIndex - 1]; //else, we keep the previous minimum
        }
    }

    // function to pop the top element from the stack
    void pop() {
        if (topIndex == -1) {
            throw std::underflow_error("EMPTY"); // checks for stack underflow
        }

        topIndex--; //decrements the top index to remove the top element in the stack
    }

    // function to return the top element of the stack
    int top() {
        if (topIndex == -1) {
            throw std::underflow_error("EMPTY"); // checks for stack underflow
        }

        return data[topIndex]; // returns the top element from the data stack
    }

    // function to get the minimum value in the stack
    int getMin() {
        if (topIndex == -1) {
            throw std::underflow_error("EMPTY"); // checks for stack underflow
        }

        return minData[topIndex]; // returns the top minimum value from minData
    }
};

int main() {
    MiniStack myStack(5); // creates a MiniStack with a capacity of 8
    myStack.push(3);
    myStack.push(1);
    myStack.push(2);
    myStack.push(7);
    myStack.push(9);
   // myStack.push(0); //if added, this would be min and top, test for new min
  //myStack.push(4); if this was added, stack would be full
  
    std::cout << "Top element: " << myStack.top() << std::endl; //displays the top element
    std::cout << "Minimum element: " << myStack.getMin() << std::endl; //displays the minimum element


    myStack.pop();
    std::cout << "Top element after pop occured: " << myStack.top() << std::endl; //displays the top element after the pop
    std::cout << "Minimum element after pop occured: " << myStack.getMin() << std::endl;// displays the minimum element after the pop

    return 0;
}
