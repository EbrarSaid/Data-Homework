#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
} DoublyLinkedList;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Initialize list
DoublyLinkedList* initList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    return list;
}

// Add element at end
void addElement(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Add array elements
void addArray(DoublyLinkedList* list, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        addElement(list, arr[i]);
    }
}

// Delete node by value
void deleteNode(DoublyLinkedList* list, int data) {
    if (list->head == NULL) return;
    
    Node* current = list->head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    
    if (current == NULL) return;
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    
    free(current);
}

// Forward traversal
void traverseForward(DoublyLinkedList* list) {
    Node* current = list->head;
    printf("Forward: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Backward traversal
void traverseBackward(DoublyLinkedList* list) {
    if (list->head == NULL) return;
    
    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    printf("Backward: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Main example
int main() {
    DoublyLinkedList* list = initList();
    
    int arr[] = {10, 20, 30, 40, 50};
    addArray(list, arr, 5);
    
    traverseForward(list);
    traverseBackward(list);
    
    deleteNode(list, 30);
    traverseForward(list);
    
    return 0;
}