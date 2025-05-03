#include <iostream>
#include <stack>
using namespace std;

// function to sort a stack using an additional temporary stack
void sort_stack(stack<int>& s, stack<int>& temp) {
    // loop until the original stack is empty
    while (!s.empty()) {
        // takes the top element from the original stack
        int current = s.top();
        s.pop();

        // moves the elements from the temporary stack back to the original stack
        // as long as they are greater than the current element
        while (!temp.empty() && temp.top() > current) {
            s.push(temp.top());  // moves element from temp to original stack
            temp.pop();         // removes the element from temp
        }

        // pushes the current element onto the temporary stack
        temp.push(current);
    }

    // after processing elements the temporary stack contains
    // the elements in a sorted order, so we move them back to the original stack
    while (!temp.empty()) {
        s.push(temp.top());  // moves element from temp to original stack
        temp.pop();         // removes the element from temp
    }
}

int main() {
    stack<int> st;      // original stack that is to be sorted
    stack<int> temp;    // temporary stack for the sorting

    // fill st with the input values(given in slides)
    st.push(45);
    st.push(55);
    st.push(5);
    st.push(55);
    st.push(25);
    st.push(35);
    st.push(25);

    // sorts the st using the sort_stack function
    sort_stack(st, temp);

    // prints the sorted stack
    while (!st.empty()) {
        cout << st.top() << endl;  // prints the top element of the stack
        st.pop();                 // removes the top element
    }

    return 0;
}

