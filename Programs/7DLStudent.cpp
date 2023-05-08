#include<iostream>
#include<cstring>
using namespace std;

//Employee class to store data
class Employee{
    public:
        string ssn;
        string name;
        string dept;
        string designation;
        float sal;
        string phno;
};

//DLL Node structure
class DLLNode{
    public:
        Employee empData;
        DLLNode *prev, *next;
};

//DLL class
class DLL{
    private:
        DLLNode *head, *tail;

    public:
    //constructor to initialize head and tail to NULL
    DLL(){
        head = NULL;
        tail = NULL;
    }

    //function to create a DLL of N Employees by end insertion
    void create(int n){
        for(int i=0; i<n; i++){
            DLLNode *newNode = new DLLNode();

            cout << "Enter employee " << i+1 << " data:\n";
            cout << "SSN: ";
            cin >> newNode->empData.ssn;
            cout << "Name: ";
            cin >> newNode->empData.name;
            cout << "Department: ";
            cin >> newNode->empData.dept;
            cout << "Designation: ";
            cin >> newNode->empData.designation;
            cout << "Salary: ";
            cin >> newNode->empData.sal;
            cout << "Phone number: ";
            cin >> newNode->empData.phno;

            newNode->prev = tail;
            newNode->next = NULL;

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    //function to display the status of DLL and count the number of nodes in it
    void display(){
        int count = 0;
        DLLNode *current = head;

        cout << "Doubly Linked List: ";
        while(current != NULL){
            count++;
            cout << "\nEmployee " << count << ":\n";
            cout << "SSN: " << current->empData.ssn << "\n";
            cout << "Name: " << current->empData.name << "\n";
            cout << "Department: " << current->empData.dept << "\n";
            cout << "Designation: " << current->empData.designation << "\n";
            cout << "Salary: " << current->empData.sal << "\n";
            cout << "Phone number: " << current->empData.phno << "\n";

            current = current->next;
        }
        cout << "Total number of nodes: " << count << "\n";
    }

    //function to perform insertion at end of DLL
    void insertEnd(){
        DLLNode *newNode = new DLLNode();

        cout << "Enter employee data to be inserted at end:\n";
        cout << "SSN: ";
        cin >> newNode->empData.ssn;
        cout << "Name: ";
        cin >> newNode->empData.name;
        cout << "Department: ";
        cin >> newNode->empData.dept;
        cout << "Designation: ";
        cin >> newNode->empData.designation;
        cout << "Salary: ";
        cin >> newNode->empData.sal;
        cout << "Phone number: ";
        cin >> newNode->empData.phno;

        newNode->prev = tail;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
    }}

    //function to perform deletion at end of DLL
    void deleteEnd(){
        if(head == NULL){
            cout << "DLL is empty!\n";
            return;
        }
        else if(head == tail){
            delete head;
            head = NULL;
            tail = NULL;
        }
        else{
            DLLNode *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        cout << "Node deleted from end of DLL.\n";
    }

    //function to perform insertion at front of DLL
    void insertFront(){
        DLLNode *newNode = new DLLNode();

        cout << "Enter employee data to be inserted at front:\n";
        cout << "SSN: ";
        cin >> newNode->empData.ssn;
        cout << "Name: ";
        cin >> newNode->empData.name;
        cout << "Department: ";
        cin >> newNode->empData.dept;
        cout << "Designation: ";
        cin >> newNode->empData.designation;
        cout << "Salary: ";
        cin >> newNode->empData.sal;
        cout << "Phone number: ";
        cin >> newNode->empData.phno;

        newNode->prev = NULL;
        newNode->next = head;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            head->prev = newNode;
            head = newNode;
        }
    }

    //function to perform deletion at front of DLL
    void deleteFront(){
        if(head == NULL){
            cout << "DLL is empty!\n";
            return;
        }
        else if(head == tail){
            delete head;
            head = NULL;
            tail = NULL;
        }
        else{
            DLLNode *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        cout << "Node deleted from front of DLL.\n";
    }

    //function to demonstrate how this DLL can be used as Double Ended Queue
    void doubleEndedQueue(){
        int choice;
        while(true){
            cout << "\nDouble Ended Queue Operations:\n";
            cout << "1. Insert at front\n";
            cout << "2. Insert at end\n";
            cout << "3. Delete from front\n";
            cout << "4. Delete from end\n";
            cout << "5. Display\n";
            cout << "6. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice){
                case 1: insertFront();
                        break;
                case 2: insertEnd();
                        break;
                case 3: deleteFront();
                        break;
                case 4: deleteEnd();
                        break;
                case 5: display();
                        break;
                case 6: return;
                default: cout << "Invalid choice!\n";
            }
        }
    }
};

//main function to test the DLL class
int main(){
    DLL employeeList;
    int n, choice;

    while(true){
        cout << "\nDoubly Linked List Operations:\n";
        cout << "1. Create a DLL\n";
        cout << "2. Display\n";
        cout << "3. Insert at end\n";
        cout << "4. Delete from end\n";
        cout << "5. Insert at front\n";
        cout << "6. Delete from front\n";
        cout << "7. Double Ended Queue operations\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: cout << "Enter number of employees to be added: ";
                    cin >> n;
                    employeeList.createList(n);
                    break;
            case 2: employeeList.display();
                    cout << "Number of nodes in DLL: " << employeeList.countNodes() << endl;
                    break;
            case 3: employeeList.insertEnd();
                    break;
            case 4: employeeList.deleteEnd();
                    break;
            case 5: employeeList.insertFront();
                    break;
            case 6: employeeList.deleteFront();
                    break;
            case 7: employeeList.doubleEndedQueue();
                    break;
            case 8: exit(0);
            default: cout << "Invalid choice!\n";
        }
    }

    return 0;
}
