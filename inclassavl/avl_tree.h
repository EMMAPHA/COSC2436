

#ifndef avl_tree_h
#define avl_tree_h

#include <iostream>
using namespace std;


struct node
{
    node *left;
    int v;
    int h;
    node *right;
};

class avl_tree
{
public:
    node *root;
    avl_tree();
    bool isempty();
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    int height(node *);
    int bf(node *);
    node* ll_rotation(node *);

   
/*
      -insert similar to BST
      - seld balancing ....Balance
If BF(node) = +2 and BF(node -> left-child) = +1, perform LL rotation. (ll_rotation)
If BF(node) = -2 and BF(node -> right-child) = 1, perform RR rotation.  (rr_rotation)
If BF(node) = -2 and BF(node -> right-child) = +1, perform RL rotation. (rl_rotation)
If BF(node) = +2 and BF(node -> left-child) = -1, perform LR rotation.  (lr_rottaion)
*/
    void insert(node *, int);
};

#endif /* avl_tree_h */
