#include "ArgumentManager.h"
#include <algorithm> //added
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string findGreatestPermutation(string firstPerm) {
  if (firstPerm.length() <= 1) {
    return firstPerm;
  }
  int max = firstPerm[0] - '0';
  string newString = "";
  int index = 0;
  for (int i = 1; i < firstPerm.length(); i++) {
    int num = int(firstPerm[i] - '0');

    if (max < num) {
      index = i;
      max = num;
    }
  }
  newString = firstPerm.substr(0, index) + firstPerm.substr(index + 1, firstPerm.length());
  return to_string(max) + findGreatestPermutation(newString);
}

int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);

  string input = am.get("input");
  string output = am.get("output");

  ofstream ofs(output);
  ifstream ifs(input);

  // ifstream ifs("input1.txt");
  // ofstream ofs("output1.txt");

  string inputString;
  string sentence = "";
  string firstPerm = "";

  while (ifs >> sentence) {
    firstPerm += sentence;
  }
  // ofs << "Hi: " << firstPerm;
  ofs << findGreatestPermutation(firstPerm);

  ifs.close(); // MAKE SURE TO CLOSE FILES
  ofs.close();
  return 0;
}
