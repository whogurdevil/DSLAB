#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<conio.h>

using namespace std;

class StackOperations{
    int size = 0;
    int *str;
    int top = -1;

  public:
    StackOperations();
    void initial();
    void choice(int);
    void createStack();
    void pushElement();
    void popElement();
    void displayStatus();
    void checkPallindorme();
    void pressButton();
};

StackOperations :: StackOperations(){
    initial();
}

void StackOperations :: initial(){
    int option;
    bool condition = true;
    while(condition){
        system("cls");
        cout<<"                                      ****STACK OPERATIONS****"<<endl;
        cout << "1. Create a Stack of characters." << endl
        << "2. Push an element into the stack." << endl
        << "3. Pop an element from the stack." << endl
        << "4. Display the status of the stack."<< endl
        << "5. Check Pallindrome."<<endl
        << "6. Exit" << endl
        << "Choose from the given options: ";
        option = int(getch()-48);
        if(option==6){
            cout << endl << "Thanks for using me";
            condition = false;
        }
        else    
            choice(option);
    }
}

void StackOperations :: choice(int option){
    switch(option){
        case 1:
            createStack();
            break;
        case 2:
            pushElement();
            break;
        case 3:
            popElement();
            break;
        case 4:
            displayStatus();
            break;
        case 5:
            checkPallindorme();
            break;
        default:
            cout << "Choose a Valid option.";
            pressButton();
    }
}

void StackOperations :: createStack(){
    system("cls");
    cout << "*******Create a Stack*********" << endl << endl; 
    cout<<"Enter the size of the stack: ";
    cin>> size;
    str = new int[size];
    cout << "Stack has been created." << endl ;
    pressButton();
}

void StackOperations :: pushElement(){
    system("cls");
    cout << "*********Push Element********" << endl
    <<"Enter only one element at a time."<< endl;
    if(size==0){
        cout << "*****INVALID*****" <<endl<< "Create a stack first"
        <<endl; 
        pressButton();
    }
    else{
        if(top == size - 1){
            cout<<"Stack Overflow. Can't push element.";
            pressButton();
        }
        else{
            int element;
            cout << "Enter an element: "; 
            cin >> element;
            top++;
            str[top] = element;
            cout << "Element has been pushed." << endl; 
            pressButton();
        }
    }
}

void StackOperations :: popElement(){
    system("cls");
    cout << "*********Pop Element********" << endl;
    if(top == -1){
        cout << "*****INVALID******" << endl
        << "Can't pop element" << endl
        << "ErrorType: StackUnderFlow" << endl;
        pressButton();
    }
    else{
        top--;
        size--;
        cout << "Element has been popped." << endl;
        pressButton();
    }
}

void StackOperations :: displayStatus(){
    
    system("cls");
    cout << "*********Display Status********" << endl;
    if(top == -1){
        cout<<"Stack is empty\n"<<endl;
        pressButton();
    }
    else{
        cout<<"The stack has "<<top+1<<" elements."
        <<endl<<"Element at top of stack is '"<<str[top] << "'"<<endl;
        cout<<"'"<<size-top-1<<"' more elements can be inserted."<< endl;
        pressButton();
    }
}

void StackOperations ::checkPallindorme(){
    system("cls");
    if (size == 0) {
        cout << "Stack is empty" << endl;
        pressButton();
        return;
    }

    stack<int> s;
    int mid = size/2;
    for(int i = 0; i<mid; i++){
        s.push(str[i]);
    }

    if(size%2 != 0){
        mid++;
    }
    bool isPalindrome = true;
    for(int i = mid; i<size; i++){
        int c = s.top();
        s.pop();
        
        if(c != str[i]){
            isPalindrome = false;
            break;
        }
        
    }

    if (isPalindrome) {
        cout << "The stack forms a palindrome" << endl;
    }
    else {
        cout << "The stack does not form a palindrome" << endl;
    }

    pressButton();
}




void StackOperations :: pressButton(){
    cout<<"Press any key to continue...";
    getch();
}

int main(){
    StackOperations ob;
    return 0;
}