#include <stdio.h>

// Function to solve Tower of Hanoi puzzle

void hanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("\nMove disk 1 from %c to %c\n", source, target);
        return;
    }
    hanoi(n - 1, source, auxiliary, target);
    printf("\nMove disk %d from %c to %c\n", n, source, target);
    hanoi(n - 1, auxiliary, target, source);
}

int main() {
    int num_disks;

    printf("\nEnter number of disks: ");
    if (scanf("%d", &num_disks) != 1 || num_disks < 1) {
        printf("\nInvalid input.\n");
        return 1;
    }

    printf("\nSteps to solve Tower of Hanoi:\n");
    hanoi(num_disks, 'A', 'C', 'B');
    printf("\n");
    return 0;
}