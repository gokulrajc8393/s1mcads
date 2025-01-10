#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

int a[11] = {0}; // Set A
int b[11] = {0}; // Set B
int res[11] = {0}; // Result Set
int U[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Universal Set

void display(int bs[]) {
    for (int i = 1; i < 11; i++) {
        printf("%d\t", bs[i]);
    }
    printf("\n");
}

void input(int bs[], int n) {
    int x;
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x >= 1 && x <= 10) {
            bs[x] = 1;
        } else {
            printf("Invalid element. Please enter a number between 1 and 10.\n");
            i--;
        }
    }
}

void set_union() {
    for (int i = 1; i < 11; i++) {
        res[i] = a[i] | b[i];
    }
    printf("\nUnion Set: ");
    display(res);
}

void set_intersection() {
    for (int i = 1; i < 11; i++) {
        res[i] = a[i] & b[i];
    }
    printf("\nIntersection Set: ");
    display(res);
}

void set_difference() {
    for (int i = 1; i < 11; i++) {
        res[i] = a[i] & ~b[i];
    }
    printf("\nDifference Set: ");
    display(res);
}

bool set_equality() {
    for (int i = 1; i < 11; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;

    printf("Enter the number of elements in set A: ");
    scanf("%d", &n);
    input(a, n);

    printf("Enter the number of elements in set B: ");
    scanf("%d", &n);
    input(b, n);

    int choice;
    do {
        printf("\nMENU");
        printf("\n1. Union\n2. Intersection\n3. Difference\n4. Check Equality\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                set_union();
                break;
            case 2:
                set_intersection();
                break;
            case 3:
                set_difference();
                break;
            case 4:
                if (set_equality()) {
                    printf("\nSets A and B are equal.\n");
                } else {
                    printf("\nSets A and B are not equal.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice >= 1 && choice <= 5);

    return 0;
}
