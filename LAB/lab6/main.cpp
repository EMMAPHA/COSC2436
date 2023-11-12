#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "thetree.h"
#include "ArgumentManager.h"
using namespace std;

string noWhitespace(const string& str) {
    size_t endpos = str.find_last_not_of(" \t");
    if (string::npos != endpos) {
        return str.substr(0, endpos + 1);
    }
    return str; 
}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream ifs(am.get("input"));
    ofstream ofs(am.get("output"));

    BST tree;
    string line = "";

while(getline(ifs, line)){
    line.erase(remove(line.begin(), line.end(), '\n'),line.end());
    line.erase(remove(line.begin(), line.end(), '\r'),line.end());

    string nums = "";

    if(line.find("Insert") != -1){
        getline(ifs, nums);
        nums.erase(remove(nums.begin(), nums.end(), '\n'),nums.end());
        nums.erase(remove(nums.begin(), nums.end(), '\r'),nums.end());

        istringstream ss(nums);
        int value;

        while(ss >> value){
            tree.setNewRoot(tree.insertToBST(tree.getRoot(), value));
        }
    }
else if(line.find("Remove") != -1){
    getline(ifs, nums);
     nums.erase(remove(nums.begin(), nums.end(), '\n'),nums.end());
     nums.erase(remove(nums.begin(), nums.end(), '\r'),nums.end());
    //int value = stoi(nums);
      istringstream ss(nums);
      int value;
      while(ss >> value){
      if(tree.isOneNodeInBST()){
        tree.deleteTheRoot();
      }
      else{
        tree.setNewRoot(tree.deleteNode(tree.getRoot(), value));
      }
}

}
//  if(tree.isEmpty()){
//     ofs << "False" << endl;
// } 

    if(line.find("Traverse") != -1){

        if(tree.isEmpty()){
          ofs << "False" << endl;
        }
        else if(!tree.isEmpty()){
        getline(ifs, nums);
        nums.erase(remove(nums.begin(), nums.end(), '\n'),nums.end());
        nums.erase(remove(nums.begin(), nums.end(), '\r'),nums.end());

        string verifyIt = noWhitespace(nums);

        string InOrder = tree.inOrder(tree.getRoot());

        InOrder = noWhitespace(InOrder);

        string PreOrder= tree.preOrder(tree.getRoot());
  
        PreOrder = noWhitespace(PreOrder);


        string PostOrder = tree.postOrder(tree.getRoot());
  
        PostOrder = noWhitespace(PostOrder);

        if(verifyIt == InOrder){
            ofs << "Inorder" << endl;
        }
        if(verifyIt == PreOrder){
            ofs << "Preorder" << endl;
        }
        if(verifyIt == PostOrder){
            ofs << "Postorder" << endl;
        }

        if(verifyIt != InOrder && verifyIt != PreOrder &&  verifyIt != PostOrder){
            ofs << "False" << endl;
        }
    
    }
}
}
    ifs.close();
    ofs.close();
    return 0;
}  