#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(stack<int> st){
    stack<int> temp1 = st;
    stack<int> temp2;

    for(int i = 0; i < temp1.size()/2; i++){
        temp2.push(temp1.top());
        temp1.pop();
    }
    if(st.size()%2 != 0){
        temp1.pop();
    }

    for(int i = 0; i < temp1.size(); i++){
        int x = temp1.top();
        temp1.pop();
        int y = temp2.top();
        temp2.pop();
        if(x != y){
            return false;
        }
    }
    return true;
}


int main(){
    stack<int> st;
    st.push(23);
    st.push(5);
    st.push(4);
    st.push(5);
    st.push(23);

    if(isPalindrome(st)){
        cout << "Stack is palindrome" << endl;
    }
    else{
        cout << "Stack is not palindrome" << endl;
    }

    return 0;
}