#include <stdio.h>
#include <ctype.h>

void countCharacters(const char *str) {
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
    
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        char ch = str[i];
        
        if (ch == ' ') {
            spaces++;
        } else if (isdigit((unsigned char)ch)) {
            digits++;
        } else if (isalpha((unsigned char)ch)) {
            char lower = tolower((unsigned char)ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
        // Punctuation and special characters are ignored automatically
    }
    
    printf("%d %d %d %d\n", vowels, consonants, digits, spaces);
}

int main(void) {
    char str[1024];
    if (fgets(str, sizeof(str), stdin) != NULL) {
        countCharacters(str);
    }
    return 0;
}