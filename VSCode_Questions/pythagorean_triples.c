#include <stdio.h>

void findPythagoreanTriples(int N) {
    int found = 0;
    for (long long a = 1; a <= N - 2; a++) {
        for (long long b = a + 1; b <= N - 1; b++) {
            for (long long c = b + 1; c <= N; c++) {
                if (a * a + b * b == c * c) {
                    printf("%lld %lld %lld\n", a, b, c);
                    found = 1;
                }
            }
        }
    }
    if (!found) {
        printf("None\n");
    }
}

int main(void) {
    int N;
    if (scanf("%d", &N) == 1) {
        findPythagoreanTriples(N);
    }
    return 0;
}

