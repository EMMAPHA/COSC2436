#ifndef thetree_h
#define thetree_h

#include <iostream>
using namespace std;
//most is from workshop
struct treeNode {
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int d) {
        data = d;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

class BST{
    private:
        treeNode* root;
    
    public:
        BST(){
            root = nullptr;
        }

        bool isEmpty(){
            return root == nullptr;
        }

        treeNode* getRoot(){
            return root;
        }

        void setNewRoot(treeNode* newRoot){
            root = newRoot;
        }


    treeNode* insertToBST(treeNode* curr, int data){
        if(curr==nullptr){
            if(root==nullptr){
                root = new treeNode(data);
                return root;
            }
            else if(data == root->data){
                return root;
            }

            else
                return new treeNode(data);
        }
        else if(data == curr->data){
            return curr;
        }
        else if(data < curr->data){
            curr->leftChild = insertToBST(curr->leftChild, data);
        }
        else if(data > curr->data){
            curr->rightChild = insertToBST(curr->rightChild, data);
        }
        return curr;
    }

bool isOneNodeInBST(){
    return root != nullptr && root->leftChild == nullptr && root->rightChild == nullptr;
}

void deleteTheRoot(){
    if(root != nullptr && root->leftChild == nullptr && root->rightChild == nullptr){
        delete root;
        root = nullptr;
    }
}

treeNode* inOrderSuccessor(treeNode* node) {
    treeNode* current = node->rightChild;
    while (current != nullptr && current->leftChild != nullptr) {
        current = current->leftChild;
    }
    return current;
}


treeNode* deleteNode(treeNode* root, int nodeToRemove) {
    //if we reached the end of the tree, return nullptr
    if (root == nullptr) {
        return nullptr;
    }

    //If the node to remove is less than the current node, go left
    else if (nodeToRemove < root->data) {
        root->leftChild = deleteNode(root->leftChild, nodeToRemove);
    } 
    
    //If the node to remove is greater than the current node, go right
    else if (nodeToRemove > root->data) {
        root->rightChild = deleteNode(root->rightChild, nodeToRemove);

    //We've found the node to remove
    } else {
        if (root->leftChild== nullptr) {
            treeNode* temp = root->rightChild;
            delete root;
            return temp;
        } else if (root->rightChild == nullptr) {
            treeNode* temp = root->leftChild;
            delete root;
            return temp;
        }
        
        //If the node has two children, replace the node with the smallest node in the right subtree (inorder successor)
        else {

            //Find inorder successor
            treeNode* succ = inOrderSuccessor(root);

            //Copy inorder successor's data to the current node
            root->data = succ->data;

            //Delete the inorder successor
            root->rightChild = deleteNode(root->rightChild, succ->data);
        }
    }

    return root;
}



string inOrder(treeNode* curr)
{
  if(curr == nullptr)
    return "";

  string leftStr = inOrder(curr->leftChild);
  string parentStr = to_string(curr->data) +" ";
  string rightStr = inOrder(curr->rightChild);

  return leftStr + parentStr + rightStr;
}

string preOrder(treeNode* curr)
{
  if(curr == nullptr)
    return "";

  string parentStr = to_string(curr->data) +" ";
  string leftStr = preOrder(curr->leftChild);
  string rightStr = preOrder(curr->rightChild);

  return parentStr + leftStr + rightStr;
}

string postOrder(treeNode* curr)
{
  if(curr == nullptr)
    return "";

  string leftStr = postOrder(curr->leftChild);
  string rightStr = postOrder(curr->rightChild);
  string parentStr = to_string(curr->data) +" ";

  return leftStr + rightStr + parentStr;
}
};

#endif