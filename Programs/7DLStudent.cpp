#include <bits/stdc++.h>
using namespace std;

struct node{
    int ssn, sal, phone;
    string name, dept, desig;
    node* next = NULL;
    node* prev = NULL;

    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
}

void insert(node* head, int val) {
    if(head == NULL) {
        cout << "Empty" << endl;
        return;
    }

    node* temp = new node(val);
    

    
}

int main(){
    

    return 0;
}