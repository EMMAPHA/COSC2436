#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct node
{
    string name;
    int age, deposit, numDrinks;
    node *next = nullptr;
    node(string n, int a, int d, int numD)
        : name(n), age(a), deposit(d), numDrinks(numD) {}
};

class LinkedList
{
private:
    node *head;
    int size;

public:
    // empty list
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

    node *getHead() { return head; }
    int getSize() { return size; }

    // ? Finds the NODE of the given index
node *searchData(int index)
        {
         node *temp = head;
             if (index < 0)
                return nullptr;
            else if (index > size - 1)
            index == size - 1;

        while (size-- > 0)
        temp = temp->next;
     return temp;
 }

void insertAtHead(node *newNode)
    {
        if (head == nullptr)
        {
            head = newNode, size++;
            return;
        } // add to head. think of a bookshelf and you shove the books to the right
        if (head->name == newNode->name &&
            head->age == newNode->age) // if both are the same
        {
            head->deposit = newNode->deposit;     // update deposit in current
            head->numDrinks = newNode->numDrinks; // update numDrinks in current
            return;                               // stop, no need to insert because you were only updating
        }
        node *current = head;
        while (current->next != nullptr)
        { // stop at last node //how many times will this
          // run?(Big O)
            if (current->next->name == newNode->name && current->next->age == newNode->age)
            {
                // current->deposit = newNode->deposit;     // update deposit in current
                // current->numDrinks = newNode->numDrinks; // update numDrinks in current
                node *temp = current->next;          // Store a temporary pointer to the node to be deleted
                current->next = current->next->next; // Update the next pointer of the current node
                delete temp;
                size--;
                break;
            }
            current = current->next;
        }

        newNode->next = head; // insert part
        head = newNode;

        size++;
    }

    void insertAtTail(node *newNode)
    {
        // do something
        node *current = head;
        while (current->next != nullptr)
            { // stop at last node //how many times will this
              // run?(Big O)
                if (current->name == newNode->name && current->age == newNode->age) //->next
                {
                     current->deposit = newNode->deposit;     // update deposit in current //
                     current->numDrinks = newNode->numDrinks; // update numDrinks in current //
/*                     node *temp = current->next;          // Store a temporary pointer to the node to be deleted
                    current->next = current->next->next; // Update the next pointer of the current node
                    delete temp;
                    size--;
                    break; */
                    return;
                }
                current = current->next;
            }
        current = head;
        while (current->next)
        { // stop at last node //how many times will this
          // run?(Big O)
            // if (current->name == newNode->name && current->age == newNode->age)
            // {
            //     current->deposit = newNode->deposit;     // update deposit in current
            //     current->numDrinks = newNode->numDrinks; // update numDrinks in current
            //     return;                                  // stop, no need to insert because you were only updating
            // }

            current = current->next;
        }

        // cout << "Adding data " << endl;
        current->next = newNode;
        size++;
    }  

    void insertAtPos(node *newNode, int pos)
    {
        if (size == 0 || pos <= 0)
        {
            insertAtHead(newNode);
            //cout << "case 1" << endl;
        }
        else if (pos >= size)
        {
            insertAtTail(newNode);
            //cout << "case 2" << endl;
        }
        else
        {
            node *current = head;
   while (current != nullptr)
            { // stop at last node //how many times will this
              // run?(Big O)
                if (current->name == newNode->name && current->age == newNode->age)
                {
                     current->deposit = newNode->deposit;     // update deposit in current
                    current->numDrinks = newNode->numDrinks; // update numDrinks in current
/*                   node *temp = current->next;          // Store a temporary pointer to the node to be deleted
                    current->next = current->next->next; // Update the next pointer of the current node
                    delete temp;
                    size--; 
                    break; */
                    return;
                }
                current = current->next;
            }
            current = head;
            // gets right before the position
            for (int i = 0; i < pos - 1; i++)
            { // if(pos>=0 && pos <= getSize()-1)
                if (current == nullptr)
                {
                    return; // added
                }
                if (current->name == newNode->name && current->age == newNode->age)
                {
                    current->deposit = newNode->deposit;     // update deposit in current
                    current->numDrinks = newNode->numDrinks; // update numDrinks in current
                    return;                                  // stop, no need to insert because you were only updating
                }

                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
            size++;
            //cout << "case 3" << endl;
        }
    } 

    // ? Remove Functions
    void removeAtHead()
    {
        // do something
        if (size > 0)
        {
            // data type   //pointer variable
            node *oldHead = head;
            head = head->next;
            delete oldHead;
            size--;
        }
    }

    void removeAtTail()
    {
        int index = size;
        node *temp = head;
        // ? Iterate through until one before last node
        while (index-- > 1)
            temp = temp->next;
        // ? Delete next
        delete temp->next;
        temp->next = nullptr, size--;
    }

    void removeBy(string attribute, int val, string name = "")
    {
        if (attribute.find("age") != string::npos)
            remove("age", val);
        else if (attribute.find("drinks") != string::npos)
            remove("drinks", val);
        else if (attribute.find("deposit") != string::npos)
            remove("deposit", val);
        else
            remove("name", name);
    }

    // ? Finds the INDEX of desired node
    // * Takes in attribute and value to find
    void remove(string attribute, int val = 0)
    {
        node *temp = head;
        if (attribute.find("age") != string::npos)
        {
            node *curr = head;
            node *prev = nullptr;

            while (curr != nullptr)
            {
                if (curr->age == val)
                {
                    if (prev != nullptr)
                    {
                        prev->next = curr->next; // Update the previous node's next pointer
                        delete curr;             // Delete the current node
                        curr = prev->next;       // Move curr to the next node
                        size--;
                    }
                    else
                    {
                        node *temp = curr;
                        curr = curr->next;
                        head = curr; // Update the head if the first node matches the value
                        delete temp;
                        size--;
                    }
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }

        else if (attribute.find("deposit") != string::npos)
        {
            node *curr = head;
            node *prev = nullptr;

            while (curr != nullptr)
            {
                if (curr->deposit == val)
                {
                    if (prev != nullptr)
                    {
                        prev->next = curr->next; // Update the previous node's next pointer
                        delete curr;             // Delete the current node
                        curr = prev->next;       // Move curr to the next node
                        size--;
                    }
                    else
                    {
                        node *temp = curr;
                        curr = curr->next;
                        head = curr; // Update the head if the first node matches the value
                        delete temp;
                        size--;
                    }
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
        else if (attribute.find("drinks") != string::npos)
        {
            node *curr = head;
            node *prev = nullptr;

            while (curr != nullptr)
            {
                if (curr->numDrinks == val)
                {
                    if (prev != nullptr)
                    {
                        prev->next = curr->next; // Update the previous node's next pointer
                        delete curr;             // Delete the current node
                        curr = prev->next;       // Move curr to the next node
                        size--;
                    }
                    else
                    {
                        node *temp = curr;
                        curr = curr->next;
                        head = curr; // Update the head if the first node matches the value
                        delete temp;
                        size--;
                    }
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    }

    void remove(string attribute, string name)
    {
        node *curr = head;
        node *prev = nullptr;

        while (curr != nullptr)
        {
            if (curr->name == name)
            {
                if (prev != nullptr)
                {
                    prev->next = curr->next; // Update the previous node's next pointer
                    delete curr;             // Delete the current node
                    curr = prev->next;       // Move curr to the next node
                    size--;
                }
                else
                {
                    node *temp = curr;
                    curr = curr->next;
                    head = curr; // Update the head if the first node matches the value
                    delete temp;
                    size--;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
    void swapNodeValues(node *a, node *b)
    {
        // Swap the values within the nodes
        swap(a->name, b->name);
        swap(a->age, b->age);
        swap(a->deposit, b->deposit);
        swap(a->numDrinks, b->numDrinks);
    }
    // ? Sort alphabetically for name
    void sortByAlpha()
    {
        if (head == nullptr || head->next == nullptr)
        {
            // Nothing to sort for an empty list or a list with one element.
            return;
        }

        bool swapped;
        node *current;
        node *prev = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != nullptr)
            {
                if (current->name > current->next->name)
                {
                    // Swap the values within the nodes
                    swapNodeValues(current, current->next);

                    swapped = true;
                }

                prev = current;
                current = current->next;
            }
        } while (swapped);
    }
    void sortByAge()
    {
        if (head == nullptr || head->next == nullptr)
        {
            // Nothing to sort for an empty list or a list with one element.
            return;
        }

        bool swapped;
        node *current;
        node *prev = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != nullptr)
            {
                if (current->age > current->next->age)
                {
                    // Swap the values within the nodes
                    swapNodeValues(current, current->next);

                    swapped = true;
                }

                prev = current;
                current = current->next;
            }
        } while (swapped);
    }
    // ? Sort ascending for deposit
    void sortByDeposit()
    {
        if (head == nullptr || head->next == nullptr)
        {
            // Nothing to sort for an empty list or a list with one element.
            return;
        }

        bool swapped;
        node *current;
        node *prev = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != nullptr)
            {
                if (current->deposit > current->next->deposit)
                {
                    // Swap the values within the nodes
                    swapNodeValues(current, current->next);

                    swapped = true;
                }

                prev = current;
                current = current->next;
            }
        } while (swapped);
    }

    void sortByDrinks()
    {
        if (head == nullptr || head->next == nullptr)
        {
            // Nothing to sort for an empty list or a list with one element.
            return;
        }

        bool swapped;
        node *current;
        node *prev = nullptr;

        do
        {
            swapped = false;
            current = head;

            while (current->next != nullptr)
            {
                if (current->numDrinks > current->next->numDrinks)
                {
                    // Swap the values within the nodes
                    swapNodeValues(current, current->next);

                    swapped = true;
                }

                prev = current;
                current = current->next;
            }
        } while (swapped);
    }
    void print() const
    {
        node *temp = head;
        while (temp)
        {
            if (!temp->next)
            {
                cout << "[name: " + temp->name + "; age: " + to_string(temp->age) +
                            "; deposit: " + to_string(temp->deposit) +
                            "; number of drinks: " + to_string(temp->numDrinks) + "]"
                     << std::endl;

                temp = temp->next;
            }
            else
            {
                cout << "[name: " + temp->name + "; age: " + to_string(temp->age) +
                            "; deposit: " + to_string(temp->deposit) +
                            "; number of drinks: " + to_string(temp->numDrinks) + "]"
                     << std::endl;
                temp = temp->next;
            }
        }
    }

    void print(ostream &out) const
    {
        node *temp = head;
        while (temp)
        {
            if (!temp->next)
            {
                out << "[name: " + temp->name + "; age: " + to_string(temp->age) +
                           "; deposit: " + to_string(temp->deposit) +
                           "; number of drinks: " + to_string(temp->numDrinks) + "]";
                temp = temp->next;
            }
            else
            {
                out << "[name: " + temp->name + "; age: " + to_string(temp->age) +
                           "; deposit: " + to_string(temp->deposit) +
                           "; number of drinks: " + to_string(temp->numDrinks) + "]"
                    << std::endl;
                temp = temp->next;
            }
        }
    }

    // More functions

    // node is storing the word(data and link/reference)
};

#endif