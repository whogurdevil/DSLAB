//program to convert infix to prefix

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%') {
        return true;
    }
    return false;
}

int getPrecedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/' || c == '%') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return -1;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c;
        }
        else if (isOperator(c)) {
            while (!s.empty() && s.top() != '(' && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {

    cout << "Enter infix expression: ";
    string infix;
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
