#include <iostream>

struct tNode {
    int val;
    tNode* left;
    tNode* right;

    // Constructor
    tNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

tNode* insertBST(tNode* root, int value) {
    if (root == nullptr) {
        return new tNode(value);
    }

    if (value < root->val) {
        root->left = insertBST(root->left, value);
    } else if (value > root->val) {
        root->right = insertBST(root->right, value);
    }

    return root;
}

bool isSubtree(tNode* rootA, tNode* rootB) {
    if (rootA == nullptr && rootB == nullptr) {
        return true;
    }
    if (rootA == nullptr || rootB == nullptr) {
        return false;
    }

    if (rootA->val == rootB->val && isSubtree(rootA->left, rootB->left) && isSubtree(rootA->right, rootB->right)) {
        return true;
    }

    return isSubtree(rootA->left, rootB) || isSubtree(rootA->right, rootB);
}

bool isNestedPortion(tNode* rootA, tNode* rootB) {
    if (rootB == nullptr) {
        return true;
    }
    if (rootA == nullptr) {
        return false;
    }

    if (isSubtree(rootA, rootB)) {
        return true;
    }

    return isNestedPortion(rootA->left, rootB) || isNestedPortion(rootA->right, rootB);
}

// function to delete nodes in a tree
void deleteTree(tNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main() {
    int values[] = {7, 5, 9, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);

    // Build Tree A
    tNode* rootA = nullptr;
    for (int i = 0; i < n; ++i) {
        rootA = insertBST(rootA, values[i]);
    }

    // Build Tree B
    tNode* rootB = new tNode(5);
    rootB->left = new tNode(4);
   //rootB->left = new tNode(2); //uncomment this to be false
    rootB->right = new tNode(6);

    bool result = isNestedPortion(rootA, rootB);

    if (result) {
        std::cout << "Tree B is a nested portion of Tree A.\n";
    } else {
        std::cout << "Tree B is not a nested portion of Tree A.\n";
    }

    //free memory to clear space
    deleteTree(rootA);
    deleteTree(rootB);

    return 0;
}
