#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int size;
} Tree;

// Initialize tree
Tree* initTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->size = 0;
    return tree;
}

// Insert element in tree (level-order)
void insert(Tree* tree, int value) {
    if (tree->size < MAX_SIZE) {
        tree->arr[tree->size] = value;
        tree->size++;
    } else {
        printf("Tree is full!\n");
    }
}

// Get left child index
int getLeftChild(int index) {
    return 2 * index + 1;
}

// Get right child index
int getRightChild(int index) {
    return 2 * index + 2;
}

// Get parent index
int getParent(int index) {
    return (index - 1) / 2;
}

// Print tree in level-order
void printTree(Tree* tree) {
    for (int i = 0; i < tree->size; i++) {
        printf("%d ", tree->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Tree* tree = initTree();
    
    insert(tree, 1);
    insert(tree, 2);
    insert(tree, 3);
    insert(tree, 4);
    insert(tree, 5);
    
    printf("Tree: ");
    printTree(tree);
    
    free(tree);
    return 0;
}