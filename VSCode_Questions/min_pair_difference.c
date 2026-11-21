#include <stdio.h>
#include <stdlib.h>

long long minPairDifference(long long arr[], int n) {
    if (n <= 1) return 0;

    long long minDiff = -1; // Flag for initial pair comparison

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long diff = arr[i] - arr[j];
            if (diff < 0) diff = -diff; // Absolute difference

            if (minDiff == -1 || diff < minDiff) {
                minDiff = diff;
            }
        }
    }

    return minDiff;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 1) {
        return 0;
    }

    long long *arr = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    printf("%lld\n", minPairDifference(arr, n));

    free(arr);
    return 0;
}