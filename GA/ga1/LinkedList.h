#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node{
  string id;
  node* next;
};

class LinkedList{
    private:
      node* head = nullptr;
      string listName = "";

    public:
      LinkedList(string n = ""){
        head = nullptr;
        listName = n;
      }

    node* returnHead(){
      return head;
    }

    bool search(string pending) //if found, return true. else, false.
    {
      node* curr = head;
      while(curr != nullptr)
      {
        if(curr->id == pending)
        {
          return true;
        }
        curr = curr->next;
      }
      return false;
    };

    bool isDuplicate(string pending) //if duplicate, delete it and return true. else, false.
    {
      if(head == nullptr) //if list is empty
      {
        return false;
      }
      node* curr = head;
      //if guilty is head (i.e. the first node matches the pending string)
      if(head->id == pending)
      {
        head = head->next;
        delete curr;
        return true;
      }

      node* prev = nullptr;
      while(curr != nullptr)
      {
        if(curr->id == pending)
        {
          prev->next = curr->next;
          delete curr;
          return true;
        }
        prev = curr;  
        curr = curr->next;
      }
      
      return false;
    };

    string trim0s(string str)
    {
      int firstNon0 = 0;
      while(firstNon0 < str.length() && str.at(firstNon0) == '0')
      {
        firstNon0++;
      }
      if(firstNon0 < str.length())
        return str.substr(firstNon0);
      return "0";
    }

    void insert(string id)
    {
      node* temp = new node;
      temp->id = id;
      temp->next = nullptr;
      
      if(head == nullptr) //add to empty list
      {
        head = temp;
        return;
      }

      string trim = trim0s(id);
      
      if(trim.length() < trim0s(head->id).length() || trim < trim0s(head->id)) //try to add to head
        //if temp has less digits or is smaller
      {  //you can compare strings like this right //yea
        temp->next = head;
        head = temp;
        return;
      }
      node* prev = head;
      node* curr = head->next;
      while(curr != nullptr) //try to add temp in between head and curr
      {
        if(trim.length() < trim0s(curr->id).length() || trim < trim0s(curr->id))
        {
          prev->next = temp;
          temp->next = curr;
          return;
        }
        prev = curr;
        curr = curr->next;
      }
      //temp goes last
      prev->next = temp;
    };

    void print(ofstream& out){
      if(head==nullptr){ 
        return;
      }
      out << listName << ":" << endl; 
      node* current = head;
      while(current!=nullptr)
      {
        out << current->id << endl; 
        current=current->next;
      }
    }
    
};