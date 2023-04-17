//program for circular linked list menu driven program

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

void print(struct node* head){
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    if(head->next == head){
        cout << head->data << endl;
        return;
    }

    struct node* temp1 = head;
    struct node* temp2 = head->next;;

    cout << temp1->data << " ";
    while(temp2 != temp1){
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;
}

void insertAtTail(struct node* &head, struct node* nodeToAdd){
    
    if(head == NULL){
        head = nodeToAdd;
        head->next = head;
        return;
    }

    
    struct node* temp1 = head;
    struct node* temp2 = head;

    while(temp2->next != temp1){
        temp2 = temp2->next;
    }

    nodeToAdd->next = head;
    temp2->next = nodeToAdd;

}

void insertAtHead(struct node* &head, struct node* nodeToAdd){
    if(head == NULL){
        head = nodeToAdd;
        head->next = head;
        cout << "Node inserted at beginning successfully" << endl;
        return;
    }
    
    nodeToAdd->next = head;

    struct node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = nodeToAdd;
    head = nodeToAdd;
    cout << "Node inserted at beginning successfully" << endl;
}

void pop_front(struct node* &head){
    if(head == NULL){
        cout << "List is empty, nothing to remove" << endl;
        return;
    }
    if(head->next == head){
        head->next = NULL;
        delete(head);
        head = NULL;
        cout << "Node deleted from beginning successfully" << endl;

        return;
    }

    struct node* temp1 = head;
    struct node* temp2 = head;

    while(temp2->next != temp1){
        temp2 = temp2->next;
    }

    temp2->next = temp1->next;
    head = temp2->next;
    temp1->next = NULL;
    delete(temp1);
    cout << "Node deleted from beginning successfully" << endl;
}

void pop_back(struct node* &head){
    if(head == NULL) {
        cout << "List is empty, nothing to remove" << endl;
        return;
    }

    if(head->next == head) {
        head->next = NULL;
        delete(head);
        head = NULL;
        cout << "Node from end removed successfully" << endl;

        return;
    }

    node* temp1 = head;
    node* temp2 = head->next;
    while(temp2->next->next != temp1){
        temp2 = temp2->next;
    }
    node* del = temp2->next;
    temp2->next = temp1;
    del->next = NULL;
    delete(del);

    cout << "Node from end removed successfully" << endl;

}

int findEle(struct node* head, int ele) {
    if(head == NULL) {
        cout << "List is empty" << endl;
        return -1;
    }
    struct node* temp = head;
    int count = 1;
    if(temp->data == ele){
        return count++;
    }
    temp = temp->next;
    count++;
    while((temp->data != ele) || temp != head) {
        if(temp->data == ele) {
            return count;
        }
        temp = temp->next;
        count++;
    }

    return -1;
}

int main(){
    struct node* head = NULL;
    struct node* temp = NULL;
    int val;

    while(true) {
        system("cls");
        cout << "Operations for circular Linked List\n\n";
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Delete from beginning" << endl;
        cout << "4. Delete from end" << endl;
        cout << "5. Display elements in List" << endl;
        cout << "6. Find element in Linked List" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose options to operate...";
        int option;
        cin >> option;

        switch(option) {
            case 1:
            system("cls");
            cout << "Enter data for node to be added: ";
            cin >> val;
            temp = new node(val);
            insertAtHead(head, temp);
            print(head);
            system("pause");
            break;

            case 2:
            system("cls");
            cout << "Enter data for node to be added: ";
            cin >> val;
            temp = new node(val);
            insertAtTail(head, temp);
            print(head);
            system("pause");
            break;

            case 3:
            system("cls");
            pop_front(head);
            print(head);
            system("pause");
            break;

            case 4:
            system("cls");
            pop_back(head);
            print(head);
            system("pause");
            break;  

            case 5:
            system("cls");
            cout << "Printing list..." << endl;
            print(head);
            system("pause");
            break;

            case 6:
            system("cls");
            cout << "Enter value to search: ";
            cin >> val;
            if(findEle(head, val) != -1){
                cout << "Element found at " << findEle(head, val) << "th place" << endl;
            }
            system("pause");
            break;

            case 7:
            cout << "Exiting program" << endl;
            return 0;

            default:
            cout << "Invalid option, choose options from the above list" << endl;
        }
    }


    return 0;
}