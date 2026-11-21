#include <stdio.h>
#include <stdlib.h>

// Function to find the length of the longest strictly increasing contiguous subarray
int longestIncreasingRun(int arr[], int n) {
    if (n <= 0) return 0;
    
    int maxLen = 1;
    int currentLen = 1;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            currentLen++;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else {
            currentLen = 1; // Reset run length when non-increasing element is found
        }
    }
    
    return maxLen;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("0\n");
        return 0;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) return 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d\n", longestIncreasingRun(arr, n));
    
    free(arr);
    return 0;
}