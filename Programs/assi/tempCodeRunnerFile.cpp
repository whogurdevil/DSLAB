void print(struct Node* head){
//     Node* temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

// void insertAtTail(struct Node* &head, struct Node* nodeToAdd){

//     if(head == NULL){
//         head = nodeToAdd;
//         return;
//     }

//     Node* temp = head;


//     while(temp->next != NULL){
//         temp = temp -> next;
//     }

//     temp -> next =  nodeToAdd;
// }

// void insertAtHead(struct Node* &head, struct Node* nodeToAdd){
//     if(head == NULL){
//         head = nodeToAdd;
//         return;
//     }

//     nodeToAdd->next = head;
//     head = nodeToAdd;
// }