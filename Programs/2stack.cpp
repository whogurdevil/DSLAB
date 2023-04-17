#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
    int* arr = NULL;
    int top;
    int max;

    public:
    Stack(){
        this->top = -1;
        this->max = 0;
    }
    Stack(int size){
        this->top = -1;
        this->max = size;
        this->arr = new int[max];
    }
    Stack(const Stack &s){
        this->top = s.top;
        this->max = s.max;
        this->arr = new int[max];
        for(int i = 0; i <= top; i++){
            arr[i] = s.arr[i];
        }
    }


    void create(){
        cout << "Enter max size of the stack: ";
        cin >> max;
        arr = new int[max];
        cout << "Array created successfully" << endl;
    }

    bool push(int temp){
        if (arr == NULL) {
            cout << "Stack not created... Create stack first" << endl;
            return false;
        }

        if(top >= max-1){
            cout << "Stack overflowed... Can't add more elements" << endl;
            return false;
        }
        top++;
        arr[top] = temp;
        return true;
    }
    int pop(){
        if(top == -1){
            cout << "Stack underflowed" << endl;
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }

    void printStatus(){
        if(top == -1){
            cout << "Stack is empty... Add some elements first" << endl;
            return;
        }
        cout << "Maximum size of the Stack: " << max << endl;
        cout << "Filled size: " << top+1 << endl;
        cout << "Available size: " << max-(top+1) << endl;
        this->print();

    }
    void print(){
        int cnt = 0;
        cout << "Elements from top to bottom : " << endl;
        while(top > -1){
            int x = this->pop();
            cout << x << endl;
            cnt++;
        }
        cout << endl;
        top += cnt;
    }

    bool notEmpty(){
        if(top == -1){
            return false;
        }
        return true;
    }

    int getLength(){
        return (this->top+1);
    }
    void isPalindrome(){
        if(top == -1 || top == 0){
            cout << "Stack is palindrome" << endl;
            return;
        }
        this->print();

        //copy st constructor to temp
        Stack temp1 = *(this);
        Stack temp2(temp1.getLength());
        for(int i = 0; i <= temp1.getLength()/2; i++){
            temp2.push(temp1.pop());

        }
        // ignore the middle element if odd length
        if(temp1.getLength() % 2 != 0){
            temp2.pop();
        }
        
        //palindrome checking
        while(temp1.notEmpty() || temp2.notEmpty()){
            int x = temp1.pop(); 
            int y = temp2.pop();
            if(x != y){
                cout << "Stack is not in palindrome form" << endl;
                return;
            }
        }
        
        cout << "Stack is in palindrome form" << endl;
    }
};




int main(){

    system("cls");
    
    Stack st;
    int option = -1;
    while(true){
        cout << "1. Create Stack\n";
        cout << "2. Push an element\n";
        cout << "3. Pop the last element\n";
        cout << "4. Show status\n";
        cout << "5. Check weather the entered elements form a palindrome or not\n";
        cout << "6. Exit\n";
        cout << "Select an option to operate.... ";


        cin >> option;

        switch(option){
            case 1:
            system("cls");
            st.create();
            system("pause");
            system("cls");

            break;


            case 2:
            system("cls");
            cout << "Enter element to push in the stack: ";
            int temp;
            cin >> temp;
            if(st.push(temp)){
                cout << temp << " pushed successfully" << endl;
            }
            else{
                cout << temp << " not pushed!!!" << endl;
            }
            system("pause");
            system("cls");

            break;

            case 3:
            system("cls");
            st.pop();
            cout << "Last Element pop out successfully" << endl;
            system("pause");
            system("cls");

            break;


            case 4:
            system("cls");
            st.printStatus();
            system("pause");
            system("cls");

            break;


            case 5:
            system("cls");
            st.isPalindrome();
            system("pause");
            system("cls");

            break;

            case 6:
            cout << "Exiting program...." << endl;
            return 0;


            default:
            cout << "!!! Not a valid option !!!" ;
            system("pause");
            system("cls");

        }
    }
    return 0;
}
