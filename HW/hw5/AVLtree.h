#ifndef AVLtree_h
#define AVLtree_h

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
    int height;

    treeNode(int val) {
        data = val;
        left = right = nullptr;
        height = 0;
    }
};

class AVL{
    private:
        treeNode* root;

    public:
        AVL(){
            root = nullptr;
        }

        treeNode* getRoot(){
            return root;
        }

        void setRoot(treeNode* r){
            root = r;
        }

        treeNode* insert(treeNode* curr, int data){
            if(curr==nullptr){
                if(root==nullptr){
                    root = new treeNode(data);
                    return root;
                }
                else
                    return new treeNode(data);
            }
            else if(data < curr->data){
                curr->left = insert(curr->left,data);
            }
            else if(data > curr->data){
                curr->right = insert(curr->right,data);
            }
          else
            return curr;

        int balance = balanceFactor(curr);

        if(balance > 1 && data < curr->left->data)
            return singleRightRotation(curr);

        else if(balance < -1 && data > curr->right->data)
            return singleLeftRotation(curr);

        else if(balance > 1 && data > curr->left->data)
            return leftRightRotation(curr);

        else if(balance < -1 && data < curr->right->data)
            return rightLeftRotation(curr);   

           return curr;     
        } 

        treeNode* deleteNode(treeNode* curr, int nodeToRemove) {
            //if we reached the end of the tree, return nullptr
            if (curr == nullptr) {
                return nullptr;
            }

             //If the node to remove is less than the current node, go left
             else if (nodeToRemove < curr->data) {
                curr->left = deleteNode(curr->left, nodeToRemove);
             } 
    
            //If the node to remove is greater than the current node, go right
             else if (nodeToRemove > curr->data) {
                curr->right = deleteNode(curr->right, nodeToRemove);

            //We've found the node to remove
            } else {

                if (curr->left== nullptr) {
                     treeNode* temp = curr->right;
                    delete curr;
                    return temp;
                } else if (curr->right == nullptr) {
                    treeNode* temp = curr->left;
                    delete curr;
                    return temp;
                }
                //If the node has two children, replace the node with the smallest node in the right subtree (inorder successor)
                else {

                    //Find inorder successor
                    treeNode* temp = curr->right;
                     while(temp->left != nullptr)
                        temp = temp->left;

                    //Copy inorder successor's data to the current node
                     curr->data = temp->data;

                    //Delete the inorder successor
                    curr->right = deleteNode(curr->right, temp->data);

                }
            }

        curr->height = getHeight(curr);
        int balance = balanceFactor(curr);

        if(balance > 1 && balanceFactor(curr->left) >= 0)
            return singleRightRotation(curr);

        else if(balance < -1 && balanceFactor(curr->right) <= 0)
            return singleLeftRotation(curr);

        else if(balance > 1 &&  balanceFactor(curr->left) < 0){
            return leftRightRotation(curr);
        }

        else if(balance < -1 && balanceFactor(curr->right) > 0){
            return rightLeftRotation(curr);   
        }
        return curr;
     }

        treeNode* singleRightRotation(treeNode* curr){
            treeNode* temp = curr->left;
            curr->left = temp->right;
            temp->right = curr;

            curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
            temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
            return temp;
        }

        treeNode* singleLeftRotation(treeNode* curr){
            treeNode* temp = curr->right;
            curr->right = temp->left;
            temp->left = curr;

            curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
            temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
            return temp;
        }

        treeNode* leftRightRotation(treeNode* curr){
            curr->left= singleLeftRotation(curr->left);
            return singleRightRotation(curr);
        }

        treeNode* rightLeftRotation(treeNode* curr){
            curr->right = singleRightRotation(curr->right);
            return singleLeftRotation(curr);
        }

        int getHeight(treeNode* curr){
            if(curr==nullptr)
                return -1;

            return 1 + max(getHeight(curr->left), getHeight(curr->right));
        }

        int balanceFactor(treeNode* curr){
            if(curr==nullptr)
                return 0;

            return (getHeight(curr->left)-getHeight(curr->right));
        }

        void printLevelOrder(ofstream &output, treeNode *n){
            if(n == nullptr){
                cout << "AVL is empty" << endl;
                return;
           }
           queue<treeNode*> q;
           q.push(n);
           while(!q.empty()){
             int levelSize = q.size();
             for(int i = 0; i < levelSize; i++){
                   treeNode *cu = q.front();
                    q.pop();
                    output << cu->data << " ";
                if(cu->left != nullptr)        
                    q.push(cu->left);
                if(cu->right != nullptr)
                    q.push(cu->right);
                }
                 output << endl;
            }
        }
};
#endif