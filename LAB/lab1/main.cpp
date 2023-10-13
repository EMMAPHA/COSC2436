#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "ArgumentManager.h"
using namespace std;
//Applying recursion to check if a string is a palindrome or not | Reverse the array using recursion
//^ YouTube video title to assist me for lab1
// YouTube link: https://www.youtube.com/watch?v=ziJgsbfk5ko

bool isPalindrome(string phrase, int start, int end) {
    // base case: if the start index is greater than or equal to end index, it's a palindrome
    if (start >= end) { //From YT video mentioned above
        return true;
    }
     //ignores everything that isn't alphabet and digits, and space characters
    if (!isalpha(phrase[start]) && !isdigit(phrase[start])) { 
        return isPalindrome(phrase, start + 1, end);
    }
    if (!isalpha(phrase[end]) && !isdigit(phrase[end])) {
        return isPalindrome(phrase, start, end - 1);
    }

    //since it's NOT case-sensitive, I could do tolower() or toupper()
    if (tolower(phrase[start]) != tolower(phrase[end])) { //From YT video mentioned above
        return false;
    }
     //From YT video mentioned above
    return isPalindrome(phrase, start + 1, end - 1);// recursive case: check the substring without the first and last characters.
}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
  
     string input = am.get("input");
     string output = am.get("output");


    ofstream ofs(output);
    ifstream ifs(input);


    //ifstream ifs("input1.txt");
    //ofstream ofs("output1.txt");

    string inputString;
    string sentence;
    
    while(getline(ifs, inputString))
    {
      sentence += inputString;   
    }
  
    if (isPalindrome(sentence, 0, sentence.size() - 1)) { //From YT video mentioned above
        ofs << "true" << endl; //output
    } else {
        ofs << "false" << endl; //output
    }

    ifs.close(); //MAKE SURE TO CLOSE FILES
    ofs.close();
    return 0;

} 
