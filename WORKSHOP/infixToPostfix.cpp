#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

//returns priority of operator
int checkOperatorPriority(char op)
{
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string str)
{
    stack<char> s;
    string postfix = "";

    //iterate through string
    for(int i = 0; i < str.length(); i++)
    {
        //if character is an operand, add to postfix string
        if(isdigit(str[i]))
            postfix += str[i];

        //push opening parenthesis to stack
        else if(str[i] == '(')
            s.push(str[i]);

        //when you find a closing parenthesis, pop all operators from stack
        //until you reach the opening parenthesis
        else if(str[i] == ')')
        {
            while(s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            //discard opening parenthesis
            s.pop();
        }

        //if you find any other operator
        else
        {
            while(!s.empty() && checkOperatorPriority(str[i]) <= checkOperatorPriority(s.top()))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(str[i]);
        }
    }

    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}


int evaluatePostfix(string str)
{
    stack<char> s;

    //iterate through string
    for(int i = 0; i < str.length(); i++)
    {
        //if character is an operand, add to postfix string
        if(isdigit(str[i]))
            //convert char to int and push to stack
            s.push(str[i] - '0');

        //if character is an operator, pop two operands from stack
        //apply operator to operands and push result back to stack
        else
        {
            int firstDigit = s.top();
            s.pop();

            int secondDigit = s.top();
            s.pop();

            switch(str[i])
            {
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

    return s.top();
}

int main(){
    string infixExpression = "1+2*(6-3)";

    cout << "Infix expression: " << infixExpression << endl;

    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Postfix expression: " << postfixExpression << endl;

    cout << "Result: " << evaluatePostfix(postfixExpression) << endl;
}