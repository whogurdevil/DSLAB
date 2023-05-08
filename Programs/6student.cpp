#include <bits/stdc++.h>
using namespace std;



class Node
{

    public:
    string username, name, branch;
    int sem, phone;
    Node* next;

    Node(){
        this->next = NULL;
        cout << "Enter username: ";
        cin >> this->username;
        cout << "Enter name: ";
        cin >> this->name;
        cout << "Enter branch: ";
        cin >> this->branch;mmm
        cout << "Enter sem(numeral): ";
        cin >> this->sem;
        cout << "Enter phone number: ";
        cin >> this->phone;
    }

    ~Node() {
        cout << "Node with username " << username << " deleted" << endl;
    }
};

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << "Username: " << temp->username << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Branch: " << temp->branch << endl;
        cout << "Semester: " << temp->sem << endl;
        cout << "Phone Number: " << temp->phone << endl;

        temp = temp->next;
        cout << endl;

    }
}

void insertAtHead(Node* &head){
    Node* temp = new Node();

    temp->next = head;
    head = temp;

}

void insertAtTail(Node* &tail){
    Node *temp = new Node();

    tail->next = temp;
    tail = temp;
}

void delFromHead(Node* &head){
    Node* temp = head;
    head = head -> next;

    //delete memory
    temp->next = NULL;  //condition to satisfy destructor 
    delete temp;
}

void delFromEnd(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }

    if(prev == NULL) { //only one element in the list
        head = NULL;
    } else {
        prev->next = NULL;
    }
    delete curr;
}

int main(){
    system("cls");
    Node* head = NULL;
    Node* tail = NULL;
    Node* s = NULL;

    while (true) {
        cout << "1. Create a SLL of N Students Data by using front insertion\n2. Display the status\n3. Insertion at end\n4. Deletion from end\n5. Insertion from front\n6. Deletion from front\n7. Exit" << endl;
        int option;
        cout << "Enter an option: ";
        cin >> option;
switch (option)
{
    case(1) : 
        system("cls");

        s = new Node();
        head = s;
        tail = s;
        cout << "Student created!" << endl;
        system("pause");
        system("cls");
        break;
    case(2) :
        // cout << "Total students: " << count << endl;
    
        system("cls");

        print(head);
        system("pause");
        system("cls");
        break;
    case(3):
        system("cls");

        insertAtTail(tail);
        cout << "Student added at the end!" << endl;
        system("pause");
        system("cls");
        break;
    case(4):
        system("cls");

        if (head == NULL) {
            cout << "The list is empty!" << endl;
            break;
        }
        else if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
        // count--;
        cout << "Last student deleted!" << endl;
        system("pause");
        system("cls");
        break;
    case(5):
        system("cls");

        insertAtHead(head);
        cout << "Student added at the beginning!" << endl;
        system("pause");
        system("cls");
        break;
    case(6):
        system("cls");

        if (head == NULL) {
            cout << "The list is empty!" << endl;
            break;
        }
        else if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        // count--;
        cout << "First student deleted!" << endl;
        system("pause");
        system("cls");
        break;
    case(7):
        cout << "Exiting program..." << endl;
        return 0;
    default:
        cout << "Invalid option!" << endl;
        break;
        }
    }
}
