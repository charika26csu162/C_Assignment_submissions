#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("NO\n");
        return 0;
    }
    
    long long **matrix = (long long **)malloc(n * sizeof(long long *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (long long *)malloc(n * sizeof(long long));
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }
    
    int isSymmetric = 1;
    // Compare entries above the main diagonal (j > i) with mirrored entries (matrix[j][i])
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) break;
    }
    
    if (isSymmetric) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}