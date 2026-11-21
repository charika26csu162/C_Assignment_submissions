#include <stdio.h>
#include <stdlib.h>

// Function to find and print the first saddle point in row-major order
void findSaddlePoint(long long **matrix, int r, int c) {
    if (r <= 0 || c <= 0) {
        printf("None\n");
        return;
    }
    
    int found = 0;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            long long val = matrix[i][j];
            int isRowMin = 1;
            int isColMax = 1;
            
            // Check if val is minimum in row i
            for (int k = 0; k < c; k++) {
                if (matrix[i][k] < val) {
                    isRowMin = 0;
                    break;
                }
            }
            
            // Check if val is maximum in column j
            if (isRowMin) {
                for (int k = 0; k < r; k++) {
                    if (matrix[k][j] > val) {
                        isColMax = 0;
                        break;
                    }
                }
            } else {
                isColMax = 0;
            }
            
            // If both conditions are satisfied, print the first match (0-indexed: row col value)
            if (isRowMin && isColMax) {
                printf("%d %d %lld\n", i, j, val);
                found = 1;
                return; // Stop at first row-major match
            }
        }
    }
    
    if (!found) {
        printf("None\n");
    }
}

int main(void) {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        printf("None\n");
        return 0;
    }
    
    // Dynamically allocate 2D matrix
    long long **matrix = (long long **)malloc(r * sizeof(long long *));
    for (int i = 0; i < r; i++) {
        matrix[i] = (long long *)malloc(c * sizeof(long long));
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }
    
    findSaddlePoint(matrix, r, c);
    
    // Free dynamic memory
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}
