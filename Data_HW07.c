#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to add element at the end
void addElement(int arr[], int *size, int value) {
    if (*size < MAX_SIZE) {
        arr[*size] = value;
        (*size)++;
        printf("Element %d added successfully.\n", value);
    } else {
        printf("Array is full!\n");
    }
}

// Function to delete element at index
void deleteElement(int arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index!\n");
        return;
    }
    
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element at index %d deleted successfully.\n", index);
}

// Function to display array
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    
    addElement(arr, &size, 10);
    addElement(arr, &size, 20);
    addElement(arr, &size, 30);
    displayArray(arr, size);
    
    deleteElement(arr, &size, 1);
    displayArray(arr, size);
    
    return 0;
}

// Function to insert element at specific index
void insertElement(int arr[], int *size, int index, int value) {
    if (index < 0 || index > *size) {
        printf("Invalid index!\n");
        return;
    }
    if (*size >= MAX_SIZE) {
        printf("Array is full!\n");
        return;
    }
    
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*size)++;
    printf("Element %d inserted at index %d successfully.\n", value, index);
}