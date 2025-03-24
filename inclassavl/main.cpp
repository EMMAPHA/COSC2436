//
//  main.cpp
//  inclassavl
//
//  Created by Bao Tu on 11/9/23.
//

#include <iostream>

#include "avl_tree.h"
using namespace std;

int main(int argc, const char * argv[]) {
    avl_tree t;
    
    t.insert(t.root, 1);
    t.insert(t.root, 3);
    //t.insert(t.root, 2);
    t.insert(t.root, 4);
    
    t.inorder(t.root);
    cout << endl;
    t.preorder(t.root);
    cout << endl;
    t.postorder(t.root);
    cout << endl;
    
    return 0;
}
