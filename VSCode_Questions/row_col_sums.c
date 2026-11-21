#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        return 0;
    }
    
    long long **matrix = (long long **)malloc(r * sizeof(long long *));
    for (int i = 0; i < r; i++) {
        matrix[i] = (long long *)malloc(c * sizeof(long long));
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }
    
    // Print row sums on line 1
    for (int i = 0; i < r; i++) {
        long long rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += matrix[i][j];
        }
        printf("%lld%c", rowSum, (i == r - 1) ? '\n' : ' ');
    }
    
    // Print column sums on line 2
    for (int j = 0; j < c; j++) {
        long long colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += matrix[i][j];
        }
        printf("%lld%c", colSum, (j == c - 1) ? '\n' : ' ');
    }
    
    // Free dynamically allocated 2D array memory
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}
