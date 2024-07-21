#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 1000

int main() {
    int word_lengths[MAX_WORD_LENGTH + 1] = {0};
    char word[MAX_WORD_LENGTH + 1];
    int word_count = 0;
    int c, len = 0;

    while ((c = getchar()) != EOF && word_count < MAX_WORDS) {
        if (isalpha(c)) {
            if (len < MAX_WORD_LENGTH) {
                word[len++] = c;
            }
        } else if (len > 0) {
            word[len] = '\0';
            word_lengths[len]++;
            word_count++;
            len = 0;
        }
    }

    printf("Word Length Histogram:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        if (word_lengths[i] > 0) {
            printf("%2d: ", i);
            for (int j = 0; j < word_lengths[i]; j++) {
                putchar('*');
            }
            printf(" (%d)\n", word_lengths[i]);
        }
    }

    return 0;
}
