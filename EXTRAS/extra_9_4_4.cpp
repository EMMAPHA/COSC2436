#include <iostream>
//extra_9_5_1
// Write a function that appends a linked list at the end of another linked list.
// Your function should return the head of the new linked list.
// Define the node struct for a singly linked list.
struct node {
    int data;
    node* next;

        node(int val) {// constructor
        data = val;
        next = nullptr;
    }
    //node(int val) : data(val), next(nullptr) {} // constructor
};

// Function to append list2 at the end of list1.
node* append(node* list1, node* list2) {
    // If list1 is empty, return list2.
    if (list1 == nullptr)
        return list2;

    // If list2 is empty, return list1.
    else if (list2 == nullptr)
        return list1;

    // Store the original list1 pointer in newList.
    // This is done to ensure that you return the original head of list1 at the end,
    // even after list1 is modified during traversal.
    node* newList = list1;

    // Traverse list1 to find its last node.
    while (list1->next != nullptr) {
        list1 = list1->next;
    }

    // Connect the last node of list1 to list2, effectively appending list2 to list1.
    list1->next = list2;

    // Return the updated list1 (which now contains list2 appended to it).
    return newList;
}

// Function to print a linked list.
void printList(node* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create two linked lists.
    node* list1 = new node(4);
    list1->next = new node(2);
    list1->next->next = new node(3);
    list1->next->next->next = new node(4);
    list1->next->next->next->next = new node(6);
    node* list2 = new node(5);
    list2->next = new node(0);
    list2->next->next = new node(4);
    list2->next->next->next = new node(9);

    std::cout << "List 1: ";
    printList(list1);

    std::cout << "List 2: ";
    printList(list2);

    // Append list2 at the end of list1.
    node* mergedList = append(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
