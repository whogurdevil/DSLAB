#include <iostream>
using namespace std;

const int MAX = 100; // Maximum size of stack

class Stack {
    private:
        int top; // Index of top element
        int arr[MAX]; // Array implementation of stack

    public:
        Stack() {
            top = -1; // Initialize top to -1
        }

        void push(int val) {
            if (top == MAX - 1) {
                cout << "Stack Overflow!" << endl;
                return;
            }
            top++;
            arr[top] = val;
            cout << val << " pushed onto the stack." << endl;
        }

        void pop() {
            if (top == -1) {
                cout << "Stack Underflow!" << endl;
                return;
            }
            int val = arr[top];
            top--;
            cout << val << " popped from the stack." << endl;
        }

        bool isPalindrome() {
            int i = 0, j = top;
            while (i < j) {
                if (arr[i] != arr[j]) {
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }

        void displayStatus() {
            if (top == -1) {
                cout << "Stack is empty." << endl;
                return;
            }
            cout << "Stack status: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "STACK OPERATIONS MENU:" << endl;
        cout << "1. Push an element" << endl;
        cout << "2. Pop an element" << endl;
        cout << "3. Check palindrome" << endl;
        cout << "4. Display stack status" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> val;
                s.push(val);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                if (s.isPalindrome()) {
                    cout << "The stack is a palindrome." << endl;
                } else {
                    cout << "The stack is not a palindrome." << endl;
                }
                break;

            case 4:
                s.displayStatus();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}