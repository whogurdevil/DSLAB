#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

void create(struct node* Node, int val){
    Node = malloc(sizeof(Node) + sizeof(val));
    Node->data = val;
    Node->next = NULL;
    printf("%d", Node->data);

}

int main(){
    struct node* temp;
    create(temp, 10);
}