#include <bits/stdc++.h>

using namespace std;

int evaluateSuffix(string expression) {
    stack<int> operandStack;
    int operand1, operand2;
    for (int i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            operandStack.push(expression[i] - '0');
        } else {
            operand2 = operandStack.top();
            operandStack.pop();
            operand1 = operandStack.top();
            operandStack.pop();
            switch (expression[i]) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                case '%':
                    operandStack.push(operand1 % operand2);
                    break;
                case '^':
                    operandStack.push(pow(operand1, operand2));
                    break;
            }
        }
    }
    return operandStack.top();
}

int main() {
    cout << "Enter suffix expression: ";
    string expression;
    cin >> expression;
    int result = evaluateSuffix(expression);
    cout << "Result: " << result << endl;
    return 0;
}
