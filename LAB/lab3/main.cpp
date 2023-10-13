#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <vector>
#include "MyStackLL.h" //MINE
#include "ArgumentManager.h"
using namespace std;

//SOURCE: SOME OF THESE FUNCTIONS ARE GIVEN BY THE WORKSHOP, THEN I IMPLEMENTED MY OWN
//EVALUATE PREFIX FUNCTION INCLUDING MY OWN STACK STRUCTURE

int checkOperatorPriority(char op) { //checks out
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string str) {//slightly modify
    MyStackLL<char> s;
    string postfix = "";

    // Iterate through the infix string

    for (int i = 0; i < str.length(); i++) {
        // If character is an operand, add to postfix string
        if (isdigit(str[i])){
             while (i < str.length() && isdigit(str[i])) {
            postfix += str[i];
            i++;
        }
            i--; 
            postfix += ' ';
        }
        //push opening parenthesis to stack
        else if (str[i] == '('){
            s.push(str[i]);
        }
        //when you find a closing parenthesis, pop all operators from stack
        //until you reach the opening parenthesis    
        else if (str[i] == ')') {

            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.peek();
                s.pop();
                //cout << "pop" << endl;
                //s.printTail();
                postfix += ' ';
            }

            if (!s.isEmpty() && s.peek() == '(')
                s.pop(); 
                //s.printTail();
            }  
            else if(str[i]==' '){
                continue;
            }
            //if you find any other operator
            else {
                while (str[i] != ' ' && !s.isEmpty() && s.peek() != '(' && checkOperatorPriority(str[i]) <= checkOperatorPriority(s.peek())) {
                    postfix += s.peek();
                    postfix += ' ';
                    s.pop();
                    //cout << "pop" << endl;
                    //s.printTail();
                }
                s.push(str[i]);
                //cout << "push" << endl;
                //s.printTail();
            }
        }

    while (!s.isEmpty()) { //checks out
        postfix += s.peek();
        postfix += ' ';
        s.pop();
        //cout << "pop" << endl;
    }
  //cout << postfix << endl; 
    return postfix;
} 

double evaluatePostfix(string str) {
  MyStackLL<double> s;
    // Iterate through the postfix string
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])){
            //s.push(str[i] - '0');
            string num;
        while(i < str.length() && (isdigit(str[i]) || str[i] == '.')){
            num+=str[i];
            i++;
    }
    i--;
    s.push(stod(num));
    }
        else if(str[i] != ' '){

            double firstDigit = s.peek();
            s.pop();
            double secondDigit = s.peek();
            s.pop();
            switch (str[i]) {
                case '+':
                    s.push(secondDigit + firstDigit);
                    break;
                case '-':
                    s.push(secondDigit - firstDigit);
                    break;
                case '*':
                    s.push(secondDigit * firstDigit);
                    break;
                case '/':
                    s.push(secondDigit / firstDigit);
                    break;
                case '^':
                    s.push(pow(secondDigit, firstDigit));
                    break;
            }
        }
    }

    return s.peek();
} 



/* double evaluatePrefix(string str) {
    MyStackLL<double> s;

    reverse(str.begin(), str.end());

    stringstream ss(str);
    string single_element;

    while(ss >> single_element){
        if(isdigit(single_element[0])){
            s.push(stod(single_element));
        }
        else {

            double firstDigit = s.peek();
            s.pop();
            double secondDigit = s.peek();
            s.pop();
            switch (single_element[0]) {
                case '+':
                    s.push(firstDigit + secondDigit);
                    break;
                case '-':
                    s.push(firstDigit - secondDigit);
                    break;
                case '*':
                    s.push(firstDigit * secondDigit);
                    break;
                case '/':
                    s.push(firstDigit / secondDigit);
                    break;
                case '^':
                    s.push(pow(firstDigit, secondDigit));
                    break;
            }
        }
    }

    return s.peek();
} */
double evaluatePrefix(string str) {
    MyStackLL<double> s;

    // Split the input string into tokens
    stringstream ss(str);
    vector<string> tokens;
    string token;

    while (ss >> token) {
        tokens.push_back(token);
    }

    // Reverse the tokens
    reverse(tokens.begin(), tokens.end());

    for (const string& token : tokens) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            s.push(stod(token));
        } else {
            double firstDigit = s.peek();
            s.pop();
            double secondDigit = s.peek();
            s.pop();

            switch (token[0]) {
                case '+':
                    s.push(firstDigit + secondDigit);
                    break;
                case '-':
                    s.push(firstDigit - secondDigit);
                    break;
                case '*':
                    s.push(firstDigit * secondDigit);
                    break;
                case '/':
                    s.push(firstDigit / secondDigit);
                    break;
                case '^':
                    s.push(pow(firstDigit, secondDigit));
                    break;
            }
        }
    }

    return s.peek();
}

int main(int argc, char* argv[]) {
    ArgumentManager am(argc, argv);
    ifstream ifs(am.get("input"));
    ofstream ofs(am.get("output"));

    // ifstream ifs("input1.txt");
    // ofstream ofs("output1.txt");

    string expType,  exp;

    getline(ifs, expType); // Read the expression type
    getline(ifs, exp); // Read the expression to evaluate

    expType.erase(remove(exp.begin(), exp.end(), '\n'), exp.end());
    expType.erase(remove(exp.begin(), exp.end(), '\r'), exp.end());
    expType.erase(remove(expType.begin(), expType.end(), ' '), expType.end());


     exp.erase(remove(exp.begin(), exp.end(), '\n'), exp.end());
     exp.erase(remove(exp.begin(), exp.end(), '\r'), exp.end());

    if (expType.find("infix") != -1) {

        string postfixExpression = infixToPostfix(exp);
        double result = evaluatePostfix(postfixExpression);
    
        ofs << fixed << setprecision(2) << static_cast<double>(result) << endl;

    } else if (expType.find("postfix") != -1) {
        
        double result = evaluatePostfix(exp);
        ofs << fixed << setprecision(2) << static_cast<double>(result) << endl;

    } else if (expType.find("prefix") != -1){
        
      double result = evaluatePrefix(exp);
        ofs << fixed << setprecision(2) << static_cast<double>(result) << endl;
      
    }

    ifs.close();
    ofs.close();
    return 0;
}  