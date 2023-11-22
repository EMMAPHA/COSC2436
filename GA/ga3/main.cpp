#include <iostream>
#include <fstream>

#include "ArgumentManager.h"

using namespace std;


/*
The input file will contain a single line of numbers separated by spaces.
● The input file will never be empty
● There will always be at least 1 number in the input file
● There will never be more than 100 numbers in the input file
● You should insert the numbers into the BST starting from the first number in the input file. For
example, if the input file contains: 4 2 5 1 you should input 4 into the BST first, then 2, then 5,
and then lastly 1
  */


struct node
{
  int val;
  node* left;
  node* right;
};

class bst
{
private:
  node* root;

public:
  bst() {root = nullptr;}

  bool empty() {return root == nullptr;}
  node* getRoot() {return root;}

  //i'm gonna do everything with recursion because i'm feeling violent
  void insert(node* curr, int val)
  {
    if(root == nullptr)
    {
      node* temp = new node;
      temp->val = val;
      temp->left = nullptr;
      temp->right = nullptr;

      root = temp;
    }
    else if(curr == nullptr)
      return;
    //insert at right
    else if(val > curr->val)
    {
      if(curr->right == nullptr)
      {
        node* temp = new node;
        temp->val = val;
        temp->left = nullptr;
        temp->right = nullptr;
        curr->right = temp;
        return;
      }
      insert(curr->right, val);
    }
    //insert at left
    else if(val < curr->val)
    {
      if(curr->left == nullptr)
      {
        node* temp = new node;
        temp->val = val;
        temp->left = nullptr;
        temp->right = nullptr;
        curr->left = temp;
        return;
      }
      insert(curr->left, val);
    }
    //what if equal? I'm assuming if equal (dupe), do not insert
  }

  void preorder(node* curr, ofstream& ofs, string pos = "x" )
  {
    if(curr == nullptr)
      return;

    ofs << "[" << pos << "] " << curr->val << endl;
    preorder(curr->left, ofs, pos + "l");
    preorder(curr->right, ofs, pos + "r");
  }

};

int main(int argc, char* argv[])
{
  ArgumentManager am(argc, argv);

  const string input = am.get("input");
  const string output = am.get("output");

  ifstream ifs(input);
  ofstream ofs(output);

  int val;
  bst tree;
  
  while(ifs >> val)
  {
    tree.insert(tree.getRoot(), val);
  }

  tree.preorder(tree.getRoot(), ofs);

  ifs.close();
  ofs.close();
  return 0;
}