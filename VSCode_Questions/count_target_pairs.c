#include <stdio.h>
#include <stdlib.h>

// Function to count index pairs i < j such that arr[i] + arr[j] == target
int countTargetPairs(int arr[], int n, long long target) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long)arr[i] + arr[j] == target) {
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    int n;
    long long target;
    
    if (scanf("%d %lld", &n, &target) != 2 || n <= 1) {
        printf("0\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", countTargetPairs(arr, n, target));

    free(arr);
    return 0;
}
