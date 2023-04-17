#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void push_front(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        int temp = (*head)->data;
        (*head)->data = newNode->data;
        newNode->data = temp;
    }
}

void push_back(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode;
    }
}

void pop_front(struct Node **head) {
    if (*head == NULL) {
        printf("Circular linked list is empty.\n");
    } else {
        struct Node *temp = (*head)->next;
        if (temp == *head) {
            *head = NULL;
        } else {
            (*head)->next = temp->next;
            free(temp);
        }
    }
}

void pop_back(struct Node **head) {
    if (*head == NULL) {
        printf("Circular linked list is empty.\n");
    } else {
        struct Node *temp = (*head)->next;
        if (temp == *head) {
            *head = NULL;
        } else {
            while (temp->next != *head) {
                temp = temp->next;
            }
            temp->next = (*head)->next;
            free(*head);
            *head = temp;
        }
    }
}

void traverse(struct Node *head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
    } else {
        struct Node *temp = head->next;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head->next);
        printf("\n");
    }
}

int search(struct Node *head, int data) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
    } else {
        struct Node *temp = head->next;
        int found = 0;
        int count = 1;
        do {
            if (temp->data == data) {
                printf("Element found at %dth position\n", count);
                found = 1;
                return count;
                break;
            }
            temp = temp->next;
            count++;
        } while (temp != head->next);
        if (!found) {
            printf("Element not found.\n");
            return -1;
        }
    }
}

int main() {
    struct Node *head = NULL;
    int choice, data;
    do {
    printf("Circular Linked List Operations\n");
    printf("1. Insert from beginning\n");
    printf("2. Insert from end\n");
    printf("3. Delete from beginning\n");
    printf("4. Delete from end\n");
    printf("5. Traverse and display elements\n");
    printf("6. Search elements from circular linked list\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            system("cls");
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            push_front(&head, data);
            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            push_back(&head, data);
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            pop_front(&head);
            system("pause");
            system("cls");
            break;

        case 4:
            system("cls");
            pop_back(&head);
            system("pause");
            system("cls");
            break;

        case 5:
            system("cls");
            traverse(head);
            system("pause");
            system("cls");
            break;

        case 6:
            system("cls");
            printf("Enter the element to be searched: ");
            scanf("%d", &data);
            search(head, data);
            system("pause");
            system("cls");
            break;

        case 7:
            system("cls");
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

} while (choice != 7);

return 0;
}
