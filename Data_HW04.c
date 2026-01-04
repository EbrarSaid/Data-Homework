#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int size;
} Heap;

// Utility function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// MAX HEAP FUNCTIONS
void insertMaxHeap(Heap *heap, int value) {
    if (heap->size >= MAX_SIZE) return;
    heap->arr[heap->size] = value;
    int i = heap->size;
    heap->size++;
    
    while (i > 0 && heap->arr[(i - 1) / 2] < heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapify(Heap *heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

int deleteMaxHeap(Heap *heap) {
    if (heap->size == 0) return -1;
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);
    return max;
}

// MIN HEAP FUNCTIONS
void insertMinHeap(Heap *heap, int value) {
    if (heap->size >= MAX_SIZE) return;
    heap->arr[heap->size] = value;
    int i = heap->size;
    heap->size++;
    
    while (i > 0 && heap->arr[(i - 1) / 2] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapify(Heap *heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;
    
    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

int deleteMinHeap(Heap *heap) {
    if (heap->size == 0) return -1;
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return min;
}

void printHeap(Heap *heap) {
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);
    printf("\n");
}

// MAIN FUNCTION
int main() {
    Heap maxHeap, minHeap;
    maxHeap.size = 0;
    minHeap.size = 0;
    
    printf("MAX HEAP:\n");
    insertMaxHeap(&maxHeap, 10);
    insertMaxHeap(&maxHeap, 20);
    insertMaxHeap(&maxHeap, 15);
    insertMaxHeap(&maxHeap, 30);
    printHeap(&maxHeap);
    
    printf("MIN HEAP:\n");
    insertMinHeap(&minHeap, 10);
    insertMinHeap(&minHeap, 20);
    insertMinHeap(&minHeap, 15);
    insertMinHeap(&minHeap, 30);
    printHeap(&minHeap);
    
    return 0;
}