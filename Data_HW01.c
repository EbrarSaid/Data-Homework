#include <stdio.h>
#include <stdlib.h>

// Structure for a sparse matrix element (row, col, value)
typedef struct {
    int row;
    int col;
    int value;
} Element;

// Structure for a sparse matrix
typedef struct {
    int rows;
    int cols;
    int num;      // Number of non-zero elements
    Element *data;
} SparseMatrix;

// Function to create a sparse matrix
SparseMatrix createSparseMatrix(int rows, int cols, int num) {
    SparseMatrix sm;
    sm.rows = rows;
    sm.cols = cols;
    sm.num = num;
    sm.data = (Element *)malloc(num * sizeof(Element));
    return sm;
}

// Function to print a sparse matrix
void printSparseMatrix(SparseMatrix sm) {
    printf("Row Col Value\n");
    for (int i = 0; i < sm.num; i++) {
        printf("%3d %3d %5d\n", sm.data[i].row, sm.data[i].col, sm.data[i].value);
    }
}

// Function to transpose a sparse matrix
SparseMatrix transposeSparseMatrix(SparseMatrix sm) {
    SparseMatrix trans;
    trans.rows = sm.cols;
    trans.cols = sm.rows;
    trans.num = sm.num;
    trans.data = (Element *)malloc(sm.num * sizeof(Element));

    int k = 0;
    for (int col = 0; col < sm.cols; col++) {
        for (int i = 0; i < sm.num; i++) {
            if (sm.data[i].col == col) {
                trans.data[k].row = sm.data[i].col;
                trans.data[k].col = sm.data[i].row;
                trans.data[k].value = sm.data[i].value;
                k++;
            }
        }
    }
    return trans;
}

int main() {
    // Example: 3x3 matrix with 4 non-zero elements
    SparseMatrix sm = createSparseMatrix(3, 3, 4);
    sm.data[0] = (Element){0, 0, 1};
    sm.data[1] = (Element){0, 2, 2};
    sm.data[2] = (Element){1, 1, 3};
    sm.data[3] = (Element){2, 0, 4};

    printf("Original Sparse Matrix:\n");
    printSparseMatrix(sm);

    SparseMatrix trans = transposeSparseMatrix(sm);
    printf("\nTransposed Sparse Matrix:\n");
    printSparseMatrix(trans);

    free(sm.data);
    free(trans.data);
    return 0;
}