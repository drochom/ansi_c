#include <stdio.h>

#define MAX_WORD_LENGTH 20
#define IN 1
#define OUT 0

int main() {
    int c, i, j, state, word_length;
    int word_lengths[MAX_WORD_LENGTH];

    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        word_lengths[i] = 0;
    }

    state = OUT;
    word_length = 0;

    printf("Enter text (Ctrl+D to end):\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (word_length < MAX_WORD_LENGTH) {
                    ++word_lengths[word_length];
                } else {
                    ++word_lengths[MAX_WORD_LENGTH - 1];
                }
                word_length = 0;
            }
            state = OUT;
        } else {
            if (state == OUT) {
                state = IN;
                word_length = 1;
            } else {
                ++word_length;
            }
        }
    }

    // Print histogram
    printf("\nHistogram of word lengths:\n");
    for (i = 1; i < MAX_WORD_LENGTH; ++i) {
        printf("%2d: ", i);
        for (j = 0; j < word_lengths[i]; ++j) {
            putchar('*');
        }
        printf("\n");
    }

    // Handle overflow case
    if (word_lengths[MAX_WORD_LENGTH - 1] > 0) {
        printf("%2d+: ", MAX_WORD_LENGTH);
        for (j = 0; j < word_lengths[MAX_WORD_LENGTH - 1]; ++j) {
            putchar('*');
        }
        printf("\n");
    }

    return 0;
}
