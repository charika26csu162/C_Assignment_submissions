#include <stdio.h>
#include <stdlib.h>

int countLocalPeaks(long long **matrix, int r, int c) {
    if (r <= 0 || c <= 0) return 0;
    
    int peakCount = 0;
    
    // Direction offsets for Up, Down, Left, Right
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            long long current = matrix[i][j];
            int isPeak = 1;
            
            for (int d = 0; d < 4; d++) {
                int ni = i + dr[d];
                int nj = j + dc[d];
                
                // Only compare against valid in-bounds neighbours
                if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                    if (current <= matrix[ni][nj]) {
                        isPeak = 0;
                        break;
                    }
                }
            }
            
            if (isPeak) {
                peakCount++;
            }
        }
    }
    
    return peakCount;
}

int main(void) {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        printf("0\n");
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
    
    printf("%d\n", countLocalPeaks(matrix, r, c));
    
    // Free dynamic memory
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}