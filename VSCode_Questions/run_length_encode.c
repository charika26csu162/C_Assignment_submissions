#include <stdio.h>
#include <string.h>

void runLengthEncode(const char *str) {
    int len = strlen(str);
    if (len == 0) return;
    
    int count = 1;
    for (int i = 0; i < len; i++) {
        // Skip newline or carriage return if present
        if (str[i] == '\n' || str[i] == '\r') continue;
        
        // Check if next character matches current
        if (i + 1 < len && str[i] == str[i + 1]) {
            count++;
        } else {
            printf("%c%d", str[i], count);
            count = 1; // Reset run count for next character group
        }
    }
    printf("\n");
}

int main(void) {
    char str[1024];
    if (fgets(str, sizeof(str), stdin) != NULL) {
        runLengthEncode(str);
    }
    return 0;
}