#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "doublyLL.h"
#include "ArgumentManager.h"
using namespace std;

//I used this website 
//https://www.geeksforgeeks.org/insertion-sort-doubly-linked-list/
//to help me with the insertion sort

//https://www.youtube.com/watch?v=bSORX7TcFvs&t=1001s 
//^this gave me insight for the sorting functions

void insertionSort(doublyLL& DLL, ofstream& ofs) {
    node* head = DLL.getHead();
    bool swapped = false;
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    node* sorted = nullptr; // this initializes the sorted list as empty
  
    node* cur = head; // traverses through the original list
    while (cur != nullptr) {
        node* next = cur->next; //this stores the next node

        if (sorted == nullptr || sorted->data >= cur->data) {
            // this inserts at the beginning of the sorted list
            cur->next = sorted;
            cur->prev = nullptr;
            if (sorted != nullptr) {
                sorted->prev = cur;
            }
            sorted = cur;
        } else {
            // finds the node in sorted list where cur is
            node* temp = sorted;
            while (temp->next != nullptr && temp->next->data < cur->data) {
                temp = temp->next;
            }
            cur->next = temp->next;
            cur->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = cur;
            }
            temp->next = cur;
        }

        cur = next; // moves to the next node in the original list
      if(swapped){
        node* currprint = sorted;
        ofs << "[";
        while (currprint != nullptr){ //printing the sorted part in the list
          ofs << currprint->data;
          if(currprint->next){
            ofs << ",";
            }
          currprint = currprint->next;
        }

      if (cur != nullptr){ //check if unsorted part of list has anything
        ofs << ",";
      }

        currprint = cur;
        while (currprint!=nullptr){ //this is printing the unsorted list
          ofs << currprint->data;
          if (currprint->next){
            ofs << ",";
            }
          currprint = currprint->next;
        }
      ofs << "]" << endl;
      }
      swapped = true;
    }
    head = sorted; // updates head to sorted list
}


void selectionSort(doublyLL& DLL, ofstream& ofs) {
    node* head = DLL.getHead();
    node* curr = head;
    while (curr != nullptr) {
        node* minNode = curr;
        node* temp = curr->next;
        while (temp != nullptr) {
            if (temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != curr) {
            // swaps the nodes
            if (curr->next == minNode) {
                // nodes here are adjacent
                if (curr->prev != nullptr) {
                    curr->prev->next = minNode;
                }
                if (minNode->next != nullptr) {
                    minNode->next->prev = curr;
                }
                curr->next = minNode->next;
                minNode->prev = curr->prev;
                curr->prev = minNode;
                minNode->next = curr;
                if (head == curr) {
                    head = minNode;
                    DLL.setHead(head);
                }
                curr = minNode;
            } else {
                // nodes here are not adjacent
                if (curr->prev != nullptr) {
                    curr->prev->next = minNode;
                }
                if (curr->next != nullptr) {
                    curr->next->prev = minNode;
                }
                if (minNode->prev != nullptr) {
                    minNode->prev->next = curr;
                }
                if (minNode->next != nullptr) {
                    minNode->next->prev = curr;
                }
                node* tempNext = curr->next;
                node* tempPrev = curr->prev;
                curr->next = minNode->next;
                curr->prev = minNode->prev;
                minNode->next = tempNext;
                minNode->prev = tempPrev;
                if (head == curr) {
                    head = minNode;
                    DLL.setHead(head);
                }
                curr = minNode;
            }
        }
        curr = curr->next;
        if(curr != nullptr){
        DLL.display(ofs);
        }
    }
}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream ifs(am.get("input"));
    ofstream ofs(am.get("output"));

    doublyLL DLL;
    string line = " ";
    int num;

    // reads the first line in input, should be numbers
    getline(ifs, line);
    if (isdigit(line[0])) {
        stringstream ss(line);
        while (ss >> num) {
            DLL.append(num);
        }
    }

    //reads the second line, should be the sorting type(no bubble sort)
    getline(ifs, line);
    if (line == "Insertion") {
        insertionSort(DLL, ofs);
    } else if (line == "Selection") {
        selectionSort(DLL, ofs);
    } else {
        ofs << "Input is invalid." << endl;
    }

    ifs.close();
    ofs.close();
    return 0;
}