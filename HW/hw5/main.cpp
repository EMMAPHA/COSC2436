#include <iostream>
#include <fstream>
#include <string> //substr
#include <sstream>
#include <algorithm>
#include "AVLtree.h"
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream ifs(am.get("input"));
    ofstream ofs(am.get("output"));

    AVL tree;
    string line = "";

while(getline(ifs, line)){
    line.erase(remove(line.begin(), line.end(), '\n'),line.end());
    line.erase(remove(line.begin(), line.end(), '\r'),line.end());

    string command = line.substr(0, line.find('('));
    int value = stoi(line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1));

     if(command == "Insert"){
        tree.setRoot(tree.insert(tree.getRoot(),value));
    }
     else if(command == "Remove"){
        tree.setRoot(tree.deleteNode(tree.getRoot(),value));
    }
 }

    tree.printLevelOrder(ofs, tree.getRoot());

    ifs.close();
    ofs.close();
    return 0;
}