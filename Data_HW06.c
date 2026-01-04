#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* addArray(Node* head, int arr[], int size) {
    if (size == 0) return head;
    
    Node* newNode = createNode(arr[0]);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
    }
    
    for (int i = 1; i < size; i++) {
        Node* node = createNode(arr[i]);
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        node->next = head;
        temp->next = node;
    }
    
    return head;
}

Node* deleteNode(Node* head, int data) {
    if (head == NULL) return NULL;
    
    if (head->data == data && head->next == head) {
        free(head);
        return NULL;
    }
    
    if (head->data == data) {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        return temp->next;
    }
    
    Node* temp = head;
    while (temp->next != head && temp->next->data != data) {
        temp = temp->next;
    }
    
    if (temp->next != head) {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    
    return head;
}

void traverse(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    Node* head = NULL;
    int arr[] = {10, 20, 30, 40, 50};
    
    head = addArray(head, arr, 5);
    printf("After adding array: ");
    traverse(head);
    
    head = deleteNode(head, 30);
    printf("After deleting 30: ");
    traverse(head);
    
    head = deleteNode(head, 10);
    printf("After deleting 10: ");
    traverse(head);
    
    return 0;
}