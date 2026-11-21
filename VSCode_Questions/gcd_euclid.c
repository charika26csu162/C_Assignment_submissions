#include <stdio.h>

// Function to compute GCD using Euclidean Algorithm
long long gcd(long long a, long long b) {
    // Convert inputs to absolute values since GCD is always positive
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    // Iterative Euclidean Algorithm: gcd(a, b) = gcd(b, a % b)
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    
    return a;
}

int main(void) {
    long long a, b;
    
    // Read a and b from standard input
    if (scanf("%lld %lld", &a, &b) == 2) {
        printf("%lld\n", gcd(a, b));
    }
    
    return 0;
}