#include<iostream>
using namespace std;

struct node{
    node *next;
    int xcoeff;
    int ycoeff;
    int zcoeff;
};

struct node *head;

void inputPoly(){
    node *newNode = new node;

    cout << "Enter the Coefficients of x, y & z" << endl;
    cin >> newNode->xcoeff >> newNode->ycoeff >> newNode->zcoeff;
    newNode->next = NULL;

    
    if (head == NULL){
        head = newNode;
        
    }
    
    else{
        head->next = newNode;
        newNode->next = head;
        
    }
}

void add(){
    node *poly1 = head;
    node *poly2 = head->next;

    cout<<"\nSum of the two polynomials is:"<<endl;
    cout<< (poly1->xcoeff + poly2->xcoeff) << "x " << "+ " << (poly1->ycoeff + poly2->ycoeff) <<"y " << "+ " << (poly1->zcoeff + poly2->zcoeff) << "z" << endl;
}

int main(){
    cout<<"For the first polynomial ";
    inputPoly();
    cout<<"For the second polynomial ";
    inputPoly();
    cout<<"\nDisplaying coefficients of x, y, z of polynomials:"<<endl;
    add();
    return 0;
}
