#include <stdio.h>
#include <stdlib.h>

// Helper function to calculate sum of digits
int digitSum(int num) {
    if (num < 0) num = -num;
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countEqualDigitSumPairs(int arr[], int n) {
    if (n <= 1) return 0;
    
    int *sums = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        sums[i] = digitSum(arr[i]);
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sums[i] == sums[j]) {
                count++;
            }
        }
    }

    free(sums);
    return count;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 1) {
        printf("0\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", countEqualDigitSumPairs(arr, n));

    free(arr);
    return 0;
}