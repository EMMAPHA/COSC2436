#include "avl_tree.h"


/*
 struct node
 {
     node *left;
     int v;
     int h;
     node *right;
 };
*/

avl_tree::avl_tree()
{
    root = nullptr;
}
bool avl_tree::isempty()
{
    return root = nullptr;
}
void avl_tree::inorder(node* curr)
{
    if(curr == nullptr)
        return;
    inorder(curr->left);
    cout << curr->v << " ";
    inorder(curr->right);
}
void avl_tree::preorder(node* curr)
{
    if(curr == nullptr)
        return;
    cout << curr->v << " ";
    preorder(curr->left);
    preorder(curr->right);
}
void avl_tree::postorder(node* curr)
{
    if(curr == nullptr)
        return;
    postorder(curr->left);
    postorder(curr->right);
    cout << curr->v << " ";
}
int avl_tree::height(node* curr)
{
    if(curr == nullptr)
        return -1;
    //leaves have height 0
    else if(curr->right == nullptr && curr->left == nullptr)
    {
        curr->h = 0;
        return 0;
    }
    int left = height(curr->left);
    int right = height(curr->right);
    if(left > right)
    {
        curr->h = 1 + left;
        return 1 + left;
    }
    curr->h = 1 + right;
    return 1 + right;
}
int avl_tree::bf(node* curr)
{
    if(curr == nullptr)
        return 0;
    return height(curr->left) - height(curr->right);
}
node* avl_tree::ll_rotation(node* oldcurr)
{
    node* newcurr = oldcurr->right;
    cout << "hi" << endl;
    //save ncleft
    node* ncleft = newcurr->left;
    //unlink ncleft to old curr
    newcurr->left = oldcurr;
    oldcurr->right = ncleft;
    
    if(oldcurr == root)
        root = newcurr;
    return newcurr;
}
void avl_tree::insert(node* curr, int key)
{
    /*
          -insert similar to BST
          - self balancing ....Balance
    If BF(node) = +2 and BF(node -> left-child) = +1, perform LL rotation. (ll_rotation)
    If BF(node) = -2 and BF(node -> right-child) = 1, perform RR rotation.  (rr_rotation)
    If BF(node) = -2 and BF(node -> right-child) = +1, perform RL rotation. (rl_rotation)
    If BF(node) = +2 and BF(node -> left-child) = -1, perform LR rotation.  (lr_rottaion)
    */
    
    node* temp = new node;
    temp->v = key;
    temp->h = 0;
    temp->left = nullptr;
    temp->right = nullptr;
    
    if(root == nullptr)
    {
        temp->h = 0;
        root = temp;
        return;
    }
    else if(temp->v < curr->v)
    {
        if(curr->left == nullptr)
        {
            curr->left = temp;
            return;
        }
        insert(curr->left, key);
    }
    else
    {
        if(curr->right == nullptr)
        {
            curr->right = temp;
            return;
        }
        insert(curr->right, key);
    }
    
    //if(bf(curr) >= 2 && bf(curr->right) <= -1)
        //curr = ll_rotation(curr);
    if(bf(root) <= -2 && bf(root->right) <= -1)
        root = ll_rotation(root);
    //else if(bf(curr) >= 2 && bf(curr->right) <= -1)
        //curr = ll_rotation(curr);
    //else if(bf(curr) >= 2 && bf(curr->right) <= -1)
        //curr = ll_rotation(curr);
}
